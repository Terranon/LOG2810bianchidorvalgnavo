#include "Porte.h"

Porte::Porte(fstream& porte) {

}
Porte::~Porte() {

}

void Porte::genererAutomate() {

}
void Porte::lireFichier(string nomDuFichier) {
	ifstream fichier(nomDuFichier);//declaration du fichier en mode lecture et ouverture du fichier 

	if (fichier.fail())
		throw exception("le fichier n'a pas reussi à être ouvert");
	else {
		string nom = nomDuFichier;
		// ici je vais enlever les quatres derniers caratere (.txt)
		//TODO


		string etatCourant, entree, etatProchain;
		fichier.ignore(2); 
		// regles
		while (fichier.peek() != '}') {

			string uneRegle;
			getline(fichier, uneRegle, ',');
			if (regles_.find(uneRegle[0]) == regles_.end()) {

				vector<pair<char, char>> coteDroit;
				pair<char, char> entreEtProchainEtat;
				if (uneRegle.size() == 3) {
					entreEtProchainEtat = make_pair(' ', ' ');
				}
				else if (uneRegle.size() == 4) {
					entreEtProchainEtat = make_pair(uneRegle[3], ' ');
				}
				else {
					entreEtProchainEtat = make_pair(uneRegle[3], uneRegle[4]);
				}

				coteDroit.push_back(entreEtProchainEtat);
				regles_.insert(make_pair(uneRegle[0], coteDroit));
			}
			else {

				pair<char, char> entreEtProchainEtat = make_pair(uneRegle[3], uneRegle[4]);
				regles_.at(uneRegle[0]).push_back(entreEtProchainEtat);
			}
			while (fichier.peek() == ',' || fichier.peek() == ' ' || fichier.peek() == '\n') {
				fichier.ignore(1);
			}
		}

		//si le fichier est un fichier de personnes
	}
}
bool Porte::validerPorte(string motDePasse) {
	return true;
}
bool Porte::getEstGouffre() {
	return true;
}