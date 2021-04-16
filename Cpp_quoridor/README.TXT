Quridor
Wersja 1.0
Maj 2020
projekt realizowany w Microsoft Visual Studio 2017

W tym pliku znajduje sie kilka wskazowek dotyczacych dzialania programu.

------------------- SPIS TRESCI -------------------

1) O grze
2) Instrukcja obslugi programu
3) Przykladowe problemy - historia gier
4) Przykladowe problemy - plik rejestrujacy dzialanie programu (log.txt)
5) Przykladowe dane

---------------------------------------------------

1) O grze

Rozgrywka toczy się na planszy – szachownicy o rozmiarze 9×9.
Gracze zaczynaja rozgrywke z pionami ustawionymi w odpowiednich miejscach na planszy.
W trakcie tury gracz moze przesunac swoj pion o jedno pole w przod, tyl, bok lub postawic
scianke, ktora blokuje droge. Scianka zaslania dwa pola szachownicy, nie mozna
przez nia przejsc, raz postawiona, nie moze zostac przesunieta czy tez zdjeta z planszy.
Przesuwajacy sie pion moze napotkac inny przeciwnika, wtedy moze go przeskoczyc.
Osoba ktora jako pierwsza ustawi swoj pion w rzedzie z ktorego startowal pion wspolgracza – wygrywa.

---------------------------------------------------

2) Instrukcja obslugi programu

Wszystkie mozliwosci w trakcie dzialania programu beda opisane,
wiec musisz jedynie wybierac w odpowiedni sposob dane opcje.
Informacje na temat podawania danych programowi, aby zareagowal
znajdziesz w sekcji czwartej: przykladowe dane wejsciowe.
Poruszasz pionkiem za pomoca klawiszy (w - gora, a - lewo, s - dol
d - prawo).
W celu postawienia sciany musisz najpierw podac jej rodzaj,
a nastepnie podac wspolrzedne punktu (dolnego - dla sciany
pionowej, duzy znak, a nastepnie maly; lewego - dla sciany poziomej, duzy znak, a nastepnie maly).
Sciana sklada sie z trzech znakow i blokuje ogranicza dostep do dwoch pol.
W dowolnym momencie mozesz zdecydowac o opuszczeniu programu.
W trakcie rozgrywki i w menu glownym znajduja sie stowone opcje.

---------------------------------------------------

3) Przykladowe problemy - historia gier

Program jest tak napisany, ze bedzie odczytywal okreslona ilosc
linijek z plikow graczy. Zatem jesli zdarzy sie sytuacja, w ktorej
uzytkownik zamknie konsole manualnie zanim zakonczy sie rozgrywka
lub dzialanie programu zostanie przerwane przez brak dostepu do odpowiednich
plikow to moze sie okazac, ze wsrod ostatnich trzech zapisow rozgrywek znajdzie
sie niedokonczony, co spowoduje wyswietlenie np. samego rezultatu jednej
i jednynie komunikatu o rozpoczeciu drugiej. W celu naprawienia zaistnialej
sytuacji udaj sie do pliku danego gracza i usun zapis tej niedokonczonej
rozgrywki (bedzie widoczny jednynie komunikat o wybraniu trybu rozgrywki,
nie bedzie tego o jej wyniku.

Przyklad zapisow:
(prawidlowy zapis)
Wed May 27 13:07:17 2020
Wybrano tryb rozgrywki na dwoch graczy. gracz1: test1	gracz2: Bot_Andrzej
Wed May 27 13:07:41 2020
Rozgrywka zakonczyla sie zwyciestwem gracza1 o pseudonimie: test1
(jedna wolna linijka)

(bledny zapis)
Tue May 26 12:24:28 2020
Wybrano tryb rozgrywki na dwoch graczy. gracz1: test1	gracz2: Bot_Andrzej

Zwroc uwage, ze w blednym zapisie nie ma odstepu po komunikacie.

Przyklad usuwania:
(przed)
Wed May 27 17:33:16 2020
Wybrano tryb rozgrywki na dwoch graczy. gracz1: test1	gracz2: Bot_Andrzej
Wed May 27 17:33:36 2020
Rozgrywka zakonczyla sie zwyciestwem gracza1 o pseudonimie: test1

Wed May 27 17:33:47 2020
Wybrano tryb rozgrywki na dwoch graczy. gracz1: test1	gracz2: Bot_Andrzej
Wed May 27 17:33:57 2020
Wybrano tryb rozgrywki na dwoch graczy. gracz1: test1	gracz2: Bot_Andrzej
Wed May 27 17:34:05 2020
Rozgrywka zostala przerwana przed wylonieniem zwyciezcy.


(po)
Wed May 27 17:33:16 2020
Wybrano tryb rozgrywki na dwoch graczy. gracz1: test1	gracz2: Bot_Andrzej
Wed May 27 17:33:36 2020
Rozgrywka zakonczyla sie zwyciestwem gracza1 o pseudonimie: test1

Wed May 27 17:33:57 2020
Wybrano tryb rozgrywki na dwoch graczy. gracz1: test1	gracz2: Bot_Andrzej
Wed May 27 17:34:05 2020
Rozgrywka zostala przerwana przed wylonieniem zwyciezcy.

---------------------------------------------------

4) Przykladowe problemy - plik rejestrujacy dzialanie programu (log.txt)

Gdyby we wymienionym pliku nie znalazl sie komunikat o zakonczeniu sesji
oznacza to, ze wydarzylo sie jedno z dwoch:

a) uzytkownik zamknal konsole manualnie, nie poprzez wybory w menu
(moze nie byc takze komunikatu o rezulatacie rozgrywki)

b) program zakonczyl swoje dzialanie, poniewaz nie udalo sie otworzyc
plikow, rejestrujacych przebieg rozgrywki (log.txt, pliki graczy)

W przypadku bledu drugiego sprawdz, czy nie sa one uzywane w trakcie
rozgrywki przez takie programy jak Microsoft Word itp. W razie dalszych
problemow prosze o kontakt na adres mailowy podany na koncu pliku.

---------------------------------------------------

5) Przykladowe dane wejsciowe

Obsluga programu jest scisle zwiazana z pobieraniem od uzytkownika danych.
Ten dzial ma Ci uswiadomic jak robic to w poprawny sposob (nie obawiaj sie
program na kazdym kroku przypomina jak radzic sobie z trudniejszymi
aspektami podawania danych).

Wiekszosc decyzji bedziesz podejmowal/a podajac liczbe calkowita z odpowiedniego
zakresu.
Przyklad:
Na poczatku rozgrywki zostaniesz zapytany o wybor jednej z trzech mozliwosci.
Wowczas wyboru dokonujesz poprzez wcisniecie przycisku na klawiaurze reprezentujacego
dana cyfre i zatwierdzasz przyciskiem ENTER. (Dane: np. 1, ENTER) Proste, prawda?

W trakcie samej rozgrywki pojawia sie trudniejsze decyzje takiej jak:
1) poruszenie pionkiem
Przyklad:
Gdy bedziesz mial przed soba menu gracza, w celu wykonania ruchu musisz podac najpierw
liczbe calkowita odpowiadajaca wyborowi tej opcji i zatwierdzic klawiszem ENTER, a nastepnie
podac odpowiedni znak i ponownie zatwierdzic przyciskiem ENTER. (Dane: np. 1, ENTER; w, ENTER).

2) postawienie sciany
Przyklad:
Gdy bedziesz mial przed soba menu gracza, w celu postawienia sciany musisz podac najpierw
liczbe calkowita odpowiadajaca wyborowi tej opcji i zatwierdzic klawiszem ENTER, a nastepnie dwukrotnie podac odpowiedni
znak (za pierwszym razem z duzymi) i ponownie zatwierdzic przyciskiem ENTER. (Dane: np. 2, ENTER; Shift + a, ENTER; c, ENTER).
Dokladne wytlumaczenie zajeloby sporo czasu, a zapewne chcesz juz zagrac, wiec zalecam przed
pierwsza rozgrywka wybrac tryb rozgrywki na dwoch graczy i przecwiczyc ustawianie scian.

---------------------------------------------------

Jestes juz gotowy do przystapienia do rozgrywki. Dobrej zabawy!
