#include "stdafx.h"
#include "linker.h"
	player::player()
	{
//		this->FgetCenter();
		m_health = 100;
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

	void player::f_setTexture(sf::Texture &texture, sf::Vector2f size)
	{
		m_player.setTexture(texture);
		if (size.x == 0 || size.y == 0)
		{
			m_player.setTextureRect(sf::IntRect(0,0,int(m_player.getGlobalBounds().width), int( m_player.getGlobalBounds().height)));
		}
		else
		{
			m_player.setTextureRect(sf::IntRect(0, 0, int( size.x),int( size.y)));
		}
		
	}

	void f_animationTexture(sf::Texture &texture, std::string type, int maxFrames, float speed)
	{

	}

	void player::f_setPlayerGameState(std::string status)
	{
		m_status = status;
	}
	 