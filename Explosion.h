#pragma once
#include "constantes.h"
#include "GameObject.h"
#include "Bombe.h"
#include "Particule.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Explosion : public GameObject
{
public:
	Explosion(void);
	Explosion(Bombe bombe);
	~Explosion(void);
	void update(int carte[WIDTH_SQUARES_COUNT][HEIGHT_SQUARES_COUNT]);
	void init(int carte[WIDTH_SQUARES_COUNT][HEIGHT_SQUARES_COUNT]);

	enum
	{
		PARTICULE_EPICENTRE,
		PARTICULE_TOP,
		PARTICULE_RIGHT,
		PARTICULE_BOTTOM,
		PARTICULE_LEFT,
		PARTICULE_TOPEND,
		PARTICULE_RIGHTEND,
		PARTICULE_BOTTOMEND,
		PARTICULE_LEFTEND
	};

	int player;
	int frame;
	int range;
	bool alive;
	bool started;
	std::vector<Particule> vParticule;
};
