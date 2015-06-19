#include "stdafx.h"
#include "linker.h"

menu::menu()
{
}


menu::~menu()
{
}

void menu::FloadingMenu(sf::Sprite &loadingBarSprite, float frameLength, float loadingBarx, float loadingBary, float frameX, float frameY, std::string direction)
{
	this->LOADINGBAR = loadingBarSprite;
	this->LOADINGBARD.x = loadingBarx;
	this->LOADINGBARD.y = loadingBary;
	this->FRAMECOUNT = 0;
	this->MAXFRAME = frameLength;
	this->FRAME.x = frameX;
	this->FRAME.y = frameY;
	this->DIRECTION = direction;
}
void menu::FanimationBar()
{
	if (this->FRAMECOUNT <= this->MAXFRAME)
	{
		this->FRAMECOUNT++;
		if (this->DIRECTION == "right")
		{
			this->LOADINGBAR.setTextureRect(sf::IntRect(this->FRAMECOUNT * this->FRAME.x, 0, FRAME.x, FRAME.y));
			
		}
		else if (this->DIRECTION == "down")
		{
			this->LOADINGBAR.setTextureRect(sf::IntRect(0, this->FRAMECOUNT * this->FRAME.y, this->FRAME.x, this->FRAME.y));
		}
	}
	else
	{
		this->FRAMECOUNT = 0;
	}
}
void menu::FmainMenu()
{
	std::vector<std::string>::iterator menuContainter = MENUITEMCONTAINERLIST.begin();
	for (std::vector<sf::Sprite>::iterator menuItem = MENUITEMLIST.begin(); menuItem != MENUITEMLIST.end(); menuItem++)
	{
		if (*menuContainter == "main menu")
		{
			this->game::GAMESCREEN.draw(*menuItem);
		}
		menuContainter++;
	}
}
void menu::FpauseMenu()
{
	std::vector<std::string>::iterator menuContainter = MENUITEMCONTAINERLIST.begin();
	for (std::vector<sf::Sprite>::iterator menuItem = MENUITEMLIST.begin(); menuItem != MENUITEMLIST.end(); menuItem++)
	{
		if (*menuContainter == "pause menu")
		{
			this->GAMESCREEN.draw(*menuItem);
		}
		menuContainter++;
	}
}
void menu::FstartMenu()
{
	std::vector<std::string>::iterator menuContainter = MENUITEMCONTAINERLIST.begin();
	for (std::vector<sf::Sprite>::iterator menuItem = MENUITEMLIST.begin(); menuItem != MENUITEMLIST.end(); menuItem++)
	{
		if (*menuContainter == "start menu")
		{
			this->GAMESCREEN.draw(*menuItem);
		}
		menuContainter++;
	}
}
void menu::FwinMenu()
{
	std::vector<std::string>::iterator menuContainter = MENUITEMCONTAINERLIST.begin();
	for (std::vector<sf::Sprite>::iterator menuItem = MENUITEMLIST.begin(); menuItem != MENUITEMLIST.end(); menuItem++)
	{
		if (*menuContainter == "win menu")
		{
			this->GAMESCREEN.draw(*menuItem);
		}
		menuContainter++;
	}
}
void menu::FloseMenu()
{
	std::vector<std::string>::iterator menuContainter = MENUITEMCONTAINERLIST.begin();
	for (std::vector<sf::Sprite>::iterator menuItem = MENUITEMLIST.begin(); menuItem != MENUITEMLIST.end(); menuItem++)
	{
		if (*menuContainter == "close menu")
		{
			this->GAMESCREEN.draw(*menuItem);
		}
		menuContainter++;
	}
}
void menu::FaddMenuItem(sf::Texture &texture, float locationX, float locationY, std::string simpleLocation, std::string menuType)
{
	this->MENUITEM.setTexture(texture);
	this->MENUITEMLOCATION.x = locationX;
	this->MENUITEMLOCATION.y = locationY;
	this->MENUITEMSIZE.x = this->MENUITEM.getGlobalBounds().width;
	this->MENUITEMSIZE.y = this->MENUITEM.getGlobalBounds().height;

	if (simpleLocation != "")
	{
		this->MENUITEM.setPosition(MENUITEMLOCATION.x, MENUITEMLOCATION.y);
	}
	else if (simpleLocation == "Bottom Left")
	{
		this->MENUITEM.setPosition(0, this->GAMESIZEY - this->MENUITEMSIZE.y);
	}
	else if (simpleLocation == "Middle Left")
	{
		this->MENUITEM.setPosition(0, this->GAMESIZEY - (this->MENUITEMSIZE.y / 2) / 2);
	}
	else if (simpleLocation == "Top Left")
	{
		this->MENUITEM.setPosition(0, 0);
	}
	else if (simpleLocation == "Top Right")
	{
		this->MENUITEM.setPosition(this->GAMESIZEX - (this->MENUITEMSIZE.x), 0);
	}
	else if (simpleLocation == "Middle Right")
	{
		this->MENUITEM.setPosition(this->GAMESIZEX - (this->MENUITEMSIZE.x), this->GAMESIZEY - (this->MENUITEMSIZE.y / 2) / 2);
	}
	else if (simpleLocation == "Bottom Right")
	{
		this->MENUITEM.setPosition(this->GAMESIZEX - (this->MENUITEMSIZE.x), this->GAMESIZEY - (this->MENUITEMSIZE.y) );
	}
	else if (simpleLocation == "Center Top")
	{
		this->MENUITEM.setPosition(this->GAMESIZEX - (this->MENUITEMSIZE.y / 2) / 2, 0);
	}
	else if (simpleLocation == "Center Middle")
	{
		this->MENUITEM.setPosition(this->GAMESIZEX - (this->MENUITEMSIZE.x / 2) / 2, this->GAMESIZEY - (this->MENUITEMSIZE.y / 2) / 2);
	}
	else if (simpleLocation == "Center Bottom")
	{
		this->MENUITEM.setPosition(this->GAMESIZEX - (this->MENUITEMSIZE.x / 2) / 2, this->GAMESIZEY - (this->MENUITEMSIZE.y));
	}
	this->MENUITEMLIST.push_back(this->MENUITEM);
	this->MENUITEMCONTAINERLIST.push_back(menuType);
}