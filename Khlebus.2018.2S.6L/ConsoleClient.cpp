// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IntegralLibrary.h"
#include <cmath>
#include <iostream>

using namespace Integral;
using namespace std;

int main()
{
	double beginsegment;

	cout << "Enter Begin of segment : " << endl;
	cin >> beginsegment;

	double endsegment;

	cout << "Enter End of segment : " << endl;
	cin >> endsegment;

	double accurancy;

	cout << "Enter accurancy : " << endl;
	cin >> accurancy;

	double fragmentation;

	cout << "Enter fragmentation : " << endl;
	cin >> fragmentation;

	double integral = ValueOfIntegral(beginsegment, endsegment, accurancy, fragmentation);

	cout << "Value of Integral of function = " << integral << endl;

	system("pause");
    
}

