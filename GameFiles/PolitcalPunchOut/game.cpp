#include "stdafx.h"
#include "linker.h"

using namespace simplicity;

	game::game()
	{
		m_gamestatelist.push_back("splash");
		f_setGameState("splash");
	}
	game::game(std::string title, unsigned int GameSizeX, unsigned int GameSizeY, int frameRate, bool hideterminal, bool fullscreen)
	{
		/* Setting sizes */
		m_gameTitle = title;
		m_screenSize.x = GameSizeX;
		m_screenSize.y = GameSizeY;
		m_maxFrameRate = frameRate;
		m_fullScreen = fullscreen;

		if (hideterminal)
		{
			f_hideTerminal();
		}

		/* Not sure if I want to do this still */
		m_gamestatelist.push_back("splash");
		f_setGameState("splash");
		f_loadWindow();
	}
	game::~game()
	{
	}
	int game::FsetFrameRate(int maxframerate)
	{
		m_maxFrameRate = maxframerate;
		return 0;
	}
	bool game::FsetGameTitle(std::string gameTitle)
	{
		m_gameTitle = gameTitle;
		return true;
	}
	void game::f_setGameSize(unsigned int sizeX, unsigned int sizeY)
	{
		m_screenSize.x = sizeX;
		m_screenSize.y = sizeY;
	}
	void game::f_setFullScreen()
	{
		m_fullScreen = true;
	}
	void game::f_hideTerminal()
	{
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
	void game::f_setIcon(int x, int y, sf::Image &icon)
	{
		m_gameScreen.setIcon(x, y, icon.getPixelsPtr());
	}
	void game::f_loadWindow()
	{
		if (m_fullScreen)
		{
			m_gameScreen.create(sf::VideoMode(m_screenSize.x, m_screenSize.y), m_gameTitle, sf::Style::Fullscreen);
		}
		else
		{
			m_gameScreen.create(sf::VideoMode(m_screenSize.x, m_screenSize.y), m_gameTitle);
		}
		m_gameScreen.setFramerateLimit(m_maxFrameRate);
		m_gameScreen.setActive();
	}
	void game::f_checkEventState()
	{
		sf::Event event;
		while (m_gameScreen.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{

				m_gamestate = "close";
				m_gameScreen.close();
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				m_clickEvent = true;
			}
		}

	}
	void game::f_setGameState(std::string state)
	{
		m_gamestate = state;
	}
	void game::f_addGameState(std::string state)
	{
		m_gamestatelist.push_back(state);
	}
	/* Remove this */
	void game::f_DisplaySplash(sf::Texture splashDisplay, std::string location)
	{
		m_splashTexture = splashDisplay;
		m_background.setTexture(m_splashTexture);
		if (location == "center")
		{
			m_background.setPosition(m_gameScreen.getSize().x - m_background.getGlobalBounds().width / 2, m_gameScreen.getSize().y - m_background.getGlobalBounds().height / 2);
		}
		m_gameScreen.draw(m_background);
	}
	void game::f_Clear()
	{
		m_gameScreen.clear();
	}
	void game::f_update()
	{
		m_gameScreen.display();
	}
	void game::f_draw()
	{
		int frame = 0;
		/* Loop through menu*/
		for (std::vector<std::vector<sf::Sprite>>::iterator itr = m_menuItem.begin(); itr != m_menuItem.end(); itr++)
		{
			
			if ((m_menuList[frame][0].compare(m_gamestate)) == 0)
			{
				if (m_menuList[frame][2] == "background")
				{
					m_gameScreen.draw(m_menuItem[frame][0]);
				}
				else
				{
					//draw this item
					if (!m_menuItem[frame][0].getGlobalBounds().contains(float(sf::Mouse::getPosition(m_gameScreen).x), float(sf::Mouse::getPosition(m_gameScreen).y)))
					{
						m_gameScreen.draw(m_menuItem[frame][0]);

					}
					else
					{
						m_gameScreen.draw(m_menuItem[frame][1]);
						if (m_clickEvent)
						{
							m_gamestate = m_menuList[frame][3];
							m_eventVariable = m_menuList[frame][4];
							std::cout << m_gamestate;
						}
					}

				}
			}
			
			frame++; 
		}
		m_clickEvent = false;
	}
	void game::f_draw(player* c_player)
	{
		if (c_player->m_status == m_gamestate)
		{
			m_gameScreen.draw(c_player->m_player);
		}
		
	}
	void game::f_loadTexture(sf::Texture &texture, std::string path)
	{
		texture.loadFromFile(path);
	}
