#pragma once
#include "stdafx.h"
#include "linker.h"

class controller
{
public:
	controller();
	~controller();
	bool f_getKey(sf::Keyboard::Key input);
	bool f_checkKey(sf::Keyboard::Key input);
};

