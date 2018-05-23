#pragma once

#ifdef LABA_EXPORTS
#define LABA_API __declspec(dllexport) 
#else
#define LABA_API __declspec(dllimport) 
#endif

namespace Massive
{
	LABA_API  int Inverse( int n);
	LABA_API int BinExcepForNeg(int n);
	LABA_API int BinaryTranslation(double n);
	LABA_API int Counter(int n);
	LABA_API void DisplayArray(int * array, int n);
	LABA_API int * AllocateMemory(int);
	LABA_API void FreeMemory(int *);
	LABA_API void InitArray(int * array, int n);
	LABA_API void EnterArray (int * array, int n);
	LABA_API void SortingOldMassive(int * array, int n);
	LABA_API void RemoveOldElements(int * array, int *newArray, int &n);
	LABA_API void Swap(int&, int&);
	LABA_API void IsNewMassive(int * array, int *newArray, int n);
	LABA_API int NumberOfElementsInNewMassive(int * array, int n);

	LABA_API void DisplayBinCountArr(int * array, int n);

	LABA_API int CounterDigit(int n);

	

}