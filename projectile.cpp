#include "stdafx.h"
#include "projectile.h"


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
