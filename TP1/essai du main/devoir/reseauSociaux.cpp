#include"reseauSociaux.h"
#include<iostream>
#include <exception>
#include <string>
#include <fstream>
#include "individu.h"
#include <vector>

reseauSociaux::reseauSociaux() {
	table_Individu = lirefichiertexte("Individus.txt");
}

vector<Individu*> reseauSociaux::lirefichiertexte(string nomfichier) {

	ifstream fichier(nomfichier);//declaration du fichier en mode lecture et ouverture du fichier 

	if (fichier.fail())
		throw exception("le fichier n'a pas reussi à être ouvert");
	else {



		//si le fichier est un fichier de personnes --on peut manipuler cette partie de sorte les varaivle fichier de relation
		if (nomfichier == "Individus.txt") {
			string couleur_cheveux, couleur_yeux;

			string genie;

			//char genie[4];///on pourrait creer un tableau de char soit char genie[2]--mais cela génére un bug pour une raison que j,ignore alors j,AI PRÉFERER GARDER STRING

			string nom;

			while (!ws(fichier).eof()) {//tant qu'il reste autre chose que des espaces

				fichier >> nom;
				fichier >> couleur_cheveux;
				fichier >> couleur_yeux;
				fichier >> genie;

				//creer un individu avec les caractéristiques ci dessus
				Individu* individu = new Individu(nom, couleur_cheveux, couleur_yeux, genie);
				table_Individu.push_back(individu);
			}

			fichier.close();	//si le fichier est un fichier de personnes
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
						break; //sortir de la boucle si on a trouvé l'individu
					}
				}
				for (Individu* item2 : table_Individu) { //rechercher l'individu portant le nom 2
					if (item2->getNom() == nom2) {
						individu2 = item2;
						break;//sortir de la boucle si on a trouvé l'individu
					}

				}

				if (individu1->getNom() == nom1 && individu2->getNom() == nom2) {// trouver les individus correspondant aux noms 
					individu1->setRelation(individu2, nombre_relation);//mettre a jour la relation entre les deux individus
					individu2->setRelation(individu1, nombre_relation);//mettre a jour la relation entre les deux individus
				}

			}
			fichier.close();
		}



	}


	return table_Individu;

}

void reseauSociaux::creerReseauSocial(string fichier1, string fichier2) {
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

/*nom: afficherReseauSocial

type parametre:void
type retour : void
fonction: affiche le reseau crée à partir du tableau d'individu de la partie


*/
void reseauSociaux::afficherReseauSocial() {

	for (Individu* individu : table_Individu) {

		//pour chaque individu de ma tableIndividu  ---->  afficher l'individu et son voisin 



		auto i = individu->getDonneesRelation().begin();
		auto fin = individu->getDonneesRelation().end();
		for (i; i != fin; i++) {

			cout << "(" << individu->getNom() << "," << i->first->getNom() << "," << "(" << i->second << ")" << ")" << endl;

		}
	}
};
