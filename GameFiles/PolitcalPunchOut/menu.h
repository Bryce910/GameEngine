#pragma once
#include "stdafx.h"
#include "player.h"
#include "game.h"
#include "SFML/Graphics.hpp"
class menu: public game
{
public:
	menu();
	~menu();
	void FloadingMenu(sf::Sprite &loadingBarSprite, float frameLength, float loadingBarx, float loadingBary, float frameX, float frameY, std::string direction);
	void FanimationBar();
	sf::Sprite LOADINGBAR;
	sf::Vector2f LOADINGBARD, FRAME, MENUITEMLOCATION;
	std::vector<sf::Sprite> MENUITEMLIST;
	sf::Sprite MENUITEM;
	int FRAMECOUNT, MAXFRAME;
	std::string DIRECTION;
	void FmainMenu();
	void FpauseMenu();
	void FstartMenu();
	void FwinMenu();
	void FloseMenu();
	void FaddMenuItem(sf::Texture &texture, float locationX, float locationY, std::string simpleLocation);
};

