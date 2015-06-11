#include "stdafx.h"
#include "game.h"
#include "SFML/Graphics.hpp"
#include <iostream>
game::game()
{
	
}


game::~game()
{
}

int game::FsetFrameRate(int maxframerate)
{
	this->MAXFRAMERATE = maxframerate;
	return 0;
}

bool game::FsetGameTitle(std::string gameTitle)
{
	this->GAMETITLE = gameTitle;
	return true;
}

void game::FsetGameSize(unsigned int sizeX, unsigned int sizeY)
{
	this->GAMESIZEX = sizeX;
	this->GAMESIZEY = sizeY;
}
void game::FloadWindow()
{
	this->GAMESCREEN.create(sf::VideoMode(this->GAMESIZEX, this->GAMESIZEY), this->GAMETITLE);
	this->GAMESCREEN.setFramerateLimit(this->MAXFRAMERATE);
	this->GAMESCREEN.setActive();
}
void game::FcheckEventState()
{
	sf::Event event;
	while (this->GAMESCREEN.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{

			GAMESTATE = EGameState::close;
			this->GAMESCREEN.close();
		}
	}

}
void game::FDisplaySplash(sf::Texture splashDisplay, std::string location)
{
	this->SPLASHTEXTURE = splashDisplay;
	this->BACKGROUND.setTexture(this->SPLASHTEXTURE);
	if (location == "center")
	{
		this->BACKGROUND.setPosition(this->GAMESCREEN.getSize().x - this->BACKGROUND.getGlobalBounds().width / 2, this->GAMESCREEN.getSize().y - this->BACKGROUND.getGlobalBounds().height / 2);
	}
	this->GAMESCREEN.draw(this->BACKGROUND);
}
void game::Fupdate()
{
	this->GAMESCREEN.display();
}
void game::FClear()
{
	this->GAMESCREEN.clear();
}

