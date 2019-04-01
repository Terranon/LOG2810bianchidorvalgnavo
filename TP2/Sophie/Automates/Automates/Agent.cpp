#include "Agent.h"

Agent::Agent() {

}
Agent::~Agent() {
}


void Agent::afficherLeCheminParcouru(vector <Porte*> chemin_) {
	for (int i = 0; i < chemin_.size(); i++) {
		if (chemin_[i]->getNom() == "Boss") {
			cout << "Evenement Boss" << endl;
			chemin_[i]->affronterBoss(chemin_);
			chemin_[i]->afficherBoss(chemin_);
		}
		else {
			cout << "Evenement Porte" << endl;
			cout << "a. " << chemin_[i]->getNom() << endl;
			chemin_[i]->afficherPorte();
		}
	}		
}
