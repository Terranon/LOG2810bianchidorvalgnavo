#include "chemin.h"

using namespace std;

Chemin::Chemin(Jeu& jeu) {
	deepCopierVector(jeu.gettableauIndividu());
}

Chemin::~Chemin() {
	//TODO delete les individus dans sousGraph_
}

vector<Individu*> Chemin::getSousGraph() {
	return sousGraph_;
}
void Chemin::setSousGraph(vector<Individu*>& sousGraph) {
	sousGraph_ = sousGraph;
}

void Chemin::deepCopier(vector <Individu*> tableauIndividu) {
	vector<Individu*> deepCopyOfVector;
	for (int i = 0; i < tableauIndividu.size(); i++) {
		Individu* individuTemp = new Individu(*tableauIndividu[i]); 
		deepCopyOfVector.push_back(individuTemp);//mise à jour du vector
		}
	setSousGraph(deepCopyOfVector);
}

void Chemin::enleverArcsUnCharacteristique(Individu* individuMystere1, Individu* individuMystere2, string characteristique) {
	auto sousGraphIt = sousGraph_.begin();
	for (sousGraphIt; sousGraphIt != sousGraph_.end(); sousGraphIt++) {
		if (sousGraphIt->second != 0) {
			if (sousGraphIt->first.first != individuMystere1 || sousGraphIt->first.first != individuMystere2
				|| sousGraphIt->first.second != individuMystere1 || sousGraphIt->first.second != individuMystere2) {
				if (sousGraphIt->first.first->getCouleurCheveux() == characteristique) {
					if (sousGraphIt->first.second->getCouleurCheveux() == characteristique) {
						sousGraphIt->second = 0;
					}
				}
			}
		}
	}
}

void Chemin::enleverArcsIndesirables(Individu* individuMystere1, Individu* individuMystere2,
	string couleursCheveux, string couleursYeux, string genie) {

	// cheveux indesirables
	enleverArcsUnCharacteristique(individuMystere1, individuMystere2, couleursCheveux);

	// yeux indesirables
	enleverArcsUnCharacteristique(individuMystere1, individuMystere2, couleursYeux);

	// genie indesirables
	enleverArcsUnCharacteristique(individuMystere1, individuMystere2, genie);
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
	// trouver la meilleur relation d'Individu1 qui est la prochaine paire

	// la pair creer consiste de:
	// clef:
	// l'individu entre en parametre dans la fonction trouver prochainePaire,
	// l'individu qui a la meilleur relation
	// valeur:
	// la valeur de leur relation
	pair<pair<Individu*, Individu*>, int> prochainePaire = trouverProchainePaire(individu1, NULL);
	// Un vecteur contenant tout les individus qui sont des "bad nodes"
	vector<Individu*> pasCesIndividus;

	// verifier si la relation dans le sous graph a ete elimine
	while (sousGraph_.at(prochainePaire.first) == 0) {
		Individu* pasCetIndividu = prochainePaire.first.second;
		vector<Individu*> pasCesIndividus;
		pasCesIndividus.push_back(pasCetIndividu);
		prochainePaire = trouverProchainePaire(individu1, pasCetIndividu);
	}

	

	map<pair<Individu*, Individu*>, int> chemin;
	chemin.insert(prochainePaire);

	if (prochainePaire.first.second->getNom() != individu2->getNom()) {
		while (true) {

		}
		auto cheminIt = chemin.begin();
		for (cheminIt; cheminIt != chemin.end(); cheminIt++) {
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

void Chemin::afficherSousGraph(map<pair<Individu*, Individu*>, int> unSousGraph) {
	auto mapIt = unSousGraph.begin();
	for (mapIt; mapIt != unSousGraph.end(); mapIt++) {
		cout << "(" << mapIt->first.first->getNom() << "," << mapIt->first.second->getNom() << ","
			<< "(" << mapIt->second << ")" << ")" << endl;
	}
}