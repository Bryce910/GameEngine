#pragma once
#include "stdafx.h"
#include "linker.h"

class player: public projectile
	{
	public:
		player();
		~player();
		sf::Sprite m_player;
		std::string m_activeAnimation;
		std::string  m_playerAction;
		float m_xSpeed, m_ySpeed, m_health, m_angle;
		bool m_collisionMesh;
		sf::RectangleShape m_playerBox;
		std::string m_status;
		sf::Vector2f v_playerCenter;
		std::vector<sf::Texture>v_animationList;
		std::vector<sf::Clock>v_animationClock;
		sf::Clock c_aniClock;
		std::vector<std::vector<std::string>>v_animationRules;
		std::vector<std::vector<bool>>v_animationReverseRules;
		std::vector<int>v_animationDimensions;
		void FgetMovement();
		void FgetCenter();
		void FmovePlayer();
		void FgetHealth();
		void FsetHealth();
		void FgetAngle();
		void f_setPlayerGameState(std::string status);
		void f_setTexture(sf::Texture &texture, sf::Vector2f size, float scaleX, float scaleY);
		void f_animationTexture(sf::Texture &texture, int frameSizeX,int frameSizeY, std::string type, int maxFrames, std::string direction,  bool reverse, int speed);
		void f_animate();
		void f_setPostion(sf::RenderWindow &app);
		void f_move(std::string direction);
		void f_move(std::string direction, float speed);
		void animate();
		void f_physic();
	};

