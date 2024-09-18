#include "Hand.h"
#include "Card.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <windows.h>

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


void Hand::displayHand(const Player& player) {
	std::cout << "  ";
	for (const auto& card : cards) {
		// Se establece el color rojo para corazones y diamantes y negro para tréboles y picas.
		int colorCode = (card.suitToString() == "Hearts" || card.suitToString() == "Diamonds") ? 12 : 15;  // 12 es rojo en muchos sistemas, 0 para negro
		Game::setColor(colorCode);
		std::cout << card.toStringCard() << "  ";
	}
	std::cout << std::endl;
}
