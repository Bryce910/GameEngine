#include "stdafx.h"
#include "linker.h"

class player
	{
	public:
		player();
		~player();
		sf::Sprite m_player;
		enum PlayerMovement { up, down, left, right };
		enum PlayerAction { walk, run, idle, jump };
		enum PlayerMovement e_playerDirection;
		enum PlayerAction e_playerAction;
		float m_xSpeed, m_ySpeed, m_health, m_angle;
		std::string m_status;
		sf::Vector2f v_playerCenter;
		void FgetMovement();
		void FgetCenter();
		void FmovePlayer();
		void FgetHealth();
		void FsetHealth();
		void FgetAngle();
		void f_setPlayerGameState(std::string status);
		void f_setTexture(sf::Texture &texture, sf::Vector2f size);
		void f_animationTexture(sf::Texture &texture, std::string type, int maxFrames, float speed);
	};

