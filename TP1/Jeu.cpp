#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <vector>
#include <string> 
using namespace std;
#include Jeu.h

class Jeu {


	void CreerStructure(string fichier) {

		Individus temp;
		ifstream in(fichier);
		if (!in) {
			cout << "The input file did not open.";
		}
		string line;
		while (getline(in, line))
			stringstream ss(line);
			if (ss>>temp.nom>>temp.cheveux>>temp.yeux>>temp.genie) {
				individu.push.back(temp);
			}
		in.close();
	}


	bool predicat_cheveux(const Individus& item)
	{
			return item.cheveux != input;
	}
	bool predicat_yeux(const Individus& item)
	{
		return item.yeux != input;
	}
	bool predicat_genie(const Individus& item)
	{
		return item.genie != input;
	}

	void IdentifierIndividus(string reponse, string input, string caracteristique) {
		
	Switch (reponse) {
		case o: 
			if (caracteristique == "cheveux") {					
				individu.erase(remove_if(individu.begin(), individu.end(), predicat_cheveux, individu.end());	
			}

			if (caracteristique == "yeux") {
				individu.erase(remove_if(individu.begin(), individu.end(), predicat_yeux, individu.end());
			}

			if (caracteristique == "genie") {
				individu.erase(remove_if(individu.begin(), individu.end(), predicat_genie, individu.end());
			}

			if (individu.size()==2) {
				cout << "Les individus mystere sont: " << endl;
				for (int i = 0; i < individu.size();i++) {
					cout << individu[i].nom << endl;
				}
			}
			questionCount += 1;
		
		case u:

		case n:
			if (caracteristique == "cheveux") {
					individu.erase(remove_if(individu.begin(), individu.end(), !predicat_cheveux, individu.end());
				}

				if (caracteristique == "yeux") {
					individu.erase(remove_if(individu.begin(), individu.end(), !predicat_yeux, individu.end());
				}

				if (caracteristique == "genie") {
					individu.erase(remove_if(individu.begin(), individu.end(), !predicat_genie, individu.end());
				}

				if (individu.size() == 2) {
					cout << "Les individus mystere sont: " << endl;
					for (int i = 0; i < individu.size();i++) {
						cout << individu[i].nom << endl;
					}
				}
			questionCount += 1;
		case s:
			cout << "Les susptect encore sur la liste sont: " << endl;
			for (int i = 0; i < individu.size();i++) {
				cout << individu[i].nom << endl;
			}

		default: 
			cout << "invalid input" << endl;
			cin << reponse << endl;
	}

};
#endif