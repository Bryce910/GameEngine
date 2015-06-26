#pragma once
/**/
#include "linker.h"
class level
{
public:
	level();
	/*
	std::vector<char[]> LEVELLIST;
	char LEVEL[500] = { 0 };
	std::vector<sf::Sprite> LEVELOBJECTLIST;
	sf::Sprite LEVELOBJECT;
	sf::Vector2f startingPosition;
	std::vector<std::string> LEVELOBJECTTYPELIST;
	std::string LEVELOBJECTTYPE;
	std::vector<bool> LEVELCOLISIONLIST;
	bool LEVELCOLISION;
	*/
	~level();
	void FaddLevel();
	void FaddLevelObject();
	void FaddLevelEnemy();
};

