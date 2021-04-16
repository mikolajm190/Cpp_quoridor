#ifndef Plansza_h
#define Plansza_h

//stale okreslajace pozycje startowe pionkow
const int wymiary = 18, startpoz1x = 1, startpoz1y = 9, startpoz2x = 17, startpoz2y = 9;
class Pionek;
class Gracz;

class Plansza
{
	//atrybuty
	char rep_graf[wymiary][wymiary];

public:
	//konstruktor domyslny
	Plansza();

	//metoda rysujaca plansze
	void rysuj();

	//metoda stawiajace sciane
	void postaw_sciane(int, int, int);

	//metoda przesuwajaca pionek
	void przesun_pionek(int, int, char);

	//sekcja przyjaciol klasy
	friend class Pionek;
	friend class Gracz_czl;
	friend class Gracz_kom;
};

#endif
