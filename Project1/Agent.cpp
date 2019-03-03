#include "Agent.h"
#include <algorithm>

#include<iostream>
#include <exception>
#include <string>
#include <fstream>
#include "individu.h"
#include <vector>
#include "Jeu.h"

using namespace std;




//Constructeur d'agent 
Agent::Agent() {


	questionCount = 0;
}
Agent::Agent(vector<Individu*> tab) {

	
	questionCount = 0;

	//deepCopierVector(tab, tableauSuspect);// on copie tout les individu dans le tableau de suspect
	//deepCopierVector(tab, tableauIndividus);//on copie tout les individus dans le tableau  individus qui ne sera pas modifiés
	setTable(tab);
	Individu individuMystere1(" ", " ", " ", " ");
	Individu individuMystere2(" ", " ", " ", " ");
	vector<string> characteristic;
	vector<string> characteristicGenie;
	vector<string> characteristicYeux;
	vector<Individu> mystereGuess;
	vector<Individu> mystereNonDeviner;
	vector<Individu> mystereVrai;

}

Agent::~Agent() {};


void Agent::setTable(vector<Individu*>&acopier) {
	deepCopierVector(acopier, tableauSuspect);// on copie tout les individu dans le tableau de suspect
	deepCopierVector(acopier, tableauIndividus);
}
/*
	nom: deepCopierVector
	paramètre: vector<Individu*>&
	type retour: void
	fonction: effectue une deep copie d'un vecteur

*/

	void  Agent::deepCopierVector(vector<Individu*>&acopier, vector <Individu*>& tableau) {//vector est le tableau a copier et le tableau est le tableau quicontient les valeurs copiés


		for (Individu* item : acopier) {

			Individu* individuTemp = new Individu(*item);
			tableau.push_back(individuTemp);//mise à jour du vector
		}

	};

	


/*
nom : incrementerCount
retour : void
type parametre : void
fonction : incremente la valeur de la variable questionCount de 1

*/

void Agent::incrementerCount() {

	questionCount++;


}


void Agent::demarrerjeu() {


	cout << " Pour repondre aux questions qui suivent ,veuillez entrez 'o' pour oui pour les deux, 'n' pour non pour les deux , 's' pour afficher la liste de suspects , 'u' pour oui pour un seul individu " << endl;
	trouverCheveux('N');


};

/*
nom : ReduireListeSuspects
retour : void
type parametre : char,string,string
fonction : elimine les individus de la liste de suspect en fonction de la réponse et des caracteristiques 

*/

void Agent::ReduireListeSuspects(char reponse, string input, string caracteristique) {
	
	switch (reponse) {
		case 'o':
		{
		
		
			//convertion du string input en string
			auto debut = tableauSuspect.begin();
			auto fin = tableauSuspect.end();
			tableauSuspect.erase(remove_if(debut, fin, Predicat(caracteristique, input)), fin);

			// mettre à jour les caractéristiques des individus
			if (caracteristique == "cheveux") {
				individuMystere1.setCouleurCheveux(input);
				individuMystere2.setCouleurCheveux(input);
			}
			
			if (caracteristique == "yeux") {
				individuMystere1.setCouleurYeux(input);
				individuMystere2.setCouleurYeux(input);
			}
			if (caracteristique == "genie") {
			
				
					individuMystere1.setGenie(input);
					individuMystere2.setGenie(input);
				
			}
		
				 deviner = devinerIndividusMysteres();
			

		}
	
			break;
		case 'u':
		{
			
				characteristic.push_back(input);
			
				if (characteristic.size() == 2) {
					
					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					tableauSuspect.erase(remove_if(debut, fin, PredicatU(caracteristique, characteristic[0], characteristic[1])), fin);
					
					if (caracteristique == "cheveux") {
						individuMystere1.setCouleurCheveux(characteristic[0]);
						individuMystere2.setCouleurCheveux(characteristic[1]);
						
						characteristic.clear();//remettre le tableau de caracteristiques a 0
					}

					if (caracteristique == "yeux") {
						individuMystere1.setCouleurYeux(characteristic[0]);
						individuMystere2.setCouleurYeux(characteristic[1]);
						characteristic.clear();		//remettre le tableau de caracteristiques a 0
					}
					if (caracteristique == "genie") {


						individuMystere1.setGenie(characteristic[0]);
						individuMystere2.setGenie(characteristic[1]);
						characteristic.clear();		//remettre le tableau de caracteristiques a 0

					}
						 deviner = devinerIndividusMysteres();

				}
			
		


		}

			break;
		case 'n':
		    {

				auto debut = tableauSuspect.begin();
				auto fin = tableauSuspect.end();
			
				tableauSuspect.erase(remove_if(debut, fin, PredicatN(caracteristique, input)), fin);
					deviner = devinerIndividusMysteres();

			
		    }
			
			break;
		case 's':
			cout << "Les suspects encore sur la liste sont: " << endl;
			for (int i = 0; i < tableauSuspect.size(); i++) {
				cout << tableauSuspect[i]->getNom() << endl;
			}
			break;
		default:
		{
			cout << "invalid input" << endl;
			
			

		}
		break;
			
	}
};

bool Agent::validerCorrection(string nom1, string nom2) {

	int count = 0;
	for (int i = 0; i < tableauIndividus.size(); i++) {
		if (nom1 == tableauIndividus[i]->getNom() || nom2 == tableauIndividus[i]->getNom()) {
			count++;
		}
	}
		if (count == 2) {
			return true;
		}
		else {
			return false;
		}
}

void Agent::Corriger() {
	
	cout << "Est ce correct?" << endl;
	char answer;
	do {
		
		cin >> answer;  // faire une gestion de mauvaise réponse 
		if (answer == 'o') {
			for (int i = 0; i < mystereGuess.size(); i++) {
				mystereVrai.push_back(mystereGuess[i]);
			}
		}

		if (answer == 'n' || answer == 'u') {
			cout << "Entrer les nom des deux individus mysteres" << endl;
			string nomMystere1, nomMystere2;
			cin >> nomMystere1 >> nomMystere2; // sauvegarder les noms dans une variable plus tard 
			while (validerCorrection(nomMystere1, nomMystere2) == false) {
				cout << ("veuillez entrez des noms d'individus présent dans la liste dans le format: nomMystere1  nomMystere2") << endl;
				cin >> nomMystere1 >> nomMystere2;
			}

			if (mystereGuess.size() == 1) { // si le nombre d'individu deviné egale à un
				if (nomMystere1 != mystereGuess[0].getNom()) { // si le nom mystere 1 est different de l'individu devine.
					mystereNonDeviner.push_back(nomMystere1);
				}
				if (nomMystere2 != mystereGuess[0].getNom()) {
					mystereNonDeviner.push_back(nomMystere2);
				}

			}


			if (mystereGuess.size() == 2) { // si le nombre d'individu deviné egale à deux 
				if (nomMystere1 != mystereGuess[0].getNom() && nomMystere1 != mystereGuess[1].getNom()) {
					mystereNonDeviner.push_back(nomMystere1);
				}
				if (nomMystere2 != mystereGuess[0].getNom() && nomMystere2 != mystereGuess[1].getNom()) {
					mystereNonDeviner.push_back(nomMystere2);
				}

			}
			



			mystereVrai.push_back(nomMystere1);
			mystereVrai.push_back(nomMystere2);
		}

		if (!(answer == 'o' || answer == 'n' || answer == 'u')) {
			cout << "invalid input!" << "Entrer 'o' pour oui, 'n' pour non ou 'u' pour un seul des individus identifies " << endl;

		
		}
	} while (!(answer == 'o' || answer == 'n' || answer == 'u'));//si answer n'est pas un caracter valide rester dans la boucle infini
	
}

bool Agent::devinerIndividusMysteres() {
	bool arretQuestions = false;
	if (tableauSuspect.size() == 2) { // si il reste deux individus dans le tableau 
		cout << "Les individus mystere sont: " << endl;
		for (int i = 0; i < tableauSuspect.size(); i++) {
			cout << tableauSuspect[i]->getNom() << endl;
			mystereGuess.push_back(tableauSuspect[i]->getNom());
		}
		Corriger();//vérifier si les individus devinés sont corrects
		arretQuestions = true; // variable indiquant la fin des questions 

		cout << "Les deux individus mysteres sont: ";
		for (int i = 0; i < mystereVrai.size(); i++) {
			cout << mystereVrai[i].getNom() << " ";
		}
		cout << endl;
	}
	if (individuMystere1.getGenie() != "" && individuMystere2.getGenie() != "" && tableauSuspect.size() != 2) { //
		cout << "Les individus mystere sont: " << endl;
		for (int i = 0; i < tableauSuspect.size(); i++) {
			if (tableauSuspect[i]->getCouleurCheveux() == individuMystere1.getCouleurCheveux() && tableauSuspect[i]->getCouleurYeux() == individuMystere1.getCouleurYeux()
				&& tableauSuspect[i]->getGenie() == individuMystere1.getGenie()) {
				mystereGuess.push_back(tableauSuspect[i]->getNom());
				cout << tableauSuspect[i]->getNom()<<endl;
			}
			if (tableauSuspect[i]->getCouleurCheveux() == individuMystere2.getCouleurCheveux() && tableauSuspect[i]->getCouleurYeux() == individuMystere2.getCouleurYeux()
				&& tableauSuspect[i]->getGenie() == individuMystere2.getGenie()) {
				mystereGuess.push_back(tableauSuspect[i]->getNom());
				cout  << tableauSuspect[i]->getNom() << endl;
			}
		}
		Corriger();//vérifier si les individus devinés sont corrects
		arretQuestions = true; // variable indiquant la fin des questions 

		cout << "Les deux individus mysteres sont: ";
		for (int i = 0; i < mystereVrai.size(); i++) {
			cout << mystereVrai[i].getNom() << " ";
		}
		cout << endl;
	}
	return arretQuestions;
}

void Agent::affichage() {
	cout << "Le nombre de questions posees est: " << questionCount << endl;
	
	
	if (mystereGuess.size() != 0) {
		cout << "Les individus mysteres trouves sont: ";
		for (int i = 0; i < mystereGuess.size(); i++) {
			if (mystereGuess[i].getNom() == mystereVrai[0].getNom() || mystereGuess[i].getNom() == mystereVrai[1].getNom()) { //verifier si lse individus trouvés correspondent au individu dictés par l'adversaire
				cout << mystereGuess[i].getNom() << " " << endl;
			}
		}
	}

	if (mystereNonDeviner.size() != 0) {
		cout << "Les individus mysteres non devinees sont: ";
		for (int i = 0; i < mystereNonDeviner.size(); i++) {
			
			cout << mystereNonDeviner[i].getNom() << " " << endl;
		}
	}
	
}

char Agent::PoserQuestion(string input, string caracteristique, string type) {
	cout << "Les individus ont ils  '" << type << "' pour caracteristique de type " << caracteristique <<"?" << endl;
	incrementerCount();//incrementer le compteur de question
	char rpnse;
	cin >> rpnse;
	ReduireListeSuspects(rpnse, input, caracteristique);
	return rpnse;
}

void Agent::trouverCheveux(char input  ) {
	bool CheveuxTrouver = false;
	vector<char> uOption;
	while (CheveuxTrouver == false) {
		switch (input) {
		case 'N':
		{
			char rep = PoserQuestion("N", "cheveux", "noir" );
			if (rep == 'o') {
				CheveuxTrouver = true; 
			}
			else if (rep == 'n') {
				input = 'B';
			}
			else if (rep == 'u') {
				uOption.push_back('N');
				
				//ajout de la condition pour sortir 
				if (uOption.size() == 2) {
					CheveuxTrouver = true;
				}
				input = 'B';
			}
			else {
				input = 'N';
			}
		}
		break;
		case 'B':
			{
			char rep1 = PoserQuestion("B", "cheveux", "blond" );
				if (rep1 == 'o') {
					CheveuxTrouver = true;
				}
				else if (rep1 == 'n') {
					input = 'M';
				}
				else if (rep1 == 'u') {
					uOption.push_back('B');
					if (uOption.size() == 2) {
						CheveuxTrouver = true;
					}
					else {
						input = 'M';
					}
				}
				else {
					input = 'B';
				}
			}
		break;
		case 'M':
		{
			char rep2 = PoserQuestion("M", "cheveux", "marron" );
		if (rep2 == 'o') {
			CheveuxTrouver = true;
		}
		else if (rep2 == 'n') {
			input = 'R';
		}
		else if (rep2 == 'u') {
			uOption.push_back('M');
			if (uOption.size() == 2) {
				CheveuxTrouver = true;
			}
			CheveuxTrouver = true;
		}
		else {
			input = 'M';
		}
		}
		break;
		case 'R':
		{
				char rep3 = PoserQuestion("R", "cheveux", "roux" );
			if (rep3 == 'o') {
				CheveuxTrouver = true;
			}
			else if (rep3 == 'u') {
				uOption.push_back('R');
				if (uOption.size() == 2) {
					CheveuxTrouver = true;
				}
				else
					input = 'N';
			}
			else {
				input = 'R';
			}
			}
			break;
		}
			if (deviner == true) {
				return;
			}
	}
	
	trouverYeux('N');//on pose à l'agent une question au sujet des yeux une fois les cheveux trouvés
}

void Agent::trouverYeux(char input  ) {
	vector<char> uOption;
	bool YeuxTrouver = false;
	while (YeuxTrouver == false) {
		switch (input) {
		case 'N':
			{
				char rep = PoserQuestion("N", "yeux", "noir");
				if (rep == 'o') {
					YeuxTrouver = true;

				}
				else if (rep == 'n') {
					input = 'B';
				}
				else if (rep == 'u') {
					uOption.push_back('N');
					input = 'B';
				}
				else {
					input = 'N';
				}
		}
		break;
		case 'B':
			{
			char rep1 = PoserQuestion("B", "yeux", "bleus");
			if (rep1 == 'o') {
				YeuxTrouver = true;
			}
			else if (rep1 == 'n') {
				input = 'M';
			}
			else if (rep1 == 'u') {
				uOption.push_back('B');
				if (uOption.size() == 2) {
					YeuxTrouver = true;
				}
				else {
					input = 'M';
				}
			}
			else {
				input = 'B';
			}
		}
		break;
		case 'M':
		{char rep2 = PoserQuestion("M", "yeux", "marron");
		if (rep2 == 'o') {
			YeuxTrouver = true;
		}
		else if (rep2 == 'n') {
			input = 'R';
		}
		else if (rep2 == 'u') {
			uOption.push_back('M');
			if (uOption.size() == 2) {
				YeuxTrouver = true;
			}
			else {
				input = 'R';
			}
		}
		else {
			input = 'M';
		}
		}
		break;
		case 'R':
		{
			char rep3 = PoserQuestion("R", "yeux", "rouge" );
		if (rep3 == 'o') {
			YeuxTrouver = true;
		}
		else if (rep3 == 'n') {
			input = 'V';
		}
		else if (rep3 == 'u') {
			uOption.push_back('R');
			if (uOption.size() == 2) {
				YeuxTrouver = true;
			}
			else {
				input = 'V';
			}
		}
		else {
			input = 'R';
		}
		}
		break;
		case 'V':
		{
				char rep4 = PoserQuestion("V", "yeux", "vert" );
			if (rep4 == 'o') {
				YeuxTrouver = true;
			}
			else if (rep4 == 'u') {
				uOption.push_back('V');
				if (uOption.size() == 2) {
					YeuxTrouver = true;
				}

				else
					input = 'G';
			}
			else {
				input = 'V';
			}

		}
		
		case 'G':
		{
			char rep5 = PoserQuestion("G", "yeux", "gris");
			if (rep5 == 'o') {
				YeuxTrouver = true;
			}
			else if (rep5 == 'u') {
				uOption.push_back('G');
				if (uOption.size() == 2) {
					YeuxTrouver = true;
				}

				YeuxTrouver = true;// condition pour sortir de la boucle car le programme est séquentielle
			}
			else {
				input = 'G';
			}

		}
		break;
		}
		if (deviner == true) {
			return;
		}
	}
	trouverGenie('GE' );//on pose à l'agent une question au suet du génie une fois les yeux trouvé
}

void Agent::trouverGenie(char input  ) {
	vector<char> uOption;
	bool GenieTrouver = false;
	while (GenieTrouver == false) {
		switch (input) {
			case 'E':
			{
					char rep = PoserQuestion("GE", "genie", "electrique" );
				if (rep == 'o') {
					GenieTrouver = true;
				}
				else if (rep == 'n') {
					input = 'I';
				}
				else if (rep == 'u') {
					uOption.push_back('E');
					input = 'I';
				}
				else {
					input = 'E';
				}
		    }
		break;
		case 'I':
			{char rep1 = PoserQuestion("GI", "genie", "informatique" );
			if (rep1 == 'o') {
				GenieTrouver = true;
			}
			else if (rep1 == 'n') {
				input = 'P';
			}
			else if (rep1 == 'u') {
				uOption.push_back('I');
				if (uOption.size() == 2) {
					GenieTrouver = true;
				}
				else {
					input = 'P';
				}
			}
			else {
				input = 'I';
			}
		}
		break;
		case 'P':
			{char rep2 = PoserQuestion("GP", "genie", "physique" );
			if (rep2 == 'o') {
				GenieTrouver = true;
			}
			else if (rep2 == 'n') {
				input = 'C';
			}
			else if (rep2 == 'u') {
				uOption.push_back('P');
				if (uOption.size() == 2) {
					GenieTrouver = true;
				}
				else {
					input = 'C';
				}
			}
			else {
				input = 'P';
			}
		}
		break;
		case 'C':
			{char rep3 = PoserQuestion("GC", "genie", "chimique" );
			if (rep3 == 'o') {
				GenieTrouver = true;
			}
			else if (rep3 == 'n') {
				input = 'A';
			}
			else if (rep3 == 'u') {
				uOption.push_back('C');
				if (uOption.size() == 2) {
					GenieTrouver = true;
				}
				else {
					input = 'A';
				}
			}
			else {
				input = 'C';
			}
		}
		break;
		case 'A':
			{char rep4 = PoserQuestion("GA", "genie", "aerospatial" );
			if (rep4 == 'o') {
				GenieTrouver = true;
			}
			else if (rep4 == 'n') {
				input = 'B';
			}
			else if (rep4 == 'u') {
				uOption.push_back('A');
				if (uOption.size() == 2) {
					GenieTrouver = true;
				}
				else {
					input = 'B';
				}
			}
			else {
				input = 'A';
			}
		}
		break;
		case 'B':
			{char rep5 = PoserQuestion("GB", "genie", "biomedical" );
			if (rep5 == 'o') {
				GenieTrouver = true;
			}
			else if (rep5 == 'n') {
				input = 'M';
			}
			else if (rep5 == 'u') {
				uOption.push_back('B');
				if (uOption.size() == 2) {
					GenieTrouver = true;
				}
				else {
					input = 'M';
				}
			}
			else {
				input = 'B';
			}
		}
		break;
		case 'M':
			{char rep6 = PoserQuestion("GM", "genie", "mecanique" );
			if (rep6 == 'o') {
				GenieTrouver = true;
			}
			else if (rep6 == 'n') {
				input = 'N';
			}
			else if (rep6 == 'u') {
				uOption.push_back('M');
				if (uOption.size() == 2) {
					GenieTrouver = true;
				}
				else {
					input = 'N';
				}
			}
			else {
				input = 'M';
			}
		}
		break;
		case 'N':
			{char rep7 = PoserQuestion("Gind", "genie", "industriel" );
			if (rep7 == 'o') {
				GenieTrouver = true;
			}
			else if (rep7 == 'n') {
				input = 'R';
			}
			else if (rep7 == 'u') {
				uOption.push_back('N');
				if (uOption.size() == 2) {
					GenieTrouver = true;
				}
				else {
					input = 'R';
				}
			}
			else {
				input = 'N';
			}
		}
		break;
		case 'R':
			{
			char rep8 = PoserQuestion("ER", "genie", "energetique" );
			if (rep8 == 'o') {
				GenieTrouver = true;
			}
			else if (rep8 == 'n') {
				input = 'E';
			}
			else if (rep8 == 'u') {
				uOption.push_back('R');
				if (uOption.size() == 2) {
					GenieTrouver = true;
				}
				GenieTrouver = true;
			}
			else {
				input = 'R';
			}
		}
		break;
		}
		if (deviner == true) {
			return;
		}
	}
}

