#pragma once
#include "Screen.h"
#include "Config.h"

class ScreenSetup : public Screen
{
private:
	int playerCount;
	int roundCount;
	int selected;
	sf::String setupTitle;
	sf::String setupPlay;
	sf::String setupReturn;
	sf::String setupMsg1;
	sf::String setupMsg2;
	sf::String setupPlayer;
	sf::String setupRound;

	sf::Image background;
	sf::Sprite backgroundSprite;
public:
	ScreenSetup(void);
	~ScreenSetup(void);	
	virtual void Init(void);
	virtual void Draw(sf::RenderWindow &App);
	virtual int Run(sf::RenderWindow &App);
};
