#pragma once
#include<iostream>
#include <exception>
#include <string>
#include <fstream>
using namespace std;

/*
Nom:CreerReseauSocial
type Param�tre: ofstream
type retour: void

fonction : lit les fichiers texte et  g�nere un individu, g�n�re le r�seau social correspondant

*/


////je pense a separer en deux la lecture du fichier de relation et la lecture du fichier individus
void lirefichiertexte(string nomfichier) {

	ifstream fichier(nomfichier);//ouverture du fichier

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
				cout << "l'individu " << nom << "ayant pour caract�ristiques" << couleur_cheveux << " " << couleur_yeux << " " << genie << endl;
			}

			//si le fichier est un fichier de personnes
		}

		//si le fichier est un fichier de relation<iostream>
#include <exception>
		#include <string>

		if (nomfichier == "Relations.txt") {
			string nom1, nom2;
			int nombre_relation;
			while (!ws(fichier).eof()) {//tant qu'il reste autre chose que des espaces

				fichier >> nom1;
				fichier >> nombre_relation;
				fichier >> nom2;


				//creer un individu avec les caract�ristiques ci dessus
				cout << "l'individu " << nom1 << " ayant pour relation " << nombre_relation << " et pour voisin " << nom2 << endl;
			}
		}



	}




}

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
	#include <exception>
	#include <string>





}

