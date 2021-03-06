// 12.04.2018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include "Material.Laba3.h"
//#include <stdlib>
//#include <process>

using namespace std;

void CreateFile(char* fileName, int n);
int ContentsFile(char*);
int** InitArray(char*, int);
void AddFile(char*, int**, int);


int main()
{
	const int N = 80;
	char fileName[N] = "";

	cout << "Enter the name of file: ";
	cin.getline(fileName, N, '\n');

	int n;
	cout << "Enter dimension of matrix :" << endl;
	cin >> n;

	CreateFile(fileName, n);

	int count = ContentsFile(fileName);

	int** matrix = InitArray(fileName, count);
	int** newMatrix = AllocateMemory(n);

	InitNewMatrix = (matrix, newMatrix, n);
	
	AddFile(fileName, newMatrix, n);

	FreeMemory(matrix, n);
	FreeMemory(newMatrix, n);

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
		for (int j = 1; j <= n; j++)
		{
			int temp = rand() % 100 - 50;
			streamOut.width(5);
			streamOut << temp;
		}
		std::cout << std::endl;
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

	/*streamIn.seekg(0, ios::beg);
	streamIn.clear();

	int count_space = 0;
	char symbol;
	while (!streamIn.eof())
	{
		streamIn.get(symbol);
		if (symbol == ' ') count_space++;
		if (symbol == '\n') break;
	}

	streamIn.seekg(0, ios::beg);
	streamIn.clear();
*/
	streamIn.close();

	count = sqrt(count);

	return count;
}

int** InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			streamIn >> arr[i][j];
		}
    }
	streamIn.close();
	return arr;
}

void AddFile(char* fileName, int** arr, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			streamOut.width(5);
			streamOut << arr[i];
		}
		std::cout << std::endl;
	}
	streamOut.close();
}




