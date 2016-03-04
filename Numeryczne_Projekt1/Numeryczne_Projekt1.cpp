// Numeryczne_Projekt1.cpp 
//

#include "stdafx.h"
#include <iostream>
//#include <cmath>
#include <stdio.h>      /* printf */
#include <math.h>       /* sinh, log */

using namespace std;



int main()
{
	double parametr;

	double param, result;
	param = log(2.0);
	result = sinh(param);
	printf("The hyperbolic sine of %f is %f.\n", param, result);

	double x = param;

	int k = 0;
	double wynik = 0, S = param, wyniki_poœrednie[50];

	do {
		
		wynik = wynik + S;  //sumowanie max->min
		wyniki_poœrednie[k] = S;	//wyniki poœrednie do sumowania min->max

		k = k + 1;
		S = S * (x * x / ((k + 1) * (k + 2)));
		cout << S << endl;

	} while (k < 15);

	cout << wynik << endl;
	wynik = 0;

	for (int i = k - 1; i >= 0; i--) {
		wynik += wyniki_poœrednie[i];
	}

	cout << wynik << endl;

	return 0;
}

