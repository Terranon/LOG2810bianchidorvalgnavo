#ifndef PORTE_H
#define PORTE_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

class Porte {
public:
	Porte(fstream& porte);
	~Porte();

	void genererAutomate(string nomDuFichier);
	bool validerPorte(string motDePasse);
	void verifierSiGouffre();
	bool getEstGouffre();
	vector<pair<string, pair<string, bool>>> getPorteConnecter();
	void afficherPorte();

private:
	string nom_;
	//  etat courant ----input---prochain etat
	map<char, vector<pair<char, char>>> regles_;
	// nom D'une Porte---mot de passe---validiter(true == valide, false == non-valide)
	vector<pair<string, pair<string, bool>>> portesConnectes_;
	bool estGouffre_;
};
#endif