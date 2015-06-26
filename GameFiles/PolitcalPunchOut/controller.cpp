#include "stdafx.h"
#include "linker.h"


controller::controller()
{
}


controller::~controller()
{
}

bool controller::f_getKey(sf::Keyboard::Key input)
{
	if (sf::Keyboard::isKeyPressed(input))
	{
		return true;
	}
	return false;
}
/* Not sure if we even need this */
bool controller::f_checkKey(sf::Keyboard::Key input)
{
		if (sf::Keyboard::isKeyPressed(input))
	{
		return true;
	}
	return false;
}