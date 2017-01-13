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



void FirstGen(int aleg,int dealer[max],int player[max],int cpu_player[max],int uz[max],int &fgen)
{
	int nrgen;

	Regen:

	nrgen = VerifGen(uz);

	if (aleg == 1)
	{

		if (fgen >= 0 && fgen < 4)
		{
			if (fgen == 0) dealer[0] = nrgen;
			if (fgen == 1) player[0] = nrgen;
			if (fgen == 2) dealer[1] = nrgen;
			if (fgen == 3) player[1] = nrgen;
			fgen++;
			goto Regen;
		}
	}

	if (aleg == 2)
	{

		if (fgen >= 0 && fgen < 6)
		{
			if (fgen == 0) dealer[0] = nrgen;
			if (fgen == 1) player[0] = nrgen;
			if (fgen == 2) dealer[1] = nrgen;
			if (fgen == 3) player[1] = nrgen;
			if (fgen == 4) cpu_player[0] = nrgen;
			if (fgen == 5) cpu_player[1] = nrgen;
			fgen++;
			goto Regen;
		}
	}
}


int GenCpuPlayer(int uz[max],int cpu_play[max])
{
	int val = 0, scor = 0;

	while (scor < 17)
	{
		scor = 0;
		gen_dealer(uz, cpu_play);
		for (int i = 0; i < max; i++)
		{
			if (cpu_play[i] != 0)
			{
				val = cpu_play[i] / 10;
				if (val == 1) scor += 11;
				else if (val == 11) scor += 10;
				else if (val == 12) scor += 10;
				else if (val == 13) scor += 10;
				else scor += val;
			}
		}
	}
	return scor;

}

int main()
{
	int uz_carti[max], dealer[max], player[max], cpu_player[max];  // Vectorii in care vom memora toate cartile generate si cartile fiecarui player + dealerul ..
	int playerbet, cpu_playerbet, insurancebet;	// variabilele care memoreaza pariurile (vor fi suprascrise) ..
	int bani = 0, cpu_playerbani = 0;	// suma de bani  cu care playerul real intra in joc (50 - 1000) ..
	int alegere1, alegere2;			// alegere1 = tipul de joc , alegere2 = obtiunea din meniu ..
	int tip, val, nrgen;			// tipul si valorea cartilor generate ..
	int i, j;						// pt foruri (contori) ..
	char nume_player[10];			// sir caractere pt numele playerului real ..
	int fgen = 0;					// primele 4 sau 6 generari (primele carti de pe masa pana la meniul jocului) - contor ..
	bool splitok = false, jocnou = true, rularenoua = true, insuranceok = false, showHiden = false;
	int scorplayer = 0, scordealer = 0, scorcpuplayer = 0, scorascuns = 0;	//  variabile care memoreaza scorurile fiecarui player + dealer , vor fi suprascrise la un nou joc / runda ..
	//int aux1 = 0, aux2 = 0, aux3 = 0, aux4 = 0;
	int splitscorplayer = 0, splitplayerbet = 0;
	// ++++++++++  Nume & Suma de bani  ++++++++++
	titlu();

	cout << "Introduceti numele cu care doriti sa intrati in joc : ";
	cin >> nume_player;

	bani_alegere:
	PlayerCont(bani);

	cout <<"\n\n";




	_jocnou:
	if (jocnou == true)
	{

		for (i = 0; i < max; i++)
		{
			uz_carti[i] = 0;
			dealer[i] = 0;
			player[i] = 0;
			cpu_player[i] = 0;
		}
		fgen = 0;
		scorcpuplayer = 0;
		scorplayer = 0;
		splitscorplayer = 0;
		scordealer = 0;
		scorascuns = 0;
		splitok = false;
		jocnou = true;
		//rularenoua = true;
		insuranceok = false;
		showHiden = false;
		playerbet = 0;
		cpu_playerbet = 0;
		insurancebet = 0;
		splitplayerbet = 0;
		system("cls");
	}


	titlu();
	if (rularenoua == true)
	{
		alegere1 = ModJoc();
		rularenoua = false;
	}


	rebet:

	playerbet = PlayerBet(bani);


	if (alegere1 == 2)
	{
		cpu_playerbani = gen_bani();
		cpu_playerbet = gen_bet(cpu_playerbani);
		cpu_playerbani -= cpu_playerbet;
	}

	system("cls");
	titlu();

	regenerare:
	cout << "Loading ...";

	nrgen = VerifGen(uz_carti);


	FirstGen(alegere1, dealer, player, cpu_player, uz_carti, fgen);


	_alegere2:
	system("cls");
	titlu();




	cout << " Dealer   : ";
	if (showHiden == false)
	{

		for (i = 0; i < max; i++)
		{
			if (dealer[i] != 0 && i == 0)
			{
				cout << "??  ";
				if (dealer[i] / 10 == 1) scorascuns += 11;
				else if (dealer[i] / 10 == 11) scorascuns += 10;
				else if (dealer[i] / 10 == 12) scorascuns += 10;
				else if (dealer[i] / 10 == 13) scorascuns += 10;
				else scorascuns += dealer[i] / 10;
			}
			else if (dealer[i] != 0 && i > 0)
			{
				val = dealer[i] / 10;
				if (val == 1)
				{
					cout << "A";
					scordealer += 11;
					scorascuns += 11;
				}
				else if (val == 11)
				{
					cout << "J";
					scordealer += 10;
					scorascuns += 10;
				}
				else if (val == 12)
				{
					cout << "Q";
					scordealer += 10;
					scorascuns += 10;
				}
				else if (val == 13)
				{
					cout << "K";
					scordealer += 10;
					scorascuns += 10;
				}
				else
				{
					cout << val;
					scordealer += val;
					scorascuns += val;
				}

				tip = dealer[i] % 10;
				if (tip == 1) cout << (char)03;
				else if (tip == 2) cout << (char)04;
				else if (tip == 3) cout << (char)05;
				else if (tip == 4) cout << (char)06;
				cout << " ";
			}
		}
	}
	else if (showHiden == true)
	{
		for (i = 0; i < max; i++)
		{
			if (dealer[i] != 0)
			{

				val = dealer[i] / 10;
				if (val == 1)
				{
					cout << "A";
					scordealer += 11;
					scorascuns += 11;
				}
				else if (val == 11)
				{
					cout << "J";
					scordealer += 10;
					scorascuns += 10;
				}
				else if (val == 12)
				{
					cout << "Q";
					scordealer += 10;
					scorascuns += 10;
				}
				else if (val == 13)
				{
					cout << "K";
					scordealer += 10;
					scorascuns += 10;
				}
				else
				{
					cout << val;
					scordealer += val;
					scorascuns += val;
				}

				tip = dealer[i] % 10;
				if (tip == 1) cout << (char)03;
				else if (tip == 2) cout << (char)04;
				else if (tip == 3) cout << (char)05;
				else if (tip == 4) cout << (char)06;
				cout << " ";
			}
		}
	}

	if (scorascuns > 21)
	{
		for (i = 0; i < max; i++)
		{
			if (dealer[i] == 0) break;
			if (dealer[i] == 11)
			{
				scorascuns -= 10;
				if (showHiden == true) scordealer -= 10;
			}
			else if (dealer[i] == 12)
			{
				scorascuns -= 10;
				if (showHiden == true) scordealer -= 10;
			}
			else if (dealer[i] == 13)
			{
				scorascuns -= 10;
				if (showHiden == true) scordealer -= 10;
			}
			else if (dealer[i] == 14)
			{
				scorascuns -= 10;
				if (showHiden == true) scordealer -= 10;
			}
		}

	}
	cout << "\n Scor Dealer este : " << scordealer;
	cout << "\n\n";


// CPU Player  ...

	if (alegere1 == 2)
	{

		cout << " Computer  : ";
		for (i = 0; i < max; i++)
		{
			if (cpu_player[i] != 0)
			{
				val = cpu_player[i] / 10;
				if (val == 1)
				{
					cout << "A";
					scorcpuplayer += 11;
				}
				else if (val == 11)
				{
					cout << "J";
					scorcpuplayer += 10;
				}
				else if (val == 12)
				{
					cout << "Q";
					scorcpuplayer += 10;
				}
				else if (val == 13)
				{
					cout << "K";
					scorcpuplayer += 10;
				}
				else
				{
					cout << val;
					scorcpuplayer += val;
				}

				tip = cpu_player[i] % 10;
				if (tip == 1) cout << (char)03;
				else if (tip == 2) cout << (char)04;
				else if (tip == 3) cout << (char)05;
				else if (tip == 4) cout << (char)06;
				cout << " ";
			}
		}

		if (scorcpuplayer > 21)
		{
			for (i = 0; i < max; i++)
			{
				if (cpu_player[i] == 0) break;
				if (cpu_player[i] == 11) scorcpuplayer -= 10;
				else if (cpu_player[i] == 12) scorcpuplayer -= 10;
				else if (cpu_player[i] == 13) scorcpuplayer -= 10;
				else if (cpu_player[i] == 14) scorcpuplayer -= 10;
			}

		}

		cout << "\n Scor  Computer : " << scorcpuplayer;
		cout << "\n Cont  Computer : " << cpu_playerbani;
		cout << "\n Pariu  Computer : " << cpu_playerbet;
		cout << "\n\n";
	}



	if (splitok == false)
	{

		cout << " " << nume_player << " : ";
		for (i = 0; i < max; i++)
		{
			if (player[i] != 0)
			{
				val = player[i] / 10;
				if (val == 1)
				{
					cout << "A";
					scorplayer += 11;
				}
				else if (val == 11)
				{
					cout << "J";
					scorplayer += 10;
				}
				else if (val == 12)
				{
					cout << "Q";
					scorplayer += 10;
				}
				else if (val == 13)
				{
					cout << "K";
					scorplayer += 10;
				}
				else
				{
					cout << val;
					scorplayer += val;
				}

				tip = player[i] % 10;
				if (tip == 1) cout << (char)03;
				else if (tip == 2) cout << (char)04;
				else if (tip == 3) cout << (char)05;
				else if (tip == 4) cout << (char)06;
				cout << " ";
			}
		}

		if (scorplayer > 21)
		{
			for (i = 0; i < max; i++)
			{
				if (player[i] == 0) break;
				if (player[i] == 11) scorplayer -= 10;
				else if (player[i] == 12) scorplayer -= 10;
				else if (player[i] == 13) scorplayer -= 10;
				else if (player[i] == 14) scorplayer -= 10;
			}
		}

		cout << "\n Scor   " << nume_player << " : " << scorplayer;
		cout << "\n Cont   " << nume_player << " : " << bani;
		cout << "\n Pariu  " << nume_player << " : " << playerbet;
		if (insuranceok == true) cout << "\n iPariu " << nume_player << " : " << insurancebet;
		cout << "\n\n";
	}
	else if (splitok == true)
	{
		cout << " " << nume_player << " : ";
		for (i = 0; i < max; i++)
		{
			if (player[i] != 0 && i % 2 == 0)
			{
				val = player[i] / 10;
				if (val == 1)
				{
					cout << "A";
					scorplayer += 11;
				}
				else if (val == 11)
				{
					cout << "J";
					scorplayer += 10;
				}
				else if (val == 12)
				{
					cout << "Q";
					scorplayer += 10;
				}
				else if (val == 13)
				{
					cout << "K";
					scorplayer += 10;
				}
				else
				{
					cout << val;
					scorplayer += val;
				}

				tip = player[i] % 10;
				if (tip == 1) cout << (char)03;
				else if (tip == 2) cout << (char)04;
				else if (tip == 3) cout << (char)05;
				else if (tip == 4) cout << (char)06;
				cout << " ";
			}
		}

		if (scorplayer > 21)
		{
			for (i = 0; i < max; i++)
			{
				if (i % 2 == 0)
				{
					if (player[i] == 0) break;
					if (player[i] == 11) scorplayer -= 10;
					else if (player[i] == 12) scorplayer -= 10;
					else if (player[i] == 13) scorplayer -= 10;
					else if (player[i] == 14) scorplayer -= 10;
				}
			}
		}

		cout << "\n Scor1  " << nume_player << " : " << scorplayer;
		cout << "\n Pariu1 " << nume_player << " : " << scorplayer;


		for (i = 0; i < max; i++)
		{
			if (player[i] != 0 && i % 2 == 1)
			{
				val = player[i] / 10;
				if (val == 1)
				{
					cout << "A";
					splitscorplayer += 11;
				}
				else if (val == 11)
				{
					cout << "J";
					splitscorplayer += 10;
				}
				else if (val == 12)
				{
					cout << "Q";
					splitscorplayer += 10;
				}
				else if (val == 13)
				{
					cout << "K";
					splitscorplayer += 10;
				}
				else
				{
					cout << val;
					splitscorplayer += val;
				}

				tip = player[i] % 10;
				if (tip == 1) cout << (char)03;
				else if (tip == 2) cout << (char)04;
				else if (tip == 3) cout << (char)05;
				else if (tip == 4) cout << (char)06;
				cout << " ";
			}
		}

		if (splitscorplayer > 21)
		{
			for (i = 0; i < max; i++)
			{
				if (i % 2 == 1)
				{
					if (player[i] == 0) break;
					if (player[i] == 11) splitscorplayer -= 10;
					else if (player[i] == 12) splitscorplayer -= 10;
					else if (player[i] == 13) splitscorplayer -= 10;
					else if (player[i] == 14) splitscorplayer -= 10;
				}
			}
		}

		cout << "\n Scor2  " << nume_player << " : " << splitscorplayer;
		cout << "\n Pariu2 " << nume_player << " : " << splitplayerbet;
		cout << "\n Cont   " << nume_player << " : " << bani;
		cout << "\n\n";
	}



	if (dealer[1] / 10 == 1) insuranceok = true;
	if (player[0] / 10 == player[1] / 10) splitok = true;



	if (alegere1 == 2)
	{
		if (scorcpuplayer == 21 && cpu_player[2] == 0)
		{
			cpu_playerbani += (cpu_playerbet * 3) / 2;
		}
		else if (scorcpuplayer <= 21 && scordealer < scorcpuplayer && showHiden == true)
		{
			cpu_playerbani += cpu_playerbet * 2;
		}
		else if (scorcpuplayer <= 21 && scordealer > 21 && showHiden == true)
		{
			cpu_playerbani += cpu_playerbet * 2;
		}
		else if (scorcpuplayer == scordealer && showHiden == true)
		{
			cpu_playerbani += cpu_playerbet;
		}
	}


	if (alegere1 == 2)
	{
		scorcpuplayer = GenCpuPlayer(uz_carti, cpu_player);
	}




	if (scorplayer == 21 && player[2] == 0)
	{
		jocnou = true;
		bani += (playerbet * 3) / 2;
		cout << "!!! ***BlackJack*** !!! \n";
		cout << "Apasa enter pt un joc nou !!! \n";
		cin.get();
		cin.get();
		system("cls");
		titlu();
		goto _jocnou;
	}
	else if (insuranceok == true && showHiden == true)
	{
		jocnou = true;
		if (scorascuns == 21 && dealer[2] == 0)
		{
			bani = bani + insurancebet * 2;
			cout << "Ai castigat pariul 'Insurance' !!! \n";
			cout << "Apasa enter pt un joc nou !!! \n";
			cin.get();
			cin.get();
			system("cls");
			titlu();
			goto _jocnou;
		}
		else if (scorascuns < 21 && dealer[2] == 0)
		{
			cout << "Ai pierdut pariul 'Insurance' !!! \n";
			cout << "Apasa enter pt un joc nou !!! \n";
			cin.get();
			cin.get();
			system("cls");
			titlu();
			goto _jocnou;
		}
	}
	else if (scorplayer > 21)
	{
		jocnou = true;
		cout << "!!! Ai pierdut !!! \n";
		cout << "Apasa enter pt un joc nou !!! \n";
		cin.get();
		cin.get();
		system("cls");
		titlu();
		goto _jocnou;
	}
	else if (scorplayer <= 21 && scordealer < scorplayer && showHiden == true)
	{
		jocnou = true;
		bani += playerbet * 2;
		cout << "!!! Ai castigat !!! \n";
		cout << "Apasa enter pt un joc nou !!! \n";
		cin.get();
		cin.get();
		system("cls");
		titlu();
		goto _jocnou;
	}
	else if (scordealer <= 21 && scordealer > scorplayer && showHiden == true)
	{
		jocnou = true;
		cout << "!!! Ai pierdut !!! \n";
		cout << "Apasa enter pt un joc nou !!! \n";
		cin.get();
		cin.get();
		system("cls");
		titlu();
		goto _jocnou;
	}
	else if (scorplayer <= 21 && scordealer > 21 && showHiden == true)
	{
		jocnou = true;
		bani += playerbet * 2;
		cout << "!!! Ai castigat !!! \n";
		cout << "Apasa enter pt un joc nou !!! \n";
		cin.get();
		cin.get();
		system("cls");
		titlu();
		goto _jocnou;
	}
	else if (scorplayer == scordealer && showHiden == true)
	{
		jocnou = true;
		bani += playerbet;
		cout << "!!! Ai scor egal cu dealerul !!! \n";
		cout << "Apasa enter pt un joc nou !!! \n";
		cin.get();
		cin.get();
		system("cls");
		titlu();
		goto _jocnou;
	}
	else if (splitok == true && showHiden == true)
	{
		if (scordealer > 21)
		{
			jocnou = true;
			bani = bani + playerbet + splitplayerbet;
			cout << "!!! Ai castigat !!! \n";
			cout << "Apasa enter pt un joc nou !!! \n";
			cin.get();
			cin.get();
			system("cls");
			titlu();
			goto _jocnou;
		}
		else if ((scordealer <= 21 && scorplayer > scordealer && splitscorplayer > scordealer) ||
				 (scordealer <= 21 && scorplayer > scordealer && splitscorplayer < scordealer) ||
				 (scordealer <= 21 && scorplayer < scordealer && splitscorplayer > scordealer))
		{
			jocnou = true;
			bani = bani + splitplayerbet;
			cout << "!!! Ai castigat numai 'o mana' !!! \n";
			cout << "Apasa enter pt un joc nou !!! \n";
			cin.get();
			cin.get();
			system("cls");
			titlu();
			goto _jocnou;
		}
		else if (scordealer <= 21 && scorplayer < scordealer && splitscorplayer < scordealer)
		{
			jocnou = true;
			cout << "!!! Ai pierdut !!! \n";
			cout << "Apasa enter pt un joc nou !!! \n";
			cin.get();
			cin.get();
			system("cls");
			titlu();
			goto _jocnou;
		}

	}






	cout << "\t        |***MENIU***| \n";
	cout << "1.Hit \n";
	cout << "2.Stand \n";
	cout << "3.Surrender \n";
	if (scorplayer == 9 || scorplayer == 10 || scorplayer == 11) cout << "4.Double \n";
	if (splitok == true) cout << "5.Split \n";
	if (insuranceok == true) cout << "6.Insurance ?? \n";
	cout << "0. >EXIT< \n";
	cout << "\n";
	cout << "Alegerea dumneavoastra : ";
	cin >> alegere2;

	if (alegere2 < 0 || alegere2 > 6)
	{
		cout << "!!! Comanda eronata !!!     \n";
		cin.get();
		cin.get();
		goto _alegere2;
	}
	else if (alegere2 == 1)
	{
		if (splitok == false)
		{
			nrgen = VerifGen(uz_carti);

			for (i = 0; i < max; i++)
			if (player[i] == 0)
			{
				player[i] = nrgen;
				break;
			}
		}
		else if (splitok == true)
		{
			j = 1;
			while (j == 2)
			{
				nrgen = VerifGen(uz_carti);

				for (i = 0; i < max; i++)
				if (player[i] == 0)
				{
					player[i] = nrgen;
					break;
				}
			}
		}

		scordealer = 0;
		scorplayer = 0;
		scorcpuplayer = 0;
		scorascuns = 0;
		goto _alegere2;
	}
	else if (alegere2 == 2)
	{
		while (scorascuns < 17)
		{
			scorascuns = 0;
			gen_dealer(uz_carti, dealer);
			for (i = 0; i < max; i++)
			{
				if (dealer[i] != 0)
				{
					val = dealer[i] / 10;
					if (val == 1) scorascuns += 11;
					else if (val == 11) scorascuns += 10;
					else if (val == 12) scorascuns += 10;
					else if (val == 13) scorascuns += 10;
					else scorascuns += val;
				}
			}

			if (scorascuns > 21)
			{
				for (i = 0; i < max; i++)
				{
					if (dealer[i] == 0) break;
					if (dealer[i] == 11) scorascuns -= 10;
					else if (dealer[i] == 12) scorascuns -= 10;
					else if (dealer[i] == 13) scorascuns -= 10;
					else if (dealer[i] == 14) scorascuns -= 10;
				}
			}
		}

		showHiden = true;
		scordealer = 0;
		scorplayer = 0;
		scorcpuplayer = 0;
		scorascuns = 0;
		goto _alegere2;
	}
	else if (alegere2 == 3)
	{
		playerbet = playerbet / 2;
		bani += playerbet;

		cout << "Apasati ENTER pentru a incepe un joc nou !!! \n";
		cin.get();
		cin.get();
		goto _jocnou;
	}
	else if (alegere2 == 4)
	{

		if (scorplayer == 9 || scorplayer == 10 || scorplayer == 11)
		{

			bani -= playerbet;
			playerbet = playerbet * 2;


			nrgen = VerifGen(uz_carti);
			for (i = 0; i < max; i++)
			if (player[i] == 0)
			{
				player[i] = nrgen;
				break;
			}



			while (scorascuns < 17)
			{
				scorascuns = 0;
				gen_dealer(uz_carti, dealer);
				for (i = 0; i < max; i++)
				{
					if (dealer[i] != 0)
					{
						val = dealer[i] / 10;
						if (val == 1) scorascuns += 11;
						else if (val == 11) scorascuns += 10;
						else if (val == 12) scorascuns += 10;
						else if (val == 13) scorascuns += 10;
						else scorascuns += val;
					}
				}

				if (scorascuns > 21)
				{
					for (i = 0; i < max; i++)
					{
						if (dealer[i] == 0) break;
						if (dealer[i] == 11) scorascuns -= 10;
						else if (dealer[i] == 12) scorascuns -= 10;
						else if (dealer[i] == 13) scorascuns -= 10;
						else if (dealer[i] == 14) scorascuns -= 10;
					}
				}

				showHiden = true;
				scordealer = 0;
				scorplayer = 0;
				scorcpuplayer = 0;
				scorascuns = 0;
				goto _alegere2;
			}
		}
	}
	else if (alegere2 == 5 && splitok == true)
	{
		splitplayerbet = playerbet / 2;
		playerbet = splitplayerbet;

		j = 1;

		while (j == 2)
		{
			nrgen = VerifGen(uz_carti);

			for (i = 0; i < max; i++)
			if (player[i] == 0)
			{
				player[i] = nrgen;
				break;
			}
		}

		splitscorplayer = 0;
		scordealer = 0;
		scorplayer = 0;
		scorcpuplayer = 0;
		scorascuns = 0;
		goto _alegere2;
	}
	else if (alegere2 == 6 && insuranceok == true)
	{
		insurancebet = playerbet / 2;
		bani -= insurancebet;

		showHiden = true;
		scordealer = 0;
		scorplayer = 0;
		scorcpuplayer = 0;
		scorascuns = 0;
		goto _alegere2;
	}
	else if (alegere2 == 0)
	{
		goto exitgame;
	}

	exitgame:

	return 0;
}
