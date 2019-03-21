#include "Porte.h"

Porte::Porte(fstream& porte) {

}
Porte::~Porte() {

}

void Porte::genererAutomate(string nomDuFichier) {

	ifstream fichier(nomDuFichier + ".txt");//declaration du fichier en mode lecture et ouverture du fichier 

	if (fichier.fail())
		throw exception("le fichier n'a pas reussi � �tre ouvert");
	else {
		// nom_
		nom_ = nomDuFichier;

		while (fichier.peek() == '{' || fichier.peek() == ' ' || fichier.peek() == '\n') {
			fichier.ignore(1);
		}

		// regles_
		string lesRegles;
		getline(fichier, lesRegles, '\n');
		string uneRegle;
		vector<string> lesReglesDivises;

		for (int i = 0; i < lesRegles.size(); i++) {
			if (isalpha(lesRegles[i])) {
				uneRegle += lesRegles[i];
			}
			if (lesRegles[i] == ',') {
				lesReglesDivises.push_back(uneRegle);
				uneRegle = "";
			}
		}
		lesReglesDivises.push_back(uneRegle); // rajouter la derniere regle qui n'a pas de virgule

		for (int j = 0; j < lesReglesDivises.size(); j++) {
			vector<pair<char, char>> coteDroit;
			pair<char, char> entreEtProchainEtat;
			if (islower(lesReglesDivises[j][0])) {
				lesReglesDivises[j][0] = toupper(lesReglesDivises[j][0]);
			}
			if (regles_.find(lesReglesDivises[j][0]) == regles_.end()) {

				if (lesReglesDivises[j].size() == 1) {
					entreEtProchainEtat = make_pair(' ', ' ');
				}
				else if (lesReglesDivises[j].size() == 2) {
					if (isupper(lesReglesDivises[j][1])) {
						entreEtProchainEtat = make_pair(' ', lesReglesDivises[j][1]);
					}
					else {
						entreEtProchainEtat = make_pair(lesReglesDivises[j][1], ' ');
					}

				}
				else {
					entreEtProchainEtat = make_pair(lesReglesDivises[j][1], lesReglesDivises[j][2]);
				}

				coteDroit.push_back(entreEtProchainEtat);
				regles_.insert(make_pair(lesReglesDivises[j][0], coteDroit));
			}
			else {
				if (lesReglesDivises[j].size() == 1) {
					entreEtProchainEtat = make_pair(' ', ' ');
				}
				else if (lesReglesDivises[j].size() == 2) {
					if (isupper(lesReglesDivises[j][1])) {
						entreEtProchainEtat = make_pair(' ', lesReglesDivises[j][1]);
					}
					else {
						entreEtProchainEtat = make_pair(lesReglesDivises[j][1], ' ');
					}
				}
				else {
					entreEtProchainEtat = make_pair(lesReglesDivises[j][1], lesReglesDivises[j][2]);
				}
				regles_.at(lesReglesDivises[j][0]).push_back(entreEtProchainEtat);
			}
		}

		while (fichier.peek() == '}' || fichier.peek() == ' ' || fichier.peek() == '\n') {
			fichier.ignore(1);
		}
		// portesConnectes_
		while (!ws(fichier).eof()) {
			string motDePasseEtPorte;
			getline(fichier, motDePasseEtPorte, '\n');
			string motDePasse, nomDePorte;
			if (motDePasseEtPorte[0] == 'P') {
				motDePasse = " ";
				nomDePorte = motDePasseEtPorte;
			}
			else {
				int i = 0;
				for (i; i < motDePasseEtPorte.size(); i++) {
					if (motDePasseEtPorte[i] != ' ') {
						motDePasse += motDePasseEtPorte[i];
					}
					else {
						break;
					}
				}
				while (motDePasseEtPorte[i] == ' ') {
					i++;
				}
				for (int j = i; j < motDePasseEtPorte.size(); j++) {
					if (motDePasseEtPorte[j] != ' ') {
						nomDePorte += motDePasseEtPorte[j];
					}
					else {
						break;
					}
				}
			}
			pair<string, pair<string, bool>> unePorte = make_pair(nomDePorte, make_pair(motDePasse, validerPorte(motDePasse)));
			portesConnectes_.push_back(unePorte);
		}
	}
}
bool Porte::validerPorte(string motDePasse) {
	bool estValide = true; 
	char prochainEtat = 'S';
	for (int i = 0; i < motDePasse.size(); i++) {
		if (prochainEtat == ' ') {
			estValide == false;
			break;
		}
		for (int j = 0; j < regles_.at(prochainEtat).size(); j++) {
			if (motDePasse[i] == regles_.at(prochainEtat)[j].first) {
				prochainEtat = regles_.at(prochainEtat)[j].second;
				break;
			}
			else {
				estValide = false;
			}
		}
		if (estValide == false) {
			break;
		}
	}
	return estValide;
}

void Porte::verifierSiGouffre() {
	estGouffre_ = true;
	for (int i = 0; i < portesConnectes_.size(); i++) {
		if (portesConnectes_[i].second.second == true) {
			estGouffre_ = false;
			break;
		}
	}
}

bool Porte::getEstGouffre() {
	return estGouffre_;
}