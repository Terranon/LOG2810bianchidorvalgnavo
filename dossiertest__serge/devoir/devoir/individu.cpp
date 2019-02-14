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
int Individu::getRelation(string nom) const {

	
	for (pair<string,int> item: relation_) {
		if (item.first == nom)//si l'element en question dont on cherche le nom est dans le conteneur 
			return item.second; //on retourne sa relation 
		
	}
	 return 0; //sinon on retourne 0 (pour signifier une absence de relation)
	
	

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
void Individu::setRelation(string nom_voisin,int valeur_relation) {//set relation au lieu de set voisin
	
	relation_.insert(make_pair(nom_voisin, valeur_relation)); 
}

//operator=
Individu& Individu::operator=(const Individu& individu) {//rajouter set relations
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