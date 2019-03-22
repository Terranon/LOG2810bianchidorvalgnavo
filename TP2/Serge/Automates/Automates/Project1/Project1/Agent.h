#ifndef AGENT_H
#define AGENT_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Porte.h"
#include "Boss.h"

using namespace std;
class Agent {
public:
	Agent();
	~Agent();

	void ouvrirPorte(fstream& Porte1) {

		if (deciderProchainePorte()->getEstGouffre()) {
			//retourner a la porte 1
			porteCourante_ = chemin_[0];

		}
		else
		{
			// 
			porteCourante_ = deciderProchainePorte();
		}


	};
	Porte* deciderProchainePorte();
	void afficherLeCheminParcouru();

private:

	vector<pair<Porte*, int>> tableauDeProbaValide_; // pour aider a la decision de la prochaine porte a prendre
	Porte* porteCourante_;
	vector<Porte*> chemin_;//il doit se souvenir du chemin et de l'input 
    Boss* boss;
};
#endif