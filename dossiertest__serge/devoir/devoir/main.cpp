#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "fonctions.h"
using namespace std;

///créer une classe partie??

///mettre les fonctions . h dans un fichiers et mettre également les classes individus dans un fichier



int main() {


	bool conditionboucle = true;

	while (conditionboucle) {

		
		char option = selectionneroption();//fonction permettant la saisie d'une option valide
		
		string nomfichier1,nomfichier2;
	

		if (option == 'a') {///on peut utiliser des cases ici ou alors utiliser du polymorphisme option.faireoperation comportant des variables de selection afin d'ÉVITER LE IF OU LE CASE POUVANT ETRE DOTE DE BOOL OPTION VALIDER QUI SERA UNE VARIABLE PARTAGER PAR TOUTES LES CLASSES OPTIONS
		
			cout << "Entrez le nom du premier fichier";
			cin >> nomfichier1;
			cout << "Entrez le nom du deuxième fichier";
			cin >> nomfichier2;
			creerReseauSocial(nomfichier1,nomfichier2);
		
		
		}
		if (option == 'e')
			return 0;//terminer le programme-- si le programme retourne comment avoir la possibilité de reprendre correctement le jeu qui -est-ce?
	
	
	}

}

// a faire creer une classe individu et completer les fonctions lirefichier qui devront crer un individu et le mettre dans un tableau d'individu 

// chaque classe individu a  un nom , des caracteristiques , et un tableau de voisins (qui sont des classes derivée d'individu qui ont une variable relation en plus  )

//on part du fait que les fichiers de relations et de ... sont correctement rentré