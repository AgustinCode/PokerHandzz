#include "Hand.h"
#include "Card.h"
#include "Player.h"
#include <iostream>

Hand::Hand() {}

void Hand::newHand() {
	if (cards.empty()) { 
		cards.push_back(Card::summonCard());
		cards.push_back(Card::summonCard());
		std::cout << "Cards added." << std::endl;
	}
	else resetHand();
}

void Hand::clearHand() { cards.clear(); }

void Hand::resetHand() {
	clearHand();
	newHand();
}


void Hand::displayHand(const Player& plr) {
	if (!cards.empty()) { // Cambiar de hasCards a !cards.empty()
		std::cout << "Player " << plr.getId() << std::endl;
		cards[0].display();
		cards[1].display();
		std::cout << "\n";
	}
	else std::cout << "You have no cards" << std::endl;
}