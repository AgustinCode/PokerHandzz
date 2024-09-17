#ifndef CARD_H
#define CARD_H

#include <iostream>


//Enums------------------
enum class Suit {
	Hearts,
	Diamond,
	Spades,
	Clubs
};

enum class Value {
	Two = 2,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace
};

//------------------------

class Card {

private:
	Suit suit;
	Value value;
	
public:
	Card();
	Card(Suit s, Value v);

	Suit getSuit();
	Value getValue();

	static Card summonCard();

	std::string suitToString();
	std::string valueToString();
	std::string toStringCard();
	void display();

	

};


#endif







