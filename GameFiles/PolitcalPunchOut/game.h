#include "stdafx.h"
#include "linker.h"
namespace simplicity
{
	class game : public menu, public controller, public sf::Texture
	{
	public:
		game();
		game(std::string title, unsigned int GameSizeX, unsigned int GameSizeY, int frameRate, bool hideterminal, bool fullscreen);
		~game();
		/* Public Variables */
		std::vector<std::string> m_gamestatelist;
		std::string m_gamestate;
		bool teamSet = false;
		enum EGameType { standard, sidescroller, verticalscroller, platformer, shootemup, faller };
		enum EGameState m_gametype;
		int m_maxFrameRate;
		std::string m_gameTitle;
		int FsetFrameRate(int maxframerate);
		bool FsetGameTitle(std::string gameTitle);
		sf::RenderWindow m_gameScreen;
		sf::Vector2i m_screenSize;
		sf::Texture m_splashTexture;
		sf::Sprite m_background;
		bool m_fullScreen = false;
		/* Public Functions */
		void f_loadWindow();
		void f_update();
		void f_setGameSize(unsigned int sizeX, unsigned int sizeY);
		void f_checkEventState();
		void f_setGameState(std::string state);
		void f_DisplaySplash(sf::Texture splashDisplay, std::string location);
		void f_setIcon(int x, int y, sf::Image &icon);
		void f_setOverallVolume();
		void f_setSingelVolume();
		void f_setFullScreen();
		void f_Clear();
		void f_hideTerminal();
		void f_addGameState(std::string state);
		void f_draw();
		void f_draw(player* c_player);
		void f_screenShake(float x, float y, std::string intensity);
		void f_screenShake(float x, float y);
		void f_loadTexture(sf::Texture &texture, std::string path);
	};

}