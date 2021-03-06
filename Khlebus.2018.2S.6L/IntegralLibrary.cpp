// IntegralLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "IntegralLibrary.h"
#include <cmath>
#include <iostream>

INTEGRALLIBRARY_API double Integral::ValueOfFunc(double x)
{
	return sqrt(x)*cos(x) ;
}

INTEGRALLIBRARY_API double Integral::LeftRect(double begsegment, double endsegment, unsigned n)
{
	if (begsegment > endsegment)
	{
		throw std::invalid_argument("Invalid data !!!");
	}

	if (n <=  0)
	{
		throw std::invalid_argument("Invalid data !!!");
	}

	double step = 0;
	step = (begsegment + endsegment) / n;

	double integral = 0;
	double t = begsegment;

	while (t < endsegment)
	{
		integral += ValueOfFunc(t);
		t += step;
	}

	integral *= step;

	return integral;
}

INTEGRALLIBRARY_API double Integral::ValueOfIntegral(double begsegment, double endsegment, double accurancy, unsigned n)
{
	if (accurancy < 0 || accurancy > 1)
	{
		throw std::invalid_argument("Accurancy must be between 0 and 1 !!!");
	}

	if (begsegment > endsegment)
	{
		throw std::invalid_argument("Invalid data !!!");
	}

	if (n <= 0)
	{
		throw std::invalid_argument("Invalid data !!!");
	}

	double previousintegral = 0, nextintegral = 1;

	while (fabs(previousintegral - nextintegral) > accurancy)
	{
		previousintegral = LeftRect(begsegment, endsegment, n);
		nextintegral = LeftRect(begsegment, endsegment, 2 * n);
		n *= 2;
	}
}
