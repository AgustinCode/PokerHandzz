#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Hand;

class Player {

private:
	int playerID;

public:
	Hand* hand;

	Player(int id);
	
	int getId() const { return playerID; }





};








#endif