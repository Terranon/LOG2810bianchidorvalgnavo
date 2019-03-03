#include "chemin.h"

using namespace std;

Chemin::Chemin(Jeu& jeu):
	sousGraph_(jeu.gettableauIndividu()){
	//deepCopier(jeu.gettableauIndividu());
	
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



void Chemin::enleverArcsIndesirables(Individu* individuMystere1, Individu* individuMystere2,
	string couleursCheveux, string couleursYeux, string genie) {

	// cheveux indesirables
	for (int i = 0; i < sousGraph_.size(); i++) {
		auto itRelations = sousGraph_[i]->getDonneesRelation().begin();
		for (itRelations; itRelations != sousGraph_[i]->getDonneesRelation().end(); itRelations++) {
			if (itRelations->second != 0) {
				if (sousGraph_[i] != individuMystere1 || sousGraph_[i] != individuMystere2
					|| itRelations->first != individuMystere1 || itRelations->first != individuMystere2) {
					// cheveux indesirables
					if (sousGraph_[i]->getCouleurCheveux() == couleursCheveux
						&& itRelations->first->getCouleurCheveux() == couleursCheveux) {
						itRelations->second = 0;
					}
					// yeux indesirables
					if (sousGraph_[i]->getCouleurYeux() == couleursYeux
						&& itRelations->first->getCouleurYeux() == couleursYeux) {
						itRelations->second = 0;
					}
					// genie indesirables
					if (sousGraph_[i]->getGenie() == genie
						&& itRelations->first->getGenie() == genie) {
						itRelations->second = 0;
					}
				}
			}
		}
	}
}
bool Chemin::aEteTraiter(Individu* unIndividu) {
	bool aEteTraiter = false;
	for (int i = 0; i < individuTraite_.size(); i++) {
		if (unIndividu->getNom() == individuTraite_[i]->getNom()) {
			aEteTraiter = true; break;
		}
	}
	return aEteTraiter;
}
bool Chemin::aUnCheminFixe(Individu* unIndividu) {
	bool aUnCheminFixe = false;
	for (int i = 0; i < cheminsFixe_.size(); i++) {
		int dernierIndividuSurChemin = cheminsFixe_[i].first.size() - 1;
		if (unIndividu->getNom() == cheminsFixe_[i].first[dernierIndividuSurChemin]->getNom()) {
			aUnCheminFixe = true; break;
		}
	}
	return aUnCheminFixe;
}

int Chemin::getPosDansCheminFixe(Individu* unIndividu) {
	int i = 0;
	for (i; i < cheminsFixe_.size(); i++) {
		int dernierIndividuSurChemin = cheminsFixe_[i].first.size() - 1;
		if (unIndividu->getNom() == cheminsFixe_[i].first[dernierIndividuSurChemin]->getNom()) {
			break;
		}
	}
	return i;
}

int Chemin::getPosDansSousGraph(Individu* unIndividu) {
	int i = 0;
	for (i; i < sousGraph_.size(); i++) {
		if (unIndividu->getNom() == sousGraph_[i]->getNom()) {
			break;
		}
	}
	return i;
}

pair<vector<Individu*>, int> Chemin::trouverChaineContacts(Individu* individu1, Individu* individu2) {
	vector<Individu*> unChemin;
	int longueurDuCheminLePlusCourt = 0;
	vector<Individu*> individusNonTraite;
	individusNonTraite.push_back(individu1);
	int itIndividusNonTraite = 0;
	int nombreDIterationsVide = 0;
	individuTraite_.push_back(individu1);
	// trouver tout les chemins connecte au prochain individu a traiter
	// S == IndividuTraite_
	// u == sousGraph_[?]
	// v == it->first
	// w(u,v) == itRelations->second
	// L(u) == cheminsFixe_[getposDansCheminsFixe(sousGraph[?])].second
	// L(v) == cheminsFixe_[getposDansCheminsFixe(it->first].second
	while (!aEteTraiter(sousGraph_[getPosDansSousGraph(individu2)])) {
		if (!aEteTraiter(individusNonTraite[0])) {
			individuTraite_.push_back(individusNonTraite[itIndividusNonTraite]);
			individusNonTraite.erase(individusNonTraite.begin());
			auto itRelations = individuTraite_[itIndividusNonTraite]->getDonneesRelation().begin();
			for (itRelations; itRelations != individuTraite_[itIndividusNonTraite]->getDonneesRelation().end(); itRelations++) {
				if (itRelations->second != 0) {
					int posDansCheminsFixe = getPosDansCheminFixe(individuTraite_[itIndividusNonTraite]);
					if (aUnCheminFixe(itRelations->first)) {
						if (cheminsFixe_[posDansCheminsFixe].second + itRelations->second < cheminsFixe_[getPosDansCheminFixe(itRelations->first)].second) {
							unChemin = cheminsFixe_[posDansCheminsFixe].first;
							unChemin.push_back(itRelations->first);
							longueurDuCheminLePlusCourt = cheminsFixe_[posDansCheminsFixe].second + itRelations->second;
							cheminsFixe_[getPosDansCheminFixe(itRelations->first)] = make_pair(unChemin, longueurDuCheminLePlusCourt);
						}
					}
					else {
						unChemin = cheminsFixe_[posDansCheminsFixe].first;
						unChemin.push_back(itRelations->first);
						longueurDuCheminLePlusCourt = cheminsFixe_[posDansCheminsFixe].second + itRelations->second;
						cheminsFixe_.push_back(make_pair(unChemin, longueurDuCheminLePlusCourt));
					}
					individusNonTraite.push_back(itRelations->first);
				}
			}
		}
		else {
			itIndividusNonTraite++;
		}
		if (itIndividusNonTraite >= 4 * sousGraph_.size()) {
			break;
		}
		if (aUnCheminFixe(sousGraph_[getPosDansSousGraph(individu2)])) {
			return cheminsFixe_[getPosDansCheminFixe(sousGraph_[getPosDansSousGraph(individu2)])];
		}
		else {
			return cheminsFixe_[0];
		}
	}
}



void Chemin::afficherLeMeilleureChemin(pair<vector<Individu*>, int> leMeilleurChemin) {
	if (leMeilleurChemin.second == 0) {
		cout << "L'individu Mystere1 et 2 ne sont pas connecter par un reseau social" << endl;
	}
	else {
		cout << "La meilleur chaine:" << endl;
		for (int i = 0; i < leMeilleurChemin.first.size(); i++) {
			cout << leMeilleurChemin.first[i]->getNom() << " => ";
		}
		cout << endl << "La longueur du chemin est: " << leMeilleurChemin.second << endl;
	}
}



/*
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
}*/