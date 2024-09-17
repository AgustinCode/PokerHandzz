#include "Game.h"
#include "Player.h"
#include "Hand.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

Game::Game(int players) : playerCount(players) {}

int gameState = 0;
bool gameEnded = false;

// Player functions--------------------------------------------
void Game::addPlayer() {
    if (players.size() < MAX_PLAYERS) {
        std::cout << "Adding player " << players.size() +1 << " \n";
        Player player(static_cast<int>(players.size()+1));
        players.push_back(player);
    }
    else std::cout << "Full room!" << std::endl;
}

void Game::delPlayer(int id) {
    players.erase(players.begin() + id);
}

void Game::clearPlayers() { players.clear(); }
// ------------------------------------------------------------



// Game functions ---------------------------------------------
void Game::dealCards() {
    std::cout << "Dealing cards..\n";
    for (int i = 0; i < players.size(); i++) {
        players[i].hand->newHand();
    }
    }


void Game::nextState() {

    switch (gameState) {
    case 0: state = GameState::Preflop; gameState++;
        break;
    case 1: state = GameState::Flop; gameState++;
        break;
    case 2: state = GameState::Turn; gameState++;
        break;
    case 3: state = GameState::River; gameState++;
        break;
    case 4: state = GameState::Showdown;
        break;
    default: std::cerr << "Invalid GameState";
    }

}


void Game::showComCards() {
    std::cout << "-----------------------------------------------------------" << std::endl;

    switch (state) {
    case GameState::Preflop:
        preflop();
        break;
    case GameState::Flop:
        flop();
        break;
    case GameState::Turn:
        turn();
        break;
    case GameState::River:
        river();
        break;
    case GameState::Showdown:
        showdown();
        gameEnded = true;
        break;
    default:
        std::cout << "Unknown game state!" << std::endl;
    }

    std::cout << "-----------------------------------------------------------" << std::endl;
}

void Game::river() {
    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            std::cout << "RIVER ROUND :  ";
            for (int x = 0; x < 5; x++) {
                std::cout << x + 1 << ": " << community[x].toStringCard() << " - ";
            }
        }
        std::cout << std::endl;
    }
}

void Game::preflop() {
    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            std::cout << "PREFLOP ROUND :  NO CARDS ON THE TABLE";
            for (int x = 0; x < 5; x++) {
                community.emplace_back(Card::summonCard());
            }
        }
        std::cout << std::endl;
    }
}

void Game::flop() {
    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            std::cout << "FLOP ROUND :  ";
            for (int x = 0; x < 3; x++) {
                std::cout << x + 1 << ": " << community[x].toStringCard() << " - ";
            }
        }
        std::cout << std::endl;
    }
}

void Game::turn() {
    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            std::cout << "TURN ROUND :  ";
            for (int x = 0; x < 4; x++) {
                std::cout << x + 1 << ": " << community[x].toStringCard() << " - ";
            }
        }
        std::cout << std::endl;
    }
}

void Game::showdown() {
    std::cout << "Match ended" << std::endl;
}

void Game::reset() {
    std::cout << "Game reset" << std::endl;
}

void Game::displayGameState() {
    std::cout << gameState;
}

void Game::displayPlayers() {
    for (int i = 0; i < players.size(); i++) {
        players[i].hand->displayHand(players[i]);
    }
}

void Game::gameLoop() {
    // Add players
    for (int i = 0; i < playerCount; i++) {
        addPlayer();
    }

    // Deal cards
    dealCards();

    // Show cards
    while (!gameEnded) {


        showComCards();
        displayPlayers();
        std::cout << "Use arrow keys to continue." << std::endl;
        _getch(); 
        system("cls");
        nextState();
        displayPlayers();
        std::cout << "Use arrow keys to continue." << std::endl;
        _getch();
        system("cls");

    }
    



}
