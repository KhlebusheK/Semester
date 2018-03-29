// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "StringLibrary.h"

using namespace std;

int main()
{
	const int LENGTH = 256;
	char str[LENGTH] = "	The   ??? arra usual form of input, 098 -1  =+   For most statistical functions is a list of data... 89 Form. ";

	system("cls");
	cout << endl << "\tSTRING IS:" << endl;
	cout << str;

	int n = 0;
	char** arrayWords = StringExtention::ObtainWords(str, n);
	cout << endl << "\tARRAY OF WORDS" << endl;

	StringExtention::DisplayWords(arrayWords, n);

	StringExtention::FreeHeap(arrayWords, n);

	cout << endl;
	system("pause");
	
}

