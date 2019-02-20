#pragma once

#ifndef FONCTIONS_H
#define FONCTIONS_H
#include<iostream>
#include <exception>
#include <string>
#include <fstream>
#include "individu.h"
#include <vector>
using namespace std;


///attribut de partie 




/*
map<pair<Individu*, Individu*>, int> deepCopier() {
	int nbrIndividus = table_Individu.size();
	map<pair<Individu*, Individu*>, int> sousGraph;

	for (int copyIt = 0; copyIt < nbrIndividus; copyIt++) {
		Individu* individuLeft = new Individu(*table_Individu[copyIt]);
		auto mapIt = individuLeft->getDonneesRelation().begin();
		for (mapIt; mapIt != table_Individu[copyIt]->getDonneesRelation().end(); mapIt++) {
			Individu* individuRight = new Individu(*(mapIt->first));
			int valeurRelationTemp = mapIt->second;
			pair<Individu*, Individu*> pairClef = make_pair(individuLeft, individuRight);
			sousGraph.insert(make_pair(pairClef, valeurRelationTemp));
		}
	}
	return sousGraph;
};



map<pair<Individu*, Individu*>, int> enleverArcsIndesirables(string couleursCheveux, string couleursYeux, string genie) {

	map<pair<Individu*, Individu*>, int> sousGraph = deepCopier();

	// cheveux indesirables
	auto sousGraphIt = sousGraph.begin();
	for (sousGraphIt; sousGraphIt != sousGraph.end(); sousGraphIt++) {
		if (sousGraphIt->second != 0) {
			if (sousGraphIt->first.first->getCouleurCheveux() == couleursCheveux) {
				if (sousGraphIt->first.second->getCouleurCheveux() == couleursCheveux) {
					sousGraphIt->second = 0;
				}
			}
		}
	}

	// yeux indesirables
	sousGraphIt = sousGraph.begin();
	for (sousGraphIt; sousGraphIt != sousGraph.end(); sousGraphIt++) {
		if (sousGraphIt->second != 0) {
			if (sousGraphIt->first.first->getCouleurYeux() == couleursYeux) {
				if (sousGraphIt->first.second->getCouleurYeux() == couleursYeux) {
					sousGraphIt->second = 0;
				}
			}
		}
	}

	// genie indesirables
	sousGraphIt = sousGraph.begin();
	for (sousGraphIt; sousGraphIt != sousGraph.end(); sousGraphIt++) {
		if (sousGraphIt->second != 0) {
			if (sousGraphIt->first.first->getGenie() == genie) {
				if (sousGraphIt->first.second->getGenie() == genie) {
					sousGraphIt->second = 0;
				}
			}
		}
	}
	return sousGraph;
};
*/
/*
void afficherSousGraph(map<pair<Individu*, Individu*>, int> sousGraph) {
	auto mapIt = sousGraph.begin();
	for (mapIt; mapIt != sousGraph.end(); mapIt++) {
		cout << "(" << mapIt->first.first->getNom() << "," << mapIt->first.second->getNom() << ","
			<< "(" << mapIt->second << ")" << ")" << endl;
	}*/


#endif