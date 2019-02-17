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


	bool predicat_cheveux(const Individus& item, string input)
	{
			return item.cheveux != input;
	}

	bool predicatCheveuxU(const Individus& item, string input, string input2)
	{
		if (item.cheveux != input && item.cheveux != input2) {
			return true;
		}
	}

	bool predicat_yeux(const Individus& item, string input)
	{
		return item.yeux != input;
	}

	bool predicatYeuxU(const Individus& item, string input, string input2)
	{
		if (item.yeux != input && item.yeux != input2) {
			return true;
		}
	}

	bool predicat_genie(const Individus& item, string input)
	{
		return item.genie != input;
	}

	bool predicatGenieU(const Individus& item, string input, string input2)
	{
		if (item.genie != input && item.genie != input2) {
			return true;
		}
	}

	void IdentifierIndividus(string reponse, string input, string caracteristique) {
		
	Switch (reponse) {
		case o: 
			if (caracteristique == "cheveux") {					
				individu.erase(remove_if(individu.begin(), individu.end(), predicat_cheveux(input)), individu.end());	
			}

			if (caracteristique == "yeux") {
				individu.erase(remove_if(individu.begin(), individu.end(), predicat_yeux(input)), individu.end());
			}

			if (caracteristique == "genie") {
				individu.erase(remove_if(individu.begin(), individu.end(), predicat_genie(input)), individu.end());
			}

			if (individu.size()==2) {
				cout << "Les individus mystere sont: " << endl;
				for (int i = 0; i < individu.size();i++) {
					cout << individu[i].nom << endl;
				}
			}
			questionCount += 1;
		
		case u:
			if (caracteristique == "cheveux") {
				vector<string> caracteristique;
				caracteristique.push.back(input);

				if (caracteristique.size() == 2) {
					individu.erase(remove_if(individu.begin(), individu.end(), predicatCheveuxU(caracteristique[0], caracteristique[1])), individu.end());
				}

			}

			if (caracteristique == "yeux") {
				vector<string> caracteristique;
				caracteristique.push.back(input);

				if (caracteristique.size() == 2) {
					individu.erase(remove_if(individu.begin(), individu.end(), predicatYeuxU(caracteristique[0], caracteristique[1])), individu.end());
				}
			}

			if (caracteristique == "genie") {
				vector<string> caracteristique;
				caracteristique.push.back(input);

				if (caracteristique.size() == 2) {
					individu.erase(remove_if(individu.begin(), individu.end(), predicatGenieU(caracteristique[0], caracteristique[1])), individu.end());
				}
			}
			questionCount+=1;

		case n:
			if (caracteristique == "cheveux") {
					individu.erase(remove_if(individu.begin(), individu.end(), !predicat_cheveux(input)), individu.end());
				}

				if (caracteristique == "yeux") {
					individu.erase(remove_if(individu.begin(), individu.end(), !predicat_yeux(input)), individu.end());
				}

				if (caracteristique == "genie") {
					individu.erase(remove_if(individu.begin(), individu.end(), !predicat_genie(input)), individu.end());
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