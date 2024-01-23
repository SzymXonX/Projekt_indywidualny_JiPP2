#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include "Data.h"

using namespace std;

class Notatka: public Data
{
	unsigned int lp;
	string tytul;
	string tekst;
	Data data;

public:
	Notatka();
	Notatka(string tytul, string tekst, unsigned int lp);
	void PokazNotatke();
	void setTytul(string tytul);
	void setTekst(string tekst);
	void setData(time_t czas);
	void setLp(unsigned int lp);
	void zapisz(ofstream& zapis);
	string getTytul();
	string getTekst();
	friend ofstream& operator<<(ofstream& zapis, Notatka notatka);
};

