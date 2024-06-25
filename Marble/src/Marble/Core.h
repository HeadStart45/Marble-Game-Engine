#pragma once
//Define macros for exporting or importing DLL functions
#ifdef MB_PLATFORM_WINDOWS
	#ifdef MB_BUILD_DLL
		#define MARBLE_API __declspec(dllexport) //IN ENGINE
	#else
		#define MARBLE_API __declspec(dllimport) //ELSEWHERE
	#endif 
	
#else
	#error Marble is currently only supported on Windows

#endif

#ifdef MB_ENABLE_ASSERTS
	#define MB_ASSERT(x, ...) { if(!(x)) { MB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MB_CORE_ASSERT(x, ...) { if(!(x)) { MB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MB_ASSERT(x, ...)
	#define MB_CORE_ASSERT(x, ...)

#endif


#define BIT(x) (1 << x)