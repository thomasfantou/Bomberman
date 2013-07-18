#pragma once
#include "Screen.h"
#include "Config.h"
#include "Bomberman.h"
#include "Bonus.h"
#include "Intersections.h"
#include "Explosion.h"
#include <iostream>
#include <list>

class ScreenGame : public Screen
{
private:
	int cfgPlayer;
	int cfgRound;
	int returnFromUpdate;
	int frame;
	float elapsedTime;
	std::vector<Bonus> vbonus; // une liste de bonus dont on stockera les bonus actif sur la carte
	sf::Clock Clock;
	sf::Clock timerFps;

	sf::Image background;
	sf::Image logo;
	sf::Image avatarP1;
	sf::Image avatarP2;
	sf::Image avatarP3;
	sf::Image avatarP4;
	sf::Image sol;
	sf::Image bloc;
	sf::Image caisse;
	sf::Image loading;

	sf::Sprite backgroundSprite;
	sf::Sprite logoSprite;
	sf::Sprite avatarP1Sprite;
	sf::Sprite avatarP2Sprite;
	sf::Sprite avatarP3Sprite;
	sf::Sprite avatarP4Sprite;
	sf::Sprite solSprite;
	sf::Sprite blocSprite;
	sf::Sprite caisseSprite;
	sf::Sprite loadingSprite;
	sf::Vector2<int> position;
	

	Bomberman bomberman[4];


public:
	ScreenGame(void);
	ScreenGame(sf::RenderWindow &App);
	~ScreenGame(void);

	virtual void Init(void);
	virtual void Draw(sf::RenderWindow &App);
	virtual int Run(sf::RenderWindow &App);
	int Update(sf::RenderWindow &App, const sf::Input& Input);
	void LoadContent();
	void tryToMove(Bomberman &bomberman, int direction);
	void dropBonus();
	void checkForBonus(Bomberman &bomberman);

	Config cfg;
	Intersections intersections;
	
	enum
	{
		SURFACE_SOL,
		SURFACE_BLOC,
		SURFACE_CAISSE
	};
	enum //enum pour les mouvements des bomberman
	{
		STOP = -1,
		DOWN,
		RIGHT,
		UP,
		LEFT
	};
	enum
	{
		BONUS_SPEEDUP,
		BONUS_SPEEDDOWN,
		BONUS_BOMBUP,
		BONUS_BOMBDOWN,
		BONUS_FIREUP,
		BONUS_FIREDOWN,
		BONUS_FULLFIRE
	};

	int carte[WIDTH_SQUARES_COUNT][HEIGHT_SQUARES_COUNT];

};
