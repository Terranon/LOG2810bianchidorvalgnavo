#include <iostream>
#include <fstream>
#include <string>
#include <exception>

#include "Agent.h"

#include "Jeu.h"

#include "chemin.h"

using namespace std;


char selectionneroption() {
	char option;
	cout << "(a) Creer le reseau social " << endl << "(b) Afficher le reseau social" << endl << "(c) Jouer a Qui est-ce?" << endl << "(d) Afficher le resultat" << endl << "(e) Quitter" << endl;

	do {
		cout << "Choissisez une option valide a l'aide de la lettre: e pour quitter par exemple " << endl;
		cin >> option;


	} while (option != 'a' && option != 'b' && option != 'c' && option != 'd' && option != 'e');

	return option;
}


int main() {
	Jeu jeu;

	bool conditionboucle = true;
	bool conditionA = false;
	bool conditionC = false;
	while (conditionboucle) {
		Agent agent(jeu.gettableauIndividu());

		char option = jeu.selectionneroption();//fonction permettant la saisie d'une option valide

		string nomfichier1, nomfichier2;

		if (option == 'a') { ///on peut utiliser des cases ici ou alors utiliser du polymorphisme option.faireoperation comportant des variables de selection afin d'ÉVITER LE IF OU LE CASE POUVANT ETRE DOTE DE BOOL OPTION VALIDER QUI SERA UNE VARIABLE PARTAGER PAR TOUTES LES CLASSES OPTIONS

			cout << "Entrez le nom du premier fichier (Individus.txt) : ";

			cin >> nomfichier1;
			cout << "Entrez le nom du deuxieme fichier (Relations.txt) : ";
			cin >> nomfichier2;


			jeu.creerReseauSocial(nomfichier1, nomfichier2);

			conditionA = true;

		}
		if (option == 'b') {

			if (conditionA)

				jeu.afficherReseauSocial();

			else
				cout << "L'option A doit avoir ete selectionner avant l'option B" << endl;

		}
		if (option == 'c') {

			if (conditionA) {

				if (jeu.getnombrepartie() >= 1) {
					jeu.resetAgent();
				}

				Agent & agent = jeu.getAgent();
				vector<Individu*>table = jeu.gettableauIndividu();
				agent.setTable(table);


				agent.demarrerjeu();
				jeu.incrementer();
				conditionC = true;
			}
			else
				cout << "L'option A doit avoir ete selectionner avant l'option C" << endl;


		}
		if (option == 'd') {

			if (conditionC) {
				jeu.afficherResultat();
				Chemin chemin(jeu);
				chemin.enleverArcsIndesirables(jeu.gettableauIndividu()[0], jeu.gettableauIndividu()[1], "N", "B", "GE");
				Individu* individuMystere1 = new Individu(agent.getIndividuMystere1());
				Individu* individuMystere2 = new Individu(agent.getIndividuMystere2());
				chemin.trouverChaineContacts(individuMystere1, individuMystere2);
			}
			else {
				cout << "L'option C doit avoir ete selectionner avant l'option d" << endl;
			}


		}
		if (option == 'e')
			return 0;//terminer le programme-- si le programme retourne comment avoir la possibilité de reprendre correctement le jeu qui -est-ce?


	}


}

