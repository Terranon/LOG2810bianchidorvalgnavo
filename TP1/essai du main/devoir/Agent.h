
#ifndef AGENT
#define AGENT

#include <iostream>
#include <string>
#include <vector>
#include "Individu.h"
#include "fonctions.h"

using namespace std;
class Agent{
//struct Individus {
//		string nom;
//		string cheveux;
//		string yeux;
//		string genie;
//	};
	enum reponsepossible { u, o, n, s };
public:
	
	    Agent();
		
		bool predicat_cheveux(const Individu& item, string input);
		bool predicat_yeux(const Individu& item, string input);
		bool predicat_genie(const Individu& item, string input);
		bool predicatCheveuxU(const Individu& item, string input, string input2);
		bool predicatYeuxU(const Individu& item, string input, string input2);
		bool predicatGenieU(const Individu& item, string input, string input2);
		void IdentifierIndividus( reponsepossible reponse, string input, string caracteristique);
		void incrementerCount();

private:
		int questionCount ;
	
	vector <Individu*> tableauSuspect;
	//Individu* mystere1;
	//Individu* mystere2;

};
#endif