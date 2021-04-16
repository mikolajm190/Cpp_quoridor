#include <iostream>
#include <string>
#include <fstream>
#include "Gracz.h"
#include "Plansza.h"
#include "funkcje_pom.h"

using namespace std;

//cialo konstruktora domyslnego
Gracz_czl::Gracz_czl() : Pionek::Pionek(), ilosc_scian(10), rodzaj_pionka('1')
{
	cout << "Podaj swoj nick: ";
	nick = pobierz_od_gracza<string>("nogr", " ", " ");
}

//cialo konstruktora z argumentami
Gracz_czl::Gracz_czl(int x, int y, char r) : Pionek::Pionek(x, y), ilosc_scian(10), rodzaj_pionka(r)
{
	cout << "Podaj swoj nick: ";
	nick = pobierz_od_gracza<string>("nogr", " ", " ");
}

//cialo metody sluzacej do umozliwienia postawienia scian graczowi (brak sprawdzania, czy nie odcina drogi do wygranej)
bool Gracz_czl::postaw_sciane(Plansza &P)
{
	//zmienne
	char x = NULL, y = NULL;

	//zabezpieczenie przed nieskonczona iloscia scian
	if (ilosc_scian == 0)
	{
		cout << "Nie posiadasz juz scian! Musisz wykonac ruch." << endl;
		return false;
	}
	ilosc_scian--;

	//wybor polozenia sciany
	cout << "Sciane mozesz postawic pionowo i poziomo, wybierz teraz jedna z podanych opcji: " << endl << "1. pion" << endl << "2. poziom" << endl;

	switch (pobierz_od_gracza<int>("ogr", 1, 2))
	{
	case 1:
		cout << "Podaj wspolrzedne dolnego punktu sciany (np. Aa, pamietaj, aby kazda ze wspolrzednych zatwierdzic przyciskiem ENTER). Wybierz punkt, od ktorego sciana zostanie narysowana (w gore): ";

		//kontrola poprawnosci wprowadzanych danych (czy wspolrzedne sa poprawne, czy sciana nie wychodzi poza plansze) i zamiana wspolrzednych w formie znakow na porzadane wartosci calkowite
		while ((x = (pobierz_od_gracza<char>("ogr", 'A', 'Q') - 'A' + 1)) % 2 == 1 || (y = (pobierz_od_gracza<char>("ogr", 'c', 'q') - 'a' + 1)) % 2 == 0 || P.rep_graf[y][x] != ' ' || P.rep_graf[y - 1][x] != ' ' || P.rep_graf[y - 2][x] != ' ')
		{
			cout << "Nie mozesz postawic sciany w miejscu o tych wspolrzednych. Podaj obie jeszcze raz: ";
		}

		//wywolanie metody odpowiedzialnej za zmiany na planszy (sciany, 1 - pionowa)
		P.postaw_sciane(x, y, 1);

		break;

	case 2:
		cout << "Podaj wspolrzedne lewego punktu sciany (np. Aa, pamietaj, aby kazda ze wspolrzednych zatwierdzic przyciskiem ENTER). Wybierz punkt, od ktorego sciana zostanie narysowana (w prawo): ";

		//kontrola poprawnosci wprowadzanych danych (czy wspolrzedne sa poprawne, czy sciana nie wychodzi poza plansze) i zamiana wspolrzednych w formie znakow na porzadane wartosci calkowite
		while ((x = (pobierz_od_gracza<char>("ogr", 'A', 'O') - 'A' + 1)) % 2 == 0 || (y = (pobierz_od_gracza<char>("ogr", 'a', 'q') - 'a' + 1)) % 2 == 1 || P.rep_graf[y][x] != ' ' || P.rep_graf[y][x + 1] != ' ' || P.rep_graf[y][x + 2] != ' ')
		{
			cout << "Nie mozesz postawic sciany w miejscu o tych wspolrzednych. Podaj obie jeszcze raz: ";
		}

		//wywolanie metody odpiedzialnej za zmiany na planszy (sciany, 2 - pozioma)
		P.postaw_sciane(x, y, 2);

		break;
	}

	return true;
}

//cialo metody przesuwajacej pionek
void Gracz_czl::przesun(Plansza &P)
{
	//zmienne
	bool przesuniecie = true;

	cout << "Prosze wybrac kierunek ruchu (w - gora, a - lewo, d - prawo, s - dol): ";

	//sprawdzenie poprawnosci wykonywanego ruchu
	do
	{
		switch (pobierz_od_gracza<char>("nogr", 'a', 'a'))
		{
		case 'w':
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
			{
				cout << "Nie mozna tu przesunac pionka. Sprobuj jeszcze raz: ";
				przesuniecie = false;
			}
			break;
		case 'a':
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
			{
				cout << "Nie mozna tu przesunac pionka. Sprobuj jeszcze raz: ";
				przesuniecie = false;
			}
			break;
		case 'd':
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
			{
				cout << "Nie mozna tu przesunac pionka. Sprobuj jeszcze raz: ";
				przesuniecie = false;
			}
			break;
		case 's':
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
			{
				cout << "Nie mozna tu przesunac pionka. Sprobuj jeszcze raz: ";
				przesuniecie = false;
			}
			break;
		default:
			cout << "Nie wybrales zadnego kierunku. Sprobuj ponownie: ";
			przesuniecie = false;
			break;
		}
	} while (!przesuniecie);
}

//cialo metody kontrolujacej warunek zwyciestwa
bool Gracz_czl::wygrana()
{
	if ('2' == rodzaj_pionka)
	{
		if ((wymiary - 1) == x)
			return true;
		else
			return false;
	}
	else
	{
		if (1 == x)
			return true;
		else
			return false;
	}
}

//cialo metody odpowiedzialnej za komunikacje z graczem
bool Gracz_czl::interfejs(Plansza &P)
{
	//obsluga wyboru uzytkownika
	bool wykonanie_operacji = true;

	cout << "Tura gracza o pseudonimie: " << this->nick << endl << "Posiadasz jeszcze " << this->ilosc_scian << " scian." << endl;

	do
	{
		cout << "Wybierz jedna z dostepnych mozliwosci:" << endl << "1. Porusz pionek." << endl << "2. Postaw sciane." << endl << "3. Wroc do menu." << endl;
		switch (pobierz_od_gracza<int>("ogr", 1, 3))
		{
		case 1:
			this->przesun(P);
			P.przesun_pionek(this->wez_x(), this->wez_y(), this->wez_rodzaj());
			wykonanie_operacji = true;
			break;
		case 2:
			wykonanie_operacji = this->postaw_sciane(P);
			break;
		case 3:
			cout << "Czy na pewno, chcesz zakonczyc gre?" << endl << "1. Tak" << endl << "2. Nie" << endl;

			if (1 == pobierz_od_gracza<int>("ogr", 1, 2))
				return true;
			else
				wykonanie_operacji = false;

			break;
		}
	} while (!wykonanie_operacji);
	return false;
}

//cialo metody logujacej gracza do pliku rejstrujacego przebieg rozgrywek, w ktorych bral udzial
fstream Gracz_czl::zaloguj()
{
	//zmienne
	string plik_gracza = this->nick + ".txt";

	//otworzenie pliku dla gracza
	fstream plik;
	if (!czy_istnieje_plik(plik_gracza))
		cout << "Zostal zalozony plik rejestrujacy dla gracza " << this->nick << endl;
	plik.open(plik_gracza, ios::out | ios::app);

	czy_otwarcie(plik);

	return plik;
}