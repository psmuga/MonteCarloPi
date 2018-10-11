#include <iostream>
#include <string>
#include <iomanip>
#define _USE_MATH_DEFINES

#include <chrono>
#include <random>
#include <math.h>
using namespace std;


int main()
{
	unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine e(seed);

	double x, y, wynik;

	int licznik_kw = 0, licznik_kol = 0;

	uniform_real_distribution<double> distrR(0, 5);
	do
	{

		x = distrR(e);
		y = distrR(e);

		licznik_kw++;
		
		

		if ((x*x) + (y*y) <= (distrR.max()*distrR.max()))
			licznik_kol++;

		wynik = 4.0*licznik_kol / licznik_kw;

		cout << setprecision(9);
		cout << endl << "Dla " << licznik_kw << " punktow liczba PI wynosi: " << wynik;
	} while (fabs(wynik -  (M_PI))>1e-09);



	system("pause");
	return 0;
}