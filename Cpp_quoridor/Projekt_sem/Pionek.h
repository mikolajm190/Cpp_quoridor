#ifndef Pionek_h
#define Pionek_h

#include "Plansza.h"

class Pionek
{
protected:
	//atrybuty
	int x, y;

public:
	//konstruktor domyslny
	Pionek();

	//konstruktor z argumentami
	Pionek(int, int);

	//metoda pozwalajaca przesunac pionek przeslaniana przez metody znajdujace sie w klasach dziedziczacych (Gracz_czl i Gracz_kom)
	virtual void przesun(Plansza&) = 0;

	//sekcja przyjaciol klasy
	friend class Plansza;
};

#endif