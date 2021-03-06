// IterationMethod.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "IterationMethod.h"
#include <cmath>
#include <iostream>


ITLIBRARY_API double Iteration::Function(double x)
{
	return x - sin(x);
}

ITLIBRARY_API double Iteration::Derivative(double x)
{
	return 1 - cos(x);
}

ITLIBRARY_API double Iteration::DoubleDerivative(double x)
{
	return sin(x);
}

ITLIBRARY_API double Iteration::ModifiedNewtonMethod(double previous, double accurancy)
{
	if (accurancy < 0 || accurancy > 1)
	{
		throw std::invalid_argument("Accurancy must be between 0 and 1 !!!");
	}

	double following = previous - Function(previous) / Derivative(previous) - DoubleDerivative(previous)*Function(previous)*Function(previous) / 2 * Derivative(previous)*Derivative(previous);

	while (fabs(previous - following) >= accurancy)
	{
		previous = following;
		following = previous - Function(previous) / Derivative(previous) - DoubleDerivative(previous)*Function(previous)*Function(previous) / 2 * Derivative(previous)*Derivative(previous);
	}

	return following;
}

ITLIBRARY_API double Iteration::SecantValuesMethod( double preprevious, double accurancy)
{

	if (accurancy < 0 || accurancy > 1)
	{
		throw std::invalid_argument("Accurancy must be between 0 and 1 !!!");
	}

	double previous = ModifiedNewtonMethod(preprevious, accurancy);

	double following = previous - (previous - preprevious)*Function(previous) / (Function(previous) - Function(preprevious));

	while (fabs(previous - following) >= accurancy)
	{
		previous = following;
		following = previous - (previous - preprevious)*Function(previous) / (Function(previous) - Function(preprevious));
	}

	return following;
}
