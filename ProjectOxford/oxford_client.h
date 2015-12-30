#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <sys/stat.h>
#include <fcntl.h>
#include "curl/curl.h"

#include "config.h"
#include "face.h"


#define EXPECT_HEADER "Expect"
#define CONTENT_TYPE_HEADER "Content-Type"
#define JSON_CONTENT_TYPE_HEADER "application/json"
#define STREAM_CONTENT_TYPE_HEADER "application/octet-stream"
#define OXFORD_DETECT_ACTION_NAME "detect"
#define OXFORD_SUBSCRIPTION_HEADER "ocp-apim-subscription-key"
#define OXFORD_DETECT_FACE_QUERY OXFORD_SERVICE_URL "/" OXFORD_DETECT_ACTION_NAME "?returnFaceId=true&returnFaceLandmarks=false"

using namespace std;

class oxford_client
{
public:
	oxford_client();
	~oxford_client();
	
	face detect_face(vector<char> frameData);
};

