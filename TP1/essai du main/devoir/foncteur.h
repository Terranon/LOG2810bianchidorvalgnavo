#pragma once


#include "fonctions.h"

#include <iostream>
#include "individu.h"


using namespace std;

class  Predicat {

public:
	Predicat(string caracteristique,string input):
	input_(input),
	caracteristique_(caracteristique)
	{};



	bool operator () (Individu* item) {
	
		if(caracteristique_=="cheveux")
			return item->getCouleurCheveux() != input_;

		if (caracteristique_ == "yeux")
			return item->getCouleurYeux() != input_;


		if (caracteristique_ == "genie")
			return item->getGenie() != input_;

		
	
	
	}


private: 

	string input_;
	string caracteristique_;




};

class  PredicatU {

public:
	PredicatU(string caracteristique,string input1,string input2):
	input1_(input1),
	input2_(input2),
	caracteristique_(caracteristique)
	{};



	bool operator () (Individu* item) {
	
		if (caracteristique_ == "cheveux") {
			if (item->getCouleurCheveux() != input1_ && item->getCouleurCheveux() != input2_) {
				return true;
			}
		}

		if (caracteristique_ == "yeux")
			return item->getCouleurYeux() != input1_&& item->getCouleurYeux()!=input2_;
		

		if (caracteristique_ == "genie")
			return item->getGenie() != input1_ && item->getGenie()!=input2_;

		
	
	
	}


private: 

	string input1_;
	string input2_;
	string caracteristique_;




};

class  PredicatN {

public:
	PredicatN(string caracteristique, string input) :
		input_(input),
		caracteristique_(caracteristique)
	{};



	bool operator () (Individu* item) {

		if (caracteristique_ == "cheveux")
			return item->getCouleurCheveux() == input_;

		if (caracteristique_ == "yeux")
			return item->getCouleurYeux() == input_;


		if (caracteristique_ == "genie")
			return item->getGenie() == input_;




	}


private:

	string input_;
	string caracteristique_;




};