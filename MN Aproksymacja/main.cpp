#include <iostream>
#include <cmath>
#include <fstream>
#define ILOSC_WEZLOW 50
#define STOPIEN_WIELOMIANU 6
using namespace std;
double a=-2.0, b=2.0, x[ILOSC_WEZLOW], y[ILOSC_WEZLOW], wyniki[ILOSC_WEZLOW];
fstream plik;

double newton(int x, int y)
{
	double wynik = 1.0;
	for (int i = 1; i <= y; i++) {
		wynik *= (double)(x - i + 1) / i;
	}
	return wynik;
}

double iloczyn(int r, int s) 
{
	double wynik = 1;
	for(int i = 0; i < s; i++)
	{
		wynik*= r-i;
	}
	return wynik;
}

double wielomianGrama(int k, int n, int q) 
{
	double wynik = 0;
	for (int s = 0; s <= k; s++) {
		wynik += (double)(pow(-1, s)*newton(k, s))*newton(k + s, s)*(iloczyn(q, s) / iloczyn(n, s));
	}
	return wynik;
}

double S(int j) 
{
	double wynik = 0;
	for (int q = 0; q <= ILOSC_WEZLOW; q++)
		wynik += pow(wielomianGrama(j, ILOSC_WEZLOW, q), 2);
	return wynik;
}

double C(int j) 
{
	double wynik = 0;
	for (int q = 0; q <= ILOSC_WEZLOW; q++)
		wynik += y[q] * wielomianGrama(j, ILOSC_WEZLOW, q);
	return wynik;
}

int main()
{
	for (int i=0; i<ILOSC_WEZLOW; i++) //rownoodlegle wezly
		x[i]=a+i*((b-a)/ (ILOSC_WEZLOW-1));

	for (int i = 0; i < ILOSC_WEZLOW; i++) //wartosc funkcji w tych wezlach
		//y[i] = sin(x[i]);
		y[i] = cos(x[i]) * cos(x[i])* cos(4*x[i]);

	for (int q = 0; q < ILOSC_WEZLOW; q++) 
	{
		wyniki[q] = 0;
		for (int j = 0; j < STOPIEN_WIELOMIANU; j++)
			wyniki[q] += (C(j) / S(j)) * wielomianGrama(j, ILOSC_WEZLOW, q);
	}
	plik.open("WYNIKI.txt", ios::out);
	for (int i = 0; i < ILOSC_WEZLOW; i++)
		plik << x[i] << '\t' << y[i] << '\t' << wyniki[i] << endl;
	system("PAUSE");
	return 0;
}

/*
Sprawozdanie polega na tym ze:
przeprowadzenie pewnych badan
znaczy ja prowadze bardzo rozne przedmioty
I inne pierdoły jakieś tam mondre bardzo.

Startujemy z danych testowych na tablicy, ale funkcja w sprawku się zmienia i ma być inna:

cos^2(x) * cos(4x)

Na początku w sprawku metoda aproksymacji i dla jakiej funkcji.
BADANIA: Zwiększać stopień wielomianu aproksymacyjnego od 1 do 20 podając za każdym razem wartość błędu.
Na tej podstawie dobrać optymalny stopien wielomianu aproxymacyjnego, kilkukrotnie (min 3 razy) zmienic pozostale parametry,
tj szerokosc i polozenie przedzialow, oraz liczbe wezlow, podac wartosc bledu w formie tabelki i/lub wykresu.
Wyciągamy wnioski i obserwacje płynące z błędu oraz ze wspolczynnikow. 
Zamieścić kod i minimum jeden wykres. Coś o jakichś zastosowaniach i czy spotkalismy sie juz z problemem aproksymacji
na innych przedmiotach w programie studiów.
Pok 518, papirowe.
*/