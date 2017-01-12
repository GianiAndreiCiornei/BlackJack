#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>


using namespace std;

#define max 21


void titlu()
{
	cout << "//////////////////////////////////////////////////////////" << endl;
	cout << "                  BLACKJACK                      " << endl;
	cout << " _____________________________________________  " << endl;
	cout << "| Reguli:                                      |" << endl;
	cout << "| Valoarea cartilor: cartile intre 2 si        |" << endl;
	cout << "| 10 au valoarea scrisa pe ele, figurile       |" << endl;
	cout << "| au valoarea 10,asul poate fi 1 sau 11        |" << endl;
    cout << "| dupa preferinta jucatorului.                 |" << endl;
	cout << "|                                              |" << endl;
	cout << "| Fiecare jucator primeste initial doua carti  |" << endl;
	cout << "| ce vor fi afisate tuturor participatilor     |" << endl;
	cout << "| dealerul va primi tot 2 carti din care una   |" << endl;
	cout << "| va fi cu fata in jos.Dupa impartire fiecare  |" << endl;
	cout << "| jucator va avea sansa ca suma cartilor sa fie|" << endl;
	cout << "| 21.                                          |" << endl;
	cout << "|                                              |" << endl;
	cout << "| Dupa impartirea cartilor jucatorul are 6     |" << endl;
	cout << "| optiuni:                                     |" << endl;
	cout << "|                                              |" << endl;
	cout << "| HIT:  mai iau o carte                        |" << endl;
	cout << "| STAND: nu mai iau carte                      |" << endl;
	cout << "| SURRENDER: Jucatorul are posibilitatea de a  |" << endl;
	cout << "| se retrage dupa primirea celor 2 carti,      |" << endl;
	cout << "| primind inapoi 1/2 din pariul initial.       |" << endl;
	cout << "|                                              |" << endl;
	cout << "| INSURANCE: Cand casa are cartea cu fata in   |" << endl;
	cout << "| sus as, jucatorul poate pune un insurance ,  |" << endl;
	cout << "| acest pariu verifica daca suma casei este 21 |" << endl;
	cout << "| daca da jucatorul primeste de 2 ori valoarea |" << endl;
	cout << "| pusa in joc.                                 |" << endl;
	cout << "|                                              |" << endl;
	cout << "| Double: dublez miza si iau doar o singura    |" << endl;
	cout << "| carte ( se foloseste cand jucatorul are suma |" << endl;
	cout << "| sigur peste 19)                              |" << endl;
	cout << "|                                              |" << endl;
	cout << "|  SPLIT: se foloseste cand jucatorul are 2    |" << endl;
	cout << "|  carti la fel jucatorul formand cate o mana  |" << endl;
	cout << "|  din fiecare carte. Cele 2 maini se joaca    |" << endl;
	cout << "|  dupa regulile standard                      |" << endl;
	cout << "|                                              |" << endl;
	cout << "|                                              |" << endl;
	cout << "|______________________________________________|" << endl;
	cout << "//////////////////////////////////////////////////////////" << endl;
}



void Refill(int &cont)
{
	while (cont < 50 || cont > 1000)
	{
		cout << "Introduceti suma de bani cu care intrati in joc (minim 50 si maxim 1000) : ";
		cin >> cont;

		if (cont >= 50 && cont <= 1000) break;

		system("cls");
		titlu();
		cout << "!!!! Ati ales gresit valoarea (numai intre 50 si 1000) !!!! \n";
	}
}

int PlayerBet(int &cont)
{
	int bet = 0;;

	while (cont == 0)
	{
		system("cls");
		titlu();
		cout << "Ati ramas fara BANI :)) !!! \n";
		cout << "Apasati ENTER pt a umple contul !!! \n";
		cin.get();
		//cin.get();
		Refill(cont);
	}

	if (cont < 250)
	{
		while (bet < 1 || bet > cont)
		{
			cout << "Introduceti pariul (intre 1 si " << cont << ") : ";
			cin >> bet;

			if (bet >= 1 && bet <= cont) break;

			system("cls");
			titlu();

			cout << "!!! Ati ales gresit valoarea !!! \n";
		}
	}
	else if (cont >= 250)
	{
		while (bet < 1 || bet > 250)
		{
			cout << "Introduceti pariul (intre 1 si 250) : ";
			cin >> bet;

			if (bet >= 1 && bet <= 250) break;

			system("cls");
			titlu();

			cout << "!!! Ati ales gresit valoarea !!! \n";
		}
	}
	cont -= bet;

	return bet;
}

void PlayerCont(int &cont)
{
	system("cls");
	titlu();

	while (cont < 50 || cont > 1000)
	{
		cout << "Introduceti suma de bani cu care intrati in joc (minim 50 si maxim 1000) : ";
		cin >> cont;

		if (cont >= 50 && cont <= 1000) break;

		system("cls");
		titlu();
		cout << "!!!! Ati ales gresit valoarea (numai intre 50 si 1000) !!!! \n";
	}
}



int ModJoc()
{
	int mod = 0;
	system("cls");
	titlu();
	while (mod < 1 || mod > 2)
	{
		cout << "Alegeti modul in care doriti sa jucati !!! \n";
		cout << "1.Dealer vs. Player \n";
		cout << "2.Dealer vs. Player vs. Cpu Player \n";
		cin >> mod;

		if (mod == 1 || mod == 2)
		{
			if (mod == 1)
			{
				cout << "Ati ales sa jucati : Dealer vs. Player  !\n\n";
			}
			if (mod == 2)
			{
				cout << "Ati ales sa jucati : Dealer vs. Player vs. Cpu Player  !\n\n";
			}
		}
		else
		{
			system("cls");
			titlu();
			cout << "Ati introdus o valoare eronata ! Va rugam sa alegeti din nou ! \n";
		}
	}

	return mod;
}



int gen_bet(int BaniCpuPlayer)
{
	if (BaniCpuPlayer > 250)
	{
		srand(time(0));
		return rand() % 250 + 1;
	}
	else
	{
		srand(time(0));
		return rand() % BaniCpuPlayer + 1;
	}
}



int gen_bani()
{
	srand(time(0));
	return rand() % 1000 + 50;
}

int gen_random()  // Functia care genereaza cartile ..
{
	int x, y;
	srand(time(0));
	x = rand() % 4 + 1;
	srand(time(0));
	y = rand() % 13 + 1;
	return y * 10 + x;

}



void gen_dealer(int a[max], int b[max])
{
	int z, i;

	AgainHere:
	srand(time(0));
	z = gen_random();
	for (i = 0; i < max; i++)
	{
		if (a[i] == z && a[i] != 0) goto AgainHere;
		if (a[i] == 0)
		{
			a[i] = z;
			break;
		}
	}

	for (i = 0; i < max; i++)
	if (b[i] == 0)
	{
		b[i] = z;
		break;
	}
}


int VerifGen(int uz[max])
{
	int i, nr;

	Again:
	nr = gen_random();

	for (i = 0; i < max; i++)
	{
		if (uz[i] == nr) goto Again;

		if (uz[i] == 0)
		{
			uz[i] = nr;
			break;
		}
	}
	return nr;
}



