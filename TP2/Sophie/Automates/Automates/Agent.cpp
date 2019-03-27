#include "Agent.h"

Agent::Agent() {

}
Agent::~Agent() {
}

void Agent::ouvrirPorte(string Porte1) {
	
}

void Agent::afficherLeCheminParcouru() {

	for (int i = 0; i < chemin_.size(); i++) {
		if ((chemin_[i]->getPorteConnecter).first == "Boss") {
			cout << "Evenement Boss" << endl;
			cout << "a. ";
			for (int k = 0; k < chemin_.size(); k++) {
				cout << chemin_[k].getPorteConnecter.first << " ";
			}
			cout << endl;
			cout << "b. "<<" P = { ";
			for (int j = 0; i < chemin_[i]->getRegle().second.size(); j++) {
				cout << chemin_[i]->getRegle().first << " -> " << chemin_[i]->getRegle().second[j].first <<
					chemin_[i]->getRegle().second[j].first;
			}
			cout << " }" << endl;
			chemin_[i]->afficherBoss();
		}
		else {
			cout << "Evenement Porte" << endl;
			cout << chemin_[i]->afficherPorte << endl;
		}
	}		
}
