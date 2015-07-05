// PolitcalPunchOut.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "variable.h"
#include "linker.h"

int main()
{
	simplicity::game* c_screen = new simplicity::game("Demo Game", 800, 600, 60, false, false);
	//simplicity::player* c_player = new simplicity::player(c_screen->m_gameScreen, playerTexture, "bottom right");
	/* Don't need below */
	/*
		c_screen->FsetFrameRate(60);
		c_screen->FsetGameTitle("Politcal PunchOut");
		c_screen->FsetGameSize(800, 600);
		c_screen->FhideTerminal();
		c_screen->FloadWindow();
	*/
	/* Set Textures */
	c_screen->f_loadTexture(mainMenuTexture, "C:\\Users\\Bryce\\Documents\\GitHub\\GameEngine\\GameFiles\\x64\\Debug\\images\\splash.jpg");
	c_screen->f_loadTexture(startTexture, "C:\\Users\\Bryce\\Documents\\GitHub\\GameEngine\\GameFiles\\x64\\Debug\\images\\menu\\startGame.png");
	c_screen->f_loadTexture(quitTexture, "C:\\Users\\Bryce\\Documents\\GitHub\\GameEngine\\GameFiles\\x64\\Debug\\images\\menu\\quitGame.png");
	c_screen->f_loadTexture(startHoverTexture, "C:\\Users\\Bryce\\Documents\\GitHub\\GameEngine\\GameFiles\\x64\\Debug\\images\\menu\\startGameHover.png");
	c_screen->f_loadTexture(quitHoverTexture, "C:\\Users\\Bryce\\Documents\\GitHub\\GameEngine\\GameFiles\\x64\\Debug\\images\\menu\\quitGameHover.png");
	c_screen->f_loadTexture(splashTexture, "C:\\Users\\Bryce\\Documents\\GitHub\\GameEngine\\GameFiles\\x64\\Debug\\images\\splash.jpg");

	/* Adding menu Items*/
	c_screen->f_addMenuItem(c_screen->m_gameScreen, splashTexture, splashTexture, "splash", "Center Middle", sf::Vector2f(0, 0), 1.0f, 1.0f);
	c_screen->f_addMenuItem(c_screen->m_gameScreen, mainMenuTexture, mainMenuTexture, "play", "Center Middle", sf::Vector2f(0, 0),0.f,0.f);
	c_screen->f_addMenuItem(c_screen->m_gameScreen, startTexture, startHoverTexture, "play", "left Middle", sf::Vector2f(0, 0), 0.2f, 0.2f);
	c_screen->f_addMenuItem(c_screen->m_gameScreen, quitTexture, quitHoverTexture, "play", "Center Middle", sf::Vector2f(0, 0), 0.2f, 0.2f);
	
	/* While the window is open*/
	while (c_screen->m_gamestate != "close")
	{
		c_screen->f_checkEventState();
		c_screen->f_Clear();
		/* Check key being pushed. */
		if (c_screen->f_checkKey(c_screen->key->Space))
		{
			c_screen->m_gamestate = "play";
		}
		else if (c_screen->f_checkKey(c_screen->key->P))
		{
			c_screen->m_gamestate = "pause";
		}
		/* Draw your screen and display it. */
		c_screen->f_draw();
		c_screen->f_update();
	} 
	return 0;
}