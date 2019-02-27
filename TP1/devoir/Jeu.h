#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "individu.h"
#include <fstream>

using namespace std;

class Jeu {
public:
	
	Jeu();

	vector<Individu*>gettableauIndividu() const;

	char selectionneroption();
	void creerReseauSocial(string nomfichier1, string nomfichier2);
	void validerlecturefichier(string fichier1, string fichier2);

	void lirefichierdanstable(string nomfichier);
	
	void afficherReseauSocial();


private:
	bool resultat;
	vector <Individu*> tableIndividus_;
};