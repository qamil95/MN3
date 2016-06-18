#include <iostream>
#include <cmath>
#include <fstream>
#define ILOSC_WEZLOW 50
#define STOPIEN_WIELOMIANU 6
using namespace std;
double a,b,x[ILOSC_WEZLOW],y[ILOSC_WEZLOW], p[STOPIEN_WIELOMIANU][ILOSC_WEZLOW], s[STOPIEN_WIELOMIANU], c[STOPIEN_WIELOMIANU], wyniki[ILOSC_WEZLOW];
fstream plik;

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

	for (int k = 0; k < STOPIEN_WIELOMIANU; k++) //zmienia stopieñ
		for (int q = 0; q < ILOSC_WEZLOW; q++)
		{
			double tmp = 0;
			for (int s = 0; s<=k; s++) //wzór 10
				tmp += (pow((double)-1,s) * newton(k,s) * newton(k+s,s) * (iloczyn(q,s)/iloczyn(ILOSC_WEZLOW,s)));
			p[k][q]=tmp;
		}

	for (int j=0; j<STOPIEN_WIELOMIANU; j++) //wzor 12 S
	{
		double suma=0;
		for (int q=0; q<ILOSC_WEZLOW; q++)
		{
			suma += pow(p[j][q],2);
		}
		s[j]=suma;
	}

	for (int j=0; j<STOPIEN_WIELOMIANU; j++) // wzor 12 C
	{
		double suma=0;
		for (int q=0; q<ILOSC_WEZLOW; q++)
		{
			suma += y[q]*p[j][q];
		}
		c[j]=suma;
	}

	for (int j = 0; j<STOPIEN_WIELOMIANU; j++)
		for (int q = 0; q<ILOSC_WEZLOW; q++)
			wyniki[q] = (c[j]/s[j]) * p[j][q];
	plik.open("WYNIKI", ios::out);
	for (int i = 0; i < ILOSC_WEZLOW; i++)
		plik << y[i] << '\t' << wyniki[i] << endl;
	system("PAUSE");
	return 0;
}

/*
Sprawozdanie polega na tym ze:
przeprowadzenie pewnych badan
znaczy ja prowadze bardzo rozne przedmioty
I inne pierdo³y jakieœ tam mondre bardzo.

Startujemy z danych testowych na tablicy, ale funkcja w sprawku siê zmienia i ma byæ inna:

cos^2(x) * cos(4x)

Na pocz¹tku w sprawku metoda aproksymacji i dla jakiej funkcji.
BADANIA: Zwiêkszaæ stopieñ wielomianu aproksymacyjnego od 1 do 20 podaj¹c za ka¿dym razem wartoœæ b³êdu.
Na tej podstawie dobraæ optymalny stopien wielomianu aproxymacyjnego, kilkukrotnie (min 3 razy) zmienic pozostale parametry,
tj szerokosc i polozenie przedzialow, oraz liczbe wezlow, podac wartosc bledu w formie tabelki i/lub wykresu.
Wyci¹gamy wnioski i obserwacje p³yn¹ce z b³êdu oraz ze wspolczynnikow. 
Zamieœciæ kod i minimum jeden wykres. Coœ o jakichœ zastosowaniach i czy spotkalismy sie juz z problemem aproksymacji
na innych przedmiotach w programie studiów.
Pok 518, papirowe.
*/