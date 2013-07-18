#include "Particule.h"

Particule::Particule(void)
{
}

Particule::Particule(int _player, int _colonne, int _row, int _particule)
{
	colonne = _colonne;
	row = _row;
	position.x = POSITION_X + (colonne * SQUARE_SIZE);
	position.y = POSITION_Y + (row * SQUARE_SIZE);
	puissance = 0;
	particule = _particule;
	player = _player;
	growing = true;

	switch(player)
	{
	case 1:
		image.LoadFromFile("Sprites\\explosionP1.png");
		break;
	case 2:
		image.LoadFromFile("Sprites\\explosionP2.png");
		break;
	case 3:
		image.LoadFromFile("Sprites\\explosionP3.png");
		break;
	case 4:
		image.LoadFromFile("Sprites\\explosionP4.png");
		break;
	}
	setImage(particule);

	
}

Particule::~Particule(void)
{
}

void Particule::setImage(int _particule)
{
	spriteRect.Left = SQUARE_SIZE;
	spriteRect.Top = SQUARE_SIZE;
	spriteRect.Right = SQUARE_SIZE;
	spriteRect.Bottom = SQUARE_SIZE;

	switch(_particule)
	{
	case PARTICULE_EPICENTRE :
		spriteRect.Left *= 1;
		spriteRect.Top *= 1;
		break;
	case PARTICULE_TOP :
		spriteRect.Left *= 1;
		spriteRect.Top *= 2;
		break;
	case PARTICULE_TOPEND :
		spriteRect.Left *= 1;
		spriteRect.Top *= 0;
		break;
	case PARTICULE_RIGHT :
		spriteRect.Left *= 2;
		spriteRect.Top *= 1;
		break;
	case PARTICULE_RIGHTEND :
		spriteRect.Left *= 3;
		spriteRect.Top *= 1;
		break;
	case PARTICULE_BOTTOM :
		spriteRect.Left *= 1;
		spriteRect.Top *= 2;
		break;
	case PARTICULE_BOTTOMEND :
		spriteRect.Left *= 1;
		spriteRect.Top *= 3;
		break;
	case PARTICULE_LEFT :
		spriteRect.Left *= 2;
		spriteRect.Top *= 1;
		break;
	case PARTICULE_LEFTEND :
		spriteRect.Left *= 0;
		spriteRect.Top *= 1;
		break;
	}

	spriteRect.Right += spriteRect.Left;
	spriteRect.Bottom += spriteRect.Top;
}

bool Particule::nextFrame()
{
	if(growing)
	{
		puissance++;
		spriteRect.Top += (SQUARE_SIZE * 4);
		spriteRect.Bottom = spriteRect.Top + SQUARE_SIZE;
		if(puissance == 3)
			growing = false;
		return true;
	}
	else
	{
		puissance--;
		spriteRect.Top -= (SQUARE_SIZE * 4);
		spriteRect.Bottom = spriteRect.Top + SQUARE_SIZE;
		if(puissance == 0)
			return false;
		else
			return true;
			
	}
}