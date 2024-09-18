#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Card.h"
#include "Hand.h"

#include <iostream>
#include <vector>

enum class GameState {
	Preflop,
	Flop,
	Turn,
	River,
	Showdown
};


class Game {
private:
	const int MAX_PLAYERS = 10;
	std::vector<Player> players;
	int playerCount; 
	GameState state;
	std::vector<Card> community;


public:

	Game(int players);

	// Player functions
	void addPlayer();
	void delPlayer(int id);
	void clearPlayers();

	// Game functions
	void generateComCards();
	void dealCards();
	void showComCards();
	void nextState();
	void preflop();
	void flop();
	void turn();
	void river();
	void showdown();
	void reset();

	// Getters
	const std::vector<Card>& getCommunity() const { return community; }
	const std::vector<Player>& getPlayers() const { return players; }

	// Displays
	static void setColor(int color);	
	void displayGameState();
	void displayPlayers();

	// Main Loop
	void gameLoop();


};


#endif
