#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport) 
#else
#define MATHLIBRARY_API __declspec(dllimport) 
#endif

namespace StringExtention
{
	MATHLIBRARY_API char** ObtainWords(char* source, int& n);
	MATHLIBRARY_API void DisplayWords(char**, int);
	MATHLIBRARY_API void FreeHeap(char**, int);
}
