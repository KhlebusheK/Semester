// String.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <iostream>
#include "StringLibrary.h"

using namespace StringExtention;

MATHLIBRARY_API char** StringExtention::ObtainWords(char* source, int& n)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* vowels = "EYUIOAeyuioa";
	char** words = new char*[strlen(source) / 2];

	n = 0;
	char* pword = strpbrk(source, symbols);
	while (pword)
	{
		int length = strspn(pword, symbols);
		for (int i = 0; i <= strlen(vowels); i++)
		{
			if (words[n][0] == vowels[i])
			{
				for (int i = 0; i <= strlen(vowels); i++)
				{
					if (words[n][length - 1] == vowels[i])
					{
						words[n] = new char[length + 1];
						strncpy(words[n], pword, length);
						words[n][length] = '\0';
					}
				}
			}
		}
	
		pword += length;
		pword = strpbrk(pword, symbols);
		n++;
	}

	return words;
}

MATHLIBRARY_API void StringExtention::DisplayWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << (i + 1) << ". " << words[i] << std::endl;
}

MATHLIBRARY_API void StringExtention::FreeHeap(char** words, int n)
{
	for (int i = 0; i < n; i++)
		delete[] words[i];
	delete[] words;
}


