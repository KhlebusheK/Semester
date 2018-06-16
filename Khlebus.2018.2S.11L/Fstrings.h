#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

char** ObtainWords(char * source, int & n);
void DisplayWords(char** words, int n);
void FreeHeap(char** words, int n);
void FindMaxAndMinWords(char** words, int n, int &max, int &min);
char* WriteInArray(char** words, int n, int max, int min);

void CreateFile(char* fileName);
int ContentsFile(char*);
char* InitArray(char*, int);
void AddFile(char*, char*, char*);

#pragma region MaterialLaba5
char** ObtainWords(char * source, int & n)
{
	char* copy = new char[strlen(source) + 1];
	strcpy(copy, source);

	char** words = new char*[strlen(copy) / 2];
	n = 0;
	char symbols[42] = "	1234567890-=!@#$%^&*()_+{}|][:;'<>?/., \x22";
	char* pword = strtok(copy, symbols);
	words[n] = new char[strlen(pword) + 1];
	strcpy(words[n], pword);

	n++;
	while (pword)
	{
		pword = strtok('\0', symbols);
		if (pword)
		{
			words[n] = new char[strlen(pword) + 1];
			strcpy(words[n], pword);
			n++;
		}
	}

	delete[] copy;
	return words;
}


void DisplayWords(char** words, int n)
{
	std::cout << "All words in the string :" << "\n";

	for (int i = 0; i < n; i++)
		std::cout << (i + 1) << ". " << words[i] << std::endl;

	std::cout << "\n";
}


void FreeHeap(char** words, int n)
{
	for (int i = 0; i < n; i++)
		delete[] words[i];
	delete[] words;
}



void FindMaxAndMinWords(char** words, int n, int &max, int &min)
{
	max = 0;
	min = strlen(words[0]);
	for (int i = 0; i < n; i++)
	{
		if (strlen(words[i]) > max)
		{
			max = strlen(words[i]);
		}
		if (strlen(words[i]) < min)
		{
			min = strlen(words[i]);
		}
	}
}

char* WriteInArray(char** words, int n, int max, int min)
{
	int sum = 0;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (strlen(words[i]) == max || strlen(words[i]) == min)
		{
			sum += strlen(words[i]);
			num++;
		}
	}
	char* sortedwords = new char[sum + num];
	strcpy(sortedwords, "");
	//std::cout << "All words of the max and min length :";

	for (int i = 0; i < n; i++)
	{
		if (strlen(words[i]) == max || strlen(words[i]) == min)
		{
			strcat(sortedwords, words[i]);
			strcat(sortedwords, " ");
		}
	}

	return sortedwords;
}
#pragma endregion

void CreateFile(char* fileName)
{
	ofstream streamOut(fileName);
	//ofstream streamOut;
	//streamOut.open(fileName, ios::out);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	system("cls");
	
	streamOut << "111 Yes No-12365&*)(^%dfreejjfjkkeld; pr sd";
	streamOut.close();
}

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	int count = 0;
	char term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

char* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	char* arr = new char[n];

	streamIn >> arr;
	streamIn.close();
	return arr;
}


void AddFile(char* fileName, char* arr, char* string)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	int k = strlen(string) + 1;

	streamOut << "\n" << string << "\n" << arr;
	//streamOut << arr;
	streamOut.close();
}