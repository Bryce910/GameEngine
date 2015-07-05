#include "stdafx.h"
#include "linker.h"

menu::menu()
{

}

menu::~menu()
{
}

void menu::f_addMenuItem(sf::RenderWindow &app,sf::Texture &texture, std::string menuType, std::string location, sf::Vector2f position)
{
	sf::Texture t;
	t.loadFromFile("images/splash.jpg");
	/* Setting texture and sprite */
	m_item.setTexture(texture);
	f_setMenuPosition(location, position, app);
	m_menuItem.resize(m_menuItem.size() + 1);

	/* Add item */
	m_menuItem[m_menuItem.size()- 1].push_back(m_item);
	/* Setting data into the menulist */
	m_menuList.resize(m_menuItem.size());
	m_menuList[m_menuItem.size()-1].push_back(menuType);
	m_menuList[m_menuItem.size()-1].push_back(location);
	
}

void menu::f_addMenuItem(sf::RenderWindow &app, sf::Texture &texture, sf::Texture &hoverTexture, std::string menuType, std::string location, sf::Vector2f position)
{
	/* Setting texture and sprite */


	m_item.setTexture(texture);
	f_setMenuPosition(location, position, app);
	m_menuItem.resize(m_menuItem.size() + 1);
	/* Add item */
	m_menuItem[m_menuItem.size() -1].push_back(m_item);
	m_item.setTexture(hoverTexture);
	m_menuItem[m_menuItem.size() -1].push_back(m_item);
	/* Setting data into the menulist */

	m_menuList.resize(m_menuItem.size());
	m_menuList[m_menuItem.size() - 1].push_back(menuType);
	m_menuList[m_menuItem.size() - 1].push_back(location);
} 

void menu::f_addMenuItem(sf::RenderWindow &app, sf::Texture &texture, sf::Texture &hoverTexture, std::string menuType, std::string location, sf::Vector2f position, float scaleX, float scaleY)
{
	/* Setting texture and sprite */
	++m_menuCounter;
	m_item.setTexture(texture);
	std::cout << m_item.getTexture() << std::endl;
	m_item.setScale(scaleX, scaleY);
	f_setMenuPosition(location, position, app);
	m_menuItem.resize(m_menuItem.size() + 1);
	/* Add item */
	m_menuItem.at(m_menuItem.size() - 1).push_back(m_item);
	std::cout << m_menuCounter << std::endl;
	m_item.setTexture(hoverTexture);
	m_item.setScale(scaleX, scaleY);
	m_menuItem[m_menuItem.size() - 1].push_back(m_item);
	std::cout << m_menuItem.size() << std::endl;
	/* Setting data into the menulist */

	m_menuList.resize(m_menuItem.size());
	m_menuList[m_menuItem.size() - 1].push_back(menuType);
	m_menuList[m_menuItem.size() - 1].push_back(location);
}

void menu::f_setMenuPosition(std::string location, sf::Vector2f position, sf::RenderWindow &app)
{

	m_menuItemLocation.x = position.x;
	m_menuItemLocation.y = position.y;

	m_menuItemSize.x = m_item.getGlobalBounds().width;
	m_menuItemSize.y = m_item.getGlobalBounds().height;

	if (location == "")
	{
		m_item.setPosition(m_menuItemLocation.x, m_menuItemLocation.y);
	}
	else if (location == "Bottom Left")
	{
		m_item.setPosition(0, app.getSize().y - m_menuItemSize.y);
	}
	else if (location == "Middle Left")
	{
		m_item.setPosition(0, (app.getSize().y / 2) - (m_menuItemSize.y / 2));
	}
	else if (location == "Top Left")
	{
		m_item.setPosition(0, 0);
	}
	else if (location == "Top Right")
	{
		m_item.setPosition(app.getSize().x - (m_menuItemSize.x), 0);
	}
	else if (location == "Middle Right")
	{
		m_item.setPosition(app.getSize().x - (m_menuItemSize.x), (app.getSize().y / 2) - (m_menuItemSize.y / 2));
	}
	else if (location == "Bottom Right")
	{
		m_item.setPosition(app.getSize().x - (m_menuItemSize.x), app.getSize().y - (m_menuItemSize.y));
	}
	else if (location == "Center Top")
	{
		m_item.setPosition((app.getSize().x / 2) - (m_menuItemSize.x / 2), 0);
	}
	else if (location == "Center Middle")
	{
		m_item.setPosition((app.getSize().x / 2 )- (m_menuItemSize.x / 2), (app.getSize().y / 2 )- (m_menuItemSize.y / 2));
	}
	else if (location == "Center Bottom")
	{
		m_item.setPosition((app.getSize().x / 2 )- (m_menuItemSize.x / 2), app.getSize().y - (m_menuItemSize.y));
	}

}
/*
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
void menu::FaddMenuItem(sf::Texture &texture, float locationX, float locationY, std::string simpleLocation, std::string menuType, std::string action, std::string function)
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
	this->MENUITEMACTION.push_back(action);
	this->MENUITEMFUNCTION.push_back(function);
}
void menu::FaddInputItem(std::string type, std::string location, float minValue, float maxValue, float size, sf::Color boxColor)
{

	if (type == "button")
	{
		input->FsetButton();
	}
}
*/