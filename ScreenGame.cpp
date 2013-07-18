#include "ScreenGame.h"

ScreenGame::ScreenGame(void)
{
	returnFromUpdate = -2;
	frame = 0;

}

ScreenGame::ScreenGame(sf::RenderWindow &App)
{
	returnFromUpdate = -2;
	frame = 0;
}

ScreenGame::~ScreenGame(void)
{
}

void ScreenGame::Init()
{

}

int ScreenGame::Run(sf::RenderWindow &App)
{
	const sf::Input& Input = App.GetInput();

	//Ecran de chargement
	App.Clear();
	loading.LoadFromFile("Sprites\\chargement.png");
	loadingSprite.SetImage(loading);
	App.Draw(loadingSprite);
	App.Display();

	LoadContent();	

    bool running = true;
	while(running)
	{
		returnFromUpdate = Update(App, Input);
		Draw(App);
		elapsedTime = Clock.GetElapsedTime();
		
		if(timerFps.GetElapsedTime() >= 1.f)
		{
			std::cout << 1.f / App.GetFrameTime() << " FPS" << std::endl;
			
			timerFps.Reset();
		}

		App.SetFramerateLimit(FPS);
		Clock.Reset();

		//Si dans le update on veut changer d'écran, on retourne un int (de l'énum) et on le renvoit ici au main
		if(returnFromUpdate >= -1)
		{
			return returnFromUpdate;
		}

	}

}

void ScreenGame::LoadContent()
{	
	myFont.LoadFromFile("Policies\\CROOBIE_.TTF");
	myFont2.LoadFromFile("Policies\\hemi-head.ttf");

	background.LoadFromFile("Sprites\\backgroundGame.png");
	logo.LoadFromFile("Sprites\\logo.png");
	avatarP1.LoadFromFile("Sprites\\avatarP1.png");

	//On va definir les fenetre respective des joueur, et elles seront grisé si le joueur n'existe pas
	if(cfg.cfgPlayerCount > 1)
		avatarP2.LoadFromFile("Sprites\\avatarP2.png");
	else
		avatarP2.LoadFromFile("Sprites\\avatarP0.png");
	if(cfg.cfgPlayerCount > 2)
		avatarP3.LoadFromFile("Sprites\\avatarP3.png");
	else
		avatarP3.LoadFromFile("Sprites\\avatarP0.png");
	if(cfg.cfgPlayerCount > 3)
		avatarP4.LoadFromFile("Sprites\\avatarP4.png");
	else
		avatarP4.LoadFromFile("Sprites\\avatarP0.png");

	sol.LoadFromFile("Sprites\\surfaces\\sol.png");
	bloc.LoadFromFile("Sprites\\surfaces\\bloc.png");
	caisse.LoadFromFile("Sprites\\surfaces\\caisse.png");
	solSprite.SetImage(sol);
	blocSprite.SetImage(bloc);
	caisseSprite.SetImage(caisse);


	backgroundSprite.SetImage(background);
	logoSprite.SetImage(logo);
	avatarP1Sprite.SetImage(avatarP1);
	avatarP2Sprite.SetImage(avatarP2);
	avatarP3Sprite.SetImage(avatarP3);
	avatarP4Sprite.SetImage(avatarP4);
	logoSprite.SetPosition(15.f, 5.f);
	avatarP1Sprite.SetPosition(15.F, 115.f);
	avatarP2Sprite.SetPosition(15.F, 225.f);
	avatarP3Sprite.SetPosition(15.F, 335.f);
	avatarP4Sprite.SetPosition(15.F, 445.f);

	for(int i = 0; i < WIDTH_SQUARES_COUNT; i++) // fonction pour initialiser la map
	{
		for(int j = 0; j < HEIGHT_SQUARES_COUNT; j++)
		{
			if(i == 0 || i == HEIGHT_SQUARES_COUNT - 1) // Premiere et derniere colonne
			{
				carte[i][j] = SURFACE_BLOC;
			}
			else
			{
				if(j == 0 || j == HEIGHT_SQUARES_COUNT - 1) // Premiere et derniere ligne
				{
					carte[i][j] = SURFACE_BLOC;
				}
				else
				{
					if((i%2) == 1) // si la colonne est pair
					{
						carte[i][j] = SURFACE_SOL;
					}
					else
					{
						if((j%2) != 1) // Si la ligne est impair
						{
							carte[i][j] = SURFACE_BLOC;
						}
						else
						{
							carte[i][j] = SURFACE_SOL;
						}
					}
				}
			}
		}
	}
	carte[5][3] = SURFACE_CAISSE; //test
	carte[6][3] = SURFACE_CAISSE; //test
	dropBonus(); //test

	for(int i = 0; i < cfg.cfgPlayerCount; i++)
	{
		bomberman[i] = Bomberman(i+1); //on initialise le bomberman en fonction du joueur	
	}

}

int ScreenGame::Update(sf::RenderWindow &App, const sf::Input& Input)
{



	while (App.GetEvent(Event))
	{
		if (Event.Type == sf::Event::Closed)
		{
			return (SCREEN_EXIT);
		}

	}

	//Clavier

	if(Input.IsKeyDown(sf::Key::F))
	{
		tryToMove(bomberman[0], LEFT);
	}
	if(Input.IsKeyDown(sf::Key::H))
	{
		tryToMove(bomberman[0], RIGHT);
	}
	if(Input.IsKeyDown(sf::Key::T))
	{
		tryToMove(bomberman[0], UP);
	}
	if(Input.IsKeyDown(sf::Key::G))
	{
		tryToMove(bomberman[0], DOWN);
	}
	if(Input.IsKeyDown(sf::Key::V))
	{
		bomberman[0].dropBomb();
	}

	for(int i = 0; i < cfg.cfgPlayerCount; i++)
	{
		bomberman[i].update(elapsedTime);
		if(bomberman[i].moving)//on test si le bomberman est sur une case avec un bonus
		{
			checkForBonus(bomberman[i]);
		}
		for(int j = 0; j < bomberman[i].vExplosion.size(); j++) // update des explosions
		{
			bomberman[i].vExplosion.at(j).update(carte);
		}
	}

	return -2; // on ne voudra pas changer d'écran
}


void ScreenGame::tryToMove(Bomberman &bomberman, int direction)
{
	bomberman.spriteRect.Top = direction * 38;
	bomberman.spriteRect.Left = 0;
	bomberman.spriteRect.Right = 38;
	bomberman.spriteRect.Bottom = bomberman.spriteRect.Top + 38; // on place directement le bomberman face a la direction demandé
	switch (direction)
	{
	case UP:
		if(carte[bomberman.colonne][bomberman.row-1] == SURFACE_SOL)
		{
			bomberman.move(UP);	
		}
		break;
	case RIGHT:
		if(carte[bomberman.colonne+1][bomberman.row] == SURFACE_SOL)
		{
			bomberman.move(RIGHT);	
		}
		break;
	case DOWN:
		if(carte[bomberman.colonne][bomberman.row+1] == SURFACE_SOL)
		{
			bomberman.move(DOWN);	
		}
		break;
	case LEFT:
		if(carte[bomberman.colonne-1][bomberman.row] == SURFACE_SOL)
		{
			bomberman.move(LEFT);	
		}
		break;
	}

}

void ScreenGame::dropBonus()//temporaire
{
	Bonus bonus(BONUS_SPEEDUP);
	bonus.setPosition(4,1);
	vbonus.push_back(bonus);
	Bonus bonus2(BONUS_SPEEDDOWN);
	bonus2.setPosition(11, 1);
	vbonus.push_back(bonus2);
}

void ScreenGame::checkForBonus(Bomberman &bomberman)
{
	for(int i = 0; i < vbonus.size(); i++) // boucle de tous les bonus
	{
		sf::Sprite sp1;
		sp1.SetImage(bomberman.image);
		sp1.SetPosition(bomberman.position.x, bomberman.position.y);
		sp1.SetSubRect(bomberman.spriteRect);
		sf::Sprite sp2;
		sp2.SetImage(vbonus.at(i).image);
		sp2.SetPosition(vbonus.at(i).position.x, vbonus.at(i).position.y);
		if(intersections.intersectPixel(sp1, sp2, 1))
		{
		/*if(vbonus.at(i).colonne == bomberman.colonne && vbonus.at(i).row == bomberman.row)
		{*/

			vbonus.at(i).applyBonus(bomberman);
			vbonus.erase(vbonus.begin() + i);
		}

	}
}


void ScreenGame::Draw(sf::RenderWindow &App)
{
	App.Clear();

	App.Draw(backgroundSprite); //dessiner la partie de gauche
	App.Draw(logoSprite);
	App.Draw(avatarP1Sprite);
	App.Draw(avatarP2Sprite);
	App.Draw(avatarP3Sprite);
	App.Draw(avatarP4Sprite);
	position.x = POSITION_X;
	position.y = POSITION_Y;

	for(int i = 0; i < WIDTH_SQUARES_COUNT; i++) // dessiner la carte
	{
		position.x += i * SQUARE_SIZE;
		for(int j = 0; j < HEIGHT_SQUARES_COUNT; j++)
		{
			position.y += j * SQUARE_SIZE;
			switch(carte[i][j])
			{
			case SURFACE_SOL:
				solSprite.SetPosition(position.x, position.y);
				App.Draw(solSprite);
				break;
			case SURFACE_BLOC:
				blocSprite.SetPosition(position.x, position.y);
				App.Draw(blocSprite);
				break;
			case SURFACE_CAISSE:
				caisseSprite.SetPosition(position.x, position.y);
				App.Draw(caisseSprite);
				break;
			}

			position.y = POSITION_Y;
		}
		position.x = POSITION_X;
	}

	for(int i = 0; i < vbonus.size(); i++) //dessiner les bonus existant dans le vector
	{
		sf::Sprite spriteTemp;
		spriteTemp.SetImage(vbonus.at(i).image);
		int px = vbonus.at(i).position.x;
		int py = vbonus.at(i).position.y;
		spriteTemp.SetPosition(px, py);
		App.Draw(spriteTemp);
	}

	for(int i = 0; i < cfg.cfgPlayerCount; i++) //dessiner les bomberman
	{
		for(int j = 0; j < bomberman[i].vBomb.size(); j++) //dessiner les bombes du bomberman
		{
			sf::Sprite spriteBomb;
			spriteBomb.SetImage(bomberman[i].vBomb.at(j).image);
			spriteBomb.SetPosition(bomberman[i].vBomb.at(j).position.x, bomberman[i].vBomb.at(j).position.y);
			spriteBomb.SetSubRect(bomberman[i].vBomb.at(j).spriteRect);
			App.Draw(spriteBomb);
			
		}
		for(int k = 0; k < bomberman[i].vExplosion.size(); k++) // explorer les explosions des bombes du bomberman
		{
			for(int h = 0; h < bomberman[i].vExplosion.at(k).vParticule.size(); h++)// dessiner chacunes des particules correspondantes aux explosions
			{
				sf::Sprite spriteParticule;
				spriteParticule.SetImage(bomberman[i].vExplosion.at(k).vParticule.at(h).image);
				spriteParticule.SetPosition(bomberman[i].vExplosion.at(k).vParticule.at(h).position.x, bomberman[i].vExplosion.at(k).vParticule.at(h).position.y);
				spriteParticule.SetSubRect(bomberman[i].vExplosion.at(k).vParticule.at(h).spriteRect);
				App.Draw(spriteParticule);
			}
		}

		sf::Sprite spriteTemp;
		spriteTemp.SetImage(bomberman[i].image);
		spriteTemp.SetPosition(bomberman[i].position.x, bomberman[i].position.y);
		spriteTemp.SetSubRect(bomberman[i].spriteRect);
		App.Draw(spriteTemp);
		
	}

	

	App.Display();
}


