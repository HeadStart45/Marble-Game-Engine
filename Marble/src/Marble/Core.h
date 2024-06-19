#pragma once

#ifdef MB_PLATFORM_WINDOWS
	#ifdef MB_BUILD_DLL
		#define MARBLE_API __declspec(dllexport) //IN ENGINE
	#else
		#define MARBLE_API __declspec(dllimport) //ELSEWHERE
	#endif 
	
#else
	#error Marble is currently only supported on Windows

#endif