#ifndef CHEMIN_H
#define CHEMIN_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Jeu.h"

using namespace std;
class Chemin {
public:
	Chemin(Jeu& jeu);
	~Chemin();

	vector<Individu*> getSousGraph();
	void setSousGraph(vector<Individu*>& sousGraph);

	void deepCopier(vector <Individu*> tableauIndividu);

	void enleverArcsUnCharacteristique(Individu* individuMystere1, Individu* individuMystere2, string characteristique);
	void enleverArcsIndesirables(Individu* individuMystere1, Individu* individuMystere2, string couleursCheveux, string couleursYeux, string genie);
	/*
	pair<pair<Individu*, Individu*>, int> trouverProchainePaire(Individu* individuPresent, Individu* pasCetIndividu);
	map<pair<Individu*, Individu*>, int> trouverChaineContacts(Individu* individu1, Individu* individu2);
	void afficherSousGraph(map<pair<Individu*, Individu*>, int> sousGraph);
	*/

private:
	vector<Individu*> sousGraph_;
	vector<Individu*> individuTraite_;
	vector<pair<vector<Individu*>, int>> cheminsFixe;
	vector<pair<vector<Individu*>, int>> cheminsConnus;
};
#endif