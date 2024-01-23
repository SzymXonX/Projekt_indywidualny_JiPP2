#include "Notatka.h"

Notatka::Notatka(){}

Notatka::Notatka(string tytul, string tekst, unsigned int lp) : Data(){
	this->tytul = tytul;
	this->tekst = tekst;
	this->lp = lp;
}

void Notatka::setTytul(string tytul)
{
	this->tytul = tytul;
}

void Notatka::setTekst(string tekst)
{
	this->tekst = tekst;
}


void Notatka::setLp(unsigned int lp)
{
	this->lp = lp;
}

string Notatka::getTytul()
{
	return tytul;
}

string Notatka::getTekst()
{
	return tekst;
}



ofstream& operator<<(ofstream& zapis, Notatka notatka)
{

	string tytul = notatka.getTytul();
	int tytulRozmiar = tytul.size();
	char* temp = reinterpret_cast<char*>(&tytulRozmiar);
	zapis.write(temp, sizeof(tytulRozmiar));
	zapis.write(tytul.data(), tytulRozmiar);

	string tekst = notatka.getTekst();
	int tekstRozmiar = tekst.size();
	temp = reinterpret_cast<char*>(&tekstRozmiar);
	zapis.write(temp, sizeof(tekstRozmiar));
	zapis.write(tekst.data(), tekstRozmiar);

	time_t czas = notatka.getData();
	zapis.write(reinterpret_cast<char*>(&czas), sizeof(time_t));

	return zapis;
}

ostream& operator<<(ostream& wyjscie, Notatka notatka)
{
	time_t time = notatka.getData();
	char timeString[size("yyyy-mm-ddThh:mm:ssZ")];
	strftime(std::data(timeString), size(timeString),
		"%F  %T", gmtime(&time));
	cout << timeString << '\n';
	
	return wyjscie << "Notatka [" << (notatka.lp + 1) << "]: " << "\nT: " << notatka.tytul << endl << notatka.tekst << endl << endl;
}
