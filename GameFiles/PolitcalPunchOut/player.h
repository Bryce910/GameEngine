#include "stdafx.h"
#include "linker.h"

class player
{
public:
	player();
	~player();
	sf::Sprite PLAYER;
	enum PlayerMovement {up, down, left, right};
	enum PlayerAction {walk, run, idle, jump};
	enum PlayerMovement PLAYERDIRECTION;
	enum PlayerAction PLAYERACTION;
	float XSPEED, YSPEED, HEALTH, ANGLE;
	sf::Vector2f PLAYERCENTER;
	void FgetMovement();
	void FgetCenter();
	void FmovePlayer();
	void FgetHealth();
	void FsetHealth();
	void FgetAngle();
};

