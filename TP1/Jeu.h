#pragma once
class Jeu {

	public
		void CreerStructure(string fichier);
		bool predicat_cheveux(const Individus& item);
		bool predicat_yeux(const Individus& item);
		bool predicat_genie(const Individus& item);
		void IdentifierIndividus(string reponse, string input, string caracteristique);

		private
			int questionCount = 0;
			struct Individus {
				string nom;
				string cheveux;
				string yeux;
				string genie;
			};
			vector <Individus> individu;

};