#pragma once

#include <stdexcept>

int * AllocateMemory(int n);
void IsNewMassive(int * array, int *newArray, int n);
void RemoveOldElements(int * array, int *newArray, int &n);
int NumberOfElementsInNewMassive(int * array, int n);
void RemoveOldElements(int * array, int *newArray, int &n);
int CounterDigit(int  n);
void Swap(int &a, int &b);
void SortingOldMassive(int * array, int n);
void FreeMemory(int *array);
int Counter(int n);
int BinaryTranslation(double a);
int BinExcepForNeg(int n);
int Inverse(int n);
void DisplayBinCountArr(int * array, int  n);

int * AllocateMemory(int n)
{
	if (n <= 0)
		throw std::out_of_range("Dimension must be more zero!");

	int * array = new int[n];

	return array;

}

void IsNewMassive(int * array, int *newArray, int n)
{
	for (int i = 0, k = 0; i < n; i++)
	{
		if (!(i % 2) && *(array + i) % 2 && *(array + i) < 0)
		{
			*(newArray + k) = *(array + i);
			k++;
		}
	}
}

int NumberOfElementsInNewMassive(int * array, int n)
{
	int k = 0;

	for (int i = 0; i < n; i += 2)
	{
		if (array[i] % 2 && array[i] < 0) k++;
	}

	if (k == 0)
		throw std::out_of_range("Not elements in new massive");

	return k;
}

void RemoveOldElements(int * array, int *newArray, int &n)
{
	if (n <= 0)
		throw std::out_of_range("Dimension must be more zero!");

	for (int i = 0, j = 0; i < n; i++)
	{
		if (*(array + i) == *(newArray + j))
		{
			for (int k = i; k < n - 1; k++)
			{
				*(array + k) = *(array + k + 1);
			}
			n--;
			j++;
			i--;
		}
	}
}

int CounterDigit(int  n)
{
	int s = 0;

	for (int i = 0; (double)n >= 0.1; i++)
	{
		n /= 10;
		s++;
	}
	return s;
}

void Swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void SortingOldMassive(int * array, int n)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (Counter(array[j]) < Counter(array[j + 1]))
			{
				Swap(array[j], array[j + 1]);

			}

		}
	}

}

void FreeMemory(int *array)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	delete[] array;
}

int Counter(int n)
{
	int s1 = 0, s0 = 0;
	int k = BinaryTranslation(n);

	for (int i = 1; (double)k / 10. >= 0.1; i++, k /= 10)
	{
		if (k % 10) s1 += 1;
		else s0 += 1;
		//k /= 10;
	}

	int s = 0;
	s = s1 - s0;

	return (s);
}

int BinaryTranslation(double a)
{
	int b = 0;

	if (a < 0)
	{
		b = a;
		a = -a;
	}

	int s = 0, i = 0;

	for (; a > 1; i++)
	{
		int k = ((int)a % 2) * pow(10, i);
		s += k;
		a /= 2;
	}

	if (!s) s = pow(10, i);

	if (b)
	{
		s = BinExcepForNeg(s);
	}
	return (s);
}

int BinExcepForNeg(int n)
{
	int x = Inverse(n);
	int y = CounterDigit(x);
	int k = x % 10;
	int i = 0;

	if (!k) return Inverse(n) + 1;

	while (x % 10)
	{
		x /= 10;
		i++;

		if (i == y - 1)
		{
			k = pow(10, y);
			return k;
		}
	}
	k = pow(10, i);
	x /= 10;

	for (; (double)x >= 0.1; i++)
	{
		k += (x % 10) * pow(10, i + 1);
		x /= 10;
	}
	return k;
}

int Inverse(int n)
{
	int s = 0;



	for (int i = 0; (double)n > 0.1; i++)
	{
		int k = n % 10;

		if (k) k = 0;
		else k = 1;

		s += k * pow(10, i);
		n /= 10;
	}

	return s;
}

void DisplayBinCountArr(int * array, int  n)
{

	/*if (n <= 0)
	{
	throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (array == nullptr)
	{
	throw std::invalid_argument("Argument is null!");
	}*/

	for (int *p = array; p < array + n; p++)
	{


		std::cout << Counter(*p) << " ";
	}
}