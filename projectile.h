#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class projectile
{
public:
	projectile();
	~projectile();
	std::vector<sf::Sprite> PROJECTILELIST;
	sf::Sprite PROJECTILE;
	sf::Texture PROJECTILETEXTURE;
	std::vector<sf::Sprite>::iterator PROJECTILELOCATION;
	void FaddProjectile();
	float PROJECTILESPEEDX, PROJECTILESPEEDY;
	void FsetTexture();
	float ANGLE;
};

