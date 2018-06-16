#pragma once
#ifdef STRINGS_EXPORTS
#define STRINGS_API __declspec(dllexport) 
#else
#define STRINGS_API __declspec(dllimport) 
#endif

namespace Strings
{
	STRINGS_API char** ObtainWords(char * source, int & n);
	STRINGS_API void DisplayWords(char** words, int n);
	STRINGS_API void FreeHeap(char** words, int n);
	STRINGS_API void FindMaxAndMinWords(char** words, int n, int &max, int &min);
	STRINGS_API char* WriteInArray(char** words, int n, int max, int min);
}