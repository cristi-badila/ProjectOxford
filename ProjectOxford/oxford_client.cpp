#include "oxford_client.h"



oxford_client::oxford_client()
{
}


oxford_client::~oxford_client()
{
}

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

face oxford_client::detect_face(vector<char> pFrameData)
{
	face detectedFace;
	
	FILE *file = fopen(PHOTO_FILE_PATH, "rb");	
	if (!file)
	{
		return detectedFace;
	}
	
	struct stat file_info;		
	if (fstat(fileno(file), &file_info) != 0)
	{
		return detectedFace;		
	}
		
	CURL *curl;
	CURLcode res;
		
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if (curl)
	{
		std::string responseBuffer;
		
		struct curl_slist *headerlist = NULL;
		headerlist = curl_slist_append(headerlist, EXPECT_HEADER ":");
		headerlist = curl_slist_append(headerlist, CONTENT_TYPE_HEADER ": " STREAM_CONTENT_TYPE_HEADER);
		headerlist = curl_slist_append(headerlist, OXFORD_SUBSCRIPTION_HEADER ": " OXFORD_API_CLIENT_KEY);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
		curl_easy_setopt(curl, CURLOPT_URL, OXFORD_DETECT_FACE_QUERY);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, &pFrameData[0]);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, sizeof(char) * pFrameData.capacity());
		
		res = curl_easy_perform(curl);
		if (res == CURLE_OK)
		{
			Json::Reader jReader;
			Json::Value jValueRoot;
			jReader.parse(&responseBuffer[0], jValueRoot);
			auto jsonFace = jValueRoot[0u];
			detectedFace = face { jsonFace["faceId"].asString() };
		}
		
		curl_slist_free_all(headerlist);
    	curl_easy_cleanup(curl);
	}
	
	curl_global_cleanup();	
	return detectedFace;
}

person oxford_client::identify_face(face pFace)
{
	person result;
	CURL *curl;
	CURLcode res;
		
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if (curl)
	{
		std::string responseBuffer;
		
		Json::Value jsonBody;
		jsonBody["personGroupId"] = OXFORD_GROUP_ID;
		jsonBody["maxNumOfCandidatesReturned"] = 1;
		jsonBody["faceIds"] = Json::arrayValue;
		jsonBody["faceIds"][0u] = pFace.get_id();
		Json::FastWriter fastWriter;
		auto body = fastWriter.write(jsonBody);
		
		struct curl_slist *headerlist = NULL;
		headerlist = curl_slist_append(headerlist, CONTENT_TYPE_HEADER ": " JSON_CONTENT_TYPE_HEADER);
		headerlist = curl_slist_append(headerlist, OXFORD_SUBSCRIPTION_HEADER ": " OXFORD_API_CLIENT_KEY);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
		curl_easy_setopt(curl, CURLOPT_URL, OXFORD_IDENTIFY_FACE_QUERY);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, &body[0]);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, sizeof(char) * body.capacity());	
		
		res = curl_easy_perform(curl);
		if (res == CURLE_OK)
		{
			Json::Reader jReader;
			Json::Value jValueRoot;
			jReader.parse(&responseBuffer[0], jValueRoot);
			if (jValueRoot.isArray())
			{
				auto jsonMatchResult = jValueRoot[0u];
				auto matchedPersons = jsonMatchResult["candidates"];
				if (matchedPersons.size() > 0)
				{
					auto jsonPerson = matchedPersons[0u];
					result = person { jsonPerson["personId"].asString(), true };
				}				
			}			
		}

		curl_slist_free_all(headerlist);
		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();
	
	return result;
}