#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <vector>

class Player;


class Hand {

private:
	std::vector<Card> cards; //Cards in hand
	bool hasCards = static_cast<int>(cards.size()) > 0;

public:
	Hand();

	void newHand();
	void clearHand();
	void resetHand();
	void displayHand(const Player& plr);

};








#endif