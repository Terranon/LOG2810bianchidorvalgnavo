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
fonction : instancie un objet de type individu � partir de ses caract�ristiques et l'insere dans la table d'individu



*/


/*
Nom:selectionneroption
type Param�tre: void
type retour: char
fonction : genere une boucle tant que l'usager ne saisit pas un caractere parmi ceux propos� par l'interface console

*/


char selectionneroption() {
	char option;
	cout << "(a) Cr�er le reseau social " << endl << "(b) Afficher le reseau social" << endl << "(c) Jouer � Qui est-ce?" << endl << "(d) Afficher le resultat" << endl << "(e) Quitter"<<endl;

	do {
		cout << "Choissisez une option valide � l'aide de la lettre: e pour quitter par exemple "<<endl;
		cin >> option;
		/// v�rifier toutees les combinaisons possibles que pourrait faire l'employer . le mieux serait de faire un bloc catch

	} while (option != 'a' && option != 'b' && option != 'c' && option != 'd' && option != 'e');

	return option;
}
/*
Nom:CreerReseauSocial
type Param�tre: ofstream
type retour: void
fonction : lit les fichiers texte et  g�nere un individu, g�n�re le r�seau social correspondant

*/


////je pense a separer en deux la lecture du fichier de relation et la lecture du fichier individus
void lirefichiertexte(string nomfichier) {
	
	ifstream fichier(nomfichier);//declaration du fichier en mode lecture et ouverture du fichier 

	if (fichier.fail())
		throw exception("le fichier n'a pas reussi � �tre ouvert");
	else {
		
		

		//si le fichier est un fichier de personnes --on peut manipuler cette partie de sorte les varaivle fichier de relation
		if (nomfichier == "Individus.txt") {
			char couleur_cheveux, couleur_yeux;

			string genie;
			
			//char genie[4];///on pourrait creer un tableau de char soit char genie[2]--mais cela g�n�re un bug pour une raison que j,ignore alors j,AI PR�FERER GARDER STRING

			string nom;
		
			while (!ws(fichier).eof()) {//tant qu'il reste autre chose que des espaces

				fichier >> nom;
				fichier >> couleur_cheveux;
				fichier >> couleur_yeux;
				fichier >> genie;

				//creer un individu avec les caract�ristiques ci dessus
				Individu* individu =new Individu(nom,couleur_cheveux,couleur_yeux,genie);
				table_Individu.push_back(individu);
				cout << "l'individu " << nom << "ayant pour caract�ristiques" << individu->getCouleurCheveux() << " " << individu->getCouleurYeux() << " " << individu->getGenie()<< endl;
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

			
				Individu* individu1 = nullptr;
				Individu* individu2 = nullptr;
				for (Individu* item1 : table_Individu) { //rechercher l'individu portant le nom 1
					if (item1->getNom() == nom1) {
						individu1 = item1; 
						break; //sortir de la boucle si on a trouv� l'individu
				    }
				}
				for (Individu* item2 : table_Individu) { //rechercher l'individu portant le nom 2
					if (item2->getNom() == nom2) {
						individu2 = item2;
						break;//sortir de la boucle si on a trouv� l'individu
					}
						
				}

				if (individu1->getNom() == nom1 and individu2->getNom() == nom2) {// trouver les individus correspondant aux noms 
					individu1->setRelation(individu2, nombre_relation);//mettre a jour la relation entre les deux individus
					individu2->setRelation(individu1, nombre_relation);//mettre a jour la relation entre les deux individus
					cout << "l'individu " << individu1->getNom() << " ayant pour relation " << individu1->getValeurRelation(nom2) << " et pour voisin " << individu2->getNom() << endl;

				}
				
			}
				
		}



	}




}
/*

nom: CreerReseauSocial
type parametre: string ,string
type retour : void
fonction: g�n�re un reseau social � partir de la lecture des fichiers

*/

//segmenter en deuxfonctions lire fichiers : genere un table d�'individu pour la partie en cours  lire fichiertexte ne font que lire les choses et cree les individus et leurs relations
void creerReseauSocial(string fichier1, string fichier2) {
	bool fichier1lu = false;
	bool fichier2lu = false;
	do {

		try {
			if (fichier1lu == false) {//si le fichier1 n'avait pas �t� lu correctement on essaie de le lire
				lirefichiertexte(fichier1);
				fichier1lu = true;//le fichier1 devient valide des qu'on parvient a le lire
			}
			if (fichier2lu == false) {//si le fichier 2 n'avait pas �t� lu correctement on essaie de le lire
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


	} while (!fichier1lu || !fichier2lu);// on reste dans la boucle tant que les fichiers n'ont pas �t� lu correctement<iostream>



}

/*nom: afficherReseauSocial

type parametre:void
type retour : void
fonction: affiche le reseau cr�e � partir du tableau d'individu de la partie


*/
void afficherReseauSocial() {

	for (Individu* individu : table_Individu) {
	
		//pour chaque individu de ma tableIndividu  ---->  afficher l'individu et son voisin 

		

		auto i = individu->getDonneesRelation().begin();
		auto fin = individu->getDonneesRelation().end();
		for (i; i != fin; i++) {
		
			cout << "(" << individu->getNom() << "," << i->first->getNom() << "," << "(" << i->second << ")" << ")" << endl;
		
		}
	}
};
