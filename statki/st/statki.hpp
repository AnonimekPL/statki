#include<iostream>
#include<string>
#include<stdlib.h>
#include <windows.h>
//#include<stdlib.h>
using namespace std;






class gracz//obiekty to 2 graczy
{
	string nick;
public:

	gracz();
	string getNick();
	void setNick(string nick);
};



class statek//4,3,3,2,2,2,1,1,1,1
{

public:
	int do_plansza;
	int rozmiar = {};
	int x1 = {}, y1 = {}, x2 = {}, y2 = {};
	int getDo_plansza();
	virtual void Podaj_punkty();
};
class statek1 : public statek {

public:
	statek1(int do_plansza);
	void Podaj_punkty();
};
class statek2 : public statek {

public:
	statek2(int do_plansza);
	void Podaj_punkty();
};
class statek3 : public statek {

public:
	statek3(int do_plansza);
	void Podaj_punkty();
};
class statek4 : public statek {

public:
	statek4(int do_plansza);
	void Podaj_punkty();
};


class plansza
{
	int do_plansza = {};

public:
	int ilosc_pol = {};
	int tablica_statkow[10] = { 1,1,1,1,2,2,2,3,3,4 };
	plansza(int do_plansza);

	string tab[11][11];
	string tab_pomocnicza[11][11];

	int get_Do_plansza();
	void setIlosc();
	void Plansza_pocz();
	void Uzupelnij_pola(statek* costam);
	void sprawdzenie(statek* statek);
	void Wypisz();
	void Tworz();

	void Plansza_pomocnicza();
};



/*class plansza5 :public plansza
{

public:
	int do_plansza = {};
	int tablica_statkow[3] = { 1,1,2 };
	string tab[6][6];
	string tab_pomocnicza[6][6];
	plansza5(int do_plansza);

};
class plansza10 :public plansza
{

public:
	int do_plansza = {};
	int tablica_statkow[10] = { 1,1,1,1,2,2,2,3,3,4 };
	string tab[11][11];
	string tab_pomocnicza[11][11];
	plansza10(int do_plansza);
};*/

class ekran
{
public:
	ekran() {};
	void rysuj(plansza* plansza1);
	void kolory(plansza* plansza1);
};


class gra
{
	int xd;
public:
	int rozmiar_planszy = {};
	gra();
	void wybor();
	void Rozpocznij_gre(plansza* plansza1, plansza* plansza2, ekran* ekran, gracz* gracz1, gracz* gracz2);
	void strzal(plansza* moja, plansza* przeciwnika, ekran* ekran, gracz* gracz);
	void Tworz_plansze(int x);

};