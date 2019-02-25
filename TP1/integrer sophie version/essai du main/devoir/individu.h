#pragma once 
#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Individu {
public:
	Individu(string nom = "" ,  string cheveux = " ",string couleurYeux = " " ,string genie ="");
	Individu(const Individu& individu);

	string getCouleurYeux()const;
	string getCouleurCheveux()const;
	string getNom()const;
	string getGenie()const;
	int getValeurRelation(string nom) const;
	map<Individu*, int>& getDonneesRelation();

	void setCouleurYeux(string couleur);
	void setCouleurCheveux(string couleur);
	void setGenie(string genie);
	void setNom(string nom);
	void setRelation(Individu* voisin,int valeur_relation);

	Individu& operator=(const Individu& individu);

	friend ostream& operator<<(ostream& os, const Individu& individu);

private:
	string couleurYeux_;
	string couleurCheveux_;
	string nom_;
	string genie_;
	map<Individu*,int>relation_;//la map est constitué de paire ou la clé est le nom du voisin
};

#endif