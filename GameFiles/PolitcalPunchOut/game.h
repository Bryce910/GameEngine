#include "stdafx.h"
#include "linker.h"
class game
{
public:
	game();
	~game();
	
	std::vector<std::string> GAMESTATELIST;
	std::string GAMESTATE;
	enum EGameType { standard, sidescroller, verticalscroller, platformer, shootemup};
	enum EGameState GAMETYPE;
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
	void FsetGameState(std::string state);
	void FDisplaySplash(sf::Texture splashDisplay, std::string location);
	void FsetIcon(int x, int y,sf::Image &icon);
	void FsetOverallVolume();
	void FsetSingelVolume();
	
	void FClear();

	void FhideTerminal();
	void FaddGameState(std::string state);
	void Fdraw();
};

