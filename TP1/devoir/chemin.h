#ifndef CHEMIN_H
#define CHEMIN_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "individu.h"

using namespace std;
class Chemin {
public:
	Chemin();
	~Chemin();

	map<pair<Individu*, Individu*>, int> getSousGraph();
	void setSousGraph(map<pair<Individu*, Individu*>, int> sousGraph);

	map<pair<Individu*, Individu*>, int> enleverArcsIndesirables(string couleursCheveux, string couleursYeux, string genie);
	pair<pair<Individu*, Individu*>, int> trouverProchainePaire(Individu* individuPresent, Individu* pasCetIndividu);
	map<pair<Individu*, Individu*>, int> trouverChaineContacts(Individu* individu1, Individu* individu2);
	void afficherSousGraph(map<pair<Individu*, Individu*>, int> sousGraph);

private:
	map<pair<Individu*, Individu*>, int> sousGraph_;
};
#endif