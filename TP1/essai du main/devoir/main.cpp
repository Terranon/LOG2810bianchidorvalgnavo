#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "fonctions.h"
using namespace std;

///cr�er une classe partie??

///mettre les fonctions . h dans un fichiers et mettre �galement les classes individus dans un fichier



int main() {


	bool conditionboucle = true;

	while (conditionboucle) {

		char option;
		cout << "(a) Cr�er le reseau social " << endl << "(b) Afficher le reseau social" << endl << "(c) Jouer � Qui est-ce?" << endl << "(d) Afficher le resultat" << endl << "(e) Quitter";

		do {
			cout << "Choissisez une option valide � l'aide de la lettre ; e pour quitter par exemple";
			cin >> option;
			/// v�rifier toutees les combinaisons possibles que pourrait faire l'employer . le mieux serait de faire un bloc catch
			
		} while (option != 'a' && option != 'b' && option != 'c' && option != 'd' && option != 'e');
		string nomfichier1,nomfichier2;
	

		if (option == 'a') {///on peut utiliser des cases ici ou alors utiliser du polymorphisme option.faireoperation comportant des variables de selection afin d'�VITER LE IF OU LE CASE POUVANT ETRE DOTE DE BOOL OPTION VALIDER QUI SERA UNE VARIABLE PARTAGER PAR TOUTES LES CLASSES OPTIONS
		
			cout << "Entrez le nom du premier fichier";
			cin >> nomfichier1;
			cout << "Entrez le nom du deuxi�me fichier";
			cin >> nomfichier2;
			creerReseauSocial(nomfichier1,nomfichier2);
		
		
		}
		if (option == 'e')
			return 0;//terminer le programme
	
	
	}

}

// a faire creer une classe individu et completer les fonctions lirefichier qui devront crer un individu et le mettre dans un tableau d'individu 

// chaque classe individu a  un nom , des caracteristiques , et un tableau de voisins (qui sont des classes deriv�e d'individu qui ont une variable relation en plus  )

//on part du fait que les fichiers de relations et de ... sont correctement rentr�