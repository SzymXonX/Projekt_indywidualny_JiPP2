#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctime>
#include "ListaNotatek.h"


#define CLEAR system("CLS")

using namespace std;

void koniec();

int main()
{
    setlocale(LC_CTYPE, "Polish");
    //int j = 0;
    ListaNotatek bruh;
    /*
    bruh.DodajNotatke(Notatka("Pierwsza", "Notatka",j++));
    bruh.DodajNotatke(Notatka("Druga", "BRUH BRUH",j++));
    bruh.DodajNotatke(Notatka("TRZECIA", "AAAAAAAAAAAAAAAA",j++));
    bruh.DodajNotatke(Notatka("czwarta notatka kurde", "bez polskich znakow",j++));*/

    int i,k,m;
    string buff1;
    string buff2;

    while (1) {
        i = k = m = -1;
        do{
            cout << "1.Wyświetl notatki" << endl;
            cout << "2.Dodaj notatke" << endl;
            cout << "3.Zapisz" << endl;
            cout << "4.Wczytaj" << endl;
            cout << "0.Koniec" << endl;
            cin >> i;
            if (cin.fail()) {
                CLEAR;
                cin.clear();
                cin.ignore(1000, '\n');
                i = -1;
            }
            CLEAR;
        }while ((i < 0 || i>4) && (cout << "Nieprawidlowe dane\n\n"));

        switch (i) {
        case 1:
            if (bruh.getLp() == 0) {
                CLEAR;
                cout << "Brak notatek do wyświetlenia!\n\n";
                continue;
            }
            do {
                bruh.Wyswietl();
                cout << "1.Edytuj notatke" << endl;
                cout << "2.Usuń notatkę" << endl;
                cout << "0.Powrót" << endl;
                cin >> i;
                if (cin.fail()) {
                    CLEAR;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    i = -1;
                }
                CLEAR;
            } while ((i < 0 || i>4) && (cout << "Nieprawidlowe dane\n\n"));

            switch (i) {
            case 1: //edytuj notatke
                do {
                    bruh.Wyswietl();
                    cout << "Wybierz notatke do edycji: ";
                    cin >> i;
                    if (cin.fail()) {
                        CLEAR;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        i = -1;
                    }
                    CLEAR;
                } while ((i <= 0 || i > bruh.getLp()) && (cout << "Nieprawidlowe dane\n\n"));

                
                bruh.WyswietlJedna(i - 1);
                do {
                    cout << "1. Zmień zawartosc" << endl;
                    cout << "2. Dodaj do zawartosci" << endl;
                    cin >> k;
                    if (cin.fail()) {
                        CLEAR;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        k = -1;
                    }
                    CLEAR;
                } while ((k <= 0 || k > 2) && (cout << "Nieprawidlowe dane\n\n"));

                bruh.WyswietlJedna(i - 1);
                if (k == 1) {
                    do {
                        cout << "Zmień zawartość:\n1.Tytuł\n2.Tekst\n";
                        cin >> m;
                        if (cin.fail()) {
                            CLEAR;
                            cin.clear();
                            cin.ignore(1000, '\n');
                            m = -1;
                        }
                    } while ((m <= 0 || m > 2) && (cout << "Nieprawidlowe dane\n\n"));
                    CLEAR;
                    bruh.WyswietlJedna(i - 1);

                    if (m == 1) {
                        cout << "Nowy tytuł:\n";
                        getline(cin >> ws, buff1);
                        bruh.EdytujNotatke(i - 1, m, buff1);
                    }
                    else if (m == 2) {
                        cout << "Nowy tekst:\n";
                        getline(cin >> ws, buff1);
                        bruh.EdytujNotatke(i - 1, m, buff1);
                    }
                }
                //dodaj do zawartosci
                else if (k == 2) {
                    do {
                        cout << "Dodaj do zawartości:\n1.Tytuł\n2.Tekst\n";
                        cin >> m;
                        if (cin.fail()) {
                            CLEAR;
                            cin.clear();
                            cin.ignore(1000, '\n');
                            m = -1;
                        }
                    } while ((m <= 0 || m > 2) && (cout << "Nieprawidlowe dane\n\n"));
                    CLEAR;
                    bruh.WyswietlJedna(i - 1);

                    if (m == 1) {
                        cout << "Dodaj do tytułu:\n";
                        getline(cin >> ws, buff1);
                        bruh.DodajDoNotatki(i - 1, m, buff1);
                    }
                    else if (m == 2) {
                        cout << "Dodaj do tekstu:\n";
                        getline(cin >> ws, buff1);
                        bruh.DodajDoNotatki(i - 1, m, buff1);
                    }
                }
                CLEAR;
                cout << "Notatka edytowana pomyślnie!\n\n";
                continue;


            case 2: //usuń notatke
                do {
                    bruh.Wyswietl();
                    cout << "Wybierz notatke do usuniecia: ";
                    cin >> i;
                    if (cin.fail()) {
                        CLEAR;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        i = -1;
                    }
                    CLEAR;
                } while ((i <= 0 || i > bruh.getLp()) && (cout << "Nieprawidlowe dane\n\n"));

                bruh.UsunNotatke(i);
                CLEAR;
                cout << "Notatka usunieta pomyślnie!\n\n";
                continue;
            case 0: 
                break;

            }//end Wyswietl notatki
            continue;


        case 2: //dodaj notatke
            cout << "Podaj tytul: ";
            getline(cin >> ws, buff1);
            cout << "Podaj tekst: ";
            getline(cin >> ws, buff2);
            bruh.DodajNotatke(Notatka(buff1, buff2, bruh.getLp()));
            CLEAR;
            cout << "Notatka dodana pomyślnie!\n\n" << endl;
            continue;

        case 3: //zapis
            bruh.zapisz("bruh.bin");
            CLEAR;
            cout << "Dane zapisane pomyślnie!\n\n";
            continue;

        case 4: //odczyt
            if (bruh.getLp() != 0) {
                do {
                    cout << "Czy na pewno chcesz odczytać notatki?\nWszystkie aktualne zostaną usuniete i zastąpione notatkami z pliku\n";
                    cout << "1.Tak\n2.Nie\n";
                    cin >> i;
                    if (cin.fail()) {
                        CLEAR;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        i = -1;
                    }
                } while ((i <= 0 || i > 2) && (cout << "Nieprawidlowe dane\n\n"));
                if (i == 2) {
                    CLEAR;
                    continue;
                }
            }

            bruh.odczytaj("bruh.bin");
            CLEAR;
            cout << "Dane odczytane pomyślnie!\n\n";
            continue;

        case 0: //koniec
            cout << "KONIEC PROGRAMU!\n\n";
            return 0;
        }//end glowny wybor
    } //end while 1
} //end main


void koniec() {
    int i;
    do {
        cout << "\n0.Powrót" << endl;
        cin >> i;
        if (cin.fail()) {
            CLEAR;
            cin.clear();
            cin.ignore(1000, '\n');
            i = -1;
        }
    } while ((i != 0) && (cout << "Nieprawidlowe dane\n"));
    CLEAR;
}