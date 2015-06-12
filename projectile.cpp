#include "stdafx.h"
#include "projectile.h"
#include <math.h>

projectile::projectile()
{
}
projectile::~projectile()
{
}
void projectile::FsetTexture()
{
	this->PROJECTILE.setTexture(this->PROJECTILETEXTURE);
}
void projectile::FaddProjectile()
{
	this->FsetTexture();
	this->PROJECTILELIST.push_back(this->PROJECTILE);
}
void projectile::FmoveToLocation(float x, float y)
{
	projectile:FsetAngle(x, y);
	this->ANGLE = this->PROJECTILE.getRotation();
	/* Moving to the spot*/
	unsigned int dynamicX = cos(this->ANGLE * 3.14 / 180) * this->PROJECTILESPEED;
	unsigned int dynamicY = sin(this->ANGLE * 3.14 / 180) * this->PROJECTILESPEED;

	this->PROJECTILE.move(dynamicX, dynamicY);
}
void projectile::FsetAngle(float x, float y)
{
	sf::Vector2f curPos = sf::Vector2f(this->PROJECTILE.getGlobalBounds().left, this->PROJECTILE.getGlobalBounds().top);
	sf::Vector2f pos = sf::Vector2f(x, y);

	float pi = 3.14159265;
	float dx = curPos.x - pos.x;
	float dy = curPos.y - pos.y;
	float rotation = (atan2(dy, dx)) * 180 / pi;

	this->PROJECTILE.setRotation(rotation);
}