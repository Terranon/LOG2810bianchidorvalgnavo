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
	Porte(string porte);
	~Porte();

	void genererAutomate(string nomDuFichier);
	bool validerPorte(string motDePasse);
	void verifierSiGouffre();
	bool getEstGouffre();
	map<char, vector<pair<char, char>>> getRegle();
	void lireFichierBoss(string nomFichier);
	void affronterBoss(vector<Porte*> chemin);
	bool getBossVaincu();
	vector<pair<string, pair<string, bool>>> getPorteConnecter();
	void afficherPorte();
	void afficherBoss();

private:
	string nom_;
	//  etat courant ----input---prochain etat
	map<char, vector<pair<char, char>>> regles_;
	// nom D'une Porte---mot de passe---validiter(true == valide, false == non-valide)
	vector<pair<string, pair<string, bool>>> portesConnectes_;
	bool bossVaincu;
	bool estGouffre_;
	vector<string> portesBoss;//Liste des portes dans le fichier boss
};
#endif