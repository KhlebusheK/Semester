#pragma once

#ifdef LABA4_EXPORTS
#define LABA4_API __declspec(dllexport) 
#else
#define LABA4_API __declspec(dllimport) 
#endif

namespace Matrix4
{
	LABA4_API double ** AllocateMemory(int n);
	LABA4_API void FreeMemory(double ** matrix, int n);
	LABA4_API void InitRandomMatrix(double ** array, int n);
	LABA4_API  void Matrix4::SumOfMatrix(double** A, double** B, int n);
	LABA4_API void Matrix4::DisplayMatrix(double ** array, int  n);
}