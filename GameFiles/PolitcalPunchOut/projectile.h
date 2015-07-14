#pragma once
#include "stdafx.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include <windows.h>
#include "string.h"
#include <vector>

class projectile
{
public:
	projectile();
	~projectile();
	std::vector<sf::Sprite> v_projectileList;
	sf::Sprite m_projectile;
	sf::Texture m_projectileTexture;
	std::vector<sf::Sprite>::iterator m_projectileLocation;
	std::vector<std::vector<std::string>> v_projectileRules;
	double m_pi = 3.14159265;
	void f_addProjectile();
	float m_projectileSpeed;
	void f_setTexture();
	void f_moveProjectile(sf::RenderWindow &app, float x, float y);
	void f_setAngle(sf::RenderWindow &app, float x, float y);
	float m_angle;
};
