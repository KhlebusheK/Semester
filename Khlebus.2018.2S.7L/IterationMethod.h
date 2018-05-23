#pragma once

#ifdef ITLIBRARY_EXPORTS
#define ITLIBRARY_API __declspec(dllexport) 
#else
#define ITLIBRARY_API __declspec(dllimport) 
#endif

namespace Iteration
{
	ITLIBRARY_API double Function(double x);
	ITLIBRARY_API double Derivative(double x);
	ITLIBRARY_API double DoubleDerivative(double x);
	ITLIBRARY_API double ModifiedNewtonMethod(double previous, double accurancy);
	ITLIBRARY_API double SecantValuesMethod( double preprevious, double accurancy);
}
