// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MatrixExtension.h"
#include <iostream>
#include <cmath>

using namespace MatrixLibrary;

int main()
{
	int n;
	std::cout << "Enter number" << std::endl;
	std::cin >> n;

	int accurancy;
	std::cout << "Enter accurancy" << std::endl;
	std::cin >> accurancy;

	double** matrixA = AllocateMemory(n);

	InitMatrixTaylor(matrixA, n, accurancy);
	DisplayMatrix(matrixA, n);

	std::cout << std::endl;


	double** matrixB = AllocateMemory(n);

	InitMatrixTable(matrixB, n);
	DisplayMatrix(matrixB, n);

	std::cout << std::endl;

	CompareMatrix(matrixA, matrixB, n);

	FreeMemory(matrixA, n);
	FreeMemory(matrixB, n);

	system("pause");
}

