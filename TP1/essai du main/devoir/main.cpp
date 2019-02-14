#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

///créer une classe partie??

///mettre les fonctions . h dans un fichiers et mettre également les classes individus dans un fichier


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
				cout << "l'individu " << nom << "ayant pour caractèristiques" << couleur_cheveux << " " << couleur_yeux << " " << genie << endl;
			}

			//si le fichier est un fichier de personnes
		}
		
		//si le fichier est un fichier de relation 
		if (nomfichier=="Relations.txt") {
			string nom1, nom2;
			int nombre_relation;
			while (!ws(fichier).eof()) {//tant qu'il reste autre chose que des espaces

				fichier >> nom1;
				fichier >> nombre_relation;
				fichier >> nom2;
				

				//creer un individu avec les caractéristiques ci dessus
				cout << "l'individu " << nom1 << " ayant pour relation " << nombre_relation << " et pour voisin " << nom2<<endl;
			}
		}
		
	
	
	}




}

void creerReseauSocial(string fichier1,string fichier2) {
	bool fichier1lu=false ;
	bool fichier2lu = false; 
	do {

		try {
			if(fichier1lu==false){//si le fichier1 n'avait pas été lu correctement on essaie de le lire
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

		
	} while (!fichier1lu || !fichier2lu);// on reste dans la boucle tant que les fichiers n'ont pas été lu correctement 




}


int main() {


	bool conditionboucle = true;

	while (conditionboucle) {

		char option;
		cout << "(a) Créer le reseau social " << endl << "(b) Afficher le reseau social" << endl << "(c) Jouer à Qui est-ce?" << endl << "(d) Afficher le resultat" << endl << "(e) Quitter";

		do {
			cout << "Choissisez une option valide à l'aide de la lettre ; e pour quitter par exemple";
			cin >> option;
			/// vérifier toutees les combinaisons possibles que pourrait faire l'employer . le mieux serait de faire un bloc catch
			
		} while (option != 'a' && option != 'b' && option != 'c' && option != 'd' && option != 'e');
		string nomfichier1,nomfichier2;
	

		if (option == 'a') {///on peut utiliser des cases ici ou alors utiliser du polymorphisme option.faireoperation comportant des variables de selection afin d'ÉVITER LE IF OU LE CASE POUVANT ETRE DOTE DE BOOL OPTION VALIDER QUI SERA UNE VARIABLE PARTAGER PAR TOUTES LES CLASSES OPTIONS
		
			cout << "Entrez le nom du premier fichier";
			cin >> nomfichier1;
			cout << "Entrez le nom du deuxième fichier";
			cin >> nomfichier2;
			creerReseauSocial(nomfichier1,nomfichier2);
		
		
		}
	
	
	}

}

// a faire creer une classe individu et completer les fonctions lirefichier qui devront crer un individu et le mettre dans un tableau d'individu 

// chaque classe individu a  un nom , des caracteristiques , et un tableau de voisins (qui sont des classes derivée d'individu qui ont une variable relation en plus  )

//on part du fait que les fichiers de relations et de ... sont correctement rentré