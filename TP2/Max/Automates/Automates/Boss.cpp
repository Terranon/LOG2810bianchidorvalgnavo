#include "Boss.h"


Boss::Boss() {};//aura en parametre le chemin map<Porte*,string>  le string est la valeur qui fut entree a cette porte
Boss::~Boss() {};
void Boss::lirefichier(string nomFichier) {

	ifstream fichier(nomFichier + ".txt");//declaration du fichier en mode lecture et ouverture du fichier 

	if (fichier.fail())
		throw exception("le fichier n'a pas reussi à être ouvert");
	else {
		// nom_

		string ligne;
		while (fichier.peek() == ' ' || fichier.peek() == '\n') { //attention 
			fichier.ignore(1);
		}
		getline(fichier, ligne, '\n');//copier la premiere ligne

		unsigned int i = 0;
		for (i; i < ligne.size(); i++) {

			string nomPorte;


			if (isalpha(ligne[i])) {// si on est sur un caractere alphabétique 
				if (ligne[i] == 'P') {

					while (ligne[i] != ' ') {

						nomPorte += ligne[i];//
						i++;
					}

					Porte* p = new Porte();

					p->lirefichier(nomPorte);

					listePorte.push_back(p);
				}

			}
		}
	}


};
void Boss::genererAutomate(string lesRegles) {



	vector<string> lesReglesDivises;
	string uneRegle;
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



}
bool Boss::validerConcatenation(vector<string> entree) {

	//transfomer le string entree en char 
	vector<char> motDePasse;
	for (unsigned int i = 0; i < entree.size(); i++) {

		for (auto it = correspondance_string.begin(); it != correspondance_string.end(); it++) { // verifier que l'entree et le mot correspndent
			if (entree[i] == it->second) {
				motDePasse.push_back(it->first);
				break;
			}

		}
		if (motDePasse.size() == i) {// la taille doit etre egale a l'index +1 car a chaque i on ajoute un élement 
			motDePasse.push_back('a' + correspondance_string.size() + i);// on insere un nouvel symbole

		}
	}




	//verification
	char prochainEtat = 'S';
	int taillemotdepassevalide = 0;
	for (int i = 0; i < motDePasse.size(); i++) {

		for (int j = 0; j < regles_.at(prochainEtat).size(); j++) {
			if (motDePasse[i] == regles_.at(prochainEtat)[j].first) {
				prochainEtat = regles_.at(prochainEtat)[j].second;
				taillemotdepassevalide++;
				break;
			}

		}

		if (prochainEtat == ' ') {
			if (motDePasse.size() != taillemotdepassevalide || motDePasse[i] != motDePasse[motDePasse.size() - 1]) {//si le mot qui constitue l'automate est different du mot de passe
				return false;
			}

			return true;
		}

	}
	return false;
}
string Boss::genererProduction() {


	if (listePorte.size() == 0) { lirefichier("Boss"); }

	char caractere = 'a';
	char etat = 'A';
	char etatfutur = 'B';
	string tableauchar;

	string production = "{";
	for (int i = 0; i < listePorte.size(); i++) {

		//faire correspondre le caractere d'entrée avec le mot de passe 
		correspondance_string.insert(make_pair(caractere, listePorte[i]->getmotentree()));
		//	---devrait etre
		//	correspondance_string.insert(make_pair(caractere, chemin[listePorte[i]]);



		if (i == 0) { // si il existe d'autres états a part le debut
			if (listePorte.size() == 1) { // si il existe un seul état 
				production = production + "S->" + caractere;
			}
			else { // si l'état courant est l'état qui emmene au boss
				production = production + "S->" + caractere + (etat);

			}
			production += " ,";

			caractere++;
		}
		else if (i < listePorte.size() - 1) { // si il existe des états intermediaires

			production = production + (etat)+"->" + caractere + (etatfutur);
			production += " ,";
			caractere++;
			etat++;
			etatfutur++;
		}
		else {

			if (listePorte.size() == 1) { // si il existe un seul état 
				production = production + "S->" + caractere;
			}
			else { // si l'état courant est l'état qui emmene au boss
				production = production + (etat)+"->" + caractere;

			}


			caractere++;
		}


	}








	production += "}";
	return production;




};