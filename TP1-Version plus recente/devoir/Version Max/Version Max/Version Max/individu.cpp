/*
Program:	testpourdiscussion
Author:		Maximilien Bianchi
Version:	1.0
All Rights Reserved, Maximilien Bianchi 2019 */



#include "individu.h"

using namespace std;

Individu::Individu(string nom, string couleurCheveux, string couleurYeux, string genie) :
	couleurCheveux_(couleurCheveux),
	genie_(genie),
	couleurYeux_(couleurYeux),
	nom_(nom) {

}

Individu::Individu(Individu* individu) :
	couleurYeux_(individu->getCouleurYeux()),
	couleurCheveux_(individu->getCouleurCheveux()),
	genie_(individu->getGenie()),
	nom_(individu->getNom()) {
	auto itRelations = individu->getDonneesRelation().begin();
	for (itRelations; itRelations != individu->getDonneesRelation().end(); itRelations++) {
		Individu* nouvelIndividu = new Individu(*itRelations->first);
	}
}

string Individu::getCouleurYeux() const {
	return couleurYeux_;
}
string Individu::getCouleurCheveux() const {
	return couleurCheveux_;
}

string Individu::getNom() const {
	return nom_;
}

string Individu::getGenie() const {
	return genie_;
}
int Individu::getValeurRelation(string nom) const {


	for (pair<Individu*, int> item : relation_) {
		if (item.first->getNom() == nom)//si l'element en question dont on cherche le nom est dans le conteneur 
			return item.second; //on retourne sa relation 

	}
	return 0; //sinon on retourne 0 (pour signifier une absence de relation)



}
map<Individu*, int>& Individu::getDonneesRelation() { //ne pas donner d'attribut constant

	return relation_;


}

void Individu::setCouleurYeux(string couleur) {
	couleurYeux_ = couleur;
}
void Individu::setCouleurCheveux(string couleur) {
	couleurCheveux_ = couleur;
}

void Individu::setNom(string nom) {
	nom_ = nom;
}
void Individu::setGenie(string genie) {
	genie_ = genie;
}
void Individu::setRelation(Individu* voisin, int valeur_relation) {//set relation au lieu de set voisin

	relation_.insert(make_pair(voisin, valeur_relation));


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
		<< "couleur des yeux :" << individu.getCouleurYeux() << endl;
}