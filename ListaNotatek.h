#pragma once
#include "Notatka.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class ListaNotatek : public Notatka
{	
	vector<Notatka> lista;
	unsigned int lp = 0;

public:
	ListaNotatek();

	unsigned int getLp();
	void DodajNotatke(const Notatka& notatka);
	void Wyswietl();
	void WyswietlJedna(int i);
	void EdytujNotatke(int i, int j, string s);
	void DodajDoNotatki(int i, int j, string s);
	void UsunNotatke(int i);
	void zapisz(string plik);
	void odczytaj(string plik);
	void zapisz(ofstream &zapis);
	void odczytaj(ifstream &odczyt);
};

