#include "Player.h"
#include "Hand.h"

Player::Player(int id) : playerID(id), hand(new Hand()) {}
