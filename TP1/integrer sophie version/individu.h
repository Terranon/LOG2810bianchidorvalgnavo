#ifndef INDIVIDU
#define INDIVIDU

#include <iostream>
#include <string>

using namespace std;

class Individu {
public:
	Individu(const char& couleurYeux = ' ', const string& nom = "");
	Individu(const Individu& individu);

	char getCouleurYeux()const;
	string getNom()const;

	void setCouleurYeux(char couleur);
	void setNom(string nom);

	Individu& operator=(const Individu& individu);

	friend ostream& operator<<(ostream& os, const Individu& individu);

private:
	char couleurYeux_;
	string nom_;
};

#endif