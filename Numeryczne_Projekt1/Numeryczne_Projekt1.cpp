// Numeryczne_Projekt1.cpp 
// Damian Darczuk 154824

#include "stdafx.h"
#include <stdio.h>      /* printf */
#include <math.h>       /* sinh, log */

long long silnia(unsigned int n) {
	long long int result = 1;
	do {
		result = result * n;
	} while (--n);
	return result;
}

int main()
{
	double epsilon = 0.001;
	double param = 15;

//--------------------------------------------------------------------
	// Liczenie przy u�yciu bibloteki

	double result;
	result = sinh(param);
	printf("Sinus hiperboliczy przy uzyciu bibloteki z %f to %f.\n", param, result);

//--------------------------------------------------------------------
	//Liczenie kolejnych wyraz�w szeregu na podstawie poprzedniego	

	int k = 0;
	float wynik = 0, S = param, wyniki_po�rednie[10000], x = param;	
	
	do {

		wynik = wynik + S;			//sumowanie max->min
		wyniki_po�rednie[k] = S;	//wyniki po�rednie do sumowania min->max

		k = k + 1;					//inkrementacja
		
		S = S * (x * x) / ((2 * k + 1) * (2 * k));	// kolejny wyraz szeregu obliczany na podstawie poprzedniego		
				
	} while (S > epsilon);

	printf("Liczba obiegow petli %d \n", k);	
	printf("Sinus hiperboliczy sumowania max->min z %f to %f.\n", param, wynik);
	

	wynik = 0;
	for (int i = k - 1; i >= 0; i--) {
		wynik += wyniki_po�rednie[i];
	}

	printf("Sinus hiperboliczy sumowania min->max z %f to %f.\n", param, wynik);

//--------------------------------------------------------------------
	// Liczenie ze wzoru

	double wynikZeWzoru = 0, kolejnywyraz = 0;

	do {
		kolejnywyraz = pow(x, (2 * k + 1)) / silnia(2 * k + 1);
		wynikZeWzoru += kolejnywyraz;
	} while (S > epsilon);

	printf("Sinus hiperboliczy liczony ze wzoru z %f to %f.\n", param, wynikZeWzoru);

	return 0;
}

