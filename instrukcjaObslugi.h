//----------------------------
//@autor: Mateusz Miozga
//@data:
//@projekt: Szyfrator
//@plik: instrukcjaObslugi.h
//----------------------------

#pragma once
#include<iostream>
#include<windows.h>

using namespace std;

void ustawKolor(int kodKoloru) 
{  // Funkcja umo¿liwiaj¹ca zmianê kolorów poprzez przywo³anie jej w postaci ustawKolor(liczba) dla danego koloru
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, kodKoloru);
}

void instrukcjaObslugi() 
{ // Funkcja wyœwietlaj¹ca instrukcjê obs³ugi
	system("cls"); // Czyszczenie ekranu (komenda systemowa Windows)
	ustawKolor(9);

	cout << "|-----------------------------------------------------------------------------------------|" << endl;
	cout << "|	Instrukcje obslugi programu SZYFRATOR						  |" << endl;
	cout << "|	1. Wybierz opcje z menu.							  |" << endl;
	cout << "|	2. Wybierz metode szyfrowania/deszyfrowania.					  |" << endl;
	cout << "|	3. Wybierz czy tekst ma byc wczytany z pliku czy wprowadzony recznie.		  |" << endl;
	cout << "|	4. Wynik zostanie wyswietlony na ekranie i po zatwierdzeniu zapisany do pliku.	  |" << endl;
	cout << "|-----------------------------------------------------------------------------------------|	" << endl;
	cout << "|	Nacisnij dowolny klawisz, aby przejsc do programu.				  |" << endl;
	cout << "|-----------------------------------------------------------------------------------------|" << endl;

	system("pause > nul"); // Czeka na naciœniêcie klawisza bez wyœwietlania komunikatu systemowego

}