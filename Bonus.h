#pragma once
#include "constantes.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bomberman.h"
#include "GameObject.h"

class Bonus : public GameObject
{
public:
	Bonus(void);
	Bonus(int);
	~Bonus(void);
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
	int bonus; //on attribuera le bonus demandé
	
	void setPosition(int,int);
	void applyBonus(Bomberman &bomberman);

};
