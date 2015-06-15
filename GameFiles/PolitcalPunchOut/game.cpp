#include "stdafx.h"
#include "game.h"
#include "player.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <windows.h>

game::game()
{
	this->FsetGameState("splash");
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
void game::FhideTerminal()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
}
void game::FsetIcon(int x, int y, sf::Image &icon)
{
	this->GAMESCREEN.setIcon(x, y, icon.getPixelsPtr());
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
void game::FsetGameState(std::string state)
{
	if (state == "pause")
	{
		this->GAMESTATE = game::EGameState::paused;
	}
	else if (state == "load")
	{
		this->GAMESTATE = game::EGameState::loading;
	}
	else if (state == "menu")
	{
		this->GAMESTATE = game::EGameState::menu;
	}
	else if (state == "play")
	{
		this->GAMESTATE = game::EGameState::play;
	}
	else if (state == "lose")
	{
		this->GAMESTATE = game::EGameState::lose;
	}
	else if (state == "win")
	{
		this->GAMESTATE = game::EGameState::win;
	}
	else if (state == "splash")
	{
		this->GAMESTATE = game::EGameState::splash;
	}
	else if (state == "close")
	{
		this->GAMESTATE = game::EGameState::close;
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
void game::FdrawCharacter()
{
	this->GAMESCREEN.draw(player::PLAYER);
}
void game::FdrawProjectile()
{
	for (this->PROJECTILELOCATION = this->PROJECTILELIST.begin(); this->PROJECTILELOCATION != this->PROJECTILELIST.end(); this->PROJECTILELOCATION++)
	{
		this->GAMESCREEN.draw(*this->PROJECTILELOCATION);

	}
}
void game::FdrawMenu()
{
	this->GAMESCREEN.draw(menu::LOADINGBAR);
}