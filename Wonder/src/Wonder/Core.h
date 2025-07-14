#pragma once

#ifdef WD_PLATFORM_WINDOWS
	#ifdef WD_BUILD_DLL
		#define WONDER_API __declspec(dllexport)
	#else
		#define WONDER_API __declspec(dllimport)
	#endif
#else
	#error Wonder only supports Windows!
#endif