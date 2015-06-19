// PolitcalPunchOut.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "linker.h"

int main()
{
	game PolitalPunchout;
	PolitalPunchout.FsetFrameRate(60);
	PolitalPunchout.FsetGameTitle("Politcal PunchOut");
	PolitalPunchout.FsetGameSize(800, 600);
	PolitalPunchout.FhideTerminal();
	PolitalPunchout.FloadWindow();
	sf::Texture t;
	player Character;
	projectile Projectile;
	while (PolitalPunchout.GAMESTATE != "close")
	{
		PolitalPunchout.FcheckEventState();
		PolitalPunchout.FClear();
		if (PolitalPunchout.GAMESTATE == "splash")
		{
			PolitalPunchout.FDisplaySplash(t, "center");
		}
		else if (PolitalPunchout.GAMESTATE == "play")
		{
			Character.FgetMovement();
			Projectile.PROJECTILETEXTURE = t;
			Projectile.FaddProjectile();
		}
		else if (PolitalPunchout.GAMESTATE == "loading")
		{

		}

		PolitalPunchout.Fupdate();
	} 
	
	
	return 0;
}