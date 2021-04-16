#include <iostream>
#include "Plansza.h"
#include "Pionek.h"

#define DL_SCIANY 3

using namespace std;

//cialo konstruktora
Plansza::Plansza()
{
	//uzupelnienie reprezenatacji graficznej (narysowanie planszy)
	char znak_poziom = 'A', znak_pion = 'a';
	for (int i = 0; i < wymiary; i++)
	{
		for (int j = 0; j < wymiary; j++)
		{
			if (i % 2 == 1 && j % 2 == 1)
				rep_graf[i][j] = '0';
			else if (0 == i && j != 0)
				rep_graf[i][j] = znak_poziom++;
			else if (0 == j && i != 0)
				rep_graf[i][j] = znak_pion++;
			else
				rep_graf[i][j] = ' ';
		}
	}

	//uzupelnienie pionkow
	rep_graf[startpoz1x][startpoz1y] = '2';
	rep_graf[startpoz2x][startpoz2y] = '1';
}

//cialo metody rysujacej plansze
void Plansza::rysuj()
{
	for (int i = 0; i < wymiary; i++)
	{
		for (int j = 0; j < wymiary; j++)
			cout << rep_graf[i][j] << " ";
		cout << endl;
	}
	return;
}

//cialo metody odpowiedzialnej za postawienie sciany
void Plansza::postaw_sciane(int x, int y, int kierunek)
{

	switch (kierunek)
	{
	case 1:

		//rysowanie sciany
		for (int i = 0; i < DL_SCIANY; i++)
			rep_graf[y - i][x] = '|';

		//przedstawienie w konsoli
		system("cls");
		rysuj();

		break;

	case 2:

		//rysowanie sciany
		for (int i = 0; i < DL_SCIANY; i++)
			rep_graf[y][x + i] = '-';

		//przedstawienie w konsoli
		system("cls");
		rysuj();

		break;
	}
	return;
}

//cialo metody odpowiedzialnej za graficzna reprezentacje przesuniecia dokonanego przez gracza
void Plansza::przesun_pionek(int x, int y, char r)
{
	system("cls");

	//usuniecie starych pozycji pionkow
	for (int i = 0; i < wymiary; i++)
	{
		for (int j = 0; j < wymiary; j++)
		{
			if (r == rep_graf[i][j])
				rep_graf[i][j] = '0';
		}
	}

	//wprowadzenie nowej pozycji pionka
	if (r == '1')
		rep_graf[x][y] = '1';
	else
		rep_graf[x][y] = '2';

	rysuj();
	return;
}