
#include <iostream>
#include <vector>
#include <string> 
#include "Agent.h"
#include <cstring>
#include <algorithm>
using namespace std;




//Constructeur d'agent 
Agent::Agent() {

	questionCount = 0;
	//tableauSuspect = table_Individu;//faire une deep copie du tableauSuspect 

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
	/*void CreerStructure(string fichier) {

		Individus temp;
		ifstream in(fichier);
		if (!in) {
			cout << "The input file did not open.";
		}
		string line;
		while (getline(in, line))
			stringstream ss(line);
			if (ss>>temp.nom>>temp.cheveux>>temp.yeux>>temp.genie) {
				individu.push.back(temp);
			}
		in.close();
	}*/


	bool Agent::predicat_cheveux( const Individu& item, string input)
	{
			return item.getCouleurCheveux() != input;//retourne vrai si la couleur est différente de la valeur entrée (input)
	}

	bool Agent::predicatCheveuxU(const Individu& item, string input, string input2)
	{
		if (item.getCouleurCheveux() != input && item.getCouleurCheveux() != input2) {
			return true;
		}
	}

	bool Agent::predicat_yeux(const Individu& item, string input)
	{
		return item.getCouleurYeux() != input;
	}

	bool Agent::predicatYeuxU(const Individu& item, string input, string input2)
	{
		if (item.getCouleurCheveux() != input && item.getCouleurCheveux() != input2) {
			return true;
		}
	}

	bool Agent::predicat_genie(const Individu& item, string input)
	{
		return item.getGenie() != input;
	}

	bool Agent::predicatGenieU(const Individu& item, string input, string input2)
	{
		if (item.getGenie() != input && item.getGenie() != input2) {
			return true;
		}
	}
 ///------------ voir ici en cas de erreur d'exécution 
	
	void Agent::IdentifierIndividus(reponsepossible reponse, string input, string caracteristique) {
		//caracteristiques : cheveux , yeux et génie  //input c'est le type particulier soit de cheveux, de yeux , de génie 

		switch (reponse) {
			case o:
				if (caracteristique == "cheveux") {
					//convertion du string input en string
					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						tableauSuspect.erase(remove_if(debut, fin, predicat_cheveux(*individu, input)), fin);// --------------------si ça n'execute pas regarder ici

					}
					//mystere1.setCouleurCheveux(input);
					//mystere2.setCouleurCheveux(input);
				}

				if (caracteristique == "yeux") {

					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						tableauSuspect.erase(remove_if(debut, fin, predicat_yeux(*individu, input)), fin);// --------------------si ça n'execute pas regarder ici

					}


					//mystere1.setCouleurYeux(input);
					//mystere2.setCouleurYeux(input);
				}

				if (caracteristique == "genie") {

					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						tableauSuspect.erase(remove_if(debut, fin, predicat_genie(*individu, input)), fin);// --------------------si ça n'execute pas regarder ici

					}
					/*
					mystere1.setGenie(input);
					mystere2.setGenie(input);*/
				}

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
				incrementerCount();
		
			case u:
				if (caracteristique == "cheveux") {
					vector<string> caracteristique;
					caracteristique.push_back(input);

					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect){
						if (caracteristique.size() == 2) {
							tableauSuspect.erase(remove_if(debut, fin, predicatCheveuxU(*individu, caracteristique[0], caracteristique[1])), fin);// --------------------si ça n'execute pas regarder ici
						}
					}
				 
				}

				if (caracteristique == "yeux") {
					vector<string> caracteristique;
					caracteristique.push_back(input);

					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect){
						if (caracteristique.size() == 2) {
							tableauSuspect.erase(remove_if(debut, fin, predicatYeuxU(*individu, caracteristique[0], caracteristique[1])), fin);// --------------------si ça n'execute pas regarder ici
						}
					}
				}

				if (caracteristique == "genie") {
					vector<string> caracteristique;
					caracteristique.push_back(input);

					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						if (caracteristique.size() == 2) {
							tableauSuspect.erase(remove_if(debut, fin, predicatGenieU(*individu, caracteristique[0], caracteristique[1])), fin);// --------------------si ça n'execute pas regarder ici
						}
					}
				}
				incrementerCount();
			case n:
		
				if (caracteristique == "cheveux") {
					//convertion du string input en string
					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						tableauSuspect.erase(remove_if(debut, fin, !predicat_cheveux(*individu, input)), fin);// --------------------si ça n'execute pas regarder ici

					}
					//mystere1.setCouleurCheveux(input);
					//mystere2.setCouleurCheveux(input);
				}

				if (caracteristique == "yeux") {

					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						tableauSuspect.erase(remove_if(debut, fin, !predicat_yeux(*individu, input)), fin);// --------------------si ça n'execute pas regarder ici

					}


					//mystere1.setCouleurYeux(input);
					//mystere2.setCouleurYeux(input);
				}

				if (caracteristique == "genie") {

					auto debut = tableauSuspect.begin();
					auto fin = tableauSuspect.end();
					for (Individu* individu : tableauSuspect) {
						tableauSuspect.erase(remove_if(debut, fin, !predicat_genie(*individu, input)), fin);// --------------------si ça n'execute pas regarder ici

					}
					/*
					mystere1.setGenie(input);
					mystere2.setGenie(input);*/
				}

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
				incrementerCount();
			case s:
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


