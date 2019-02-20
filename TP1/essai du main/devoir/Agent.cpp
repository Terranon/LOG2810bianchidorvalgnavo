

#include "Agent.h"

#include <algorithm>

#include"foncteur.h"
using namespace std;




//Constructeur d'agent 
Agent::Agent() {

	questionCount = 0;
	deepCopierVector(tableauSuspect);// on copie tout les individu dans le tableau de suspect

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
