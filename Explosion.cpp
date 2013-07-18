#include "Explosion.h"

Explosion::Explosion(void)
{
}

Explosion::Explosion(Bombe bombe)
{
	colonne = bombe.colonne;
	row = bombe.row;
	position = bombe.position;
	range = bombe.range;
	alive = true;
	started = false;
	frame = 0;
	player = bombe.player;
}

Explosion::~Explosion(void)
{
}

void Explosion::update(int carte[WIDTH_SQUARES_COUNT][HEIGHT_SQUARES_COUNT])
{
	if(!started)
	{
		init(carte);
		started = true;
	}
	frame++;

	if(frame == 3)
	{
		for(int i = 0; i < vParticule.size();i++)
		{
			alive = vParticule.at(i).nextFrame(); //si le dernier frame a eu lieu, on retourne un false qui dira que l'explosion est terminé
		}
		frame = 0;
	}
}

void Explosion::init(int carte[WIDTH_SQUARES_COUNT][HEIGHT_SQUARES_COUNT])
{
	Particule epicentre(player, colonne, row, PARTICULE_EPICENTRE);
	for(int i = 0; i < (range - 1);i++)
	{
		
	}
	Particule topend(player, colonne, row - range, PARTICULE_TOPEND);
	Particule rightend(player, colonne + range, row, PARTICULE_RIGHTEND);
	Particule bottomend(player, colonne, row + range, PARTICULE_BOTTOMEND);
	Particule leftend(player, colonne - range, row, PARTICULE_LEFTEND);


	vParticule.push_back(epicentre);
	vParticule.push_back(topend);
	vParticule.push_back(rightend);
	vParticule.push_back(leftend);
	vParticule.push_back(bottomend);

}