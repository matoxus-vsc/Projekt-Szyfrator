//----------------------------
//@autor: Mateusz Miozga
//@data:
//@projekt: Szyfrator
//@plik: main.cpp
//----------------------------

#include <iostream> // Plik nag³owkowy obs³uguj¹cy standardowe wejœcie/wyjœcie
#include <conio.h> // Plik nag³owkowy obs³uguj¹cy deklaruj¹cy funkcje wejœcia/wyjœcia
#include "instrukcjaObslugi.h" //Plik nag³owkowy zawieraj¹cy instrukcjê obs³ugi
#include "metodyPomocnicze.h"  // Plik nag³owkowy zawieraj¹cy funkcje szyfrowania, deszyfrowania, przygotowanie tekstu, zapis do pliku, odczyt z pliku

using namespace std;

// G³ówna pêtla zawieraj¹ca menu g³ówne
int main() 
{ 

	char wybor;

	// Wyœwietlenie instrukcji obs³ugi, aby u¿ytkownik wiedzia³ jak korzystaæ z programu
	instrukcjaObslugi();

	// Pêtla, która bêdzie dzia³aæ dopóki u¿ytkownik nie wybierze opcji "Wyjœcie z programu"
	do 
	{
		system("cls"); // Czyszczenie ekranu (komenda systemowa Windows)
		ustawKolor(11); // Ustawienie koloru na jasnoniebieski

		cout << "|---------------------------------------|" << endl;
		cout << "|           PROGRAM SZYFRATOR           |" << endl;
		cout << "|---------------------------------------|" << endl;
		cout << "|	[1] Szyfrowanie tekstu		|" << endl;
		cout << "|	[2] Deszyfracja tekstu		|" << endl;
		cout << "|	[3] Instrukcja obslugi		|" << endl;
		cout << "|	[4] Wyjscie z programu		|" << endl;
		cout << "|---------------------------------------|" << endl;
		cout << "|	  Wybierz opcje (1-4):  	|" << endl;
		cout << "|---------------------------------------|" << endl;

		wybor = _getch(); // Obs³uga wejscia bez koniecznosci klikniecia enter do wprowadzenia liczby(wyboru)

		// Pêtla switch wywo³uj¹ca menu szyfrowania, deszyfrowania, instrukcji obslugi lub wyjscia z programu
		switch (wybor) 
		{
		case '1':
			szyfrowanieTekstu();
			break;
		case '2':
			deszyfracjaTekstu();
			break;
		case '3':
			instrukcjaObslugi();
			break;
		case '4':
			cout << "Konczenie programu. Do zobaczenia!" << endl;			
			break;
		default:
			cout << "Nie ma takiej opcji! Sprobuj ponownie." << endl;
			cout << "Nacisnij dowolny klawisz, aby kontynuowac" << endl;
			system("pause > nul"); // Zatrzymuje program, aby u¿ytkownik zd¹¿y³ przeczytaæ komunikat
		}
	} 
	while (wybor != '4');

	return 0;
	
}