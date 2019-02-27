#include "chemin.h"

using namespace std;

Chemin::Chemin() {
	//TODO lire fichier et creer la map sousGraph_
}

Chemin::~Chemin() {
	//TODO delete les individus dans sousGraph_
}

map<pair<Individu*, Individu*>, int> Chemin::getSousGraph() {
	return sousGraph_;
}
void Chemin::setSousGraph(map<pair<Individu*, Individu*>, int> sousGraph) {
	sousGraph_ = sousGraph;
}


map<pair<Individu*, Individu*>, int> Chemin::enleverArcsIndesirables(string couleursCheveux, string couleursYeux, string genie) {

	// cheveux indesirables
	auto sousGraphIt = sousGraph_.begin();
	for (sousGraphIt; sousGraphIt != sousGraph_.end(); sousGraphIt++) {
		if (sousGraphIt->second != 0) {
			if (sousGraphIt->first.first->getCouleurCheveux() == couleursCheveux) {
				if (sousGraphIt->first.second->getCouleurCheveux() == couleursCheveux) {
					sousGraphIt->second = 0;
				}
			}
		}
	}

	// yeux indesirables
	sousGraphIt = sousGraph_.begin();
	for (sousGraphIt; sousGraphIt != sousGraph_.end(); sousGraphIt++) {
		if (sousGraphIt->second != 0) {
			if (sousGraphIt->first.first->getCouleurYeux() == couleursYeux) {
				if (sousGraphIt->first.second->getCouleurYeux() == couleursYeux) {
					sousGraphIt->second = 0;
				}
			}
		}
	}

	// genie indesirables
	sousGraphIt = sousGraph_.begin();
	for (sousGraphIt; sousGraphIt != sousGraph_.end(); sousGraphIt++) {
		if (sousGraphIt->second != 0) {
			if (sousGraphIt->first.first->getGenie() == genie) {
				if (sousGraphIt->first.second->getGenie() == genie) {
					sousGraphIt->second = 0;
				}
			}
		}
	}
	return sousGraph_;
}

void Chemin::afficherSousGraph(map<pair<Individu*, Individu*>, int> unSousGraph) {
	auto mapIt = unSousGraph.begin();
	for (mapIt; mapIt != unSousGraph.end(); mapIt++) {
		cout << "(" << mapIt->first.first->getNom() << "," << mapIt->first.second->getNom() << ","
			<< "(" << mapIt->second << ")" << ")" << endl;
	}
}

pair<pair<Individu*, Individu*>, int> Chemin::trouverProchainePaire(Individu* individuPresent, Individu* pasCetIndividu) {
	map<Individu*, int> relationsDUnIndividu = individuPresent->getDonneesRelation();
	auto itRelations = relationsDUnIndividu.begin();
	int uneRelation;
	int meilleurRelation = itRelations->second; // attrapper la premiere relation
	Individu* prochainIndividu = new Individu(*itRelations->first); // savoir c'est qui
	for (itRelations; itRelations != individuPresent->getDonneesRelation().end(); itRelations++) {
		if (itRelations->first->getNom() != pasCetIndividu->getNom()) { // eviter individu indesirables
			uneRelation = itRelations->second;
			if (uneRelation < meilleurRelation && uneRelation != 0) { // prendre la meilleur relation
				meilleurRelation = uneRelation;
				prochainIndividu = new Individu(*itRelations->first);
			}
		}
	}
	return make_pair(make_pair(individuPresent, prochainIndividu), meilleurRelation);
}

map<pair<Individu*, Individu*>, int> Chemin::trouverChaineContacts(Individu* individu1, Individu* individu2) {
	// trouver la meilleur relation d'Individu1
	pair<pair<Individu*, Individu*>, int> prochainePaire = trouverProchainePaire(individu1, NULL);
	while (sousGraph_.at(prochainePaire.first) == 0) {
		Individu* indesirable = prochainePaire.first.second;
		prochainePaire = trouverProchainePaire(individu1, indesirable);
	}
	// la pair creer consiste de l'individu entre en parametre dans la fonction trouver prochainePaire,
	// l'individu qui a la meilleur relation
	// la valeur de leur relation

	map<pair<Individu*, Individu*>, int> chemin;
	chemin[prochainePaire.first] = prochainePaire.second;

	if (prochainePaire.first.second->getNom() != individu2->getNom()) {
		auto cheminIt = chemin.begin();
		for (cheminIt; cheminIt != chemin.end; cheminIt++) {
			prochainePaire = trouverProchainePaire(cheminIt->first.second, NULL);
			while (sousGraph_.at(prochainePaire.first) == 0) {
				Individu* indesirable = prochainePaire.first.second;
				prochainePaire = trouverProchainePaire(individu1, indesirable);
			}
			if (prochainePaire.first.second->getNom() != individu2->getNom()) {
				chemin[prochainePaire.first] = prochainePaire.second;
			}
			else {
				cheminIt = chemin.end();
			}
		}
	}
	return chemin;
}