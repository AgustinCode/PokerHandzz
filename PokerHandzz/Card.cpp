#include "Card.h"
#include <iostream>
#include <chrono>
#include <random>

Card::Card() {}

Card::Card(Suit s, Value v) : suit(s), value(v) {}

	
Suit Card::getSuit() const { return suit; };

Value Card::getValue() const { return value; };

std::string Card::suitToString() const {
	Suit s = Card::suit;
	switch (s) {
	case Suit::Hearts:  return "Hearts";
	case Suit::Clubs:   return "Clubs";
	case Suit::Diamond: return "Diamonds";
	case Suit::Spades:  return "Spades";

	default: return "UNKNOWN SUIT: ERROR";

	}
};


std::string Card::valueToString() const {
	Value v = Card::value;
	switch (v) {
	case Value::Two:   return "Two";
	case Value::Three: return "Three";
	case Value::Four:  return "Four";
	case Value::Five:  return "Five";
	case Value::Six:   return "Six";
	case Value::Seven: return "Seven";
	case Value::Eight: return "Eight";
	case Value::Nine:  return "Nine";
	case Value::Ten:   return "Ten";
	case Value::Jack:  return "Jack";
	case Value::Queen: return "Queen";
	case Value::King:  return "King";
	case Value::Ace:   return "Ace";

	default: return "UNKNOWN VALUE: ERROR";
	}


};

Card Card::summonCard() {
	Value v;
	Suit s;

	std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());

	std::uniform_int_distribution<> sdis(0, 3);
	std::uniform_int_distribution<> vdis(2, 14);

	s = static_cast<Suit>(sdis(gen));
	v = static_cast<Value>(vdis(gen));


	Card rcard(s, v);

	return rcard;
}


std::string Card::toStringCard() const { return (valueToString() + "/" + suitToString()); };
 
void Card::display() {
	std::cout << toStringCard() << std::endl;
}


