// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MatrixLibrary.h"

using namespace MatrixLibrary;

int main()
{
	int n;
	std::cout << "Enter number" << std::endl;
	std::cin >> n;

	double** matrixA = AllocateMemory(n);
	InitRandomMatrix(matrixA, n);
	DisplayMatrix(matrixA, n);

	std::cout << std::endl;

	double** matrixB = AllocateMemory(n);

	InitMatrixB(matrixA, matrixB, n);
	DisplayMatrix(matrixB, n);

	//FreeMemory(matrixA, n);
	//FreeMemory(matrixB, n);

	system("pause");
}

