#pragma once
#include<iostream>
#include <exception>
#include <string>
#include <fstream>
#include "individu.h"
#include <vector>
using namespace std;

vector<Individu*>table_Individu;//declarer le tableau qui contiendra les individus 
///attribut de partie 

/*
nom: insererindividu
type:
type retour :
fonction : instancie un objet de type individu à partir de ses caractéristiques et l'insere dans la table d'individu



*/


/*
Nom:selectionneroption
type Paramètre: void
type retour: char
fonction : genere une boucle tant que l'usager ne saisit pas un caractere parmi ceux proposé par l'interface console

*/


char selectionneroption() {
	char option;
	cout << "(a) Créer le reseau social " << endl << "(b) Afficher le reseau social" << endl << "(c) Jouer à Qui est-ce?" << endl << "(d) Afficher le resultat" << endl << "(e) Quitter"<<endl;

	do {
		cout << "Choissisez une option valide à l'aide de la lettre: e pour quitter par exemple "<<endl;
		cin >> option;
		/// vérifier toutees les combinaisons possibles que pourrait faire l'employer . le mieux serait de faire un bloc catch

	} while (option != 'a' && option != 'b' && option != 'c' && option != 'd' && option != 'e');

	return option;
}
/*
Nom:CreerReseauSocial
type Paramètre: ofstream
type retour: void
fonction : lit les fichiers texte et  génere un individu, génère le réseau social correspondant

*/


////je pense a separer en deux la lecture du fichier de relation et la lecture du fichier individus
void lirefichiertexte(string nomfichier) {
	
	ifstream fichier(nomfichier);//ouverture du fichier

	if (fichier.fail())
		throw exception("le fichier n'a pas reussi à être ouvert");
	else {
		
		

		//si le fichier est un fichier de personnes --on peut manipuler cette partie de sorte les varaivle fichier de relation
		if (nomfichier == "Individus.txt") {
			char couleur_cheveux, couleur_yeux;

			string genie;
			
			//char genie[4];///on pourrait creer un tableau de char soit char genie[2]--mais cela génére un bug pour une raison que j,ignore alors j,AI PRÉFERER GARDER STRING

			string nom;
		
			while (!ws(fichier).eof()) {//tant qu'il reste autre chose que des espaces

				fichier >> nom;
				fichier >> couleur_cheveux;
				fichier >> couleur_yeux;
				fichier >> genie;

				//creer un individu avec les caractéristiques ci dessus
				Individu* individu =new Individu(nom,couleur_cheveux,couleur_yeux,genie);
				table_Individu.push_back(individu);
				cout << "l'individu " << nom << "ayant pour caractèristiques" << individu->getCouleurCheveux() << " " << individu->getCouleurYeux() << " " << individu->getGenie()<< endl;
			}

			//si le fichier est un fichier de personnes
		}

		//si le fichier est un fichier de relation<iostream>
		

		if (nomfichier == "Relations.txt") {
			string nom1, nom2;
			int nombre_relation;
			while (!ws(fichier).eof()) {//tant qu'il reste autre chose que des espaces

				fichier >> nom1;
				fichier >> nombre_relation;
				fichier >> nom2;



				
				//mettre a jour la table de relation
				for (Individu* item : table_Individu) {//parcourir le tableau d'individu a la recherche de l'individu portant le nom2
					if (item->getNom() == nom2)
						item->setRelation(nom1, nombre_relation); //mettre a jour la relation entre les deux individus
					if (item->getNom() == nom1) {//parcourir le tableau d'individu a la recherche de l'individu portant le nom1
						item->setRelation(nom2, nombre_relation);//mettre a jour la relation entre les deux individus
					//creer un individu avec les caractéristiques ci dessus
						cout << "l'individu " << item->getNom() << " ayant pour relation " << item->getRelation(nom2) << " et pour voisin " << nom2 << endl;
					}

				}
			}
				
		}



	}




}
/*

nom: CreerReseauSocial
type parametre: string ,string
type retour : void
fonction: génère un reseau social à partir de la lecture des fichiers

*/

//segmenter en deuxfonctions lire fichiers : genere un table dù'individu pour la partie en cours  lire fichiertexte ne font que lire les choses et cree les individus et leurs relations
void creerReseauSocial(string fichier1, string fichier2) {
	bool fichier1lu = false;
	bool fichier2lu = false;
	do {

		try {
			if (fichier1lu == false) {//si le fichier1 n'avait pas été lu correctement on essaie de le lire
				lirefichiertexte(fichier1);
				fichier1lu = true;//le fichier1 devient valide des qu'on parvient a le lire
			}
			if (fichier2lu == false) {//si le fichier 2 n'avait pas été lu correctement on essaie de le lire
				lirefichiertexte(fichier2);
				fichier2lu = true;// le fichier2 devient valide des qu'on parvient a le lire
			}
		}
		catch (exception& e) {



			if (!fichier1lu) {
				cout << "Entrer un nom valide pour le fichier1 ";
				cin >> fichier1;

			}

			else
				if (!fichier2lu) {
					cout << "Entrer un nom valide pour le fichier2 ";
					cin >> fichier2;


				}

		}


	} while (!fichier1lu || !fichier2lu);// on reste dans la boucle tant que les fichiers n'ont pas été lu correctement<iostream>



}


