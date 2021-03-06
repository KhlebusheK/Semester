// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IterationMethod.h"
#include <cmath>
#include <iostream>

using namespace Iteration;
using namespace std;


int main()
{
	double root;

	cout << "Enter inital approximation : " << endl;
	cin >> root;

	double accurancy;

	cout << "Enter accurancy : " << endl;
	cin >> accurancy;

	cout << "16.3 The root of the equation is " << ModifiedNewtonMethod(root, accurancy) << endl;
	cout << "16.5 The root of the equation is " << SecantValuesMethod(root, accurancy) << endl;

	system("pause");
}

