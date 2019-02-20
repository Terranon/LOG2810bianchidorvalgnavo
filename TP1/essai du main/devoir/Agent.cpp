

#include "Agent.h"

#include <algorithm>


using namespace std;




//Constructeur d'agent 
Agent::Agent(vector<Individu*>tab) {

	questionCount = 0;
	deepCopierVector(tab);// on copie tout les individu dans le tableau de suspect

}


	/*
	nom : incrementerCount
	retour : void 
	type parametre : void
	fonction : incremente la valeur de la variable questionCount de 1

	*/

	void Agent::incrementerCount() {
	
		questionCount++;
	
	
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

	void Agent::IdentifierIndividus(char reponse, string input, string caracteristique) {
		//caracteristiques : cheveux , yeux et génie  //input c'est le type particulier soit de cheveux, de yeux , de génie 

		switch (reponse) {
			case 'o':
				if (caracteristique == "cheveux") {
					//convertion du string input en string
					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						auto it = remove_if(debut,fin,Predicat(caracteristique,input));
						tableauSuspect.erase(it, fin);// --------------------si ça n'execute pas regarder ici

					}
					
				}

				if (caracteristique == "yeux") {

					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						auto it = remove_if(debut, fin, Predicat(caracteristique, input));
						tableauSuspect.erase(it, fin);// --------------------si ça n'execute pas regarder ici
						//tableauSuspect.erase(remove_if(debut, fin, predicat_yeux(*individu, input)), fin);// --------------------si ça n'execute pas regarder ici
					}


				
				}

				if (caracteristique == "genie") {

					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						auto it = remove_if(debut, fin, Predicat(caracteristique, input));
						tableauSuspect.erase(it, fin);// --------------------si ça n'execute pas regarder ici
					}
				}

				Deviner();
				incrementerCount();
		
			case 'u':
				if (caracteristique == "cheveux") {
					vector<string> characteristic;
					characteristic.push_back(input);

					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect){
						if (caracteristique.size() == 2) {

							tableauSuspect.erase(remove_if(debut, fin, PredicatU(caracteristique, characteristic[0], characteristic[1])), fin);// --------------------si ça n'execute pas regarder ici

							//tableauSuspect.erase(remove_if(debut, fin, predicatCheveuxU(*individu, caracteristique[0], caracteristique[1])), fin);// --------------------si ça n'execute pas regarder ici

						}
					}
				 
				}

				if (caracteristique == "yeux") {
					vector<string> characteristic;
					characteristic.push_back(input);


					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect){
						if (caracteristique.size() == 2) {
							tableauSuspect.erase(remove_if(debut, fin, PredicatU(caracteristique, characteristic[0], characteristic[1])), fin);
							
			//tableauSuspect.erase(remove_if(debut, fin, predicatYeuxU(*individu, caracteristique[0], caracteristique[1])), fin);// --------------------si ça n'execute pas regarder ici

						}
					}
				}

				if (caracteristique == "genie") {
					vector<string> characteristic;
					characteristic.push_back(input);


					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						if (caracteristique.size() == 2) {
							tableauSuspect.erase(remove_if(debut, fin, PredicatU(caracteristique, characteristic[0], characteristic[1])), fin);
							
						}
					}
				}
				Deviner();
				incrementerCount();
			case 'n':
		
				if (caracteristique == "cheveux") {
					//convertion du string input en string
					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						auto it = remove_if(debut, fin, PredicatN(caracteristique, input));
						tableauSuspect.erase(it, fin);// --------------------si ça n'execute pas regarder ici
					}
					
				}

				if (caracteristique == "yeux") {

					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						auto it = remove_if(debut, fin, PredicatN(caracteristique, input));
						tableauSuspect.erase(it, fin);// --------------------si ça n'execute pas regarder ici

					}
				}

				if (caracteristique == "genie") {

					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						auto it = remove_if(debut, fin, PredicatN(caracteristique, input));
						tableauSuspect.erase(it, fin);// --------------------si ça n'execute pas regarder ici
					}
				}
				Deviner();

				incrementerCount();
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

			}

			
	};

	void Agent::Deviner() {
		if (tableauSuspect.size() == 2) {
			cout << "Les individus mystere sont: " << endl;
			for (int i = 0; i < tableauSuspect.size(); i++) {
				cout << tableauSuspect[i]->getNom() << endl;
			}
			cout << "Est ce correct?" << endl;
			char answer;

			cin >> answer;  // faire une gestion de mauvaise réponse 

			if (answer == 'n' || answer == 'u') {
				cout << "Entrer les nom des deux individus mysteres" << endl;
				string nomMystere1, nomMystere2;

				cin >> nomMystere1 >> nomMystere2; // sauvegarder les noms dans une variable plus tard 
			}
		}
	}

	char Agent::PoserQuestion(string input, string caracteristique, string type, Agent agent) {

		cout << "est ce que les individus ont les" << caracteristique << type<<endl;
		char rpnse;
		cin >> rpnse;
		agent.IdentifierIndividus(rpnse, input, caracteristique);
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
				else {
					uOption.push_back('N');
					input = 'M';
				}
				}
				break;
			case 'B':
				{char rep1 = PoserQuestion("B", "cheveux", "blond", agent);
				if (rep1 == 'o') {
					CheveuxTrouver = true;
				}
				else if (rep1 == 'n') {
					input = 'R';
				}
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
					CheveuxTrouver = true;
				}
				else if (rep2 == 'n') {
					input = 'B';
				}
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
				}
				break;
			}
			QuestionYeux('N', agent);
		}
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
				else {
					uOption.push_back('N');
					input = 'B';
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
				else {
					uOption.push_back('B');
					if (uOption.size() == 2) {
						YeuxTrouver = true;
					}
					else {
						input = 'M';
					}
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
				else {
					uOption.push_back('M');
					if (uOption.size() == 2) {
						YeuxTrouver = true;
					}
					else {
						input = 'R';
					}
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
				else {
					uOption.push_back('R');
					if (uOption.size() == 2) {
						YeuxTrouver = true;
					}
					else {
						input = 'V';
					}
				}
				}
				break;
			case 'V':
				{char rep4 = PoserQuestion("V", "yeux", "vert", agent);
				if (rep4 == 'o') {
					YeuxTrouver = true;
				}
				else {
					uOption.push_back('V');
					if (uOption.size() == 2) {
						YeuxTrouver = true;
					}
					YeuxTrouver = true;
				}
				}
				break;
			}

			QuestionGenie('GE',agent);
		}
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
					else {
						uOption.push_back('E');
						input = 'I';
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
					else {
						uOption.push_back('I');
						if (uOption.size() == 2) {
							GenieTrouver = true;
						}
						else {
							input = 'P';
						}
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
					else {
						uOption.push_back('P');
						if (uOption.size() == 2) {
							GenieTrouver = true;
						}
						else {
							input = 'C';
						}
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
					else {
						uOption.push_back('C');
						if (uOption.size() == 2) {
							GenieTrouver = true;
						}
						else {
							input = 'A';
						}
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
					else {
						uOption.push_back('A');
						if (uOption.size() == 2) {
							GenieTrouver = true;
						}
						else {
							input = 'B';
						}
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
					else {
						uOption.push_back('B');
						if (uOption.size() == 2) {
							GenieTrouver = true;
						}
						else {
							input = 'M';
						}
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
					else {
						uOption.push_back('M');
						if (uOption.size() == 2) {
							GenieTrouver = true;
						}
						else {
							input = 'N';
						}
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
					else {
						uOption.push_back('N');
						if (uOption.size() == 2) {
							GenieTrouver = true;
						}
						else {
							input = 'R';
						}
					}
					}
					break;
				case 'R':
					{char rep8 = PoserQuestion("ER", "genie", "energetique", agent);
					if (rep8 == 'o') {
						GenieTrouver = true;
					}
					else {
						uOption.push_back('R');
						if (uOption.size() == 2) {
							GenieTrouver = true;
						}
						GenieTrouver = true;
					}
					}
					break;
				}

			}
		}