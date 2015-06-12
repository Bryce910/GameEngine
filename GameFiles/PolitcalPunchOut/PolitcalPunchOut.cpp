// PolitcalPunchOut.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "game.h"
#include "player.h"

int main()
{
	game PolitalPunchout;
	PolitalPunchout.FsetFrameRate(60);
	PolitalPunchout.FsetGameTitle("Politcal PunchOut");
	PolitalPunchout.FsetGameSize(800, 600);
	PolitalPunchout.FloadWindow();
	sf::Texture t;
	player Character;
	projectile Projectile;
	while(PolitalPunchout.GAMESTATE != game::EGameState::close)
	{
		PolitalPunchout.FcheckEventState();
		PolitalPunchout.FClear();
		if (PolitalPunchout.GAMESTATE == game::EGameState::splash)
		{
			PolitalPunchout.FDisplaySplash(t, "center");
		}
		else if (PolitalPunchout.GAMESTATE == game::EGameState::play)
		{
			Character.FgetMovement();
			Projectile.PROJECTILETEXTURE = t;
			Projectile.FaddProjectile();
		}
		PolitalPunchout.FdrawCharacter();
		PolitalPunchout.Fupdate();
	} 
	
	
	return 0;
}