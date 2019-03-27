#ifndef BOSS_H
#define BOSS_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Porte.h"

using namespace std;
class Boss {
public:
	Boss();
	~Boss();
	void lirefichier(string nomFichier);
	void genererAutomate(string nomDuFichier);
	bool validerConcatenation(vector<string> motDePasse);

	void affronterBoss(vector<string> motDePasse) {//peut etre un bool qui permettra a la classe agent de partir sa porte courante a  la porte 1

		if (validerConcatenation(motDePasse)) {
			cout << "le boss est vaincu" << endl;

		}
		else {


			cout << "le boss a été vaincu" << endl;

		}
	};
	string genererProduction();

	map <char, string>correspondance_string;

	/*Écrire une fonction «affronterBoss()» qui lit le fichier Boss.txt, génère lautomate associé
	au chemin décrit dans le fichier, valide la concaténation des mots de passe
	sélectionnés de lentrée du labyrinthe jusquà présent et permet de trouver le langage reconnu
	par le boss*/

private:
	//  etat courant ----input---prochain etat
	map<char, vector<pair<char, char>>> regles_;

	vector<Porte*> listePorte;// les portes qui sont avant boss



};
#endif