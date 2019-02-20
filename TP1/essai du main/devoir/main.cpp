#include <iostream>
#include <fstream>
#include <string>
#include <exception>

#include "Agent.h"
#include "Jeu.h"
using namespace std;

///créer une classe partie??

///mettre les fonctions . h dans un fichiers et mettre également les classes individus dans un fichier



int main() {
	Jeu jeu;

	bool conditionboucle = true;
	bool conditionA = false;
	while (conditionboucle) {

		
		char option = jeu.selectionneroption();//fonction permettant la saisie d'une option valide
		
		string nomfichier1,nomfichier2;
	

		if (option == 'a') { ///on peut utiliser des cases ici ou alors utiliser du polymorphisme option.faireoperation comportant des variables de selection afin d'ÉVITER LE IF OU LE CASE POUVANT ETRE DOTE DE BOOL OPTION VALIDER QUI SERA UNE VARIABLE PARTAGER PAR TOUTES LES CLASSES OPTIONS
			

			cout << "Entrez le nom du premier fichier";
			cin >> nomfichier1;
			cout << "Entrez le nom du deuxième fichier";
			cin >> nomfichier2;
			//creerReseauSocial(nomfichier1,nomfichier2);
			jeu.creerReseauSocial(nomfichier1,nomfichier2);

			conditionA = true;
		
		}
		if (option == 'b' ) {  //si l'option a  avait déja été sélectionner et l'option b 

			if (conditionA)
				jeu.afficherReseauSocial(); //afficherReseauSocial();
			else
				cout << "L'option A doit avoir ete selectionner avant l'option B" << endl;
		
		}
		if (option == 'c') {
				
				Agent agent(jeu.gettableauIndividu());
				agent.QuestionCheveux('N', agent);

		}
			
		if (option == 'e')
			return 0;//terminer le programme-- si le programme retourne comment avoir la possibilité de reprendre correctement le jeu qui -est-ce?
		
	
	}

}

// a faire creer une classe individu et completer les fonctions lirefichier qui devront crer un individu et le mettre dans un tableau d'individu 

// chaque classe individu a  un nom , des caracteristiques , et un tableau de voisins (qui sont des classes derivée d'individu qui ont une variable relation en plus  )

//on part du fait que les fichiers de relations et de ... sont correctement rentré