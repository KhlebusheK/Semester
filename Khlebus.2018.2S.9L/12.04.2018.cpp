// 12.04.2018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include "Material.Laba1.h"
//#include <stdlib>
//#include <process>

using namespace std;

void CreateFile(char* fileName, int n);
int ContentsFile(char*);
int* InitArray(char*, int);
void AddFile(char*, int*, int, char*);


int main()
{
	const int N = 80;
	char fileName[N] = "";

	cout << "Enter the name of file: ";
	cin.getline(fileName, N, '\n');

	int n;
	cout << "Enter count of th numbers:" << endl;
	cin >> n;

	
	CreateFile(fileName, n);

	int count = ContentsFile(fileName);

	int* array = InitArray(fileName, count);
	int* newArray = AllocateMemory(n);

#pragma region IsNewMassive
	IsNewMassive(array, newArray, n);

	int k = NumberOfElementsInNewMassive(array, n);

	char str1[N] = "It's new massive :";
	AddFile(fileName, newArray, k, str1);
#pragma endregion

	
	RemoveOldElements(array, newArray, n);
	char str2[N] = "It's old massive without elements : ";
	AddFile(fileName, array, n, str2);

	DisplayBinCountArr(array, n);
	char str3[N] = "Elements of massive is difference between 1 and 0 in the binary form : ";
	AddFile(fileName, array, n, str3);

	SortingOldMassive(array, n);
	char str4[N] = "It's sorting massive : ";
	AddFile(fileName, array, n, str4);

	FreeMemory(array);
	FreeMemory(newArray);

	return 0;
}

void CreateFile(char* fileName, int n)
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
	for (int i = 1; i <= n; i++)
	{
		//cout << "enter value # " << i << " : ";
		//cin >> temp;
		int temp = rand() % 100 - 50;;
		streamOut.width(5);
		streamOut << temp;
		//cout << temp << endl;
	}
	

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

	int count = 0, term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];
	streamIn.close();
	return arr;
}


void AddFile(char* fileName, int* arr, int n, char* string)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	int k = strlen(string) + 1;

	streamOut << "\n" << string << "\n";

	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << arr[i];
	}
	streamOut.close();
}



