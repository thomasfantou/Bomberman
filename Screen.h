#pragma once
#include <SFML/Graphics.hpp>
#include "constantes.h"

class Screen
{
protected:
	sf::Font myFont;
	sf::Font myFont2;
	sf::Event Event;
public:
	Screen(void);
	~Screen(void);
	virtual void Init(void) = 0;
	virtual void Draw(sf::RenderWindow &App) = 0;
	virtual int Run (sf::RenderWindow &App) = 0;

	enum // On fait une énumération qui permettra de differencier les differents écrans.
	{
		SCREEN_EXIT = -1,
		SCREEN_MENU,
		SCREEN_SETUP,
		SCREEN_GAME,
		SCREEN_COMMAND
	};
};
