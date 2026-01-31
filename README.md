Opis projektu
Celem projektu było stworzenie aplikacji konsolowej w języku C++, umożliwiającej
szyfrowanie i deszyfrowanie tekstu przy użyciu wybranych algorytmów kryptograficznych.
Aplikacja pozwala użytkownikowi na interaktywne wprowadzanie danych, wybór metody
działania, odczyt tekstu z pliku i zapis wyników pracy do pliku tekstowego. Główny nacisk
położono na modułowość kodu oraz zabezpieczenie przed błędnymi danymi wejściowymi.
2.
Funkcjonalności
Program oferuje następujące funkcjonalności:
• Menu główne: Prosta nawigacja tekstowa pozwalająca na wybór między
szyfrowaniem, deszyfrowaniem, instrukcją obsługi a wyjściem z programu.
• Szyfrowanie tekstu: Możliwość zaszyfrowania wiadomości przy użyciu trzech
algorytmów:
o Szyfr Cezara (przesunięcie o stałą wartość).
o Szyfr Vigenère’a (szyfrowanie wieloalfabetowe przy użyciu hasła).
o Szyfr XOR (z dostosowaniem wyników do alfabetu A-Z).
• Deszyfracja tekstu: Proces odwrotny dla wyżej wymienionych metod.
• Walidacja danych: Mechanizm sprawdzający czy wprowadzony tekst zawiera
niedozwolone znaki (mieści się w zakresie 32-126 Tabeli ASCII).
• Odczyt z pliku: możliwość odczytania tekstu z pliku w celu szyfrowania lub
deszyfrowania.
• Zapis do pliku: Możliwość zapisania odszyfrowanej i zaszyfrowanej wiadomości do
pliku tekstowego o nazwie podanej przez użytkownika.
• Instrukcja obsługi: Wbudowany moduł wyświetlający zasady korzystania z programu.
• Obsługa błędów: Zabezpieczenie przed wprowadzaniem błędnych typów danych
(np. liter zamiast liczb).
3.
Przebieg realizacji
Projekt został zrealizowany w języku C++ z wykorzystaniem paradygmatu programowania
proceduralnego. Kod został podzielony na pliki nagłówkowe (.h) w celu zwiększenia
czytelności i łatwości zarządzania projektem. Program został napisany w Visual Studio
Community 2022.
3.1.
Struktura plików
• main.cpp: Główny plik programu. Zawiera pętlę główną aplikacji oraz obsługę menu
wyboru. Odpowiada za wywoływanie odpowiednich funkcji z innych modułów.
• instrukcjaobslugi.h: Zawiera funkcję wyświetlającą pomoc oraz funkcję ustawKolor
(wykorzystującą bibliotekę windows.h do zmiany kolorów w konsoli).
• MetodyPomocniczne.cpp/ .h: Zawiera funkcje pomocnicze, które znacząco
usprawniają program. Znajduje się tam sprawdzenie tekstu i klucz pobranego przez
użytkownika, “Menu szyfrowania i deszyfrowania”, zapis do pliku i odczyt z pliku.
• Szyfrator.cpp/.h: Zawiera zaimplementowane algorytmy szyfrujące/deszyfrujące,
obsługujące znaki tabeli ASCII 32-126.
3.2.
Opis algorytmów
W projekcie zaimplementowano następujące algorytmy:
Start_ASCII = 32;
Zakres = 95;
A. Szyfr Cezara
Algorytm przesuwający każdy znak o stałą wartość klucz. W implementacji zastosowano
operację modulo, aby wynik zawsze mieścił się w zakresie liter A-Z.
Pseudokod:
Dla każdego znaku w tekście: NowyZnak = (Znak – Start_ASCII+ Klucz) % Zakres + Start_ASCII.
B. Szyfr Vigenère’a
Szyfr polialfabetyczny, gdzie przesunięcie zależy od litery słowa kluczowego.
Opis działania: Dla znaku tekstu na pozycji i oraz klucza o długości L, przesunięcie
wyznaczane jest przez znak klucza na pozycji i % L. Wzór matematyczny zastosowany w
kodzie:
Ci = (Pi +Ki) mod Zakres,
Gdzie C to szyfrogram, P to tekst jawny, a K to klucz.
C. Szyfr XOR (wariant szesnastkowy)
Standardowy XOR operuje na bitach. W tym projekcie, aby zachować czytelność,
zastosowano wariant oparty na systemie szesnastkowym. Tekst jest konwertowany na
system szesnastkowy, następnie jest wykonywana operacja XOR.
Implementacja:
Dla każdego i: Wynik += Hex( Tekst[i] ^ Klucz[i mod |Klucz|] )
3.3.
Wykorzystane biblioteki
• <iostream>: Obsługa strumieni wejścia/wyjścia.
• <conio.h>: Obsługa strumieni wejścia/wyjścia innych niż w przypadku <iostream>.
• <string>: Operacje na łańcuchach tekstowych.
• <fstream>: Obsługa zapisu/odczytu plików tekstowych.
• <windows.h>: Wykorzystana do funkcji SetConsoleTextAttribute (kolorowanie
składni) oraz czyszczenia ekranu.
• <sstream>: Biblioteka umożliwiająca konwersję liczb na ciągi znaków.
• <iomanip>: Biblioteka umożliwiająca formatowanie tekstu/wyjścia.
4. Podsumowanie i wnioski
W ramach projektu udało się zrealizować w pełni funkcjonalny szyfrator obsługujący trzy
różne metody kryptograficzne. Największym wyzwaniem była optymalizacja kodu jak i
opracowanie odpowiedniego algorytmu do szyfrowania/deszyfrowania XOR. Funkcja
sprawdzIPrzygotujTekst skutecznie eliminuje znaki spoza ustalonego zakresu zapobiega
błędom w obliczeniach modulo, co miało duże znaczenie szczególnie w deszyfrowaniu
tekstu.
Dzięki zastosowaniu podziału na pliki nagłówkowe i źródłowe kod jest czytelny i łatwy w
modyfikacji.
Możliwe kierunki rozwoju:
• Implementacja graficznego interfejsu użytkownika (GUI).
• Zaimplementowanie nowych algorytmów szyfrujących.
