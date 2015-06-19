#include "stdafx.h"
#include "linker.h"

game::game()
{
	this->GAMESTATELIST.push_back("splash");
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

			GAMESTATE = "close";
			this->GAMESCREEN.close();
		}
	}

}
void game::FsetGameState(std::string state)
{
	this->GAMESTATE = state;
}
void game::FaddGameState(std::string state)
{
	this->GAMESTATELIST.push_back(state);
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
void game::FClear()
{
	this->GAMESCREEN.clear();
}
void game::Fupdate()
{
	this->GAMESCREEN.display();
}
void game::Fdraw()
{

}