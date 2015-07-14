#include "stdafx.h"
#include "projectile.h"
#include <math.h>

projectile::projectile()
{
}
projectile::~projectile()
{
}
void projectile::f_setTexture()
{
	m_projectile.setTexture(this->m_projectileTexture);
}
void projectile::f_addProjectile()
{
	f_setTexture();
	v_projectileList.push_back(this->m_projectile);
	v_projectileRules.resize(v_projectileList.size());
	/* Collsion Mesh */
	v_projectileRules[v_projectileList.size() - 1].push_back("true");
	/* Tracking Player */
	v_projectileRules[v_projectileList.size() - 1].push_back("false");
	/* Dissapear on Collision */
	v_projectileRules[v_projectileList.size() - 1].push_back("true");
	/* Damage on Collision */
	v_projectileRules[v_projectileList.size() - 1].push_back("10");
}
void projectile::f_moveProjectile(sf::RenderWindow &app, float x, float y)
{
	f_setAngle(app, x, y);
	m_angle = m_projectile.getRotation();
	/* Moving to the spot*/
	double dynamicX = cos(m_angle * 3.14 / 180) * m_projectileSpeed;
	double dynamicY = sin(m_angle * 3.14 / 180) * m_projectileSpeed;
	m_projectile.move(float(dynamicX), float(dynamicY));
}
void projectile::f_setAngle(sf::RenderWindow &app, float x, float y)
{
	sf::Vector2f curPos = sf::Vector2f(x, y);
	sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(app).x, sf::Mouse::getPosition(app).y);
	/* Time to get the correct angle */
	float dx = curPos.x - pos.x;
	float dy = curPos.y - pos.y;
	/* Back to degrees */
	double rotation = (atan2(dy, dx)) * 180 / m_pi;
	/* Set that angel of fire*/
	m_projectile.setRotation(float(rotation));
}