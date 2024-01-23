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
	//Data data;

public:
	Notatka();
	Notatka(string tytul, string tekst, unsigned int lp);
	void setTytul(string tytul);
	void setTekst(string tekst);
	void setLp(unsigned int lp);
	string getTytul();
	string getTekst();
	friend ofstream& operator<<(ofstream& zapis, Notatka notatka);
	friend ostream& operator<<(ostream& wyjscie, const Notatka notatka);
};

