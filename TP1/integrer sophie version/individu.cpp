/*
Program:	testpourdiscussion
Author:		Maximilien Bianchi
Version:	1.0
All Rights Reserved, Maximilien Bianchi 2019 */



#include "individu.h"

using namespace std;

Individu::Individu(const char& couleurYeux, const string& nom) :
	couleurYeux_(couleurYeux),
	nom_(nom) {

}

Individu::Individu(const Individu& individu) :
	couleurYeux_(individu.getCouleurYeux()),
	nom_(individu.getNom()) {
	
}

char Individu::getCouleurYeux() const {
	return couleurYeux_;
}

string Individu::getNom() const {
	return nom_;
}

void Individu::setCouleurYeux(char couleur) {
	couleurYeux_ = couleur;
}

void Individu::setNom(string nom) {
	nom_ = nom;
}

//operator=
Individu& Individu::operator=(const Individu& individu) {
	if (this != &individu) {
		setCouleurYeux(individu.getCouleurYeux());
		setNom(individu.getNom());
	}
	return *this;
}

// Methode d'affichage
ostream & operator<<(ostream& os, const Individu& individu) {
	return os << "Individu " << *individu.getNom << endl 
		<< "couleur des yeux :" <<  individu.getCouleurYeux << endl;
}