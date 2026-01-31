//----------------------------
//@autor: Mateusz Miozga
//@data:
//@projekt: Szyfrator
//@plik: metodyPomocnicze.h
//----------------------------


#pragma once
#include <iostream>
#include <string>
using namespace std;
char pobierzZnak();

// Funkcja pomocnicza, przygotowywuj¹ca tekst do szyfrowania lub deszyfrowania. Funkcja zwraca wartoœæ "False", gdy tekst jest pusty lub zawiera niew³aœciwe znaki
//  oraz sprawdza czy znak mieœci siê w zakresie ASCII 'A'-'Z'.
bool sprawdzIPrzygotujTekst(string& tekst); 

//Funkcja pomocnicza, która pobiera klucz od u¿ytkownika z obs³ug¹ b³êdów, przekazuje tekst do Funkcji 'sprawdzIPrzygotujTekst'. Poprawiony przez funkcje zwraca tekst lub pusty string w przypadku anulowania.
string pobierzKlucz(string komunikat);

// Funkcja pobiera tekst od u¿ytkownika z obs³ug¹ b³êdów, przekazuje tekst do Funkcji 'sprawdzIPrzygotujTekst'. Poprawiony przez funkcje zwraca tekst lub pusty string w przypadku anulowania.
string pobierzTekstOdUzytkownika(string komunikat);

// Funkcja pobiera 'klucz' od u¿ytkownika z obs³ug¹ b³êdów, przekazuje 'klucz' do Funkcji 'sprawdzIPrzygotujTekst'. Poprawiony przez funkcje zwraca 'klucz' lub pusty string w przypadku anulowania.
string pobierzKlucz(string komunikat);

// Funkcja zapisujaca tekst odszyfrowany, zaszyfrowany do pliku
void zapiszDoPliku(string tekstJawny, string tekstZaszyfrowany);

// Funkcja odczytujaca tekst do deszyfrowania, szyfrowania
string odczytZPliku(string nazwaPliku);

// 'Menu' szyfrowania
void szyfrowanieTekstu();

// 'Menu' deszyfrowania
void deszyfracjaTekstu();
