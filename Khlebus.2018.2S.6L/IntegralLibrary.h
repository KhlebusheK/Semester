#pragma once

#ifdef INTEGRALLIBRARY_EXPORTS
#define INTEGRALLIBRARY_API __declspec(dllexport) 
#else
#define INTEGRALLIBRARY_API __declspec(dllimport) 
#endif

namespace Integral
{
	INTEGRALLIBRARY_API double ValueOfFunc(double x);
	INTEGRALLIBRARY_API double LeftRect(double begsegment, double endsegment, unsigned n);
	INTEGRALLIBRARY_API double ValueOfIntegral(double begsegment, double endsegment, double accurancy, unsigned n);
}