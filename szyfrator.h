//----------------------------
//@autor: Mateusz Miozga
//@data:
//@projekt: Szyfrator
//@plik: szyfrator.h
//----------------------------

#pragma once
#include <iostream>
#include <string>

using namespace std;

//----------------------------------------------------------------
// --- Logika algorytmów ---

// Szyfrowanie Cezara: wykorzystuje przesuniecie alfabetu o klucz podany przez u¿ytkownika.
// Tekst - tekst jawny, który u¿ytkownik chce zaszyfrowaæ.
// Klucz - przesuniêcie o klucz alfabetu, klucz podany przez u¿ytkownika.
// Return tekst - zwrócenie zaszyfrowanej wiadomoœci.
// Normalizacja klucza (Ogranicznie do wielkosci tabeli ASCII, obs³uga liczb ujemnych).
// Wzór: C = (P - 'A' + K) % 95 + pierwsza liczbê ob³s³ugiwana (32 - w tabeli ASCII).
// Odejmujemy 32 aby operowaæ na liczbach 32-126, dodajemy 32 by wróciæ do ASCII.
string szyfrujCezar(string tekst, int klucz);
   
//-------------------------------------------------------------------------------------

// Szyfrowanie XOR: (wersja HEX): wykonuje operacjê XOR, a wynik zapisuje szesnastkowo.
// Zamiana na HEX jest konieczna, aby unikn¹æ znaków niedrukowalnych i b³êdów zapisu w pliku.
// Tekst - tekst jawny.
// Klucz - tekst u¿ywany jako maska bitowa.
// Return Wynik - zwraca string wynik - zaszyfrowana wiadomoœæ.
// Wykonanie XOR (alternatywa wykluczaj¹ca).
string szyfrujXOR(string tekst, string klucz);   

//-------------------------------------------------------------------------------------

// Szyfrowanie Vigenere:  polialfabetyczny szyfr podstawieniowy.
// Wzór Vigenere: C = (P + K) % 95
// Tekst - tekst jawny.
// Klucz - sk³adajacy siê z liter alfabetu(np. jakieœ s³owo).
// Return Wynik - zwraca string wynik - zaszyfrowana wiadomoœæ.
string szyfrujVigenere(string tekst, string klucz);

// ------------------------------------------------------------------------------------ 
// --- Logika algorytmów deszyfruj¹cych ---

// Deszyfrowanie Cezara: przesuwa tekst niejawny o klucz (odejmowanie klucza).
// Wzór: D = (C - K + 95) % 95.
// Dodajemy 95 przed modulo, aby unikn¹æ wartoœci ujemnych.  
string deszyfrujCezar(string tekst, int klucz);

// ------------------------------------------------------------------------------------

// Deszyfrowanie XOR: odczytuje pary znaków HEX, zamienia je na bajty i wykonuje XOR.
// Szyfrogram - ci¹g znaków w formacie szesnastkowym.
// Klucz - ten sam tekst, który zosta³ u¿yty do szyfrowania.
// Zwraca wynik - odtworzony tekst jawny.
string deszyfrujXOR(string szyfrogram, string klucz);

// ------------------------------------------------------------------------------------

// Deszyfrowanie Vigenere'a : wymaga odjêcia wartoœci klucza od szyfrogramu modulo 95.
// Matematyka: P = (Tekst - Klucz + 95) % 95.
// Dodajemy 95, poniewa¿ w C++ wynik operacji modulo na liczbie ujemnej.
// mo¿e byæ ujemny (np. -5 % 95 = -5), a potrzebujemy indeksu tablicy (32-126).
string deszyfrujVigenera(string szyfrogram, string klucz);  
