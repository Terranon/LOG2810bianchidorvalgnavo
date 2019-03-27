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

	void parcourirLabyrinthe();
	void ouvrirPorte(string Porte1);
	string deciderProchainePorte();
	void afficherLeCheminParcouru();

private:
	//Une Porte---Nombre de fois franchi --- Pourcentage de succes
	vector<pair<Porte*, pair<int, int>>> tableauDeProbaValide_; // pour aider a la decision de la prochaine porte a prendre
	Porte* porteCourante_;
	Boss* boss_;
	vector<Porte*> chemin_;
};
#endif