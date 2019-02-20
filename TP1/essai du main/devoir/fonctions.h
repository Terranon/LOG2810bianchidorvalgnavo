#pragma once 
#ifndef FONCTION_H
#define FONCTION_H

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
vector<Individu*> lirefichiertexte(string nomfichier) {
	
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
					cout << "l'individu " << individu1->getNom() << " ayant pour relation " << individu1->getValeurRelation(nom2) << " et pour voisin " << individu2->getNom() << endl;

				}
				
			}
				
		}



	}


	return table_Individu;

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

/*nom: afficherReseauSocial

type parametre:void
type retour : void
fonction: affiche le reseau crée à partir du tableau d'individu de la partie


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

/*
nom: deepCopierVector
paramètre: vector<Invidu*>&
type retour : void
fonction: effectue une deep copie d'un vecteur

*/
//void  deepCopierVector(vector<Individu*>&deepCopyOfVector) {
//	
//	for (int i = 0; i < table_Individu.size(); i++) {
//		Individu* individuTemp = new Individu(*table_Individu[i]); 
//		deepCopyOfVector.push_back(individuTemp);//mise à jour du vector
//	}
//	
//};
/*
map<pair<Individu*, Individu*>, int> deepCopier() {
	int nbrIndividus = table_Individu.size();
	map<pair<Individu*, Individu*>, int> sousGraph;

	for (int copyIt = 0; copyIt < nbrIndividus; copyIt++) {
		Individu* individuLeft = new Individu(*table_Individu[copyIt]);
		auto mapIt = individuLeft->getDonneesRelation().begin();
		for (mapIt; mapIt != table_Individu[copyIt]->getDonneesRelation().end(); mapIt++) {
			Individu* individuRight = new Individu(*(mapIt->first));
			int valeurRelationTemp = mapIt->second;
			pair<Individu*, Individu*> pairClef = make_pair(individuLeft, individuRight);
			sousGraph.insert(make_pair(pairClef, valeurRelationTemp));
		}
	}
	return sousGraph;
};



map<pair<Individu*, Individu*>, int> enleverArcsIndesirables(string couleursCheveux, string couleursYeux, string genie) {

	map<pair<Individu*, Individu*>, int> sousGraph = deepCopier();

	// cheveux indesirables
	auto sousGraphIt = sousGraph.begin();
	for (sousGraphIt; sousGraphIt != sousGraph.end(); sousGraphIt++) {
		if (sousGraphIt->second != 0) {
			if (sousGraphIt->first.first->getCouleurCheveux() == couleursCheveux) {
				if (sousGraphIt->first.second->getCouleurCheveux() == couleursCheveux) {
					sousGraphIt->second = 0;
				}
			}
		}
	}

	// yeux indesirables
	sousGraphIt = sousGraph.begin();
	for (sousGraphIt; sousGraphIt != sousGraph.end(); sousGraphIt++) {
		if (sousGraphIt->second != 0) {
			if (sousGraphIt->first.first->getCouleurYeux() == couleursYeux) {
				if (sousGraphIt->first.second->getCouleurYeux() == couleursYeux) {
					sousGraphIt->second = 0;
				}
			}
		}
	}

	// genie indesirables
	sousGraphIt = sousGraph.begin();
	for (sousGraphIt; sousGraphIt != sousGraph.end(); sousGraphIt++) {
		if (sousGraphIt->second != 0) {
			if (sousGraphIt->first.first->getGenie() == genie) {
				if (sousGraphIt->first.second->getGenie() == genie) {
					sousGraphIt->second = 0;
				}
			}
		}
	}
	return sousGraph;
};
*/
void afficherSousGraph(map<pair<Individu*, Individu*>, int> sousGraph) {
	auto mapIt = sousGraph.begin();
	for (mapIt; mapIt != sousGraph.end(); mapIt++) {
		cout << "(" << mapIt->first.first->getNom() << "," << mapIt->first.second->getNom() << ","
			<< "(" << mapIt->second << ")" << ")" << endl;
	}
};
#endif