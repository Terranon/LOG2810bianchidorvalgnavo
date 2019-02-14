#ifndef INDIVIDU
#define INDIVIDU

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Individu {
public:
	Individu(string nom = "" ,  char cheveux = ' ',char couleurYeux = ' ' ,string genie ="");
	Individu(const Individu& individu);

	char getCouleurYeux()const;
	char getCouleurCheveux()const;
	string getNom()const;
	string getGenie()const;

	void setCouleurYeux(char couleur);
	void setCouleurCheveux(char couleur);
	void setGenie(string genie);
	void setNom(string nom);
	void setVoisin(Individu& voisin);

	Individu& operator=(const Individu& individu);

	friend ostream& operator<<(ostream& os, const Individu& individu);

private:
	char couleurYeux_;
	char couleurCheveux_;
	string nom_;
	string genie_;
	vector<Individu>voisin_;
};

#endif