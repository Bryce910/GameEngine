#pragma once

#include "SFML/Graphics.hpp"

class player
{
public:
	player();
	~player();
	sf::Sprite PLAYER;
	enum PlayerMovement {up, down, left, right};
	enum PlayerAction {walk, run, idle, jump};
	enum PlayerMovement PLAYERDIRECTION;
	enum PlayerAction PLAYERACTION;
	float XSPEED, YSPEED;
	void FgetMovement();
	void FmovePlayer();
};

