
#pragma once
#ifndef RESEAUSOCIAUX_H
#define RESEAUSOCIAUX_H

#include <iostream>
#include <string>
#include <vector>
#include "individu.h"

using namespace std;
class reseauSociaux {

public:
	reseauSociaux();
	void creerReseauSocial(string fichier1, string fichier2);
	void afficherReseauSocial();
	vector<Individu*> lirefichiertexte(string nomfichier);
private:
	vector<Individu*>table_Individu;

};
#endif