#include "statki.hpp"


gra::gra() {
	this->wybor();
}

void gra::wybor()
{
	int wybor;
	cout << "Wybierz co chcesz zrobic:" << endl;
	cout << "Wybierz 1, jesli chcesz rozpoczac gre." << endl;
	cout << "Wybierz 2, jesli chcesz wyswietlic regulamin." << endl;
	cout << "Wybierz 3, jesli chcesz zakonczyc gre." << endl;
	cout << "Wybor: ";
	cin >> wybor;
	if (wybor == 1)
	{
		system("cls");
		this->Tworz_plansze(10);
		//return 1;
		//cout << "Jesli chcesz zagrac na planszy 5x5 kliknij 1:" << endl;
		//cout << "Jesli chcesz zagrac na planszy 10x10 kliknij 2:" << endl;
		//cout << "Wybor: ";
		//cin >> wybor;
		/*if (wybor == 1)
		{
			system("cls");
			this->Tworz_plansze(5);

		}
		else
		{
			system("cls");
			this->Tworz_plansze(10);
		}*/



	}
	else if (wybor == 2)
	{

	}
	else
	{
		return;
	}

}

void gra::Rozpocznij_gre(plansza* plansza1, plansza* plansza2, ekran* ekran, gracz* gracz1, gracz* gracz2)
{
	while (true)
	{
		this->strzal(plansza1, plansza2, ekran, gracz1);
		if (plansza2->ilosc_pol == 0)
		{
			cout << "Wygral gracz: " << gracz1->getNick();
			return;
		}
		this->strzal(plansza2, plansza1, ekran, gracz2);
		if (plansza1->ilosc_pol == 0)
		{
			cout << "Wygral gracz: " << gracz2->getNick();
			return;
		}
	}
}

void gra::strzal(plansza* moja, plansza* przeciwnika, ekran* ekran, gracz* gracz)
{
	system("cls");
	cout << "Ruch gracza " << gracz->getNick() << endl;
	int x, y;
	ekran->rysuj(moja);
	cout << "Strzel w pole: ";
	do {
		do {
			cin >> x >> y;
		} while (!(x >= 0 and x < moja->get_Do_plansza() + 1 and y >= 0 and y < moja->get_Do_plansza() + 1));
	} while (przeciwnika->tab[x][y] != "X" and przeciwnika->tab[x][y] != "O");
	while (przeciwnika->tab[x][y] == "X" and przeciwnika->ilosc_pol > 0)
	{

		przeciwnika->ilosc_pol -= 1;
		moja->tab_pomocnicza[x][y] = "T";
		przeciwnika->tab[x][y] = "T";
		system("cls");
		ekran->rysuj(moja);
		cout << przeciwnika->ilosc_pol;
		if (przeciwnika->ilosc_pol > 0)
		{
			cout << gracz->getNick() << " Trafiles. Strzel ponownie w pole: " << endl;
			do {
				cin >> x >> y;
			} while (!(x >= 0 and x < moja->get_Do_plansza() + 1 and y >= 0 and y < moja->get_Do_plansza() + 1));
		}

	}


	moja->tab_pomocnicza[x][y] = "N";
	przeciwnika->tab[x][y] = "N";

}

void gra::Tworz_plansze(int roz)
{
	ekran ekran1;



	gracz gracz1;

	plansza plansza1(roz);
	system("cls");
	gracz gracz2;

	plansza plansza2(roz);
	this->Rozpocznij_gre(&plansza1, &plansza2, &ekran1, &gracz1, &gracz2);
}

gracz::gracz() {
	cout << "Podaj nick: ";
	string n;
	cin >> n;
	setNick(n);
}

string gracz::getNick()
{
	return nick;
}

void gracz::setNick(string nick)
{
	this->nick = nick;
}

int statek::getDo_plansza()
{
	return do_plansza;
}

void statek::Podaj_punkty()
{
	if (rozmiar == 4)
		cout << "Podaj pierwszy i ostatni punkt (x,y) statku czteromasztowego: ";
	else if (rozmiar == 3)
		cout << "Podaj pierwszy i ostatni punkt (x,y) statku trojmasztowego: ";
	else if (rozmiar == 2)
		cout << "Podaj pierwszy i ostatni punkt (x,y) statku dwumasztowego: ";
	else
		cout << "Podaj punkt (x,y) statku jednomasztowego: ";
	do
	{
		cin >> x1;
		cin >> y1;
	} while ((x1 < 1 or x1 > getDo_plansza()) or (y1 < 1 or y1 > getDo_plansza()));
	if (rozmiar > 1)
	{
		do
		{
			cin >> x2;
			cin >> y2;
		} while ((x2 < 1 or x2 > getDo_plansza()) or (y2 < 1 or y2 > getDo_plansza()));
		while (!((x1 == x2 and abs(y1 - y2) == (rozmiar - 1)) or (y1 == y2 and abs(x1 - x2) == (rozmiar - 1))))
		{
			cout << "Podano zly punkt statku. Podaj poprawny punkt (x,y): ";
			do
			{
				cin >> x2;
				cin >> y2;
			} while ((x1 < 1 or x1 > getDo_plansza()) or (y1 < 1 or y1 > getDo_plansza()));
		}
	}

}

plansza::plansza(int do_plansza) {
	this->do_plansza = do_plansza;
	this->Plansza_pomocnicza();
	this->Plansza_pocz();
	this->Tworz();
	this->setIlosc();
}
int plansza::get_Do_plansza()
{
	return do_plansza;
}
void plansza::setIlosc()
{
	int x = 0;
	for (int i = 0; i < get_Do_plansza() + 1; i++)
	{
		for (int j = 0; j < get_Do_plansza() + 1; j++)
		{
			if (tab[i][j] == "X")
				x += 1;
		}
	}
	this->ilosc_pol = x;

}
void plansza::Plansza_pocz()
{
	for (int i = 0; i < get_Do_plansza() + 1; i++)
	{
		for (int j = 0; j < get_Do_plansza() + 1; j++)
		{
			if (i == 0 and j != 0)
			{

				tab[i][j] = to_string(j);

			}
			if (j == 0 and i != 0)
			{

				tab[i][j] = to_string(i) + " ";
				if (i >= 10)
					tab[i][j] = to_string(i);
			}
			if (i != 0 and j != 0)
			{
				//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				//SetConsoleTextAttribute(hConsole, 12);
				tab[i][j] = "O";
				//SetConsoleTextAttribute(hConsole, 7);
			}

			tab[0][0] = "  ";
		}
	}
}
void plansza::Uzupelnij_pola(statek* costam)
{
	int rozmiar = costam->rozmiar;
	if (rozmiar == 1)
	{
		int x1 = costam->x1;
		int y1 = costam->y1;
		tab[x1][y1] = "X";
	}
	else
	{
		int x1 = costam->x1;
		int x2 = costam->x2;
		int y1 = costam->y1;
		int y2 = costam->y2;
		if (x1 == x2 and y1 < y2)
		{
			for (int i = 0; i < get_Do_plansza() + 1; i++) {
				for (int j = 0; j < get_Do_plansza() + 1; j++) {
					if (i == x1 and j >= y1 and j <= y2)
					{
						tab[i][j] = "X";
					}
				}
			}

		}
		if (x1 == x2 and y1 > y2)
		{
			for (int i = 0; i < get_Do_plansza() + 1; i++) {
				for (int j = 0; j < get_Do_plansza() + 1; j++) {
					if (i == x1 and j <= y1 and j >= y2)
					{
						tab[i][j] = "X";
					}
				}
			}

		}
		if (y1 == y2 and x1 < x2)
		{
			for (int i = 0; i < get_Do_plansza() + 1; i++) {
				for (int j = 0; j < get_Do_plansza() + 1; j++) {
					if (j == y1 and i >= x1 and i <= x2)
					{
						tab[i][j] = "X";
					}
				}
			}

		}
		if (y1 == y2 and x2 < x1)
		{
			for (int i = 0; i < get_Do_plansza() + 1; i++) {
				for (int j = 0; j < get_Do_plansza() + 1; j++) {
					if (j == y1 and i >= x2 and i <= x1)
					{
						tab[i][j] = "X";
					}
				}
			}

		}
	}
	this->Wypisz();
}

void plansza::sprawdzenie(statek* statek)
{
	int rozmiar = statek->rozmiar;
	int sprawdzenie = 1;
	do {
		if (sprawdzenie == 0)
		{
			this->Wypisz();
			cout << "Podano zle wspolrzedne. Powtorz: " << endl;
			statek->Podaj_punkty();
		}
		system("cls");
		sprawdzenie = 1;
		int x1 = statek->x1;
		int y1 = statek->y1;
		if (rozmiar > 1)
		{
			int x2 = statek->x2;
			int y2 = statek->y2;

			for (int i = -1; i < 2; i++)
			{
				for (int j = -1; j < 2; j++)
				{
					if (x1 + i != get_Do_plansza() + 1 and y1 + j != get_Do_plansza() + 1 and x2 + i != get_Do_plansza() + 1 and y2 + j != get_Do_plansza() + 1) {
						if (tab[x1 + i][y1 + j] == "X" or tab[x2 + i][y2 + j] == "X")
						{
							sprawdzenie = 0;
						}
					}

				}
			}
		}
		else
		{

			for (int i = -1; i < 2; i++)
			{
				for (int j = -1; j < 2; j++)
				{
					if (x1 + i != get_Do_plansza() + 1 and y1 + j != get_Do_plansza() + 1)
					{
						if (tab[x1 + i][y1 + j] == "X")
						{
							sprawdzenie = 0;
						}

					}

				}
			}
		}
	} while (sprawdzenie != 1);
	this->Uzupelnij_pola(statek);
}

void plansza::Wypisz()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < get_Do_plansza() + 1; i++)
	{
		for (int j = 0; j < get_Do_plansza() + 1; j++)
		{
			if (this->tab[i][j] == "X")
				SetConsoleTextAttribute(hConsole, 14);
			else if (this->tab[i][j] == "N")
				SetConsoleTextAttribute(hConsole, 6);
			else if (this->tab[i][j] == "O")
				SetConsoleTextAttribute(hConsole, 8);
			else if (this->tab[i][j] == "T")
				SetConsoleTextAttribute(hConsole, 4);
			cout << tab[i][j] << " ";
			SetConsoleTextAttribute(hConsole, 15);
		}
		cout << endl;
	}
}


void plansza::Tworz()
{
	statek* st = nullptr;
	this->Wypisz();
	for (int i = 0; i < 10; i++)
	{
		if (this->tablica_statkow[i] == 1)
			st = new statek1(do_plansza);
		if (this->tablica_statkow[i] == 2)
			st = new statek2(do_plansza);
		if (this->tablica_statkow[i] == 3)
			st = new statek3(do_plansza);
		if (this->tablica_statkow[i] == 4)
			st = new statek4(do_plansza);
		this->sprawdzenie(st);
	}

}

void plansza::Plansza_pomocnicza()
{
	for (int i = 0; i < get_Do_plansza() + 1; i++)
	{
		for (int j = 0; j < get_Do_plansza() + 1; j++)
		{
			if (i == 0 and j != 0)
			{

				tab_pomocnicza[i][j] = to_string(j);

			}
			if (j == 0 and i != 0)
			{

				tab_pomocnicza[i][j] = to_string(i) + " ";
				if (i >= 10)
					tab_pomocnicza[i][j] = to_string(i);
			}
			if (i != 0 and j != 0)
			{

				tab_pomocnicza[i][j] = "O";

			}

			tab_pomocnicza[0][0] = "  ";
		}
	}
}

void ekran::rysuj(plansza* plansza1)
{

	this->kolory(plansza1);
	for (int i = 0; i < plansza1->get_Do_plansza() + 1; i++)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int j = 0; j < plansza1->get_Do_plansza() + 1; j++)
		{
			if (plansza1->tab[i][j] == "X")
				SetConsoleTextAttribute(hConsole, 14);
			else if (plansza1->tab[i][j] == "N")
				SetConsoleTextAttribute(hConsole, 6);
			else if (plansza1->tab[i][j] == "O")
				SetConsoleTextAttribute(hConsole, 8);
			else if (plansza1->tab[i][j] == "T")
				SetConsoleTextAttribute(hConsole, 4);
			cout << plansza1->tab[i][j] << " ";
			SetConsoleTextAttribute(hConsole, 15);
		}
		if (i == 0)
			cout << " " << "\t";
		else
			cout << "  " << "\t";
		for (int j = 0; j < plansza1->get_Do_plansza() + 1; j++)
		{
			if (plansza1->tab_pomocnicza[i][j] == "X")
				SetConsoleTextAttribute(hConsole, 14);
			else if (plansza1->tab_pomocnicza[i][j] == "N")
				SetConsoleTextAttribute(hConsole, 6);
			else if (plansza1->tab_pomocnicza[i][j] == "O")
				SetConsoleTextAttribute(hConsole, 8);
			else if (plansza1->tab_pomocnicza[i][j] == "T")
				SetConsoleTextAttribute(hConsole, 4);
			cout << plansza1->tab_pomocnicza[i][j] << " ";
			SetConsoleTextAttribute(hConsole, 15);
		}
		cout << endl;
	}
}

void ekran::kolory(plansza* plansza1)
{


}

statek1::statek1(int do_plansza)
{

	//this->set_do(do_plansza);
	this->do_plansza = do_plansza;
	this->rozmiar = 1;
	this->Podaj_punkty();
}

void statek1::Podaj_punkty()
{
	cout << "Podaj punkt (x,y) statku jednomasztowego: ";
	do
	{
		cin >> x1;
		cin >> y1;
	} while ((x1 < 1 or x1 > getDo_plansza()) or (y1 < 1 or y1 > getDo_plansza()));
}

statek2::statek2(int do_plansza)
{
	this->do_plansza = do_plansza;
	this->rozmiar = 2;
	this->Podaj_punkty();
}

void statek2::Podaj_punkty()
{
	cout << "Podaj pierwszy i ostatni punkt (x,y) statku dwumasztowego: ";
	do
	{
		cin >> x1;
		cin >> y1;
	} while ((x1 < 1 or x1 > getDo_plansza()) or (y1 < 1 or y1 > getDo_plansza()));
	if (rozmiar > 1)
	{
		do
		{
			cin >> x2;
			cin >> y2;
		} while ((x2 < 1 or x2 > getDo_plansza()) or (y2 < 1 or y2 > getDo_plansza()));
		while (!((x1 == x2 and abs(y1 - y2) == (rozmiar - 1)) or (y1 == y2 and abs(x1 - x2) == (rozmiar - 1))))
		{
			cout << "Podano zly punkt statku. Podaj poprawny punkt (x,y): ";
			do
			{
				cin >> x2;
				cin >> y2;
			} while ((x1 < 1 or x1 > getDo_plansza()) or (y1 < 1 or y1 > getDo_plansza()));
		}
	}
}
statek3::statek3(int do_plansza)
{
	this->do_plansza = do_plansza;
	this->rozmiar = 3;
	this->Podaj_punkty();
}

void statek3::Podaj_punkty()
{
	cout << "Podaj pierwszy i ostatni punkt (x,y) statku trojmasztowego: ";
	do
	{
		cin >> x1;
		cin >> y1;
	} while ((x1 < 1 or x1 > getDo_plansza()) or (y1 < 1 or y1 > getDo_plansza()));
	if (rozmiar > 1)
	{
		do
		{
			cin >> x2;
			cin >> y2;
		} while ((x2 < 1 or x2 > getDo_plansza()) or (y2 < 1 or y2 > getDo_plansza()));
		while (!((x1 == x2 and abs(y1 - y2) == (rozmiar - 1)) or (y1 == y2 and abs(x1 - x2) == (rozmiar - 1))))
		{
			cout << "Podano zly punkt statku. Podaj poprawny punkt (x,y): ";
			do
			{
				cin >> x2;
				cin >> y2;
			} while ((x1 < 1 or x1 > getDo_plansza()) or (y1 < 1 or y1 > getDo_plansza()));
		}
	}
}
statek4::statek4(int do_plansza)
{
	this->do_plansza = do_plansza;

	this->rozmiar = 4;
	this->Podaj_punkty();
}

void statek4::Podaj_punkty()
{
	cout << "Podaj pierwszy i ostatni punkt (x,y) statku czteromasztowego: ";
	do
	{
		cin >> x1;
		cin >> y1;
	} while ((x1 < 1 or x1 > getDo_plansza()) or (y1 < 1 or y1 > getDo_plansza()));
	if (rozmiar > 1)
	{
		do
		{
			cin >> x2;
			cin >> y2;
		} while ((x2 < 1 or x2 > getDo_plansza()) or (y2 < 1 or y2 > getDo_plansza()));
		while (!((x1 == x2 and abs(y1 - y2) == (rozmiar - 1)) or (y1 == y2 and abs(x1 - x2) == (rozmiar - 1))))
		{
			cout << "Podano zly punkt statku. Podaj poprawny punkt (x,y): ";
			do
			{
				cin >> x2;
				cin >> y2;
			} while ((x1 < 1 or x1 > getDo_plansza()) or (y1 < 1 or y1 > getDo_plansza()));
		}
	}
}

/*plansza10::plansza10(int do_plansza)
{
	this->do_plansza = do_plansza;
	this->Plansza_pomocnicza();
	this->Plansza_pocz();
	this->Tworz();
	this->setIlosc();
}

plansza5::plansza5(int do_plansza)
{
	this->do_plansza = do_plansza;
	this->Plansza_pomocnicza();
	this->Plansza_pocz();
	this->Tworz();
	this->setIlosc();
}*/