#ifndef AGENT_H
#define AGENT_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Porte.h"

using namespace std;
class Agent {
public:
	Agent();
	~Agent();


	void parcourirLabyrinthe() {
		ouvrirPorte("rien");

	};
	void entrerLabyrinthe() {

		Porte* porte1 = new Porte("Porte1");

		chemin_.push_back(porte1);
		porteCourante_ = porte1;
		tableauDeProbaValide_.push_back(make_pair(porte1->getNom(), 100));

	};
	void ouvrirPorte(string porte) {


		Porte* portechoisi = deciderProchainePorte();
		if (portechoisi->getEstGouffre()) {

			//chercher dans le tableau de probablit� valide, la porte en question 

			auto it = tableauDeProbaValide_.begin();
			//auto itportecourante=it;
			for (it; it != tableauDeProbaValide_.end(); it++) {
				if (it->first == portechoisi->getNom()) {
					it->second--;//diminuer la valeur de it->second=int pour diminuer la probabilit� qu'il soit choisi a nouveau   -- je vais mettre la probablit� a z�ro 
					//it->second = 0; si la porte est un gouffre 
					//il faut aussi un cas si on a visiter toutes les portes connect� a la porte courante .
					//si toutes les portes connectes on leurs probabilit�s a z�ro alors on met la probablit� de la porte courante a z�ro et on reprend au tout debut.

					/*if (it->first == porteCourante_->getNom()) {
						itportecourante = it;
					}*/
					//int count = 0;

					/*for(unsigned int i=0;i<porteCourante_->getPortesConnecter().size();i++){
					  //parcourir le tableau de probabilit�
								for (it tableauDeProbaValide_.begin(); it != tableauDeProbaValide_.end();it++) {
									if (it->first == porteCourante_->getPortesConnecter()->getNom()) {

										count ++;//compter si toutes les portes connect�s sont improbables.
									 }
								}
					}

						if(count ==porteCourante_->getPortesConnecter().size()) // toutes les portes connect�s menent a un cul de sac . {

						soit it->first==porteCourante_->getNom()  -- utiliser find_if()
						   itportecourante->second=0;
						}



					*/
					break;
				}


			}

			//retourner a la porte 1
			porteCourante_ = chemin_[0];
			chemin_.push_back(porteCourante_);

		}
		else
		{
			// 
			porteCourante_ = portechoisi;
			chemin_.push_back(porteCourante_);
		}


	};
	Porte* deciderProchainePorte()

	{


		bool existence;//donne l'existence d'une porte connect� dans le chemin 
		//chercher si la probabilit� des portes connect�s existent 
		//si mon chemin ne contient pas une porte connect� je calcule sa probabilit�
		for (int p = 0; p < porteCourante_->getPortesConnecter().size(); p++) {
			existence = false;

			for (int h = 0; h < chemin_.size(); h++) {

				if (porteCourante_->getPortesConnecter()[p].first == chemin_[h]->getNom()) {
					existence = true;
					break;
				}

			}

			if (existence == false) {

				pair<string, int> paire = make_pair(porteCourante_->getPortesConnecter()[p].first, (100 / porteCourante_->getPortesConnecter().size()));
				tableauDeProbaValide_.push_back(paire); // le tableau de probablit� doit prendre en compte le parent si on va de porte1a porte3 et si on va de porte2 a porte 3 la probablit� de la choisir doit etre diff�rent -- si la porte est un gouffre la probablit� de le choisir doit etre null
			}


		}
		/*
		dans le cas ou nous sommes au debut du chemi
				//chercher dans le tableau de probablit� valide, la porte en question
			auto it = chemin_[chemin_.size() - 1]->getPortesConnecter().begin();
			for (unsigned int i = 0; i < chemin_[chemin_.size() - 1]->getPortesConnecter().size; i++) {

				tableauDeProbaValide_.push_back(make_pair(it,(100/ chemin_[chemin_.size() - 1]->getPortesConnecter().size)))

			}
		*/
		Porte* porteparent = nullptr;

		int i;
		for (i = chemin_.size() - 1; i >= 0; i--) {

			if (chemin_[i]->getNom() == porteCourante_->getNom()) {
				porteparent = chemin_[i];
				break;
			}
			//une porte qui a sa probabilit� diminu� .
			//je prend la porte parent =chemin[i-1]
			//porte parent de la porte courante .



		}


		//parcourir la porte parent a la recherche de la porte pr�sentant la plus haute probablit�
		int probabilit� = -1;
		string portechoisi;
		for (int j = 0; j < porteparent->getPortesConnecter().size() && porteparent != nullptr; j++) {

			for (int k = 0; k < tableauDeProbaValide_.size(); k++) { //recherce dans le tableau de la port4 ayant la plus grande probablit�
				if (tableauDeProbaValide_[k].first == porteparent->getPortesConnecter()[j].first &&tableauDeProbaValide_[k].second > probabilit�)
					probabilit� = tableauDeProbaValide_[k].second;//mise a jour de la probablit�
				portechoisi = tableauDeProbaValide_[k].first;

			}

		}
		//ajouter ici si mon chemin contient deja le nom de la porte choisi pas besoin de crer une nouvelle porte .
		Porte * porte = new Porte(portechoisi);

		return porte;


	};
	//void afficherLeCheminParcouru() ;
	Porte* getPorteCourante() {


		return porteCourante_;

	};
	void setPorteCourante();	
	void afficherLeCheminParcouru(vector <Porte*> chemin_);
private:
	//nomporte , valeur probablit� 

	vector<pair<string, int>> tableauDeProbaValide_; // pour aider a la decision de la prochaine porte a prendre
	Porte* porteCourante_;
	vector<Porte*> chemin_;//il doit se souvenir du chemin et de l'input 


};
#endif