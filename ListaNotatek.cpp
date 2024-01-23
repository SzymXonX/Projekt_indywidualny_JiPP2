#include "ListaNotatek.h"

ListaNotatek::ListaNotatek(){}

unsigned int ListaNotatek::getLp()
{
	return lp;
}

void ListaNotatek::DodajNotatke(const Notatka& notatka)
{
	lista.push_back(notatka);
	lp++;
}

void ListaNotatek::Wyswietl()
{
	for (int i = 0; i < lp; i++) {
		lista.at(i).PokazNotatke();
	}
}

void ListaNotatek::WyswietlJedna(int i)
{
	lista.at(i).PokazNotatke();
}

void ListaNotatek::EdytujNotatke(int i, int j, string s)
{
	if (j == 1) {
		lista.at(i).setTytul(s);
	}
	else if (j == 2) {
		lista.at(i).setTekst(s);
	}
}

void ListaNotatek::DodajDoNotatki(int i, int j, string s)
{
	if (j == 1) {
		lista.at(i).setTytul(lista.at(i).getTytul() + " " + s);
	}
	else if (j == 2) {
		lista.at(i).setTekst(lista.at(i).getTekst() + "\n" + s);
	}
}

void ListaNotatek::UsunNotatke(int i)
{
	lista.erase(lista.begin() + (--i));
	lp--;
	for (int j = 0; j < lp; j++) {
		lista.at(j).setLp(j);
	}
}

void ListaNotatek::zapisz(string plik)
{
	ofstream zapis(plik, ios_base::binary);
	if (!zapis.is_open()) {
		cout << "B³¹d otwarcia pliku!\n";
	}
	else zapisz(zapis);
}

void ListaNotatek::odczytaj(string plik)
{
	if (lp > 0) {
		//lista.erase(lista.begin(), lista.begin()+lp);
		lista.clear();
	}
	ifstream odczyt(plik, ios_base::binary);
	if (!odczyt.is_open()) {
		cout << "B³¹d otwarcia pliku!\n";
	}
	else odczytaj(odczyt);
}


void ListaNotatek::zapisz(ofstream& zapis)
{
	char* temp;
	temp = reinterpret_cast<char*>(&lp);
	zapis.write(temp, sizeof(unsigned int));
	for (int i = 0; i < lp; i++) {
		zapis << lista[i];
	}
}

void ListaNotatek::odczytaj(ifstream& odczyt)
{
	time_t czas;
	char bufor[512];
	int rozmiarTytul, rozmiarTekst;
	odczyt.read(bufor, sizeof(unsigned int));
	lp = *reinterpret_cast<int*>(bufor);

	for (int i = 0; i < lp; i++) {
		odczyt.read(bufor, sizeof(int));
		rozmiarTytul = *reinterpret_cast<int*>(bufor);
		odczyt.read(bufor, rozmiarTytul);
		string tytul(bufor, rozmiarTytul);

		odczyt.read(bufor, sizeof(int));
		rozmiarTekst = *reinterpret_cast<int*>(bufor);
		odczyt.read(bufor, rozmiarTekst);
		string tekst(bufor, rozmiarTekst);

		odczyt.read(bufor, sizeof(time_t));
		czas = *reinterpret_cast<time_t*>(bufor);
		lista.push_back(Notatka(tytul, tekst, i));
		lista.at(i).setData(czas);
	}
}
