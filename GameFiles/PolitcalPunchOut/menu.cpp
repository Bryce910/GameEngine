#include "stdafx.h"
#include "menu.h"
#include "SFML/Graphics.hpp"

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

}
void menu::FpauseMenu()
{

}
void menu::FstartMenu()
{

}
void menu::FwinMenu()
{

}
void menu::FloseMenu()
{

}
void menu::FaddMenuItem(sf::Texture &texture, float locationX, float locationY, std::string simpleLocation)
{
	this->MENUITEM.setTexture(texture);
	this->MENUITEMLOCATION.x = locationX;
	this->MENUITEMLOCATION.y = locationY;
	if (simpleLocation != "")
	{
		this->MENUITEM.setPosition(MENUITEMLOCATION.x, MENUITEMLOCATION.y);
	}
	else if (simpleLocation == "Bottom Left")
	{
		this->MENUITEM.setPosition(0, this->GAMESIZEY - this->MENUITEM.getGlobalBounds().height);
	}
	else if (simpleLocation == "Middle Left")
	{
		this->MENUITEM.setPosition(0, this->GAMESIZEY - (this->MENUITEM.getGlobalBounds().height / 2) / 2);
	}
	else if (simpleLocation == "Top Left")
	{
		this->MENUITEM.setPosition(0, 0);
	}
	else if (simpleLocation == "Top Right")
	{

	}
	else if (simpleLocation == "Middle Right")
	{

	}
	else if (simpleLocation == "Bottom Right")
	{

	}
	else if (simpleLocation == "Center Top")
	{

	}
	else if (simpleLocation == "Center Middle")
	{

	}
	else if (simpleLocation == "Center Bottom")
	{

	}
	this->MENUITEM.setPosition(MENUITEMLOCATION.x, MENUITEMLOCATION.y);
	this->MENUITEMLIST.push_back(this->MENUITEM);

}