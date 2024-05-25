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
protected:
	int do_plansza;
	int rozmiar = {};
	int x1 = {}, y1 = {}, x2 = {}, y2 = {};
public:
	
	int getX1();
	int getY1();
	int getX2();
	int getY2();
	int getRozmiar();
	
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
	int ilosc_pol = {};
	int tablica_statkow[10] = { 1,1,1,1,2,2,2,3,3,4 };
	string tab[11][11];
	string tab_pomocnicza[11][11];

public:
	
	plansza(int do_plansza);
	
	int get_Do_plansza();
	void setIlosc();

	int* getTablica_statkow() { return tablica_statkow; }
	string(*getTab())[11] { return tab; }
	string(*getTab_pomocnicza())[11] { return tab_pomocnicza; }
	int getIlosc_pol() const { return ilosc_pol; }

	void setDo_plansza(int value) { do_plansza = value; }
	void setIlosc_pol(int value) { ilosc_pol = value; }
	void setTablica_statkow(int new_tablica_statkow[10]) {
		for (int i = 0; i < 10; ++i) {
			tablica_statkow[i] = new_tablica_statkow[i];
		}
	}
	void setTab(int x, int y, const string& value);
	void setTab_pomocnicza(int x, int y, const string& value);

	void setIlosc(int ilosc) { ilosc_pol = ilosc; }




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
	int rozmiar_planszy = {};
public:
	
	gra();
	void wybor();
	void Rozpocznij_gre(plansza* plansza1, plansza* plansza2, ekran* ekran, gracz* gracz1, gracz* gracz2);
	void strzal(plansza* moja, plansza* przeciwnika, ekran* ekran, gracz* gracz);
	void Tworz_plansze(int x);

};