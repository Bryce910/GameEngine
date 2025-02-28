#include "stdafx.h"
#include "linker.h"
	player::player()
	{
		m_health = 100;
		m_xSpeed = 10;
		m_ySpeed = 10;
		m_angle = m_player.getRotation();
	}

	player::~player()
	{

	}
	/*
	void player::FgetMovement()
	{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
	this->PLAYERDIRECTION = player::PlayerMovement::left;
	this->FmovePlayer();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
	this->PLAYERDIRECTION = player::PlayerMovement::right;
	this->FmovePlayer();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
	this->PLAYERDIRECTION = player::PlayerMovement::up;
	this->FmovePlayer();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
	this->PLAYERDIRECTION = player::PlayerMovement::down;
	this->FmovePlayer();
	}
	}
	void player::FmovePlayer()
	{
	this->PLAYER.move(XSPEED, YSPEED);
	}
	void player::FgetCenter()
	{
	/* Set center of player for rotation and etc. */ /*
	this->PLAYERCENTER.x = this->PLAYER.getGlobalBounds().left / 2;
	this->PLAYERCENTER.y = this->PLAYER.getGlobalBounds().top / 2;
	this->PLAYER.setOrigin(this->PLAYERCENTER.x, this->PLAYERCENTER.y);
	}
	void player::FgetAngle()
	{
	this->ANGLE = this->PLAYER.getRotation();
	}
	*/

	void player::f_setTexture(sf::Texture &texture, sf::Vector2f size, float scaleX, float scaleY)
	{
		m_player.setTexture(texture);
		m_player.setScale(scaleX, scaleY);
		if (size.x == 0 || size.y == 0)
		{
			m_player.setTextureRect(sf::IntRect(0,0,int(m_player.getGlobalBounds().width), int( m_player.getGlobalBounds().height)));
		}
		else
		{
			m_player.setTextureRect(sf::IntRect(0, 0, int( size.x),int( size.y)));
		}
		
	}

	void player::f_animationTexture(sf::Texture &texture, int frameSizeX, int frameSizeY, std::string type, int maxFrames, std::string direction,  bool reverse, int speed)
	{
		v_animationList.push_back(texture);
		c_aniClock.restart();
		v_animationClock.push_back(c_aniClock);
		v_animationRules.resize(v_animationList.size());
		v_animationRules[v_animationList.size() - 1].push_back(type);
		v_animationRules[v_animationList.size() - 1].push_back(direction);
		v_animationRules[v_animationList.size() - 1].push_back(std::to_string(maxFrames));
		v_animationRules[v_animationList.size() - 1].push_back(std::to_string(speed));
		v_animationRules[v_animationList.size() - 1].push_back(std::to_string(frameSizeX));
		v_animationRules[v_animationList.size() - 1].push_back(std::to_string(frameSizeY));
		v_animationRules[v_animationList.size() - 1].push_back(std::to_string(0));
		v_animationReverseRules.resize(v_animationList.size());
		v_animationReverseRules[v_animationList.size() - 1].push_back(reverse);
		v_animationReverseRules[v_animationList.size() - 1].push_back(false);
	}
	/* Currently bugged... moving 1 past the max frame */
	void player::f_animate()
	{
		int frame = 0;
		for (std::vector<sf::Texture>::iterator count = v_animationList.begin(); count != v_animationList.end(); count++)
		{	
			if (m_activeAnimation == v_animationRules[frame][0])
			{
				int temp_timeElasped = v_animationClock[frame].getElapsedTime().asMilliseconds();
				if (temp_timeElasped >= std::stoi(v_animationRules[frame][3]))
				{
					m_player.setTexture(v_animationList[frame]);
					if (v_animationRules[frame][1] == "right")
					{
						m_player.setTextureRect(sf::IntRect(stoi(v_animationRules[frame][4]) * stoi(v_animationRules[frame][6]), 0, stoi(v_animationRules[frame][4]), stoi(v_animationRules[frame][5])));
					}
					else if (v_animationRules[frame][1] == "left")
					{
						m_player.setTextureRect(sf::IntRect(0, 0, stoi(v_animationRules[frame][4]), stoi(v_animationRules[frame][5])));
					}
					else if (v_animationRules[frame][1] == "down")
					{
						m_player.setTextureRect(sf::IntRect(0, 0, stoi(v_animationRules[frame][4]), stoi(v_animationRules[frame][5])));
					}
					else if (v_animationRules[frame][1] == "up")
					{
						m_player.setTextureRect(sf::IntRect(0, 0, stoi(v_animationRules[frame][4]), stoi(v_animationRules[frame][5])));
					}
					if (stoi(v_animationRules[frame][6]) < stoi(v_animationRules[frame][2]) && !v_animationReverseRules[frame][1])
					{
						v_animationRules[frame][6] = std::to_string(stoi(v_animationRules[frame][6]) + 1);
					}
					else if (stoi(v_animationRules[frame][6]) > 0 && v_animationReverseRules[frame][1])
					{
						v_animationRules[frame][6] = std::to_string(stoi(v_animationRules[frame][6]) - 1);
					}
					else
					{ 
						if (!v_animationReverseRules[frame][0] && !v_animationReverseRules[frame][1] && stoi(v_animationRules[frame][6]) >= stoi(v_animationRules[frame][2]))
						{
							v_animationRules[frame][6] = "0";
						}
						else if (v_animationReverseRules[frame][0] && !v_animationReverseRules[frame][1] && stoi(v_animationRules[frame][6]) >= stoi(v_animationRules[frame][2]))
						{
							v_animationReverseRules[frame][1] = true;
						}
						else if (v_animationReverseRules[frame][1] && stoi(v_animationRules[frame][6]) <= 0)
						{
							v_animationReverseRules[frame][1] = false;
						}
					}
					v_animationClock[frame].restart();
					std::cout << v_animationRules[frame][6] << std::endl;
				}
			}
		frame++;
		}
	}
	void player::f_setPlayerGameState(std::string status)
	{
		m_status = status;
	}
	void player::f_move(std::string direction, float speed)
	{
		if (m_collisionMesh)
		{
			f_physic();
		}
		if (direction == "down")
		{
			m_player.move(0,speed);
		}
		else if (direction == "up")
		{
			m_player.move(0, -speed);
		}
		else if (direction == "right")
		{
			m_player.move(speed, 0);
		}
		else if (direction == "left")
		{
			m_player.move(-speed, 0);
		}
	}
	void player::f_move(std::string direction)
	{
		if (m_collisionMesh)
		{
			f_physic();
		}
		if (direction == "down")
		{
			m_player.move(0, m_ySpeed);
		}
		else if (direction == "up")
		{
			m_player.move(0, -m_ySpeed);
		}
		else if (direction == "right")
		{
			m_player.move(m_xSpeed, 0);
		}
		else if (direction == "left")
		{
			m_player.move(-m_xSpeed, 0);
		}
	}
	void player::f_physic()
	{
		m_playerBox.setSize(sf::Vector2f( m_player.getGlobalBounds().width, m_player.getGlobalBounds().height));
		m_playerBox.setScale(m_player.getScale().x, m_player.getScale().y);
		m_playerBox.setOutlineColor(sf::Color::Red);
		m_playerBox.setFillColor(sf::Color::Transparent);
		m_playerBox.setOutlineThickness(1.0f);
		m_playerBox.setPosition(m_player.getPosition().x, m_player.getPosition().y);

		
	}