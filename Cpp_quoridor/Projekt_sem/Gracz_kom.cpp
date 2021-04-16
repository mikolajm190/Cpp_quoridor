#include <iostream>
#include "Gracz.h"
#include "Plansza.h"
#include "funkcje_pom.h"
#include <fstream>
#include <windows.h>

using namespace std;

//cialo konstruktora domyslnego
Gracz_kom::Gracz_kom() : Pionek::Pionek(startpoz1x, startpoz1y), ilosc_scian(10), rodzaj_pionka('2'), nick("Bot_Andrzej") {}

//cialo metody umozliwiajacej graczowi komputerowemu stawianie scian
bool Gracz_kom::postaw_sciane(Plansza &P)
{
	//zmienne
	char x = NULL, y = NULL;

	//zabezpieczenie przed nieskonczona iloscia scian
	if (ilosc_scian == 0)
		return false;
	ilosc_scian--;

	cout << "Bot tworzy niepokonana strategie (stawia sciane)..." << endl;

	int wybor = pobierz_od_bota<int>("ogr", 1, 20);
	if (wybor < 11)
	{
		//kontrola poprawnosci wprowadzanych danych (czy wspolrzedne sa poprawne, czy sciana nie wychodzi poza plansze) i zamiana wspolrzednych w formie znakow na porzadane wartosci calkowite
		while ((x = (pobierz_od_bota<char>("ogr", 'A', 'Q') - 'A' + 1)) % 2 == 1 || (y = (pobierz_od_bota<char>("ogr", 'c', 'q') - 'a' + 1)) % 2 == 0 || P.rep_graf[y][x] != ' ' || P.rep_graf[y - 1][x] != ' ' || P.rep_graf[y - 2][x] != ' ')
			Sleep(10);

		//wywolanie metody odpowiedzialnej za zmiany na planszy (sciany, 1 - pionowa)
		P.postaw_sciane(x, y, 1);
	}
	else
	{
		//kontrola poprawnosci wprowadzanych danych (czy wspolrzedne sa poprawne, czy sciana nie wychodzi poza plansze) i zamiana wspolrzednych w formie znakow na porzadane wartosci calkowite
		while ((x = (pobierz_od_bota<char>("ogr", 'A', 'O') - 'A' + 1)) % 2 == 0 || (y = (pobierz_od_bota<char>("ogr", 'a', 'q') - 'a' + 1)) % 2 == 1 || P.rep_graf[y][x] != ' ' || P.rep_graf[y][x + 1] != ' ' || P.rep_graf[y][x + 2] != ' ')
			Sleep(10);

		//wywolanie metody odpiedzialnej za zmiany na planszy (sciany, 2 - pozioma)
		P.postaw_sciane(x, y, 2);
	}

	return true;
}

//cialo metody przesuwajacej pionek
void Gracz_kom::przesun(Plansza &P)
{
	//zmienne
	bool przesuniecie = true;

	cout << "Bot tworzy niepokonana strategie (porusza pionkiem)..." << endl;
	
	//sprawdzenie poprawnosci wykonywanego ruchu
	do
	{
		int wybor = pobierz_od_bota<int>("ogr", 1, 20);
		if (wybor < 3)
		{
			if (x - 2 >= 0 && P.rep_graf[x - 2][y] == '0' && P.rep_graf[x - 1][y] == ' ')
			{
				x -= 2;
				przesuniecie = true;
			}
			//obsluga przeskakiwania pionkow
			else if (x - 4 >= 0 && (P.rep_graf[x - 2][y] == '1' || P.rep_graf[x - 2][y] == '2') && P.rep_graf[x - 1][y] == ' ' && P.rep_graf[x - 3][y] == ' ' && P.rep_graf[x - 4][y] == '0')
			{
				x -= 4;
				przesuniecie = true;
			}
			else
				przesuniecie = false;
		}
		else if (wybor >= 3 && wybor < 7)
		{
			if (y - 2 >= 0 && P.rep_graf[x][y - 2] == '0' && P.rep_graf[x][y - 1] == ' ')
			{
				y -= 2;
				przesuniecie = true;
			}
			//obsluga przeskakiwania pionkow
			else if (y - 4 >= 0 && (P.rep_graf[x][y - 2] == '1' || P.rep_graf[x][y - 2] == '2') && P.rep_graf[x][y - 1] == ' ' && P.rep_graf[x][y - 3] == ' ' && P.rep_graf[x][y - 4] == '0')
			{
				y -= 4;
				przesuniecie = true;
			}
			else
				przesuniecie = false;
		}
		else if (wybor >= 7 && wybor < 11)
		{
			if (y + 2 < wymiary && P.rep_graf[x][y + 2] == '0' && P.rep_graf[x][y + 1] == ' ')
			{
				y += 2;
				przesuniecie = true;
			}
			//obsluga przeskakiwania pionkow
			else if (y + 4 < wymiary && (P.rep_graf[x][y + 2] == '1' || P.rep_graf[x][y + 2] == '2') && P.rep_graf[x][y + 1] == ' ' && P.rep_graf[x][y + 3] == ' ' && P.rep_graf[x][y + 4] == '0')
			{
				y += 4;
				przesuniecie = true;
			}
			else
				przesuniecie = false;
		}
		else
		{
			if (x + 2 < wymiary && P.rep_graf[x + 2][y] == '0' && P.rep_graf[x + 1][y] == ' ')
			{
				x += 2;
				przesuniecie = true;
			}
			//obsluga przeskakiwania pionkow
			else if (x + 4 < wymiary && (P.rep_graf[x + 2][y] == '1' || P.rep_graf[x + 2][y] == '2') && P.rep_graf[x + 1][y] == ' ' && P.rep_graf[x + 3][y] == ' ' && P.rep_graf[x + 4][y] == '0')
			{
				x += 4;
				przesuniecie = true;
			}
			else
				przesuniecie = false;
		}
	} while (!przesuniecie);
}

//cialo metody kontrolujacej warunek zwyciestwa
bool Gracz_kom::wygrana()
{
	if ((wymiary - 1) == x)
		return true;
	else
		return false;
}

//cialo metody otwierajacej plik, w ktorym beda rejestrowane wyniki komputera
fstream Gracz_kom::zaloguj()
{
	//zmienne
	string plik_bota = this->nick + ".txt";

	//otworzenie pliku dla bota
	fstream plik;
	if (!czy_istnieje_plik(plik_bota))
		cout << "Zostal zalozony plik rejestrujacy dla gracza komputerowego" << endl;
	plik.open(plik_bota, ios::out | ios::app);

	czy_otwarcie(plik);

	return plik;
}

//cialo metody obslugujacej ruchy gracza komputerowego
bool Gracz_kom::interfejs(Plansza &P)
{
	//obsluga wyboru gracza komputerowego
	bool wykonanie_operacji = false;

	do
	{
		int wybor = pobierz_od_bota<int>("ogr", 1, 10);
		if (wybor < 6)
		{
			this->przesun(P);
			P.przesun_pionek(this->wez_x(), this->wez_y(), this->wez_rodzaj());
			wykonanie_operacji = true;
		}
		else
			wykonanie_operacji = this->postaw_sciane(P);
	} while (!wykonanie_operacji);
	return false;
}