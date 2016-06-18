#include <iostream>
#include <cmath>
#define ILOSC_WEZLOW 50
#define STOPIEN_WIELOMIANU 6
using namespace std;
double a,b,x[ILOSC_WEZLOW],y[ILOSC_WEZLOW], p[STOPIEN_WIELOMIANU][ILOSC_WEZLOW], s[STOPIEN_WIELOMIANU], c[STOPIEN_WIELOMIANU], wspolczynniki[STOPIEN_WIELOMIANU];

int silnia(int x)
{
	if (x == 0)
		return 1;
    return x * silnia(x - 1);
}

double newton(int x, int y)
{
	return silnia(x) / (silnia(y) * silnia (x-y));
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

int main()
{
	a = -2; //poczatek przedzialu
	b = 2; //koniec przedzialu

	for (int i=0; i<ILOSC_WEZLOW; i++) //rownoodlegle wezly
		x[i]=a+i*((b-a)/ILOSC_WEZLOW-1);

	for (int i=0; i<ILOSC_WEZLOW; i++) //wartosc funkcji w tych wezlach
		y[i] = sin(x[i]);

	for (int k = 0; k < STOPIEN_WIELOMIANU; k++) //zmienia stopie�
		for (int q = 0; q < ILOSC_WEZLOW; q++)
		{
			double tmp = 0;
			for (int s = 0; s<=k; s++)
				tmp += (pow((double)-1,s) * newton(k,s) * newton(k+s,s) * (iloczyn(q,s)/iloczyn(ILOSC_WEZLOW,s)));
			p[k][q]=tmp;
		}

	for (int i=0; i<STOPIEN_WIELOMIANU; i++)
	{
		double suma=0;
		for (int q=0; q<ILOSC_WEZLOW; q++)
		{
			suma += pow(p[i][q],2);
		}
		s[i]=suma;
	}

	for (int i=0; i<STOPIEN_WIELOMIANU; i++)
	{
		double suma=0;
		for (int q=0; q<ILOSC_WEZLOW; q++)
		{
			suma += y[q]*p[i][q];
		}
		c[i]=suma;
	}

	for (int i = 0; i<STOPIEN_WIELOMIANU; i++)
		wspolczynniki[i] = (c[i]/s[i]);

	system("PAUSE");
	return 0;
}

/*
Sprawozdanie polega na tym ze:
przeprowadzenie pewnych badan
znaczy ja prowadze bardzo rozne przedmioty
I inne pierdo�y jakie� tam mondre bardzo.

Startujemy z danych testowych na tablicy, ale funkcja w sprawku si� zmienia i ma by� inna:

cos^2(x) * cos(4x)

Na pocz�tku w sprawku metoda aproksymacji i dla jakiej funkcji.
BADANIA: Zwi�ksza� stopie� wielomianu aproksymacyjnego od 1 do 20 podaj�c za ka�dym razem warto�� b��du.
Na tej podstawie dobra� optymalny stopien wielomianu aproxymacyjnego, kilkukrotnie (min 3 razy) zmienic pozostale parametry,
tj szerokosc i polozenie przedzialow, oraz liczbe wezlow, podac wartosc bledu w formie tabelki i/lub wykresu.
Wyci�gamy wnioski i obserwacje p�yn�ce z b��du oraz ze wspolczynnikow. 
Zamie�ci� kod i minimum jeden wykres. Co� o jakich� zastosowaniach i czy spotkalismy sie juz z problemem aproksymacji
na innych przedmiotach w programie studi�w.
Pok 518, papirowe.
*/