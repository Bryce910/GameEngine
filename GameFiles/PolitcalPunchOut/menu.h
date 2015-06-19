#include "stdafx.h"
#include "linker.h"
class menu: public game
{
public:
	menu();
	~menu();
	void FloadingMenu(sf::Sprite &loadingBarSprite, float frameLength, float loadingBarx, float loadingBary, float frameX, float frameY, std::string direction);
	void FanimationBar();
	sf::Sprite  LOADINGBAR;
	sf::Vector2f LOADINGBARD, FRAME, MENUITEMLOCATION, MENUITEMSIZE;
	std::vector<sf::Sprite>  MENUITEMLIST;
	std::vector<std::string>  MENUITEMCONTAINERLIST;
	sf::Sprite MENUITEM;
	float FRAMECOUNT, MAXFRAME;
	std::string DIRECTION;
	void FmainMenu();
	void FpauseMenu();
	void FstartMenu();
	void FwinMenu();
	void FloseMenu();
	void FaddMenuItem(sf::Texture &texture, float locationX, float locationY, std::string simpleLocation, std::string menuType);
};

