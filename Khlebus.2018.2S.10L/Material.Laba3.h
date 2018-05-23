#pragma once

#include <stdexcept>

int ** AllocateMemory(int n);
void FreeMemory(int ** matrix, int n);
int FindMax(int ** matrix, int n, int x, int y);
void InitNewMatrix(int ** array, int ** B, int n);


int ** AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	int** a = new int*[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	return a;
}

void FreeMemory(int ** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int FindMax(int ** matrix, int n, int x, int y)
{
	int k = 0, p = 0, s = 0;
	int max = matrix[x][y];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
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

void InitNewMatrix(int ** array, int ** B, int n)
{

	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (array || B == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = FindMax(array, n, i, j);
		}
	}
}