
#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include <string>
#include <vector>
#include "individu.h"
#include"foncteur.h"
#include "reseauSociaux.h"

using namespace std;
class Agent {



public:

	Agent();

	vector<Individu*> lirefichiertexte(string nomfichier);
	void IdentifierIndividus(char reponse, string input, string caracteristique);
	void incrementerCount();
	bool Deviner();
	char PoserQuestion(string input, string caracteristique, string type, Agent agent);
	void QuestionCheveux(char input, Agent agent);
	void QuestionYeux(char input, Agent agent);
	void QuestionGenie(char input, Agent agent);
	void affichage();

private:
	int questionCount;
	bool deviner;
	vector <Individu*> tableauSuspect;
	vector<string> characteristic;
	vector<string> characteristicGenie;
	vector<string> characteristicYeux;
	vector<Individu> mystereGuess;
	vector<Individu> mystereNonDeviner;
	vector<Individu> mystereVrai;
	Individu individuMystere1;
	Individu individuMystere2;

};
#endif