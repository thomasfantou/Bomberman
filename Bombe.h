#pragma once
#include "constantes.h"
#include "GameObject.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Bombe : public GameObject
{
public:
	Bombe(void);
	Bombe(int _player, int puissance);
	~Bombe(void);
	void setPosition(sf::Vector2<int> _position, int _colonne, int _row);

	int player;
	int range;
	int bombLvl;
	float timeToLive;
};
