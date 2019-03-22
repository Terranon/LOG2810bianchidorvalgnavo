#include "iostream"
#include "Porte.h"
#include "Boss.h"

using namespace std;

int main() {


	//fstream fichier("Porte1.txt");



	//tester la production de boss

	Boss boss;
	string production;
	production = boss.genererProduction();
	boss.genererAutomate(production);


	//tester  valider concatenation
	string papa = "c";//pour aller a la porte 2
	string papa2 = "e";//pour aller a la porte 7
	string papa3 = "";//pour aller a la porte 17
	string pap = "";//pour aller a la porte 14
	string papa4 = "e";//pour aller a la porte 6
	string papa5 = "a";//pour aller au boss

	vector<string>p;
	p.push_back(papa);
	p.push_back(papa2);
	p.push_back(papa3);
	p.push_back(pap);
	p.push_back(papa4);
	p.push_back(papa5);


	boss.validerConcatenation(p);

	//affronter boss


	for (int i = 0; i < 20; i++) {
		Porte porte;
		string nomfichier;
		cin >> nomfichier;
		porte.lirefichier(nomfichier);
	}







	return 0;
}