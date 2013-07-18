#include "Bombe.h"

Bombe::Bombe(void)
{
}

Bombe::Bombe(int _player, int _puissance)
{
	position.x = POSITION_X;
	position.y = POSITION_Y;
	timeToLive = 3.f;
	range = 1;
	player = _player;
	switch(player)
	{
	case 1:
		image.LoadFromFile("Sprites\\bombeP1.png");
		break;
	case 2:
		image.LoadFromFile("Sprites\\bombeP2.png");
		break;
	case 3:
		image.LoadFromFile("Sprites\\bombeP3.png");
		break;
	case 4:
		image.LoadFromFile("Sprites\\bombeP4.png");
		break;
	}
	spriteRect.Top = 0;
	spriteRect.Left = (_puissance-1)*SQUARE_SIZE;
	spriteRect.Right = spriteRect.Left + SQUARE_SIZE;
	spriteRect.Bottom = spriteRect.Top + SQUARE_SIZE;
}

Bombe::~Bombe(void)
{
}


void Bombe::setPosition(sf::Vector2<int> _position,int _colonne, int _row)
{
	/*colonne = _colonne;
	row = _row;
	position.x = POSITION_X + (colonne * SQUARE_SIZE);
	position.y = POSITION_Y + (row * SQUARE_SIZE);*/


	//On veut poser la bombe sur la case qui est la plus proche de nous
	colonne = _colonne;
	row = _row;
	int px = _position.x;
	int py = _position.y;
	int pX = POSITION_X;
	int pY = POSITION_Y;

	if((((_colonne * SQUARE_SIZE) + pX) < px) && (((px - pX) % SQUARE_SIZE) > (SQUARE_SIZE / 2)))
		colonne++;

	if((((_colonne * SQUARE_SIZE) + pX) > px) && (((px - pX) % SQUARE_SIZE) < (SQUARE_SIZE / 2)))
		colonne--;

	if((((_row * SQUARE_SIZE) + pY) < py) && (((py - pY) % SQUARE_SIZE) > (SQUARE_SIZE / 2)))
		row++;

	if((((_row * SQUARE_SIZE) + pY) > py) && (((py - pY) % SQUARE_SIZE) < (SQUARE_SIZE / 2)))
		row--;

	position.x = POSITION_X + (colonne * SQUARE_SIZE);
	position.y = POSITION_Y + (row * SQUARE_SIZE);

}