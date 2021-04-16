#ifndef Gracz_h
#define Gracz_h

#include "Pionek.h"

class Pionek;
class Plansza;

//klasa abstrakcyjna
class Gracz
{
public:
	//metoda stawiajace sciane (wirtualna)
	virtual bool postaw_sciane(Plansza&) = 0;

	//metoda sprawdzajaca, czy gracz nie odniosl zwyciestwa (wirtualna)
	virtual bool wygrana() = 0;

	//metoda logujaca uzytkownika do pliku rejestrujacego przebieg dzialania programu (wirtualna)
	virtual std::fstream zaloguj() = 0;

	//metoda odpowiedzialna za interakcje z uzytkownikiem/decyzyjnosc gracza komputerowego
	virtual bool interfejs(Plansza&) = 0;

	//getery
	virtual int wez_x() = 0;
	virtual int wez_y() = 0;
	virtual char wez_rodzaj() = 0;
	virtual std::string& wez_nick() = 0;

	//sekcja przyjaciol klasy
	friend class Plansza;
};

//klasa konkretna
class Gracz_czl :public Gracz, public Pionek
{
	//atrybuty
	unsigned int ilosc_scian;
	char rodzaj_pionka;
	std::string nick;

public:
	//konstruktor domyslny
	Gracz_czl();

	//konstruktor z argumentami
	Gracz_czl(int, int, char);

	//metoda przeslaniajaca ta znajdujaca sie w klasie Pionek
	virtual void przesun(Plansza&);

	//metody przeslaniajace te wirtualne z klasy abstrakcyjnej
	virtual bool postaw_sciane(Plansza&);
	virtual bool wygrana();
	virtual std::fstream zaloguj();
	virtual bool interfejs(Plansza&);

	//getery
	virtual int wez_x() { return x; }
	virtual int wez_y() { return y; }
	virtual char wez_rodzaj() { return rodzaj_pionka; }
	virtual std::string& wez_nick() { return nick; }
};

//klasa konkretna
class Gracz_kom :public Gracz, public Pionek
{
	//atrybuty
	unsigned int ilosc_scian;
	char rodzaj_pionka;
	std::string nick;

public:
	//konstruktor domyslny
	Gracz_kom();

	//metoda przeslaniajaca ta znajdujaca sie w klasie Pionek
	virtual void przesun(Plansza&);

	//metody przeslaniajace te wirtualne z klasy abstrakcyjnej
	virtual bool postaw_sciane(Plansza&);
	virtual bool wygrana();
	virtual std::fstream zaloguj();
	virtual bool interfejs(Plansza&);

	//getery
	virtual int wez_x() { return x; }
	virtual int wez_y() { return y; }
	virtual char wez_rodzaj() { return rodzaj_pionka; }
	virtual std::string& wez_nick() { return nick; }
};

#endif