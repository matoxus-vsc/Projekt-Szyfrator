# 🔐 Szyfrator

> *Konsolowa aplikacja w C++ do szyfrowania i deszyfrowania tekstu trzema klasycznymi algorytmami.
> Juliusz Cezar byłby dumny. NSA raczej nie.*

![C++](https://img.shields.io/badge/language-C%2B%2B-00599C?logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/platform-Windows-0078D6?logo=windows&logoColor=white)
![IDE](https://img.shields.io/badge/Visual%20Studio-Community-5C2D91?logo=visualstudio&logoColor=white)

---

## 📖 Opis projektu

Celem projektu było stworzenie aplikacji konsolowej w języku **C++**, umożliwiającej
**szyfrowanie i deszyfrowanie tekstu** przy użyciu wybranych algorytmów kryptograficznych.

Aplikacja pozwala na interaktywne wprowadzanie danych, wybór metody działania, odczyt tekstu
z pliku oraz zapis wyników do pliku tekstowego. Główny nacisk położono na **modułowość kodu**
oraz **zabezpieczenie przed błędnymi danymi wejściowymi**.

## ✨ Funkcjonalności

| | Funkcja | Opis |
|---|---|---|
| 🧭 | **Menu główne** | Prosta nawigacja klawiszami `1`–`4`, bez potrzeby wciskania Enter |
| 🔒 | **Szyfrowanie** | Trzy algorytmy do wyboru: Cezar, XOR, Vigenère |
| 🔓 | **Deszyfrowanie** | Proces odwrotny dla każdej z metod |
| 📂 | **Odczyt z pliku** | Tekst można wczytać z pliku `.txt` zamiast wpisywać ręcznie |
| 💾 | **Zapis do pliku** | Wynik można dopisać do pliku o dowolnej nazwie |
| 🛡️ | **Walidacja danych** | Akceptowane są tylko znaki ASCII z zakresu **32–126** |
| ⚠️ | **Obsługa błędów** | Ochrona przed błędnym typem danych (np. litery zamiast liczby) z opcją ponowienia |
| 📘 | **Instrukcja obsługi** | Wbudowana pomoc dostępna z poziomu menu |
| 🎨 | **Kolorowa konsola** | Bo czarno-biały terminal jest smutny |

## 🧮 Algorytmy

Wszystkie algorytmy działają na **95 drukowalnych znakach ASCII** (od spacji `32` do `~` `126`),
więc szyfrują nie tylko litery, ale też cyfry, spacje i symbole.

### 🏛️ Szyfr Cezara
Każdy znak przesuwany jest o stałą wartość (klucz liczbowy). Obsługuje też klucze ujemne.

$$C = (P - 32 + K) \bmod 95 + 32$$

### ⚡ Szyfr XOR
Operacja bitowa XOR między znakiem tekstu a znakiem klucza. Klucz jest powtarzany,
jeśli jest krótszy od tekstu.

$$C = \big((P - 32) \oplus (K - 32)\big) \bmod 95 + 32$$

### 🔑 Szyfr Vigenère'a
Polialfabetyczny szyfr podstawieniowy, czyli Cezar z innym przesunięciem dla każdego znaku,
wyznaczanym przez kolejne litery hasła.

$$C = (P + K) \bmod 95 \qquad P = (C - K + 95) \bmod 95$$

## 🖥️ Jak to wygląda

```
|---------------------------------------|
|           PROGRAM SZYFRATOR           |
|---------------------------------------|
|       [1] Szyfrowanie tekstu          |
|       [2] Deszyfracja tekstu          |
|       [3] Instrukcja obslugi          |
|       [4] Wyjscie z programu          |
|---------------------------------------|
|         Wybierz opcje (1-4):          |
|---------------------------------------|
```

## 🚀 Uruchomienie

**Wymagania:** Windows + Visual Studio Community z workloadem *Desktop development with C++*.

1. Sklonuj repozytorium lub pobierz ZIP
2. Otwórz plik `Projekt Szyfratpr2.slnx`
3. Naciśnij **Ctrl+F5**
4. Szyfruj sekrety 🤫

## 📁 Struktura plików

```
📦 Projekt-Szyfrator
 ┣ 📜 main.cpp               → pętla główna i menu programu
 ┣ 📜 instrukcjaObslugi.h    → instrukcja obsługi + kolory konsoli (windows.h)
 ┣ 📜 szyfrator.h / .cpp     → implementacja algorytmów szyfrujących i deszyfrujących
 ┣ 📜 metodyPomocnicze.h/.cpp→ walidacja, odczyt/zapis plików, obsługa menu szyfrowania
 ┗ 📄 plik.txt, plik2.txt    → przykładowe pliki testowe
```

Projekt zrealizowano w paradygmacie **programowania proceduralnego**. Kod podzielono na moduły
(pliki `.h` / `.cpp`) dla lepszej czytelności i łatwiejszego zarządzania.

## ⚠️ Disclaimer

> [!CAUTION]
> To projekt edukacyjny. Szyfry Cezara, XOR z krótkim kluczem i Vigenère'a da się złamać
> w kilka minut (a Cezara w kilka sekund). **Nie szyfruj nimi haseł do banku.** 🙃

---

<p align="center">
  Autor: <b>Mateusz Miozga</b> · napisane w Visual Studio Community
</p>
