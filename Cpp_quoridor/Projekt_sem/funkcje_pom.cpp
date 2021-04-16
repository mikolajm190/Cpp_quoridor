#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Gracz.h"
#include "Plansza.h"
#include "funkcje_pom.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>

//tutaj zmieniamy ilosc wyswietlanych rozgrywek
#define IL_WYS_ROZ 3

using namespace std;

//czyszczenie bufora
void czysc_bufor()
{
	cout << "Podales bledne dane. Popraw je: ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//cialo funkcji odpowiadajacej za przekazanie sterowania uzytkownikowi
void zagraj()
{
	//zmienne
	time_t czas;
	string nazwa_g;
	int wybor = 0;
	Gracz *wsk1, *wsk2;
	Plansza *P;

	//obsluga pliku i rozpoczecie rejestrowania przebiegu rozgrywki (tryb do zapisu i dolaczania oraz odczytu)
	fstream rej, p1, p2;
	rej.open("log.txt", ios::out | ios::app);

	//pobranie czasu
	czy_otwarcie(rej);
	time(&czas);
	cout << "Witaj w grze Quoridor." << endl;
	rej << asctime(localtime(&czas)) << "Program rozpoczal swoje dzialanie." << endl;

	//menu
	while (true)
	{
		//mozliwosci w menu
		cout << "Wybierz jedna z dostepnych opcji, przez podanie odpowiedniej liczby:" << endl << "1. Rozpocznij gre." << endl << "2. Pokaz historie gier." << endl << "3. Wyjdz z gry." << endl;
		wybor = pobierz_od_gracza<int>("ogr", 1, 3);
		switch (wybor)
		{
		case 1:
			//wybor trybu gry
			cout << "Wybierz tryb gry:" << endl << "1. Rozgrywka dwuosobowa." << endl << "2. Rozgrywka jednoosobowa." << endl;
			wybor = pobierz_od_gracza<int>("ogr", 1, 2);
			time(&czas);

			//utworzenie obiektow potrzebnych do przeprowadzenia rozgrywki oraz otwrzenie stosownych plikow za pomoca metody zaloguj
			P = new Plansza();

			if (1 == wybor)
			{
				wsk1 = new Gracz_czl();
				wsk2 = new Gracz_czl(startpoz1x, startpoz1y, '2');
				p1 = wsk1->zaloguj();
				p2 = wsk2->zaloguj();
				rej << asctime(localtime(&czas)) << "Wybrano tryb rozgrywki na dwoch graczy. gracz1: " << wsk1->wez_nick() << "\tgracz2: " << wsk2->wez_nick() << endl;
				p1 << asctime(localtime(&czas)) << "Wybrano tryb rozgrywki na dwoch graczy. gracz1: " << wsk1->wez_nick() << "\tgracz2: " << wsk2->wez_nick() << endl;
				p2 << asctime(localtime(&czas)) << "Wybrano tryb rozgrywki na dwoch graczy. gracz1: " << wsk1->wez_nick() << "\tgracz2: " << wsk2->wez_nick() << endl;
			}
			else
			{
				wsk1 = new Gracz_czl();
				wsk2 = new Gracz_kom();
				p1 = wsk1->zaloguj();
				p2 = wsk2->zaloguj();
				rej << asctime(localtime(&czas)) << "Wybrano tryb rozgrywki z komputerem. gracz1: " << wsk1->wez_nick() << "\tgracz komputerowy: " << wsk2->wez_nick() << endl;
				p1 << asctime(localtime(&czas)) << "Wybrano tryb rozgrywki na dwoch graczy. gracz1: " << wsk1->wez_nick() << "\tgracz2: " << wsk2->wez_nick() << endl;
				p2 << asctime(localtime(&czas)) << "Wybrano tryb rozgrywki na dwoch graczy. gracz1: " << wsk1->wez_nick() << "\tgracz2: " << wsk2->wez_nick() << endl;
			}

			//pokazanie planszy uzytkownikowi/kom, aby zapoznac ich z pozycjami startowymi
			P->rysuj();

			//odpalenie gry dla wybranych graczy (potrwa ona tak dlugo jak jedna z funkcji sprawdzajacej warunki zwyciestwa zwroci true)
			while (true)
			{
				if (wsk1->wygrana() || wsk2->wygrana() || wsk1->interfejs((*P))) break;
				if (wsk1->wygrana() || wsk2->wygrana() || wsk2->interfejs((*P))) break;
			}
			time(&czas);

			system("cls");

			//komunikaty zawierajace rezultat rozgrywki
			if (wsk1->wygrana())
			{
				cout << "Rozgrywka zakonczyla sie zwyciestwem gracza1 o pseudonimie: " << wsk1->wez_nick() << endl;
				rej << asctime(localtime(&czas)) << "Rozgrywka zakonczyla sie zwyciestwem gracza1 o pseudonimie: " << wsk1->wez_nick() << endl;
				p1 << asctime(localtime(&czas)) << "Rozgrywka zakonczyla sie zwyciestwem gracza1 o pseudonimie: " << wsk1->wez_nick() << endl << endl;
				p2 << asctime(localtime(&czas)) << "Rozgrywka zakonczyla sie zwyciestwem gracza1 o pseudonimie: " << wsk1->wez_nick() << endl << endl;
			}
			else if (wsk2->wygrana())
			{
				cout << "Rozgrywka zakonczyla sie zwyciestwem gracza2 o pseudonimie: " << wsk2->wez_nick() << endl;
				rej << asctime(localtime(&czas)) << "Rozgrywka zakonczyla sie zwyciestwem gracza2 o pseudonimie: " << wsk2->wez_nick() << endl;
				p1 << asctime(localtime(&czas)) << "Rozgrywka zakonczyla sie zwyciestwem gracza2 o pseudonimie: " << wsk2->wez_nick() << endl << endl;
				p2 << asctime(localtime(&czas)) << "Rozgrywka zakonczyla sie zwyciestwem gracza2 o pseudonimie: " << wsk2->wez_nick() << endl << endl;
			}
			else
			{
				cout << "Rozgrywka zostala przerwana przed wylonieniem zwyciezcy." << endl;
				rej << asctime(localtime(&czas)) << "Rozgrywka zostala przerwana przed wylonieniem zwyciezcy." << endl;
				p1 << asctime(localtime(&czas)) << "Rozgrywka zostala przerwana przed wylonieniem zwyciezcy." << endl << endl;
				p2 << asctime(localtime(&czas)) << "Rozgrywka zostala przerwana przed wylonieniem zwyciezcy." << endl << endl;
			}

			//sprzatanie
			delete wsk1;
			delete wsk2;
			delete P;
			p1.close();
			p2.close();
			break;
		case 2:
			cout << "Wyswietlone zostana dane dotyczace ostatnich (maksymalnie 5) rozgrywek gracza o podanym pseudonimie, aby ujrzec reszte prosze otworzyc plik o odpowiednim pseudonimie z rozszerzeniem '.txt', znajdujacy sie w folderze z plikami gry. W celu obejrzenia pliku zawierajacego caly przebieg dzialania programu zajrzyj do pliku 'log.txt' znajdujacego sie w folderze z plikami gry." << endl;
			cout << "Prosze podac pseudonim gracza, ktorego wyniki maja zostac pokazane: ";
			nazwa_g = pobierz_od_gracza<string>("nogr", "", ""); cout << endl;
			time(&czas);
			pokaz_rozgrywki(nazwa_g);
			rej << asctime(localtime(&czas)) << "Wyswietlono fragment historii rozgrywek dla gracza: " << nazwa_g << endl;
			break;
		case 3:
			cout << "Czy na pewno chcesz wyjsc z gry?" << endl << "1. Tak" << endl << "2. Nie" << endl;
			if (1 == pobierz_od_gracza<int>("ogr", 1, 2))
			{
				time(&czas);
				rej << asctime(localtime(&czas)) << "Zakonczono dzialanie programu." << endl << endl;
				rej.close();
				return;
			}
			break;
		}
	}
}

//cialo funkcji odpowiadajacej za wyswietlenie wynikow danego gracza
void pokaz_rozgrywki(string nick)
{
	//zmienne
	string wyniki, naz_plik;
	int ilosc_linii = 0;

	//sprawdzenie, czy plik jest pusty i czy istnieje
	naz_plik = nick + ".txt";
	if (!czy_istnieje_plik(naz_plik))
		cout << "Gracza o podanym nicku nie ma w bazie danych." << endl << endl;

	//otwarcie stosownego pliku do odczytu
	fstream rezultaty;
	rezultaty.open(naz_plik, ios::in);

	//powrot do poczatku pliku (wyczyszenie flagi konca pliku, jesli wierszy mniej niz 5)
	rezultaty.clear();
	rezultaty.seekg(0, ios::beg);

	//przesuniecie w celu odczytania jednynie ostatnich rekordow (jesli plik bedzie za maly to nie zostanie ono wykonane)
	while (getline(rezultaty, wyniki))
		ilosc_linii++;

	//powrot do poczatku pliku (wyczyszenie flagi konca pliku, jesli wierszy mniej niz 5)
	rezultaty.clear();
	rezultaty.seekg(0, ios::beg);

	for (int i = 0; i < ilosc_linii - 5 * IL_WYS_ROZ; i++)
		getline(rezultaty, wyniki);

	//wczytanie danych z pliku (jesli plik bedzie pusty to getline nie bedzie probowal nic wczytywac, poniewaz napotka flage konca pliku)
	while (getline(rezultaty, wyniki))
		cout << wyniki << endl;

	rezultaty.close();
}

//cialo funkcji sprawdzajacej, czy plik o podanej nazwie istnieje
bool czy_istnieje_plik(std::string nazwa_pliku)
{
	fstream plik;
	plik.open(nazwa_pliku, ios::in);
	return plik.good();
}

//cialo funkcji sprawdzajacej, czy otwarcie nastapilo bez przeszkod
void czy_otwarcie(std::fstream &f)
{
	if (f.good() == false)
	{
		perror("Nie udalo sie otworzyc pliku rejestrujacego przebieg rozgrywki.");
		exit(EXIT_FAILURE);
	}

	if (f.is_open())
		cout << "Plik rejestrujacy przebieg rozgywki zostal pomyslnie otwarty." << endl;
}

//szablon funkcji pobierajacych dane od gracza
template<typename T>
T pobierz_od_gracza(string s, T ogr_min, T ogr_maks)
{
	//zmienne
	T por_dan;
	cin >> por_dan;
	//sprawdzenie, czy wartosc zmiennej pobieranej ma byc kontrolowana, czy nie
	if ("ogr" == s)
	{
		//kontrola poprawnosci wczytanych danych z uwzglednieniem przedzialu
		while (cin.fail() || por_dan > ogr_maks || por_dan < ogr_min || getchar() != '\n')
		{
			czysc_bufor();
			cin >> por_dan;
		}
	}
	else if ("nogr" == s)
	{
		//kontrola poprawnosci wczytanych danych
		while (cin.fail() || getchar() != '\n')
		{
			czysc_bufor();
			cin >> por_dan;
		}
	}

	return por_dan;
}

template int pobierz_od_gracza(string, int, int);
template char pobierz_od_gracza(string, char, char);
template string pobierz_od_gracza(string, string, string);

template<typename T>
T pobierz_od_bota(string s, T ogr_min, T ogr_maks)
{
	//zmienne
	T por_dan;

	//pobranie losowej liczby w celu ustalenia decyzji
	srand((unsigned)time(NULL));
	por_dan = rand() % ogr_maks + ogr_min;
	
	//sprawdzenie, czy wartosc zmiennej pobieranej ma byc kontrolowana, czy nie
	if ("ogr" == s)
	{
		//kontrola poprawnosci wczytanych danych z uwzglednieniem przedzialu
		while (por_dan > ogr_maks || por_dan < ogr_min)
			por_dan = rand() % ogr_maks + ogr_min;
	}

	return por_dan;
}

template int pobierz_od_bota(string, int, int);
template char pobierz_od_bota(string, char, char);