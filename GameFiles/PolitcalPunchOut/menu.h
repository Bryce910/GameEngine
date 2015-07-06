#include "stdafx.h"
#include "linker.h"

class menu
{
public:
	menu();
	~menu();
	//std::vector<sf::Sprite> m_menuItem;
	std::vector<std::vector<sf::Sprite>> m_menuItem;
	std::vector<std::vector<std::string>> m_menuList;
	bool m_clickEvent = false;
	sf::Sprite m_item;
	sf::Vector2f m_menuItemLocation, m_menuItemSize;
	std::string m_eventVariable;
	void f_addMenuItem(sf::RenderWindow &app,sf::Texture &texture, std::string menuType, std::string location, sf::Vector2f position);
	void f_addMenuItem(sf::RenderWindow &app, sf::Texture &texture, sf::Texture &hoverTexture, std::string menuType, std::string location, sf::Vector2f position);
	void f_addMenuItem(sf::RenderWindow &app, sf::Texture &texture, sf::Texture &hoverTexture, std::string menuType, std::string location, sf::Vector2f position, float scaleX, float scaleY);
	void f_addMenuItem(sf::RenderWindow &app, sf::Texture &texture, sf::Texture &hoverTexture, std::string menuType, std::string newType, std::string location, sf::Vector2f position, float scaleX, float scaleY);
	void f_addMenuItem(sf::RenderWindow &app, sf::Texture &texture, sf::Texture &hoverTexture, std::string menuType, std::string newType, std::string location, sf::Vector2f position, float scaleX, float scaleY, std::string varible);

	void f_setMenuPosition(std::string location, sf::Vector2f position, sf::RenderWindow &app);
	/*void FloadingMenu(sf::Sprite &loadingBarSprite, float frameLength, float loadingBarx, float loadingBary, float frameX, float frameY, std::string direction);
	void FanimationBar();
	//inputs *input; //removed for testing
	sf::Sprite  LOADINGBAR;
	sf::Vector2f LOADINGBARD, FRAME, MENUITEMLOCATION, MENUITEMSIZE;
	std::vector<sf::Sprite>   MENUITEMLIST;
	std::vector<std::string>  MENUITEMCONTAINERLIST;
	std::vector<std::string>  MENUITEMACTION;
	std::vector<std::string>  MENUITEMFUNCTION;
	sf::Sprite MENUITEM;
	float FRAMECOUNT, MAXFRAME;
	std::string DIRECTION;
	void FmainMenu();
	void FpauseMenu();
	void FstartMenu();
	void FwinMenu();
	void FloseMenu();
	void FaddMenuItem(sf::Texture &texture, float locationX, float locationY, std::string simpleLocation, std::string menuType, std::string action, std::string function);
	void FaddMenuItem(sf::Texture &texture, std::string simpleLocation);
	void FaddLabelItem(std::string location, float value, std::string text);
	void FaddInputItem(std::string type, std::string location, float minValue, float maxValue, float size, sf::Color boxColor);
*/
};

