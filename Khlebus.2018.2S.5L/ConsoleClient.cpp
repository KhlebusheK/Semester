// Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Strings.h"

using namespace Strings;


int main()
{
	int n = 9;
	int max, min;

	char source[] = "111 Yes No-12365&*)(^%dfreejjfjkkeld; pr sd";

	char** string = ObtainWords(source, n);
	DisplayWords(string, n);

	FindMaxAndMinWords(string, n, max, min);

	char * sortedwords = WriteInArray(string, n, max, min);

	std::cout << std::endl << sortedwords << std::endl;

	FreeHeap(string,n);

	system("pause");
	return 0;
}


