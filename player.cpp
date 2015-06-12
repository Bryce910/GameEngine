#include "stdafx.h"
#include "player.h"


player::player()
{
}

player::~player()
{
}

void player::FgetMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->PLAYERDIRECTION = player::PlayerMovement::left;
		this->FmovePlayer();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->PLAYERDIRECTION = player::PlayerMovement::right;
		this->FmovePlayer();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->PLAYERDIRECTION = player::PlayerMovement::up;
		this->FmovePlayer();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->PLAYERDIRECTION = player::PlayerMovement::down;
		this->FmovePlayer();
	}
}
void player::FmovePlayer()
{
	this->PLAYER.move(XSPEED, YSPEED);
}