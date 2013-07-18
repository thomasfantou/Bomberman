#include "Bonus.h"

Bonus::Bonus(void)
{
}

Bonus::Bonus(int type)
{
	bonus = type;
	position.x = POSITION_X;
	position.y = POSITION_Y;
	switch(bonus)
	{
	case BONUS_SPEEDUP:
		image.LoadFromFile("Sprites\\bonusspeed.png");
		break;
	case BONUS_SPEEDDOWN:
		image.LoadFromFile("Sprites\\malusspeed.png");
		break;
		
	}
}

Bonus::~Bonus(void)
{
}

void Bonus::setPosition(int positionX, int positionY)
{
	position.x = positionX * SQUARE_SIZE + POSITION_X;
	position.y = positionY * SQUARE_SIZE + POSITION_Y;
	colonne = positionX;
	row = positionY;
}

void Bonus::applyBonus(Bomberman &bomberman)
{
	switch(bonus)
	{
	case BONUS_SPEEDUP:
		bomberman.vitesse++;
		break;
	case BONUS_SPEEDDOWN:
		if(bomberman.vitesse > 1)
			bomberman.vitesse--;
		break;
		
	}
}