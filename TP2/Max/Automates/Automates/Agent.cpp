#include "Agent.h"

Agent::Agent() {
	
}
Agent::~Agent() {
	porteCourante_ = nullptr;
	delete porteCourante_;

	for (int i = 0; i < tableauDeProbaValide_.size(); i++) {
		tableauDeProbaValide_[i].first = nullptr;
		delete tableauDeProbaValide_[i].first;
	}

	for (int j = 0; j < chemin_.size(); j++) {
		chemin_[j] = nullptr;
		delete chemin_[j];
	}
}

void Agent::parcourirLabyrinthe() {

}
void Agent::ouvrirPorte(string Porte1) {

}
string Agent::deciderProchainePorte() {
	for (int i = 0; i < porteCourante_->getPorteConnecter().size(); i++) {
		if (porteCourante_->getPorteConnecter()[i].second.second) {
			for (int j = 0; j < tableauDeProbaValide_.size(); j++) {

			}
		}
	}
	return "";
}
void Agent::afficherLeCheminParcouru() {
	chemin_.size();
}