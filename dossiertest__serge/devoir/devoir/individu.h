#ifndef INDIVIDU
#define INDIVIDU

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Individu {
public:
	Individu(string nom = "" ,  char cheveux = ' ',char couleurYeux = ' ' ,string genie ="");
	Individu(const Individu& individu);

	char getCouleurYeux()const;
	char getCouleurCheveux()const;
	string getNom()const;
	string getGenie()const;
	int getValeurRelation(string nom) const;
	map<Individu*, int>& getDonneesRelation();

	void setCouleurYeux(char couleur);
	void setCouleurCheveux(char couleur);
	void setGenie(string genie);
	void setNom(string nom);
	void setRelation(Individu* voisin,int valeur_relation);

	Individu& operator=(const Individu& individu);

	friend ostream& operator<<(ostream& os, const Individu& individu);

private:
	char couleurYeux_;
	char couleurCheveux_;
	string nom_;
	string genie_;
	map<Individu*,int>relation_;//la map est constitué de paire ou la clé est le nom du voisin
};

#endif