//----------------------------
//@autor: Mateusz Miozga
//@data:
//@projekt: Szyfrator
//@plik: metodyPomocnicze.cpp
//----------------------------

#include <iostream>
#include <string> 
#include <windows.h>
#include <fstream> 
#include <conio.h>
#include "metodyPomocnicze.h" 
#include "szyfrator.h" 

using namespace std;

// Funkcja pobiera jeden znak z klawiatury bez czekania na enter
char pobierzZnak() 
{
    char znak = _getch(); // Pobranie znaku bezposrednio z konsoli
    return toupper(znak);
}

// Sprawdza czy tekst zawiera tylko dozwolone znaki (ASCII 32-126)
bool sprawdzIPrzygotujTekst(string& tekst) 
{
    if (tekst.empty()) 
    {
        return false;
    }
    for (size_t i = 0; i < tekst.length(); i++) 
    {
        // Zakres 32 (spacja) - 126 (~)
        if (tekst[i] < 32 || tekst[i] > 126) 
        {
            return false;
        }        
    }
    return true;
}

// Funkcja pomocnicza do pobierania i walidacji klucza
string pobierzKlucz(string komunikat)
{
    string klucz;
    char decyzja;
    while (true)
    {
        cout << komunikat;
        
        // Jeœli w buforze wejœcia zosta³ znak nowej linii (np. po poprzednim cin >>),
        // usuwamy go, aby getline() nie pobra³ pustego napisu.
        if (cin.peek() == '\n') cin.ignore(1000, '\n'); 
        getline(cin, klucz);

        if (sprawdzIPrzygotujTekst(klucz))
        {
            return klucz;
        }

        cout << "\t [!] BLAD: Klucz pusty lub zawiera niedozwolone znaki!" << endl;
        cout << "\t [?] Chcesz sprobowac ponownie? (t - tak, n - anuluj): ";
        decyzja = pobierzZnak();
        cout << endl;

        if (decyzja == 'N')
        {
            return "";
        }
    }
}

string odczytZPliku(string nazwaPliku) 
{          
    fstream plik(nazwaPliku, ios::in); // Otwarcie pliku tylko do odczytu

    if (plik.good()) // Metoda good() sprawdza, czy plik istnieje i czy jesto do niego dostep
    {
        string tekst = "";
        string linia;
        while (getline(plik, linia)) // Plik czytany linijka po linijce az do konca pliku
        {            
            if (!tekst.empty())
            {
                tekst += " "; // Rozdzielenie miedzy liniami
            }
            tekst += linia;
        }
        plik.close(); // Zamkniecie pliku

        return tekst;
    }
    else 
    {
        cerr << "Blad: Nie udalo sie otworzyc pliku!" <<endl;
    }   
    return "";
}

string pobierzTekstOdUzytkownika(string komunikat) 
{
    string tekst;
    char wybor;

    cout << "[?] Czy chcesz odczytac tekst z pliku? (t - tak, n - nie): ";
    wybor = pobierzZnak();
    cout << endl; 

    // Opcja 1: Odczyt z pliku
    if (wybor == 'T') 
    {
        string nazwaPliku;      
        cout << "Podaj nazwe pliku (w formacie 'nazwaPliku.txt'): ";
        getline(cin, nazwaPliku);

        if(nazwaPliku != "")
        {
            tekst = odczytZPliku(nazwaPliku); 
            
            // Walidujemy tekst z pliku. Jeœli zawiera niedozwolone znaki, odrzucamy go.
            if (sprawdzIPrzygotujTekst(tekst)) 
            {
                cout << "[OK] Wczytano i zweryfikowano tekst z pliku." << endl;
                return tekst;
            }
            
            cout << "[!] BLAD PLIKU: Plik jest pusty, nie istnieje lub zawiera niedozwolone znaki (np. enter, polskie znaki)." << endl;
            cout << "[!] Przechodzenie do trybu wprowadzania recznego." << endl;
        }
    }

    // Opcja 2: Wpisywanie rêczne
    char decyzja;
    while (true)
    {
        cout << komunikat;
        
        if (cin.peek() == '\n')
        {
            cin.ignore(1000, '\n');
        }
        getline(cin, tekst);

        if (sprawdzIPrzygotujTekst(tekst)) // Sprawdzenie czy tekst sie miesci w zakresie ASCII.
        {
            break;
        }

        if (tekst.empty()) // Obsluga bledu pustego tekstu
        {
            cout << "\t [!] Tekst nie moze byc pusty!" << endl;
        } 
        else 
        {
            cout << "\t [!] BLAD: Tekst zawiera niedozwolone znaki!" << endl;
        }
        
        cout << "\t [?] Chcesz sprobowac ponownie? (t - tak, n - anuluj): ";
        decyzja = pobierzZnak();        
        cout << endl;
        tekst = "";
        if (decyzja == 'N')
        {
            break;
        }
    }
    return tekst;
}

void zapiszDoPliku(string tekstJawny, string tekstZaszyfrowany)
{
    char wybor;
    cout << "[?] Czy chcesz zapisac wynik do pliku? (t - tak, n - nie): ";
    wybor = pobierzZnak();
    cout << endl;

    if (wybor == 'T') 
    {
        string nazwaPliku;
        cout << "Podaj nazwe pliku (w formacie 'nazwaPliku.txt'): ";
        cin >> nazwaPliku;
        ofstream plik(nazwaPliku, ios::app); // ios::app(append) - dopisuje tresc na koncu pliku, zamiast nadpisywac
        if (plik.is_open()) 
        {
            plik << tekstZaszyfrowany << endl; // zapis wyniku do pliku
            
            plik.close();
            cout << "[OK] Zapisano!" << endl;
        }
        else 
        {
            cout << "[!] Blad otwarcia pliku." << endl;
        }
    }
}

void szyfrowanieTekstu()
{
    system("cls"); // Wyczyszczenie konsoli dla czytelnosci
    string tekst, klucz, wynik;
    char metoda{};

    // Wyswietlenie opcji
    cout << "\t === Szyfrowanie tekstu ===" << endl;
    cout << "[!] Dozwolone znaki ASCII (litery, cyfry, spacje, symbole)." << endl;
    // Wywo³anie funkcji, która obs³uguje ca³¹ logikê pobierania (plik lub klawiatura)
    tekst = pobierzTekstOdUzytkownika("Podaj tekst do zaszyfrowania: ");
    if (tekst == "") // jesli uzytkownik anulowal -> powrot do menu glownego
        return;
    cout << "Podaj metode: [1] -> Cezar   [2] -> XOR   [3] -> Vigenere'a " << endl;
    
    metoda = _getch();

    switch (metoda)
    {
        case '1': // Cezar
        {   
            int kluczCezar;
            cout << "Podaj przesuniecie (liczba): ";
            cin >> kluczCezar;
            while (cin.fail()) // Obsluga bledu, gdy uzytkownik wpisze litere zamiast liczby
            { 
                cin.clear(); // Czysci flage bledu strumienia
                cin.ignore(1000, '\n'); // Usuwa bledne dane z bufora
                cout << endl << "[!] Blad! Wprowadzono litere!";
                cout << endl << "Podaj przesuniecie (liczba): ";
                cin >> kluczCezar;
            }
            wynik = szyfrujCezar(tekst, kluczCezar);
            break;
        }
        case '2': // XOR
        {
            klucz = pobierzKlucz("Podaj klucz (tekst): "); // Dla XOR klucz jest tekstem/napisem
            if (klucz == "")
               return;
            wynik = szyfrujXOR(tekst, klucz);
            break;
        }
        case '3': // Vigenere
        {
            klucz = pobierzKlucz("Podaj klucz (tekst): "); // Dla Vigener'a klucz jest tekstem/napisem
            if (klucz == "") 
                return;
            wynik = szyfrujVigenere(tekst, klucz);
            break;
        }
        default: 
        {
            cout << "[!] Nieznana metoda!" << endl;
            cout << "[?] Chcesz sprobowac ponownie? (t - tak, n - anuluj): ";
            char decyzja = pobierzZnak();
            cout << endl;

            if (decyzja == 'N')
                return;
            else if (decyzja == 'T')
            {
                szyfrowanieTekstu();
            }
            return;
        }
    }
    
    cout << "-> Zaszyfrowana wiadomosc: " << wynik << endl;
    
    zapiszDoPliku(tekst, wynik);
    
    cout << endl << "Nacisnij dowolny klawisz, aby kontynuowac...";
    system("pause > nul");
}

// Menu deszyfrowania wyglada analogicznie jak w przypadku szyfrowania
void deszyfracjaTekstu() 
{
    system("cls");
    string tekst, klucz, wynik;
    char metoda;
    // Wyswietlenie opcji
    cout << "\t === Deszyfrowanie tekstu ===" << endl;
    cout << "[!] Dozwolone znaki ASCII (litery, cyfry, spacje, symbole)." << endl;
    // Wywo³anie funkcji, która obs³uguje ca³¹ logikê pobierania (plik lub klawiatura)
    tekst = pobierzTekstOdUzytkownika("Podaj tekst do odszyfrowania: ");
    if (tekst == "") // jesli uzytkownik anulowal -> powrot do menu glownego
        return;
    cout << "Podaj metode: [1] -> Cezar   [2] -> XOR   [3] -> Vigenere'a " << endl;

    metoda = _getch();

    switch (metoda) 
    {
        case '1': // Cezar        

            int kluczCezar;
            cout << "Podaj przesuniecie:  (liczba) "; 
            cin >> kluczCezar;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << endl << "[!] Blad! Wprowadzono litere! ";
                cout << endl << "Podaj przesuniecie:  (liczba) ";
                cin >> kluczCezar;
            }
            wynik = deszyfrujCezar(tekst, kluczCezar);
            break;

        case '2': // XOR
            klucz = pobierzKlucz("Podaj klucz: ");
            if (klucz == "") return;
            wynik = deszyfrujXOR(tekst, klucz);
            break;

        case '3': // Vigenere'a
            klucz = pobierzKlucz("Podaj klucz: ");
            if (klucz == "") return;
            wynik = deszyfrujVigenera(tekst, klucz);
            break;

        default: // Zabezpiecznie przed wprowadzniem bledu
        {
            cout << "[!] Nieznana metoda!" << endl;
            cout << "[?] Chcesz sprobowac ponownie? (t - tak, n - anuluj): ";
            char decyzja = pobierzZnak();
            cout << endl;

            if (decyzja == 'N')
                return;
            else if (decyzja == 'T')
            {
                deszyfracjaTekstu();
            }

            return;
        }
    }

    cout << "-> Odszyfrowana wiadomosc: " << wynik << endl;

    zapiszDoPliku(tekst, wynik); 

    cout << endl << "Nacisnij dowolny klawisz, aby kontynuowac...";
    system("pause > nul");
}