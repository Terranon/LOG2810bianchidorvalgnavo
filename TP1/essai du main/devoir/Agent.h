
#ifndef AGENT
#define AGENT

#include <iostream>
#include <string>
#include <vector>
#include "Individu.h"
#include "fonctions.h"

using namespace std;
class Agent {
	
	char reponsepossible[5] = { 'u','s','n','o' }; // une taille de 5 car le cinquième caractere est le caractere de fin 
	
public:
	
	    Agent();
		
		bool predicat_cheveux(const Individu& item, string input);
		bool predicat_yeux(const Individu& item, string input);
		bool predicat_genie(const Individu& item, string input);
		bool predicatCheveuxU(const Individu& item, string input, string input2);
		bool predicatYeuxU(const Individu& item, string input, string input2);
		bool predicatGenieU(const Individu& item, string input, string input2);
		void IdentifierIndividus( char reponse, string input, string caracteristique);
		void incrementerCount();

private:
		int questionCount ;
	
	vector <Individu*> tableauSuspect;
	//Individu* mystere1;
	//Individu* mystere2;

};
#endif