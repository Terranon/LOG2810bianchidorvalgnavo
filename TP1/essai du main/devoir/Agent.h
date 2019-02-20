#pragma once
#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include <string>
#include <vector>

#include "foncteur.h"


using namespace std;
class Agent {
	
	//char reponsepossible[5] = { 'u','s','n','o' }; // une taille de 5 car le cinqui�me caractere est le caractere de fin 
	
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

private:
		int questionCount ;
	
	vector <Individu*> tableauSuspect;
	
};
#endif