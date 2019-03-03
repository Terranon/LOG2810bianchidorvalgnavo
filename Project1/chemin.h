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

	void enleverArcsIndesirables(Individu* individuMystere1, Individu* individuMystere2,string couleursCheveux, string couleursYeux, string genie);
	
	bool aEteTraiter(Individu* unIndividu);
	bool aUnCheminFixe(Individu* unIndividu);
	int getPosDansCheminFixe(Individu* unIndividu);
	int getPosDansSousGraph(Individu* unIndividu);
	pair<vector<Individu*>, int> trouverChaineContacts(Individu* individu1, Individu* individu2);

	void afficherSousGraph();
	void afficherLesTroisIndesirables();
	void afficherLeMeilleureChemin(pair<vector<Individu*>, int> leMeilleurChemin);


private:
	vector<Individu*> sousGraph_;
	vector<Individu*> individuTraite_;
	vector<pair<vector<Individu*>, int>> cheminsFixe_;
	string cheveuxIndesirable_;
	string yeuxIndesirable_;
	string genieIndesirable_;
};
#endif