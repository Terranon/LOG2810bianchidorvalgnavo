#ifndef PORTE_H
#define PORTE_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Porte {
public:
	Porte(fstream& porte);
	~Porte();

	void genererAutomate();
	bool validerPorte(string motDePasse);
	bool getEstGouffre();

private:
	string nom_;
	//  etat courant --------input---prochain etat
	map<string, vector<pair<string, string>>> regles_;
	// nom D'une Porte---mot de passe---validiter(true == valide, false == non-valide)
	vector<pair<string, pair<string, bool>>> portesConnectes_;
	bool estGouffre_;
};
#endif