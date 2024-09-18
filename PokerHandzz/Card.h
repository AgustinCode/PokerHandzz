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

	Suit getSuit() const;
	Value getValue() const;

	static Card summonCard();

	std::string suitToString() const;
	std::string valueToString() const;
	std::string toStringCard() const;
	void display();

	

};


#endif







