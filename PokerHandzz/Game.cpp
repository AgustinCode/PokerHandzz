#include "Game.h"
#include "Player.h"
#include "Hand.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <windows.h>


Game::Game(int players) : playerCount(players) {}



int gameState = 0;
bool gameEnded = false;

// Set Colors --------------------------------------------------
void Game::setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// -------------------------------------------------------------



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
    setColor(14); // Yellow
    std::cout << "+-------------------------------------------------------+" << std::endl;
    std::cout << "|                     COMMUNITY CARDS                   |" << std::endl;
    std::cout << "+-------------------------------------------------------+" << std::endl;
    setColor(7); // White

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

    setColor(14); // Yellow
    std::cout << "+-------------------------------------------------------+" << std::endl;
    std::cout << "| Current Stage: " << std::setw(39) << std::left;
    switch (state) {
    case GameState::Preflop: std::cout << "Preflop"; break;
    case GameState::Flop: std::cout << "Flop"; break;
    case GameState::Turn: std::cout << "Turn"; break;
    case GameState::River: std::cout << "River"; break;
    case GameState::Showdown: std::cout << "Showdown"; break;
    }
    std::cout << " |" << std::endl;
    std::cout << "+-------------------------------------------------------+" << std::endl;
    setColor(7); // White
}


void Game::river() {
    setColor(10); // Light green
    std::cout << "                        RIVER ROUND                         " << std::endl;
    setColor(7); // White
    std::cout << "  ";
    for (int x = 0; x < 5; x++) {
        setColor(community[x].suitToString() == "Hearts" || community[x].suitToString() == "Diamonds" ? 12 : 15);
        std::cout << community[x].toStringCard() << "  ";
    }
    std::cout << std::endl << std::endl;
}

void Game::generateComCards() {
    for (int i = 0; i < 5; i++) {
        community.emplace_back(Card::summonCard());
    }
}


void Game::preflop() {
    setColor(10); // Light green
    std::cout << "                       PREFLOP ROUND                       " << std::endl;
    setColor(7); // White
    std::cout << "                     NO CARDS ON THE TABLE                 " << std::endl << std::endl;
}


void Game::flop() {
    setColor(10); // Light green
    std::cout << "                        FLOP ROUND                         " << std::endl;
    setColor(7); // White
    std::cout << "  ";
    for (int x = 0; x < 3; x++) {
        setColor(community[x].suitToString() == "Hearts" || community[x].suitToString() == "Diamonds" ? 12 : 15);
        std::cout << community[x].toStringCard() << "  ";
    }
    std::cout << std::endl << std::endl;
}


void Game::turn() {
    setColor(10); // Light green
    std::cout << "                       TURN ROUND                      " << std::endl;
    setColor(7); // White
    std::cout << "  ";
    for (int x = 0; x < 4; x++) {
        setColor((community[x].suitToString() == "Hearts" || community[x].suitToString() == "Diamonds") ? 12 : 15);
        std::cout << community[x].toStringCard() << "  ";
    }
    std::cout << std::endl << std::endl;
}




void Game::showdown() {
    setColor(10); // Ligth green
    std::cout << "                       SHOWDOWN ROUND                      " << std::endl;
    setColor(7); // White
    std::cout << "                        MATCH ENDED                        " << std::endl << std::endl;
}


void Game::reset() {
    std::cout << "Game reset" << std::endl;
}

// ------------------------------------------------------------

// Display functions -------------------------------------------
void Game::displayGameState() {
    std::cout << gameState;
}


void Game::displayPlayers() {
    for (int i = 0; i < players.size(); i++) {
        setColor(11); // Ligth blue
        std::cout << "+-------------------------------------------------------+" << std::endl;
        std::cout << "| Player " << i + 1 << std::setw(52) << "|" << std::endl;
        std::cout << "+-------------------------------------------------------+" << std::endl;
        setColor(7); // White
        players[i].hand->displayHand(players[i]);
        std::cout << std::endl;
    }
}

// ------------------------------------------------------------


// Game Loop --------------------------------------------------
void Game::gameLoop() {
    // Add players
    for (int i = 0; i < playerCount; i++) {
        addPlayer();
    }

    // Deal cards
    generateComCards();
    dealCards();

    // Show cards
    while (!gameEnded) {
        system("cls");
        showComCards();
        displayPlayers();
        setColor(14); // Amarillo
        std::cout << "Press any key to continue to the next stage." << std::endl;
        setColor(7); // Blanco
        _getch();
        nextState();
        _getch();
    }
}

// ------------------------------------------------------------

