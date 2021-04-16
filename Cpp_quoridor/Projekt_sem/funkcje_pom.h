#ifndef funkcje_pom_h
#define funkcje_pom_h

//funkcja odpowiedzialnej za czyszczenie bufora w przypadku podania nieprawidlowych danych
void czysc_bufor();

//funkcja odpowiedzialna za wybor trybu gry i rejestrowanie przebiegu rozgrywki
void zagraj();

//funkcja wyswietlajaca wyniki gracza o nicku podanym w argumencie wywolania
void pokaz_rozgrywki(std::string);

//funkcja sprawdzajaca, czy plik o podanej nazwie istnieje
bool czy_istnieje_plik(std::string);

//funkcja sprawdzajaca, czy otwarcie nastapilo bez przeszkod
void czy_otwarcie(std::fstream&);

//szablon funkcji pobierajacych dane wraz ze sprawdzeniem ich poprawnosci
template<typename T>
T pobierz_od_gracza(std::string, T, T);

//szablon funkcji pobierajacych dane wraz ze sprawdzeniem ich poprawnosci od gracza komputerowego
template<typename T>
T pobierz_od_bota(std::string, T, T);

#endif