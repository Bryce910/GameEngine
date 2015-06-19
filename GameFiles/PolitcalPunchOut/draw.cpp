#include "stdafx.h"
#include "draw.h"


draw::draw()
{
}


draw::~draw()
{
}
void draw::FdrawCharacter()
{
	this->GAMESCREEN.draw(player::PLAYER);
}
void draw::FdrawProjectile()
{
	for (projectile::PROJECTILELOCATION = projectile::PROJECTILELIST.begin(); projectile::PROJECTILELOCATION != projectile::PROJECTILELIST.end(); projectile::PROJECTILELOCATION++)
	{
		this->GAMESCREEN.draw(*projectile::PROJECTILELOCATION);

	}
}
void draw::FdrawMenu()
{
	std::vector<sf::Sprite>::iterator sCount;
	for (std::vector<std::string>::iterator iCount = menu::MENUITEMCONTAINERLIST.begin(); iCount != menu::MENUITEMCONTAINERLIST.end(); ++iCount)
	{
		if (*iCount == this->GAMESTATE)
		{
			this->GAMESCREEN.draw(*sCount);
		}
		++sCount;
	}
	this->GAMESCREEN.draw(menu::LOADINGBAR);
}