#include "Agent.h"

Agent::Agent() {

}
Agent::~Agent() {
}

void Agent::ouvrirPorte(string Porte1) {
	
}

void Agent::afficherLeCheminParcouru() {
	for (int i = 0; i < chemin_.size(); i++) {
		if (chemin_[i]->getNom() == "Boss") {
			
			chemin_[i]->afficherBoss();
		}
		else {
			cout << "Evenement Porte" << endl;
			cout << "a. " << chemin_[i]->getNom() << endl;
			cout << chemin_[i]->afficherPorte << endl;
		}
	}		
}
