#pragma once
#include "constantes.h"
#include "GameObject.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Particule : public GameObject
{
public:
	Particule(void);
	Particule(int _player, int _colonne, int _row, int _particule);
	~Particule(void);
	void setImage(int _particule);
	bool nextFrame();

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
	int particule;
	int puissance; //epaisseur de l'explosion
	bool growing; //si l'explosion est en phase de developpement

};
