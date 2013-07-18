#include "Bomberman.h"

Bomberman::Bomberman(void)
{
}

Bomberman::Bomberman(int _player)
{
	position.x = POSITION_X;
	position.y = POSITION_Y;
	velocity.x = 0;
	velocity.y = 0;
	vitesse = 2;
	moving = false;
	lastMovement = 0;
	spriteRect.Top = 0;
	spriteRect.Left = 0;
	spriteRect.Right = 38;
	spriteRect.Bottom = 38;
	frame = 0;
	games = 0;
	bombCount = 1;
	bombLvl = 1;

	player = _player;

	switch(_player)
	{
	case 1:
		image.LoadFromFile("Sprites\\bombermanspritesP1.png");
		colonne = 1;
		row = 1;
		break;
	case 2:
		image.LoadFromFile("Sprites\\bombermanspritesP2.png");
		colonne = 13;
		row = 13;
		break;
	case 3:
		image.LoadFromFile("Sprites\\bombermanspritesP3.png");
		colonne = 13;
		row = 1;
		break;
	case 4:
		image.LoadFromFile("Sprites\\bombermanspritesP4.png");
		colonne = 1;
		row = 13;
		break;
	}
	position.x += SQUARE_SIZE * colonne;
	position.y += SQUARE_SIZE * row;
	sprite.SetImage(image);
	sprite.SetPosition(position.x, position.y);
}

Bomberman::~Bomberman(void)
{
}

void Bomberman::move(int direction)
{
	if(!moving)
	{
		switch (direction)
		{
		case UP:
			velocity.y = -1 * vitesse;
			break;
		case RIGHT:
			velocity.x = 1 * vitesse;
			break;
		case DOWN:
			velocity.y = 1 * vitesse;
			break;
		case LEFT:
			velocity.x = -1 * vitesse;
			break;
		}
		lastMovement = direction;
		moving = true;
	}
}

void Bomberman::update(float elapsedTime)
{
	if(moving) // on test si il doit y avoir un mouvement pour update car on enlevera le mouvement qd on aura atteint une autre case
	{
		position.x += velocity.x;
		position.y += velocity.y;
		int pX = POSITION_X;
		int px = position.x;
		int pY = POSITION_Y;
		int py = position.y;

		if((px - pX)%SQUARE_SIZE == 0 && (py - pY)%SQUARE_SIZE == 0) // Si le bomberman arrive pile sur une case il s'arrete
		{
			moving = false;
			velocity.x = 0;
			velocity.y = 0;
			switch(lastMovement)
			{
			case UP:
				row--;
				break;
			case RIGHT:
				colonne++;
				break;
			case DOWN:
				row++;
				break;
			case LEFT:
				colonne--;
				break;
			}
			//std::cout << "position :" << colonne << ":" << row << std::endl;
			configureSprite(STOP);
		}
		if(velocity.x > 0)
		{
			if(((px - pX)%SQUARE_SIZE >= (SQUARE_SIZE - vitesse))) // si le bomberman est presque arrive sur une case, on va lui ajouter la vitesse necessaire pour se mettre pile dessus
			{
				velocity.x = (SQUARE_SIZE - (px - pX)%SQUARE_SIZE);
			}
			configureSprite(RIGHT);
		}
		if(velocity.x < 0)
		{
			if(((px - pX)%SQUARE_SIZE <= (vitesse)) && ((px - pX)%SQUARE_SIZE != 0))// si le bomberman est presque arrive sur une case, on va lui ajouter la vitesse necessaire pour se mettre pile dessus
			{
				velocity.x = -((px - pX)%SQUARE_SIZE);
			}
			configureSprite(LEFT);
		}
		if(velocity.y > 0)
		{
			if(((py - pY)%SQUARE_SIZE >= (SQUARE_SIZE - vitesse)))// si le bomberman est presque arrive sur une case, on va lui ajouter la vitesse necessaire pour se mettre pile dessus
			{
				velocity.y = (SQUARE_SIZE - (py - pY)%SQUARE_SIZE);
			}
			configureSprite(DOWN);
		}
		if(velocity.y < 0)
		{
			if(((py - pY)%SQUARE_SIZE <= (vitesse)) && ((py - pY)%SQUARE_SIZE) != 0)// si le bomberman est presque arrive sur une case, on va lui ajouter la vitesse necessaire pour se mettre pile dessus
			{
				velocity.y = -((py - pY)%SQUARE_SIZE);
			}
			configureSprite(UP);
		}

		
	}

	for(int i = 0; i < vBomb.size(); i++) // on regarde si les bombe on passé leur temps de vie, si c'est le cas on les élimine de la liste
	{
		vBomb.at(i).timeToLive -= elapsedTime;
		if(vBomb.at(i).timeToLive <= 0.f)
		{
			Explosion explosion(vBomb.at(i));
			vExplosion.push_back(explosion);
			vBomb.erase(vBomb.begin() + i);
			bombCount++;
		}
	}

	for(int i = 0; i < vExplosion.size(); i++) // si l'explosion est terminé, on l'élimine de la liste
	{
		if(!vExplosion.at(i).alive)
		{
			vExplosion.erase(vExplosion.begin() + i);
		}
	}


}

void Bomberman::unmove(int direction)
{
	switch (direction)
	{
	case UP:
		velocity.y = 0;
		break;
	case RIGHT:
		velocity.x = 0;
		break;
	case DOWN:
		velocity.y = 0;
		break;
	case LEFT:
		velocity.x = 0;
		break;
	}
}

void Bomberman::configureSprite(int direction)
{
	if(direction == STOP) //on a défini -1 si 
	{
		spriteRect.Top = lastMovement * 38;
		spriteRect.Left = 0;
		spriteRect.Right = spriteRect.Left + 38;
		spriteRect.Bottom = spriteRect.Top + 38;
		frame = 0;
	}
	else
	{
		spriteRect.Top = direction * SQUARE_SIZE;
		spriteRect.Bottom = spriteRect.Top + 38;
		spriteRect.Left = frame * SQUARE_SIZE;
		spriteRect.Right = spriteRect.Left + 38;
		if(frame == 8)
			frame = 1;
		else
			frame++;
	}
}

void Bomberman::dropBomb()
{
	if(bombCount >= 1)
	{
		Bombe bombe(player, bombLvl); //player pour la couleur, et bombLvl pour la taille

		bombe.setPosition(position, colonne, row);
		vBomb.push_back(bombe);

		bombCount--;
	}
}