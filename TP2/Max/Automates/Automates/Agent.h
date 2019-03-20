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

	void ouvrirPorte(fstream& Porte1);
	Porte* deciderProchainePorte();
	void afficherLeCheminParcouru();

private:
	
	vector<pair<Porte*, int>> tableauDeProbaValide_; // pour aider a la decision de la prochaine porte a prendre
	Porte* porteCourante_;
	vector<Porte*> chemin_;
};
#endif