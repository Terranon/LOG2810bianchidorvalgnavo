#include "Agent.h"
#include <algorithm>

#include<iostream>
#include <exception>
#include <string>
#include <fstream>
#include "individu.h"
#include <vector>

using namespace std;




//Constructeur d'agent 
Agent::Agent(vector<Individu*>tab) {

	
	questionCount = 0;
<<<<<<< HEAD
=======
	Individu individuMystere1(" ", " ", " ", " ");
	Individu individuMystere2(" ", " ", " ", " ");
	vector<string> characteristic;
	vector<string> characteristicGenie;
	vector<string> characteristicYeux;
	vector<Individu> mystereGuess;
	vector<Individu> mystereNonDeviner;
	vector<Individu> mystereVrai;

}
>>>>>>> fc9f10546ca531d7a5fc6c31ec9460c97b62d2f7

	deepCopierVector(tab);// on copie tout les individu dans le tableau de suspect


}


	/*
		nom: deepCopierVector
		paramètre: vector<Invidu*>&
		type retour : void
		fonction: effectue une deep copie d'un vecteur

		*/
	void  Agent::deepCopierVector(vector<Individu*>&vector) {


		for (Individu* item : vector) {

			Individu* individuTemp = new Individu(*item);
			tableauSuspect.push_back(individuTemp);//mise à jour du vector
		}

	};

 ///------------ voir ici en cas de erreur d'exécution 


/*
nom : incrementerCount
retour : void
type parametre : void
fonction : incremente la valeur de la variable questionCount de 1

*/

void Agent::incrementerCount() {

	questionCount++;


}


///------------ voir ici en cas de erreur d'exécution 

void Agent::IdentifierIndividus(char reponse, string input, string caracteristique) {
	//caracteristiques : cheveux , yeux et génie  //input c'est le type particulier soit de cheveux, de yeux , de génie 
	
	switch (reponse) {
	case 'o':
		if (caracteristique == "cheveux") {
			//convertion du string input en string
			auto debut = tableauSuspect.begin();
			auto fin = tableauSuspect.end();
<<<<<<< HEAD
			
			tableauSuspect.erase(remove_if(debut, fin, Predicat(caracteristique, input)), fin);

=======
				auto it = remove_if(debut, fin, Predicat(caracteristique, input));
				tableauSuspect.erase(it, fin);// --------------------si ça n'execute pas regarder ici
				individuMystere1.setCouleurCheveux(input);
				individuMystere2.setCouleurCheveux(input);
>>>>>>> fc9f10546ca531d7a5fc6c31ec9460c97b62d2f7
		}

		if (caracteristique == "yeux") {

			auto debut = tableauSuspect.begin();
			auto fin = tableauSuspect.end();
<<<<<<< HEAD
			
			tableauSuspect.erase(remove_if(debut, fin, Predicat(caracteristique, input)), fin);// --------------------si ça n'execute pas regarder ici
											  //tableauSuspect.erase(remove_if(debut, fin, predicat_yeux(*individu, input)), fin);// --------------------si ça n'execute pas regarder ici
			

=======
				auto it = remove_if(debut, fin, Predicat(caracteristique, input));
				tableauSuspect.erase(it, fin);// --------------------si ça n'execute pas regarder ici
											  //tableauSuspect.erase(remove_if(debut, fin, predicat_yeux(*individu, input)), fin);// --------------------si ça n'execute pas regarder ici
				individuMystere1.setCouleurYeux(input);
				individuMystere2.setCouleurYeux(input);
>>>>>>> fc9f10546ca531d7a5fc6c31ec9460c97b62d2f7


		}

		if (caracteristique == "genie") {

			auto debut = tableauSuspect.begin();
			auto fin = tableauSuspect.end();
<<<<<<< HEAD
			
				tableauSuspect.erase(remove_if(debut, fin, Predicat(caracteristique, input)), fin);// --------------------si ça n'execute pas regarder ici
			
=======
				auto it = remove_if(debut, fin, Predicat(caracteristique, input));
				tableauSuspect.erase(it, fin);// --------------------si ça n'execute pas regarder ici
				individuMystere1.setGenie(input);
				individuMystere2.setGenie(input);
>>>>>>> fc9f10546ca531d7a5fc6c31ec9460c97b62d2f7
		}

		deviner=Deviner();
		incrementerCount();
		break;
	case 'u':
		if (caracteristique == "cheveux") {
			characteristic.push_back(input);
			if (characteristic.size() == 2) {
				auto debut = tableauSuspect.begin();
				auto fin = tableauSuspect.end();
				tableauSuspect.erase(remove_if(debut, fin, PredicatU(caracteristique, characteristic[0], characteristic[1])), fin);// --------------------si ça n'execute pas regarder ici
				individuMystere1.setCouleurCheveux(characteristic[0]);
				individuMystere2.setCouleurCheveux(characteristic[1]);
			}
		}

		if (caracteristique == "yeux") {
			characteristicYeux.push_back(input);


			auto debut = tableauSuspect.begin();
			auto fin = tableauSuspect.end();
				if (characteristicYeux.size() == 2) {
					tableauSuspect.erase(remove_if(debut, fin, PredicatU(caracteristique, characteristicYeux[0], characteristicYeux[1])), fin);
					individuMystere1.setCouleurYeux(characteristicYeux[0]);
					individuMystere2.setCouleurYeux(characteristicYeux[1]);
					//tableauSuspect.erase(remove_if(debut, fin, predicatYeuxU(*individu, caracteristique[0], caracteristique[1])), fin);// --------------------si ça n'execute pas regarder ici

				}
		}

		if (caracteristique == "genie") {
			characteristicGenie.push_back(input);


			auto debut = tableauSuspect.begin();
			auto fin = tableauSuspect.end();
				if (characteristicGenie.size() == 2) {
					tableauSuspect.erase(remove_if(debut, fin, PredicatU(caracteristique, characteristicGenie[0], characteristicGenie[1])), fin);
					individuMystere1.setGenie(characteristicGenie[0]);
					individuMystere2.setGenie(characteristicGenie[1]);
				}
		}
		deviner=Deviner();
		incrementerCount();
		break;
	case 'n':

		if (caracteristique == "cheveux") {
			//convertion du string input en string
			auto debut = tableauSuspect.begin();
			auto fin = tableauSuspect.end();
				auto it = remove_if(debut, fin, PredicatN(caracteristique, input));
				tableauSuspect.erase(it, fin);// --------------------si ça n'execute pas regarder ici
		}

		if (caracteristique == "yeux") {

			auto debut = tableauSuspect.begin();
			auto fin = tableauSuspect.end();
				auto it = remove_if(debut, fin, PredicatN(caracteristique, input));
				tableauSuspect.erase(it, fin);// --------------------si ça n'execute pas regarder ici
		}

		if (caracteristique == "genie") {

			auto debut = tableauSuspect.begin();
			auto fin = tableauSuspect.end();
				auto it = remove_if(debut, fin, PredicatN(caracteristique, input));
				tableauSuspect.erase(it, fin);// --------------------si ça n'execute pas regarder ici
		}
		deviner=Deviner();

		incrementerCount();
		break;
	case 's':
		cout << "Les suspect encore sur la liste sont: " << endl;
		for (int i = 0; i < tableauSuspect.size(); i++) {
			cout << tableauSuspect[i]->getNom() << endl;
		}
		break;
	default:
		cout << "invalid input" << endl;
		char reponse;
		cin >> reponse;
		break;
	}
};

void Agent::Corriger() {
	cout << "Est ce correct?" << endl;
	char answer;

	cin >> answer;  // faire une gestion de mauvaise réponse 
	if (answer == 'o') {
		for (int i = 0; i < mystereGuess.size();i++) {
			mystereVrai.push_back(mystereGuess[i]);
		}
	}
	if (answer == 'n' || answer == 'u') {
		cout << "Entrer les nom des deux individus mysteres" << endl;
		string nomMystere1, nomMystere2;
		cin >> nomMystere1 >> nomMystere2; // sauvegarder les noms dans une variable plus tard 
		if (nomMystere1 != mystereGuess[0].getNom() && nomMystere1 != mystereGuess[1].getNom()) {
			mystereNonDeviner.push_back(nomMystere1);
		}
		if (nomMystere2 != mystereGuess[0].getNom() && nomMystere2 != mystereGuess[1].getNom()) {
			mystereNonDeviner.push_back(nomMystere2);
		}
		mystereVrai.push_back(nomMystere1);
		mystereVrai.push_back(nomMystere2);
	}
}

bool Agent::Deviner() {
	bool aDeviner = false;
	if (tableauSuspect.size() == 2) {
		cout << "Les individus mystere sont: " << endl;
		for (int i = 0; i < tableauSuspect.size(); i++) {
			cout << tableauSuspect[i]->getNom() << endl;
			mystereGuess.push_back(tableauSuspect[i]->getNom());
		}
		Corriger();
		aDeviner = true;

		cout << "Les deux individus mysteres sont: ";
		for (int i = 0; i < mystereVrai.size();i++) {
			cout << mystereVrai[i].getNom() << " ";
		}
		cout << endl;
	}
	if (individuMystere1.getGenie() != "" && individuMystere2.getGenie() != "" && tableauSuspect.size() != 2) {
		cout << "Les individus mystere sont: " << endl;
		for (int i = 0; i < tableauSuspect.size();i++) {
				if (tableauSuspect[i]->getCouleurCheveux() == individuMystere1.getCouleurCheveux() && tableauSuspect[i]->getCouleurYeux() == individuMystere1.getCouleurYeux()
					&& tableauSuspect[i]->getGenie() == individuMystere1.getGenie()) {
					mystereGuess.push_back(tableauSuspect[i]->getNom());
					cout << tableauSuspect[i]->getNom();
				}
				if (tableauSuspect[i]->getCouleurCheveux() == individuMystere2.getCouleurCheveux() && tableauSuspect[i]->getCouleurYeux() == individuMystere2.getCouleurYeux()
					&& tableauSuspect[i]->getGenie() == individuMystere2.getGenie()) {
					mystereGuess.push_back(tableauSuspect[i]->getNom());
					cout << " " << tableauSuspect[i]->getNom()<<endl;
				}
			}
		Corriger();
		aDeviner = true;

		cout << "Les deux individus mysteres sont: ";
		for (int i = 0; i < mystereVrai.size();i++) {
			cout << mystereVrai[i].getNom() << " ";
		}
		cout << endl;
	}
	return aDeviner;
}

void Agent::affichage() {
	cout << "Le nombre de questions posees est: " << questionCount << endl;
	cout << "Les deux individus mysteres sont: ";
	for (int i = 0; i < mystereVrai.size();i++) {
		cout << mystereVrai[i].getNom() << " "<<endl;
	}
	cout << "Les deux individus mysteres devinees sont: ";
	for (int i = 0; i < mystereVrai.size();i++) {
		cout << mystereGuess[i].getNom() << " " << endl;
	}
	cout << "Les individus mysteres non devinees sont: ";
	if (mystereNonDeviner.size() != 0) {
		for (int i = 0; i < mystereNonDeviner.size();i++) {
			cout << mystereNonDeviner[i].getNom()<<" "<<endl;
		}
	}
	else {
		cout << "aucun"<<endl;
	}
	cout << endl;
}

char Agent::PoserQuestion(string input, string caracteristique, string type, Agent agent) {
	if (caracteristique == "cheveux" || caracteristique == "yeux") {
		cout << "Est ce que les individus ont les " << caracteristique << " " << type << endl;
	}
	if (caracteristique == "genie") {
		cout << "Est ce que les individus sont en " << caracteristique << " " << type << endl;
	}
	char rpnse;
	cin >> rpnse;
	IdentifierIndividus(rpnse, input, caracteristique);
	return rpnse;
}

void Agent::QuestionCheveux(char input, Agent agent) {
	bool CheveuxTrouver = false;
	vector<char> uOption;
	while (CheveuxTrouver == false) {
		switch (input) {
		case 'N':
		{char rep = PoserQuestion("N", "cheveux", "noir", agent);
		if (rep == 'o') {
			CheveuxTrouver = true;
		}
		else if (rep == 'n') {
			input = 'M';
		}
		else if(rep=='u'){
			uOption.push_back('N');
			input = 'M';
		}
		else {
			input='N';
		}
		}
		break;
		case 'B':
<<<<<<< HEAD
			{char rep1 = PoserQuestion("B", "cheveux", "blond", agent);
			if (rep1 == 'o') {
=======
		{char rep1 = PoserQuestion("B", "cheveux", "blond", agent);
		if (rep1 == 'o') {
			CheveuxTrouver = true;
		}
		else if (rep1 == 'n') {
			input = 'R';
		}
		else if (rep1=='u'){
			uOption.push_back('B');
			if (uOption.size() == 2) {
>>>>>>> fc9f10546ca531d7a5fc6c31ec9460c97b62d2f7
				CheveuxTrouver = true;
			}
			else if (rep1 == 'n') {
				input = 'R';
			}
<<<<<<< HEAD
			else {
				uOption.push_back('B');
				if (uOption.size() == 2) {
					CheveuxTrouver = true;
				}
				else {
					input = 'R';
				}
			}
		}
		break;
		case 'M':
			{char rep2 = PoserQuestion("M", "cheveux", "marron", agent);
			if (rep2 == 'o') {
=======
		}
		else {
			input = 'B';
		}
		}
		break;
		case 'M':
		{char rep2 = PoserQuestion("M", "cheveux", "marron", agent);
		if (rep2 == 'o') {
			CheveuxTrouver = true;
		}
		else if (rep2 == 'n') {
			input = 'B';
		}
		else if (rep2=='u'){
			uOption.push_back('M');
			if (uOption.size() == 2) {
>>>>>>> fc9f10546ca531d7a5fc6c31ec9460c97b62d2f7
				CheveuxTrouver = true;
			}
			else if (rep2 == 'n') {
				input = 'B';
			}
<<<<<<< HEAD
			else {
				uOption.push_back('M');
				if (uOption.size() == 2) {
					CheveuxTrouver = true;
				}
				else {
					input = 'B';
				}
			}
		}
		break;
		case 'R':
			{char rep3 = PoserQuestion("R", "cheveux", "roux", agent);
			if (rep3 == 'o') {
				CheveuxTrouver = true;
			}
			else {
				uOption.push_back('R');
				if (uOption.size() == 2) {
					CheveuxTrouver = true;
				}
				CheveuxTrouver = true;
			}
=======
		}
		else {
			input = 'M';
		}
		}
		break;
		case 'R':
		{char rep3 = PoserQuestion("R", "cheveux", "roux", agent);
		if (rep3 == 'o') {
			CheveuxTrouver = true;
		}
		else if (rep3=='u'){
			uOption.push_back('R');
			if (uOption.size() == 2) {
				CheveuxTrouver = true;
			}
			CheveuxTrouver = true;
		}
		else {
			input = 'R';
		}
>>>>>>> fc9f10546ca531d7a5fc6c31ec9460c97b62d2f7
		}
		break;
		}
		if (deviner == true) {
			return;
		}
	}QuestionYeux('N', agent);
}

void Agent::QuestionYeux(char input, Agent agent) {
	vector<char> uOption;
	bool YeuxTrouver = false;
	while (YeuxTrouver == false) {
		switch (input) {
		case 'N':
		{char rep = PoserQuestion("N", "yeux", "noir", agent);
		if (rep == 'o') {
			YeuxTrouver = true;
			
		}
		else if (rep == 'n') {
			input = 'B';
		}
		else if (rep=='u'){
			uOption.push_back('N');
			input = 'B';
		}
		else {
			input = 'N';
		}
		}
		break;
		case 'B':
		{char rep1 = PoserQuestion("B", "yeux", "bleus", agent);
		if (rep1 == 'o') {
			YeuxTrouver = true;
		}
		else if (rep1 == 'n') {
			input = 'M';
		}
		else if(rep1=='u'){
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
		{char rep2 = PoserQuestion("M", "yeux", "marron", agent);
		if (rep2 == 'o') {
			YeuxTrouver = true;
		}
		else if (rep2 == 'n') {
			input = 'R';
		}
		else if(rep2=='u'){
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
		{char rep3 = PoserQuestion("R", "yeux", "rouge", agent);
		if (rep3 == 'o') {
			YeuxTrouver = true;
		}
		else if (rep3 == 'n') {
			input = 'V';
		}
		else if (rep3=='u') {
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
		{char rep4 = PoserQuestion("V", "yeux", "vert", agent);
		if (rep4 == 'o') {
			YeuxTrouver = true;
		}
		else if (rep4=='u') {
			uOption.push_back('V');
			if (uOption.size() == 2) {
				YeuxTrouver = true;
			}
			YeuxTrouver = true;
		}
		else {
			input = 'V';
		}

		}
		break;
		}
		if (deviner == true) {
			return;
		}
	}QuestionGenie('GE', agent);
}

void Agent::QuestionGenie(char input, Agent agent) {
	vector<char> uOption;
	bool GenieTrouver = false;
	while (GenieTrouver == false) {
		switch (input) {
		case 'E':
		{char rep = PoserQuestion("GE", "genie", "electrique", agent);
		if (rep == 'o') {
			GenieTrouver = true;
		}
		else if (rep == 'n') {
			input = 'I';
		}
		else if(rep=='u'){
			uOption.push_back('E');
			input = 'I';
		}
		else {
			input = 'E';
		}
		}
		break;
		case 'I':
		{char rep1 = PoserQuestion("GI", "genie", "informatique", agent);
		if (rep1 == 'o') {
			GenieTrouver = true;
		}
		else if (rep1 == 'n') {
			input = 'P';
		}
		else if(rep1=='u'){
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
		{char rep2 = PoserQuestion("GP", "genie", "physique", agent);
		if (rep2 == 'o') {
			GenieTrouver = true;
		}
		else if (rep2 == 'n') {
			input = 'C';
		}
		else if(rep2=='u'){
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
		{char rep3 = PoserQuestion("GC", "genie", "chimique", agent);
		if (rep3 == 'o') {
			GenieTrouver = true;
		}
		else if (rep3 == 'n') {
			input = 'A';
		}
		else if(rep3=='u') {
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
		{char rep4 = PoserQuestion("GA", "genie", "aerospatial", agent);
		if (rep4 == 'o') {
			GenieTrouver = true;
		}
		else if (rep4 == 'n') {
			input = 'B';
		}
		else if(rep4=='u'){
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
		{char rep5 = PoserQuestion("GB", "genie", "biomedical", agent);
		if (rep5 == 'o') {
			GenieTrouver = true;
		}
		else if (rep5 == 'n') {
			input = 'M';
		}
		else if(rep5=='u'){
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
		{char rep6 = PoserQuestion("GM", "genie", "mecanique", agent);
		if (rep6 == 'o') {
			GenieTrouver = true;
		}
		else if (rep6 == 'n') {
			input = 'N';
		}
		else if(rep6=='u'){
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
		{char rep7 = PoserQuestion("Gind", "genie", "industriel", agent);
		if (rep7 == 'o') {
			GenieTrouver = true;
		}
		else if (rep7 == 'n') {
			input = 'R';
		}
		else if(rep7=='u'){
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
		{char rep8 = PoserQuestion("ER", "genie", "energetique", agent);
		if (rep8 == 'o') {
			GenieTrouver = true;
		}
		else if(rep8=='u'){
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