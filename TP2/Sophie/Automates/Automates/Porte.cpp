#include "Porte.h"

Porte::Porte(string porte) {
	genererAutomate(porte);
	nom_=porte;
}
Porte::~Porte() {

}

string Porte::getNom() {
	return nom_;
}


void Porte::genererAutomate(string nomDuFichier) {

	ifstream fichier(nomDuFichier + ".txt");//declaration du fichier en mode lecture et ouverture du fichier 

	if (fichier.fail())
		throw exception("le fichier n'a pas reussi à être ouvert");
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

void Porte::lireFichierBoss(string nomFichier){

	ifstream fichier(nomFichier + ".txt");//declaration du fichier en mode lecture et ouverture du fichier 
	nom_ = nomFichier;
	if (fichier.fail())
		throw exception("le fichier n'a pas reussi à être ouvert");
	else {
		string seriePorte;
		while (fichier.peek() == ' ' || fichier.peek() == '\n') { //attention 
			fichier.ignore(1);
		}
		getline(fichier, seriePorte, 'B');//copier la premiere ligne

		string porte="";
		for (int i = 0; i < seriePorte.size(); i++) {
			if (isalpha(seriePorte[i])|| isdigit(seriePorte[i])) {
				porte += seriePorte[i];
			}
			else {
				if (!porte.empty()) {
					portesBoss.push_back(porte); //mettre les porte dans un vecteur
					porte = "";
				}
			}
		}
	}
};


void Porte::affronterBoss(vector<Porte*> chemin) {
	bossVaincu = true;
	lireFichierBoss("Boss");
	int j = chemin.size() - 2; // recule l<index dans chemin pour arriver au debut du chemin courant dans la liste (porte 1)
	for (int i = portesBoss.size()-1; i> 0; i--) { 
		if (chemin[j]->getNom() != portesBoss[i]) {//compare les nom de porte dans le vecteur portesBosse avec le chemin
			bossVaincu = false;
			break;
		}
		j--;
	}
}

bool Porte::getBossVaincu() {
	return bossVaincu;
}


vector<pair<string, pair<string, bool>>> Porte::getPortesConnecter(){
	return portesConnectes_;
}
	

void Porte::afficherPorte(){
	
	cout << "b. ";
	for (int i = 0; i < portesConnectes_.size(); i++) {
		string valide = "";
		if (portesConnectes_[i].second.second) {// affiche les portes connecter 
			valide = "valide";
		}
		else {
			valide = "non valide";
		}
		cout << "{ " << portesConnectes_[i].second.first << ", "<< portesConnectes_[i].first //affiche mot de passe, nom de la porte et la validiter
			<< ", " << valide <<" } ";// {{efeddaa , Porte6 , valide} {...}
	}
	cout << endl;
	string gouffre = "";
	if (getEstGouffre()) { // affiche different phrase selon si le boss est vaincu
		gouffre = "Cette porte est un gouffre";
	}
	else {
		gouffre = "Cette porte n'est pas un gouffre";
	}
	cout << "c. " << gouffre << endl;
}

map<char, vector<pair<char, char>>>& Porte::getRegles(){
	return regles_;
}

string Porte::getMotDePasseBoss(vector<Porte*> chemin) {
	string motDePasse = "";
	int i = chemin.size() - 2; //trouve l'index de la porte 1 de la dernier tentative de chemin
	for (i; i >= 0; i--) {
		if (portesBoss[0] == chemin[i]->getNom()) {
			break;
		}
	}
	for (i; i < chemin.size() - 1; i++) {
		for (int j = 0; j < chemin[i]->getPortesConnecter().size(); j++) {
			if (chemin[i + 1]->getNom() == chemin[i]->getPortesConnecter()[j].first && chemin[i]->getPortesConnecter()[j].second.first!=" ") {//prend la porte qui suit dans le boss et compare son nom avec le nom de la porte dans porte connecter
				motDePasse += chemin[i]->getPortesConnecter()[j].second.first;// ajoute le mot de passe de la porte au mot de passe, concatonne les mot de passe
			}
		}
	}
	return motDePasse;
}
string Porte::getSyntaxBoss(vector<Porte*> chemin) {
	map<string, vector<pair<char, string>>> reglesEnString;
	vector<pair<char, string>> coteDroit;
	int i = chemin.size() - 2;
	for (i; i >= 0; i--) {
		if (portesBoss[0] == chemin[i]->getNom()) { //trouve l'indice de la porte 1 la plus proche de la fin
			break;
		}
	}

	for (i; i < chemin.size() - 1; i++) {
		auto it = chemin[i]->getRegles().begin();
		char ordre = '0';//ordre de la porte
		//map<char, vector<pair<char, char>>>::iterator it;
		for (it; it != (chemin[i]->getRegles()).end(); it++) {
			for (int j = 0; j < it->second.size(); j++) {
				string prochainEtat;
				if (it->second[j].second == ' ') { // lorsque l'etat suivant est vide
					if (it->second[j].first == trouverDerniereCharDeMotDePasse(chemin,i)) {// le input est egale au dernier char du mot de passe dela porte qui suit
						prochainEtat.push_back('S'); // ajout de S1, S2 ... a l'etat suivant qio est vide
						prochainEtat += (ordre+1);
					}
				}
				else {
					prochainEtat.push_back(it->second[j].second); //ajout de 1, 2, 3... a tout les etat prochain
					prochainEtat += ordre;
				}
				pair<char, string> entreEtProchainEtat = make_pair(it->second[j].first, prochainEtat);
				coteDroit.push_back(entreEtProchainEtat);
				
			}
			string etatCourant;
			etatCourant.push_back(it->first);
			etatCourant += ordre; // ajout de 1, 2, 3... a tout les etat courant
			reglesEnString.insert(make_pair(etatCourant, coteDroit));
			ordre++;
		}
	}
	string s="";
	auto it = reglesEnString.begin();
	for (it; it != reglesEnString.end(); it++) {
		for (int j = 0; j < it->second.size(); j++) {
			s += it->first;
			s += " -> ";
			s += it->second[j].first;
			s += it->second[j].second;
			s += "; ";
		}
	}
	return s;
}

char Porte::trouverDerniereCharDeMotDePasse(vector<Porte*> chemin, int index) {
	string motDePasse;
	// trouve le mot de passe de la porte qui suit puis retourne le dernier char de ce mot de passe
	for (int j = 0; j < chemin[index]->getPortesConnecter().size(); j++) {
		if (chemin[index + 1]->getNom() == chemin[index]->getPortesConnecter()[j].first) {
			motDePasse += chemin[index]->getPortesConnecter()[j].second.first;
		}
	}
	char lastChar = motDePasse[motDePasse.size() - 1];
	return lastChar;
}


void Porte::afficherBoss(vector<Porte*> chemin) {
	cout << "a. ";
	for (int k = 0; k < portesBoss.size(); k++) {
		cout << portesBoss[k] << " ";// affiche la liste des porte en ordre pour vaincre le boss
	}
	cout << endl;

	cout << "b. " << getMotDePasseBoss(chemin) << " P = { "; // affiche le mot de passe concatoner 
	if (getBossVaincu()) {
		cout << getSyntaxBoss(chemin); // affiche les regles pour se rendre au boss
	}
	else {
		cout << "...";
	}
	cout << " }" << endl;
	
	string victoire = "";
	if (getBossVaincu()) {
		victoire = "L'agent vainc le boss"; // affiche la phrase selon si l'agent vainc le boss au non
	}
	else {
		victoire = "Le Boss vainc l'agent. Retour à la Porte1";
	}
	cout << "c. " << victoire << endl;
}
