#pragma once
#include "Screen.h"

class ScreenMenu : public Screen
{
private:
	sf::String menuPlay;
	sf::String menuCommandes;
	sf::String menuQuit;

	sf::Image background;
	sf::Sprite backgroundSprite;
public:
	ScreenMenu(void);
	~ScreenMenu(void);
	virtual void Init(void);
	virtual void Draw(sf::RenderWindow &App);
	virtual int Run(sf::RenderWindow &App);

};
