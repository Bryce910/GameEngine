// PolitcalPunchOut.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "variable.h"
#include "linker.h"
const std::string resourcePath = "C:\\Users\\Bryce\\Documents\\GitHub\\GameEngine\\GameFiles\\x64\\Debug\\images\\";

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
	/*  New Player */
	player* c_player = new player;
	c_player->f_setPlayerGameState("game");
	/* Set splashmenu texture */
	c_screen->f_loadTexture(splashTexture, resourcePath + "splash\\splash.png");
	/* Set Main Menu Textures */
	c_screen->f_loadTexture(mainMenuTexture, resourcePath + "mainMenu\\background.png");
	c_screen->f_loadTexture(startTexture, resourcePath +  "mainMenu\\startGame.png");
	c_screen->f_loadTexture(loadGameTexture, resourcePath + "mainMenu\\loadGame.png");
	c_screen->f_loadTexture(multiplayerTexture, resourcePath + "mainMenu\\multiplayer.png");
	c_screen->f_loadTexture(leaderboardTexture, resourcePath + "mainMenu\\leaderboard.png");
	c_screen->f_loadTexture(startHoverTexture, resourcePath + "mainMenu\\startGameHover.png");
	c_screen->f_loadTexture(loadGameHoverTexture, resourcePath + "mainMenu\\loadGameHover.png");
	c_screen->f_loadTexture(multiplayerHoverTexture, resourcePath + "mainMenu\\multiplayerHover.png");
	c_screen->f_loadTexture(leaderboardHoverTexture, resourcePath + "mainMenu\\leaderboardHover.png");
	/* Set Party Menu Textures */
	c_screen->f_loadTexture(partyMenuBackgroundTexture, resourcePath + "partyMenu\\background.png");
	c_screen->f_loadTexture(partyMenuRepTexture, resourcePath + "partyMenu\\rep.png");
	c_screen->f_loadTexture(partyMenuDemTexture, resourcePath + "partyMenu\\dem.png");
	/* Set player Texture */
	c_screen->f_loadTexture(playerTextureRep, resourcePath + "characters\\romney\\sprites_romney_idle_all_x.png");
	c_screen->f_loadTexture(playerTextureDem, resourcePath + "characters\\romney\\sprites_romney_idle_all_x.png");
	/* Adding Main Menu Items*/
	c_screen->f_addMenuItem(c_screen->m_gameScreen, splashTexture, splashTexture, "splash", "Center Middle", sf::Vector2f(0, 0), 1.0f, 1.0f);
	c_screen->f_addMenuItem(c_screen->m_gameScreen, mainMenuTexture, mainMenuTexture, "play", "Center Middle", sf::Vector2f(0, 0), 1.f,1.f);
	c_screen->f_addMenuItem(c_screen->m_gameScreen, loadGameTexture, loadGameHoverTexture, "play", "load", "Center Middle", sf::Vector2f(0, -50), 0.5f, 0.5f);
	c_screen->f_addMenuItem(c_screen->m_gameScreen, multiplayerTexture, multiplayerHoverTexture, "play", "multiplayer", "Center Middle", sf::Vector2f(0, 50), 0.5f, 0.5f);
	c_screen->f_addMenuItem(c_screen->m_gameScreen, leaderboardTexture, leaderboardHoverTexture, "play", "leaderboard", "Center Middle", sf::Vector2f(0, 0), 0.5f, 0.5f);
	c_screen->f_addMenuItem(c_screen->m_gameScreen, startTexture, startHoverTexture, "play", "party", "Center Middle", sf::Vector2f(0, -100), 0.5f, 0.5f);
	/* Adding Party Menu Items */
	c_screen->f_addMenuItem(c_screen->m_gameScreen, partyMenuBackgroundTexture, partyMenuBackgroundTexture, "party", "Center Middle", sf::Vector2f(0, 0), 1.f, 1.f);
	c_screen->f_addMenuItem(c_screen->m_gameScreen, partyMenuDemTexture, partyMenuDemTexture, "party", "game", "Center Middle", sf::Vector2f(-125, 0), 0.5f, 0.5f, "dem");
	c_screen->f_addMenuItem(c_screen->m_gameScreen, partyMenuRepTexture, partyMenuRepTexture, "party", "game", "Center Middle", sf::Vector2f(125, 0), 0.5f, 0.5f, "rep");
	/* While the window is open*/
	while (c_screen->m_gamestate != "close")
	{
		c_screen->f_checkEventState();
		c_screen->f_Clear();
		/* Check key being pushed. */
		if (c_screen->m_eventVariable == "rep")
		{
 			c_player->f_setTexture(playerTextureRep, { 0, 0 });
		}
		else if (c_screen->m_eventVariable == "dem")
		{
			c_player->f_setTexture(playerTextureDem, { 0, 0 });
		}
		if (c_screen->m_gamestate == "game")
		{
			if (int i = 0)
			{
				//do nothing
			}
		}
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
		c_screen->f_draw(c_player);
		c_screen->f_update();
	} 
	return 0;
}