// Common Includes
#include "stdio.h"
#include <vector>
#include "half.h"
#include <sstream>
#include <iostream>
#include <locale>
#include <string>
#include <algorithm>
//#include <cvt/wstring>
#include "windows.h"

// TinyXML
#include "tinyxml/tinyxml.h"

// FBX Includes
#ifdef LIBXENOVERSE_FBX_SUPPORT
#include <fbxsdk.h>
#include <fbxsdk/fileio/fbxiosettings.h>
#endif

#ifdef LIBXENOVERSE_ZLIB_SUPPORT
// ZLIB Includes
//#include "zlib.h"
#endif

#ifdef LIBXENOVERSE_WINSDK_SUPPORT
#include "D3Dcompiler.h"
#include <d3d9.h>
#include <d3dx9.h>
#endif

// Xenoverse Includes
#include "XenoFiles.h"
#include "XenoMath.h"
#include "Havok.h"
//#include "UassetUexp.h"


using namespace std;

#ifndef LIBXENOVERSE_H_INCLUDED
#define LIBXENOVERSE_H_INCLUDED

//#define LIBXENOVERSE_DEBUGGING_LOG

#ifdef LIBXENOVERSE_DEBUGGING_LOG
#define LOG_DEBUG(fmt, ...) if (global_debugging_log) fprintf(global_debugging_log, fmt, __VA_ARGS__)
#else
#define LOG_DEBUG(fmt, ...)
#endif

namespace LibXenoverse {
	extern FILE *global_debugging_log;
		

	//help for application preference conditions of ending
	enum ApplicationEndWait
	{
		AEW_None = 0,
		AEW_OnError,
		AEW_OnWarning,
		AEW_Always,
	};

	extern bool HAVE_WARNINGS;
	extern bool HAVE_ERRORS;
	extern ApplicationEndWait applicationEndWait;

	void setWarningErrorsFalse();
	void notifyWarning();
	void notifyError();
	void setApplicationEndWait(ApplicationEndWait aew);
	bool haveToWait();
	void waitOnEnd();

	string fillStringNumberLeft(string value, size_t numberCharacter);

	std::vector<string> initApplication(int argc, char** argv, ApplicationEndWait applicationEndWait = AEW_OnError);
	void initializeDebuggingLog();
	void flushDebuggingLog();
	void closeDebuggingLog();
}

#endif