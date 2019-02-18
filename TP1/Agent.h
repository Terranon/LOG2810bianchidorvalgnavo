#pragma once
#ifndef AGENT
#define AGENT

#include <iostream>
#include <string>

using namespace std;
class Agent{

public:
		void CreerStructure(string fichier);
		bool predicat_cheveux(const Individus& item, string input);
		bool predicat_yeux(const Individus& item, string input);
		bool predicat_genie(const Individus& item, string input);
		bool predicatCheveuxU(const Individus& item, string input, string input2);
		bool predicatYeuxU(const Individus& item, string input, string input2);
		bool predicatGenieU(const Individus& item string input, string input2);
		void IdentifierIndividus(string reponse, string input, string caracteristique);

private:
		int questionCount = 0;
	struct Individus {
		string nom;
		string cheveux;
		string yeux;
		string genie;
	};
	vector <Individus> individu;


};
#endif