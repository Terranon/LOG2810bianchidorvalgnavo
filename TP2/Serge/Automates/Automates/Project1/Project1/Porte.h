#ifndef PORTE_H
#define PORTE_H

#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class Porte {
public:
	Porte(fstream& porte);
	Porte();
	~Porte();

	void genererAutomate(string nomDuFichier);
	void lirefichier(string nomFichier);
	bool validerPorte(string motDePasse);
	void verifierSiGouffre();
	//getter
	bool getEstGouffre();
	vector<pair<string, pair<string, bool>>> getportesConnectes() { return portesConnectes_; };
	string getmotentree() { return motentree_; };

private:
	string nom_;
	//  etat courant ----input---prochain etat
	map<char, vector<pair<char, char>>> regles_;
	// nom D'une Porte---mot de passe---validiter(true == valide, false == non-valide)
	vector<pair<string, pair<string, bool>>> portesConnectes_;
	bool estGouffre_;
	string motentree_;
};
#endif