#include "iostream"
#include "Porte.h"

using namespace std;

int main() {


	fstream fichier("Porte1.txt");
	Porte porte(fichier);
	string nomfichier;
	cin >> nomfichier;
	porte.lireFichier(nomfichier);







	return 0;
}