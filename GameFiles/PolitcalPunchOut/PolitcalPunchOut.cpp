// PolitcalPunchOut.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "linker.h"

int main()
{
	rad::game* c_screen = new rad::game("Demo Game", 800, 600, 60, true, false);
	/* Don't need below */
	/*
		c_screen->FsetFrameRate(60);
		c_screen->FsetGameTitle("Politcal PunchOut");
		c_screen->FsetGameSize(800, 600);
		c_screen->FhideTerminal();
		c_screen->FloadWindow();
	*/
	sf::Texture t;
	t.loadFromFile("images/splash.jpg");
	c_screen->f_addMenuItem(c_screen->m_gameScreen, t, "splash", "Center Middle", sf::Vector2f(0, 0));
	while (c_screen->m_gamestate != "close")
	{
		c_screen->f_checkEventState();
		if (c_screen->f_getKey(sf::Keyboard::P))
		{
			// do a bunch
			c_screen->m_gamestate = "play";
		}
		c_screen->f_Clear();
		c_screen->f_draw();
		c_screen->f_update();
	} 
	
	
	return 0;
}