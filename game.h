#pragma once
#include "stdafx.h"

#include "SFML/Graphics.hpp"
class game
{
public:
	game();
	~game();
	
	enum EGameState {splash, loading, paused, menu, play, lose, win, close};
	enum EGameState GAMESTATE;
	int MAXFRAMERATE;
	std::string GAMETITLE;
	int FsetFrameRate(int maxframerate);
	bool FsetGameTitle(std::string gameTitle);
	sf::RenderWindow GAMESCREEN;
	unsigned int GAMESIZEX, GAMESIZEY;
	sf::Texture SPLASHTEXTURE;
	sf::Sprite BACKGROUND;
	void FloadWindow();
	void Fupdate();
	void FsetGameSize(unsigned int sizeX, unsigned int sizeY);
	void FcheckEventState();
	void FDisplaySplash(sf::Texture splashDisplay, std::string location);
	void FClear();
};

