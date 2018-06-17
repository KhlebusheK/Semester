#pragma once

#ifdef MATRIXLIBRARY_EXPORTS
#define MATRIXLIBRARY_API __declspec(dllimport) 
#else
#define MATRIXLIBRARY_API __declspec(dllexport) 
#endif

namespace MatrixLibrary
{
	MATRIXLIBRARY_API double SinTaylor(double, double);
	MATRIXLIBRARY_API double ** AllocateMemory(int n);
	MATRIXLIBRARY_API void FreeMemory(double ** matrix, int n);
	MATRIXLIBRARY_API void DisplayMatrix(double ** matrix, int n);
	MATRIXLIBRARY_API void InitMatrixTaylor(double ** matrix, int n, double accurancy);
	MATRIXLIBRARY_API void InitMatrixTable(double ** matrix, int n);
	MATRIXLIBRARY_API void CompareMatrix(double ** matrixTaylor, double ** matrixTable, int n);
}