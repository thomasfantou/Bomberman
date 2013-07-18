#pragma once
#include "Screen.h"

class ScreenCommand : public Screen
{
private:
	sf::String commandTitle;
	sf::String commandSubTitle;
	sf::String commandReturn;
	sf::String commandIndex;
	sf::String commandInfo;

	sf::Image background;
	sf::Sprite backgroundSprite;
	sf::Image touches;
	sf::Sprite touchesSprite;
	
	int page;
	int totalPage;
	int currentPage;
public:
	ScreenCommand(void);
	~ScreenCommand(void);
	virtual void Init(void);
	virtual void Draw(sf::RenderWindow &App);
	virtual int Run(sf::RenderWindow &App);
};
