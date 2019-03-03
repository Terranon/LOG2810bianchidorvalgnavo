#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "individu.h"
#include <fstream>
#include "agent.h"
using namespace std;

class Jeu {
public:

	Jeu();

	//void copierAgent(Agent* agent);
	vector<Individu*>gettableauIndividu();
	void resetAgent() { // on le reinitialise par defaut

		Agent agentnouveau;
		agent = agentnouveau;


	};
	char selectionneroption();
	void creerReseauSocial(string nomfichier1, string nomfichier2);
	void validerlecturefichier(string fichier1, string fichier2);
	Agent& getAgent() { return agent; };
	void lirefichierdanstable(string nomfichier);

	void afficherReseauSocial();
	void incrementer() { nombre_partie++; };
	int getnombrepartie()const { return nombre_partie; };

	void afficherResultat() { agent.affichage(); };
private:
	bool resultat;
	vector <Individu*> tableIndividus_;
	Agent agent;
	int nombre_partie;
};