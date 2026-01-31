//----------------------------
//@autor: Mateusz Miozga
//@data:
//@projekt: Szyfrator
//@plik: szyfrator.cpp
//----------------------------

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "szyfrator.h"

using namespace std;

const int START_ASCII = 32; // Pierwszy znak od ktorego szyfrujemy(spacja)
const int ZAKRES = 95; // Zakres szyfrowania (spacja) - (~)

// Szyfrowanie Cezara
string szyfrujCezar(string tekst, int klucz) 
{
    // Normalizacja klucza do zakresu [0, ZAKRES-1] - dziala tez dla ujemnych
    klucz = (klucz % ZAKRES + ZAKRES) % ZAKRES; 
    
    for (size_t i = 0; i < tekst.length(); i++) 
    {
        tekst[i] = (tekst[i] - START_ASCII + klucz) % ZAKRES + START_ASCII;
    }
    return tekst;
}

// Szyfrowanie XOR - WERSJA HEX
// Zamienia wynik na zapis szesnastkowy (bezpieczny dla plikow i konsoli)
string szyfrujXOR(string tekst, string klucz) 
{ 
    if (klucz.empty()) 
    {
        return tekst;
    }
    
    stringstream ss;
    // Ustawienia formatowania
    ss << hex << uppercase << setfill('0');

    for (size_t i = 0; i < tekst.length(); i++) 
    {
        // Pobieramy surowy bajt znaku i klucza 
        unsigned char znakTekstu = (unsigned char)tekst[i];
        unsigned char znakKlucza = (unsigned char)klucz[i % klucz.length()];
        
        // Czysty XOR
        unsigned char wynik = znakTekstu ^ znakKlucza;

        // Zapisujemy jako 2 znaki Hex (np. A5)
        ss << setw(2) << (int)wynik;
    }
    return ss.str();
}

// Szyfrowanie Vigener'a
string szyfrujVigenere(string tekst, string klucz) 
{ 
    if (klucz.empty()) 
    {
        return tekst;
    }
    string wynik = "";
    for (size_t i = 0; i < tekst.length(); i++) 
    {
        int ptekst = tekst[i] - START_ASCII;
        int pklucz = klucz[i % klucz.length()] - START_ASCII;
        
        wynik += (char)((ptekst + pklucz) % ZAKRES + START_ASCII);
    }
    return wynik;
}

// Deszyfrowanie Cezara
string deszyfrujCezar(string tekst, int klucz) 
{
    int przesuniecie = (klucz % ZAKRES + ZAKRES) % ZAKRES;
    for (size_t i = 0; i < tekst.length(); i++) 
    {
        // Odejmujemy przesuniecie. Dodajemy ZAKRES, zeby uniknac liczb ujemnych przed modulo.
        tekst[i] = (tekst[i] - START_ASCII - przesuniecie + ZAKRES) % ZAKRES + START_ASCII;
    }
    return tekst;
}

// Deszyfrowanie XOR - WERSJA HEX
// Odczytuje zapis szesnastkowy i przywraca oryginalny tekst
string deszyfrujXOR(string szyfrogram, string klucz) 
{
    if (klucz.empty()) 
    {
        return szyfrogram;
    }
    
    string wynik = "";
    // Iterujemy co 2 znaki, poniewaz kazdy bajt to 2 znaki Hex (np. F4)
    for (size_t i = 0; i < szyfrogram.length(); i += 2) 
    {
        // Zabezpieczenie przed wyjsciem poza zakres
        if (i + 1 >= szyfrogram.length()) break; 

        string hexByte = szyfrogram.substr(i, 2);
        
        // Konwersja Hex -> Liczba
        unsigned char c = (unsigned char)stoi(hexByte, nullptr, 16);
        unsigned char k = (unsigned char)klucz[(i / 2) % klucz.length()];

        // Odszyfrowanie XOR
        char z = c ^ k;
        wynik += z;
    }
    return wynik;
}

// Deszyfrowanie Vigener'a
string deszyfrujVigenera(string szyfrogram, string klucz) 
{
    if (klucz.empty()) 
    {
        return szyfrogram;
    }
    string tekst = "";
    for (size_t i = 0; i < szyfrogram.length(); i++) 
    {
        int c = szyfrogram[i] - START_ASCII;
        // POPRAWKA: Usunieto toupper(), aby zgadzalo sie z szyfrowaniem
        int k = klucz[i % klucz.length()] - START_ASCII;
        
        // Logika odwrotna: (Szyfrogram - Klucz)
        int w = (c - k + ZAKRES) % ZAKRES;
        tekst += (char)(w + START_ASCII);
    }
    return tekst;
}