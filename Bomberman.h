#pragma once
#include <SFML/Graphics.hpp>
#include "constantes.h"
#include <iostream>
#include <SFML/System.hpp>
#include "Bombe.h"
#include "Explosion.h"
#include "GameObject.h"


class Bomberman : public GameObject
{
public:
	Bomberman(void);
	Bomberman(int _player);
	~Bomberman(void);
	int vie;
	std::string couleur;
	int vitesse;
	sf::Vector2<int> velocity;
	sf::Sprite sprite;
	int player;
	bool moving;
	int lastMovement;
	int frame;
	sf::Rect<int> spriteRect;
	int games;
	int bombCount;
	int bombLvl;
	std::vector<Bombe> vBomb;
	std::vector<Explosion> vExplosion;

	
	enum
	{
		STOP = -1,
		DOWN,
		RIGHT,
		UP,
		LEFT
	};
	void move(int);
	void update(float elapsedTime);
	void unmove(int);
	void configureSprite(int);
	void dropBomb();
};
