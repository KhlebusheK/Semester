// MatrixLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <iostream>
#include "MatrixLibrary.h"

using namespace MatrixLibrary;

#pragma region prepare
MATRIXLIBRARY_API double ** MatrixLibrary::AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	double** a = new double*[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}

	return a;
}

MATRIXLIBRARY_API void MatrixLibrary::FreeMemory(double ** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

MATRIXLIBRARY_API void MatrixLibrary::DisplayMatrix(double ** matrix, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (matrix == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	/*for (int i = 0; i < n; i++)
	{
	if ( *(matrix + i) == nullptr)
	{
	throw std::invalid_argument("Argument is null!");
	}
	}*/

	for (int i = 0; i < n; ++i)
	{

		for (int j = 0; j < n; ++j)
		{
			std::cout.width(8);
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}
}
#pragma endregion

MATRIXLIBRARY_API void MatrixLibrary::InitRandomMatrix(double ** array, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (array == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = rand() % 100;
		}
	}
}

MATRIXLIBRARY_API double MatrixLibrary::FindMax(double ** matrix, int n, int x, int y)
{
	int k = 0, p = 0, s = 0;
	double max = matrix[x][y];
	
		for (int i=0; i < n; i++)
		{
			for (int j=0; j < n; j++)
			{
				k = y;
				p = x - y;
				s = x + y;

				if (j >= k || i - j <= p || i + j >= s)
				{
					if (matrix[i][j] >= max) max = matrix[i][j];
				}
			}

		}
		return max;
}

MATRIXLIBRARY_API void MatrixLibrary::InitMatrixB(double ** array, double ** B, int n)
{

	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (array||B == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int k = i; int s = j;
			B[i][j] = FindMax(array, n, k, s);
		}
	}
}

