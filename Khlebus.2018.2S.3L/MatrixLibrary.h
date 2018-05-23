#pragma once

#ifdef MATRIXLIBRARY_EXPORTS
#define MATRIXLIBRARY_API __declspec(dllexport) 
#else
#define MATRIXLIBRARY_API __declspec(dllimport) 
#endif

namespace MatrixLibrary
{
	MATRIXLIBRARY_API double ** AllocateMemory(int n);
	MATRIXLIBRARY_API void FreeMemory(double ** matrix, int n);
	MATRIXLIBRARY_API void DisplayMatrix(double ** matrix, int n);
	MATRIXLIBRARY_API void InitRandomMatrix(double ** array, int n);
	MATRIXLIBRARY_API double FindMax(double ** matrix, int i, int j, int n);
	MATRIXLIBRARY_API void InitMatrixB(double ** array, double ** B, int n);
}