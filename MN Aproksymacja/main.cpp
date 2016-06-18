#include <iostream>
#include <cmath>

using namespace std;
double a,b,x[50],y[50], p[6][50], s[6], c[6], wspolczynniki[6];

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
	a = -2;
	b = 2;

	for (int i=0; i<50; i++)
		x[i]=a+i*((b-a)/49);

	for (int i=0; i<50; i++)
		y[i] = sin(x[i]);

	for (int k = 0; k < 6; k++)//zmienia stopie�
		for (int q = 0; q < 50; q++)
		{
			double tmp = 0;
			for (int s = 0; s<=k; s++)
				tmp += (pow((double)-1,s) * newton(k,s) * newton(k+s,s) * (iloczyn(q,s)/iloczyn(50,s)));
			p[k][q]=tmp;
		}

	for (int i=0; i<6; i++)
	{
		double suma=0;
		for (int q=0; q<50; q++)
		{
			suma += pow(p[i][q],2);
		}
		s[i]=suma;
	}

	for (int i=0; i<6; i++)
	{
		double suma=0;
		for (int q=0; q<50; q++)
		{
			suma += y[q]*p[i][q];
		}
		c[i]=suma;
	}

	for (int i = 0; i<6; i++)
		wspolczynniki[i] = (c[i]/s[i]);

	system("PAUSE");
	return 0;
}

/*
Sprawozdanie polega na tym ze:
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