#Generated by VisualGDB (http://visualgdb.com)
#DO NOT EDIT THIS FILE MANUALLY UNLESS YOU ABSOLUTELY NEED TO
#USE VISUALGDB PROJECT PROPERTIES DIALOG INSTEAD

BINARYDIR := Windows

#Toolchain
CC := D:/SysGCC/threads-mingw64/bin/gcc.exe
CXX := D:/SysGCC/threads-mingw64/bin/g++.exe
LD := $(CXX)
AR := D:/SysGCC/threads-mingw64/bin/ar.exe
OBJCOPY := 

#Additional flags
PREPROCESSOR_MACROS := DEBUG
INCLUDE_DIRS := 
LIBRARY_DIRS := 
LIBRARY_NAMES := curl
ADDITIONAL_LINKER_INPUTS := ../ThirdParty/curl-7.40.0-devel-mingw64/bin/libcurl.dll
MACOS_FRAMEWORKS := 
LINUX_PACKAGES := 

CFLAGS := -ggdb -ffunction-sections -O0 -std=c++11
CXXFLAGS := -ggdb -ffunction-sections -O0 -std=c++11
ASFLAGS := 
LDFLAGS := -Wl,-gc-sections
COMMONFLAGS := 
LINKER_SCRIPT := 

START_GROUP := -Wl,--start-group
END_GROUP := -Wl,--end-group

#Additional options detected from testing the toolchain
USE_DEL_TO_CLEAN := 1
CP_NOT_AVAILABLE := 1
