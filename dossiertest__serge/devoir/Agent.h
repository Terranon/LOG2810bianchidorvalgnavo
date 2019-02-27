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
	    Agent(vector<Individu*>tab);
		~Agent();
		void setTable(vector<Individu*>tab);

		void ReduireListeSuspects(char reponse, string input, string caracteristique);
		void incrementerCount();
		bool Deviner();
		char PoserQuestion(string input, string caracteristique, string type);
		void QuestionCheveux(char input);
		void QuestionYeux(char input);
		void QuestionGenie(char input);
		void affichage();
		void Corriger();

		void  deepCopierVector(vector<Individu*>&vector);

	

	

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