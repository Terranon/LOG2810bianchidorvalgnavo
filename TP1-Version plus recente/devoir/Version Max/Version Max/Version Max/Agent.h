#pragma once
#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include <string>
#include <vector>




#include "individu.h"
#include"foncteur.h"



using namespace std;
class Agent {



public:

	Agent();
	Agent(vector<Individu*> tab);
	~Agent();
	void setTable(vector<Individu*>&acopier);
	void ReduireListeSuspects(char reponse, string input, string caracteristique);
	void incrementerCount();
	bool Deviner();
	char PoserQuestion(string input, string caracteristique, string type);
	void QuestionCheveux(char input);
	void QuestionYeux(char input);
	void QuestionGenie(char input);
	void affichage();
	void Corriger();
	void  deepCopierVector(vector<Individu*>&acopier, vector <Individu*>& tableau);
	bool verifierCorrection(string nom1, string nom2);

	Individu getIndividuMystere1();
	Individu getIndividuMystere2();
	//void  deepCopierVectorIndividus(vector<Individu*>&acopier);



private:
	int questionCount;

	bool deviner;

	vector <Individu*> tableauSuspect;
	vector<Individu*> tableauIndividus;
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