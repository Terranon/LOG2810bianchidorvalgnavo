/*
Program:	testpourdiscussion
Author:		Maximilien Bianchi
Version:	1.0
All Rights Reserved, Maximilien Bianchi 2019 */



#include "individu.h"

using namespace std;

Individu::Individu(string nom,char couleurCheveux, char couleurYeux,  string genie) :
	couleurCheveux_(couleurCheveux),
    genie_(genie),
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
char Individu::getCouleurCheveux() const {
	return couleurCheveux_;
}

string Individu::getNom() const {
	return nom_;
}

string Individu::getGenie() const {
	return genie_;
}

void Individu::setCouleurYeux( char couleur) {
	couleurYeux_ = couleur;
}
void Individu::setCouleurCheveux( char couleur) {
	couleurCheveux_ = couleur;
}

void Individu::setNom(string nom) {
	nom_ = nom;
}
void Individu::setGenie(string genie) {
	genie_ = genie;
}
void Individu::setVoisin(Individu& voisin) {
	voisin_.push_back(voisin);
}

//operator=
Individu& Individu::operator=(const Individu& individu) {
	if (this != &individu) {
		setCouleurYeux(individu.getCouleurYeux());
		setCouleurCheveux(individu.getCouleurCheveux());
		setNom(individu.getNom());
		setGenie(individu.getGenie());
	}
	return *this;
}

// Methode d'affichage
ostream & operator<<(ostream& os, const Individu& individu) {
	return os << "Individu " << individu.getNom() << endl 
		<< "couleur des yeux :" <<  individu.getCouleurYeux() << endl;
}