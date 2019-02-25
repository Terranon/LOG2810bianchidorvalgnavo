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

	
	    Agent(vector<Individu*>tab);
		

		void IdentifierIndividus( char reponse, string input, string caracteristique);
		void incrementerCount();
		void Deviner();
		char PoserQuestion(string input, string caracteristique, string type, Agent agent);
		void QuestionCheveux(char input, Agent agent);
		void QuestionYeux(char input, Agent agent);
		void QuestionGenie(char input, Agent agent);
		void  deepCopierVector(vector<Individu*>&vector);

	

<<<<<<< HEAD
	
=======
	vector<Individu*> lirefichiertexte(string nomfichier);
	void IdentifierIndividus(char reponse, string input, string caracteristique);
	void incrementerCount();
	bool Deviner();
	char PoserQuestion(string input, string caracteristique, string type, Agent agent);
	void QuestionCheveux(char input, Agent agent);
	void QuestionYeux(char input, Agent agent);
	void QuestionGenie(char input, Agent agent);
	void affichage();
	void Corriger();
>>>>>>> fc9f10546ca531d7a5fc6c31ec9460c97b62d2f7

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