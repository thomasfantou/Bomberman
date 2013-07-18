#include "ScreenCommand.h"
#include <sstream>
#include <iostream>

ScreenCommand::ScreenCommand(void)
{
	Init();
}

ScreenCommand::~ScreenCommand(void)
{
}


void ScreenCommand::Init()
{
	totalPage = 6;
	currentPage = 1;
	page = 1;

	background.LoadFromFile("Sprites\\backgroundMenu.png");
	backgroundSprite.SetImage(background);
	touchesSprite.SetPosition(100.f, 230.f);

	//Set text
	commandTitle.SetText(STR_SCREEN_COMMANDE_TITLE);
	commandSubTitle.SetText(STR_SCREEN_COMMANDE_SUBTITLE);
	commandInfo.SetText(STR_SCREEN_COMMANDE_INFO);
	//commandIndex.SetText(STR_SCREEN_COMMANDE_INDEX);
	commandReturn.SetText(STR_SCREEN_COMMANDE_RETURN);

	//Set size
	commandTitle.SetSize(50);
	commandSubTitle.SetSize(35);
	commandInfo.SetSize(20);
	commandIndex.SetSize(40);
	commandReturn.SetSize(35);

	//Set font
	commandTitle.SetFont(myFont);
	commandSubTitle.SetFont(myFont);
	commandInfo.SetFont(myFont);
	commandIndex.SetFont(myFont2);
	commandReturn.SetFont(myFont);

	//Set color
	commandTitle.SetColor(sf::Color(255,255,0));
	commandSubTitle.SetColor(sf::Color(0,55,255));
	commandInfo.SetColor(sf::Color(255,255,255));
	commandIndex.SetColor(sf::Color(255,255,255));
	commandReturn.SetColor(sf::Color(255,0,0));

	//Set position
	commandTitle.SetPosition(100.f, 50.f);
	commandSubTitle.SetPosition(110.f, 150.f);
	commandInfo.SetPosition(80.f, 250.f);
	commandIndex.SetPosition(650.f, 160.f);
	commandReturn.SetPosition(600.f, 500.f);
}


int ScreenCommand::Run(sf::RenderWindow &App)
{
	//sf::Event Event;
	//sf::Image background;
	//background.LoadFromFile("Sprites\\backgroundMenu.png");
	//sf::Sprite backgroundSprite;
	//backgroundSprite.SetImage(background);
	//sf::Image background;
	//background.LoadFromFile("Sprites\\backgroundMenu.png");
	//sf::Sprite backgroundSprite;
	//backgroundSprite.SetImage(background);
	//sf::Image touches;
	//sf::Sprite touchesSprite;
	//touchesSprite.SetPosition(100.f, 230.f);

	//commandTitle.se("Aide", myFont, 50);
	//menuCommandes.SetPosition(100.f, 50.f);
	//menuCommandes.SetColor(sf::Color(255,255,0));
	//sf::String titre;
	//titre.SetFont(myFont);
	//titre.SetSize(35);
	//titre.SetPosition(110.f, 150.f);
	//titre.SetColor(sf::Color(0,55,255));
	//sf::String message1("Déplacer le Bomberman", myFont, 20);
	//message1.SetPosition(350.f, 260.f);
	//sf::String message2("Poser une bombe", myFont, 20);
	//message2.SetPosition(350.f, 320.f);
	//sf::String message3("Bomberman est un jeu de stratégie arcade se déroulant sur la planète \n \"Bomber\" dans lequel des joueurs, réels ou pilotés par l’ordinateur,\n s’affrontent sur un plateau de jeu lors de tours de jeu en posant\n des bombes leur permettant de se frayer un chemin sur le plateau\n et de faire exploser les autres joueurs.\n\n Le gagnant d’un tour de jeu est le dernier joueur en vie sur le plateau.\n Une partie est définie par un ensemble de tours de jeu gagnant qu\’un\n joueur doit remporter pour être déclaré vainqueur de cette\n dernière.", myFont, 20);
	//message3.SetPosition(80.f, 250.f);
	//sf::String retour("Retour", myFont, 35);
	//retour.SetPosition(600.f, 500.f);
	//retour.SetColor(sf::Color(255,0,0));


	////Draw (initialiser la page)

	//App.Clear();
	//App.Draw(backgroundSprite);
	//App.Draw(menuCommandes);
	//App.Draw(touchesSprite);
	//App.Draw(message3);
	//App.Draw(retour);
	//App.Display();

    bool running = true;

	while(running)
	{
		while (App.GetEvent(Event))
        {
			//Clavier
			if (Event.Type == sf::Event::Closed)
            {
                return (SCREEN_EXIT);
            }
			if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Return))
			{
				return (SCREEN_MENU);
			}

			if ((Event.Type == sf::Event::KeyPressed) && ((Event.Key.Code == sf::Key::Down) || (Event.Key.Code == sf::Key::Right)))
			{
				if(currentPage != totalPage)
					currentPage++;
			}
			if ((Event.Type == sf::Event::KeyPressed) && ((Event.Key.Code == sf::Key::Up) || (Event.Key.Code == sf::Key::Left)))
			{
				if(currentPage != 1)
					currentPage--;
			}

			//Joystick
			if((Event.Type == sf::Event::JoyButtonPressed) && (Event.JoyMove.JoystickId == 0))
			{
				return (SCREEN_MENU);
			}
			if((Event.Type == sf::Event::JoyMoved) && (Event.JoyMove.JoystickId == 0))
			{
				if((Event.JoyMove.Axis == sf::Joy::Axis::AxisX) || (Event.JoyMove.Axis == sf::Joy::Axis::AxisY))
				{
					if(Event.JoyMove.Position == 100)
					{
						if(currentPage != totalPage)
							currentPage++;
					}
					if(Event.JoyMove.Position == -100)
					{
						if(currentPage != 1)
							currentPage--;
					}
				}
			}

			//Update
			std::ostringstream oss; // On utilise oss pour convertir nos int en chaine de caractères
			std::string strPages = "";
			oss << currentPage << '\/' << totalPage;
			strPages = oss.str();

			commandIndex.SetText(strPages);

			

		}

		Draw(App);
		App.SetFramerateLimit(FPS);
	}

}


void ScreenCommand::Draw(sf::RenderWindow &App)
{
	

	App.Clear();
	App.Draw(backgroundSprite);
	App.Draw(commandTitle);

	std::string strSubTitle = STR_SCREEN_COMMANDE_SUBTITLE;
	std::ostringstream oss; // On utilise oss pour convertir nos int en chaine de caractères
	oss << strSubTitle << ' ' << (currentPage - 1);
	strSubTitle += " " + oss.str();

	if(currentPage == 1) // Page 1 : Explication du jeu
	{
		commandSubTitle.SetText(STR_SCREEN_COMMANDE_SUBTITLE);
		commandInfo.SetPosition(80.f, 250.f);
		commandInfo.SetText(STR_SCREEN_COMMANDE_INFO);

	}

	if(currentPage == 2) // Page 2 : Commandes du joueur 1
	{
		commandSubTitle.SetText(strSubTitle);
		commandInfo.SetPosition(350.f, 260.f);
		commandInfo.SetText(STR_SCREEN_COMMANDE_INFO2);
		touches.LoadFromFile("Sprites\\commandesP1.png");
		touchesSprite.SetImage(touches);
		App.Draw(touchesSprite);
	}

	if(currentPage == 3) // Page 3 : Commandes du joueur 2
	{
		commandSubTitle.SetText(strSubTitle);
		commandInfo.SetPosition(350.f, 260.f);
		commandInfo.SetText(STR_SCREEN_COMMANDE_INFO2);
		touches.LoadFromFile("Sprites\\commandesP2.png");
		touchesSprite.SetImage(touches);
		App.Draw(touchesSprite);
	}

	if(currentPage == 4) // Page 4 : Commandes du joueur 3
	{
		commandSubTitle.SetText(strSubTitle);
		commandInfo.SetPosition(350.f, 260.f);
		commandInfo.SetText(STR_SCREEN_COMMANDE_INFO2);
		touches.LoadFromFile("Sprites\\commandesP3.png");
		touchesSprite.SetImage(touches);
		App.Draw(touchesSprite);
	}

	if(currentPage == 5) // Page 5 : Commandes du joueur 4
	{
		commandSubTitle.SetText(strSubTitle);
		commandInfo.SetPosition(350.f, 260.f);
		commandInfo.SetText(STR_SCREEN_COMMANDE_INFO2);
		touches.LoadFromFile("Sprites\\commandesP4.png");
		touchesSprite.SetImage(touches);
		App.Draw(touchesSprite);
	}

	if(currentPage == 6) // Page 6 : Commandes au Joystick
	{
		commandSubTitle.SetText(STR_SCREEN_COMMANDE_JOYSTICK);
		commandInfo.SetPosition(350.f, 260.f);
		commandInfo.SetText(STR_SCREEN_COMMANDE_INFO2);
		touches.LoadFromFile("Sprites\\commandesJoystick.png");
		touchesSprite.SetImage(touches);
		App.Draw(touchesSprite);
	}
		
	App.Draw(commandInfo);
	App.Draw(commandSubTitle);
	App.Draw(commandTitle);
	App.Draw(commandReturn);
	App.Draw(commandIndex);
	App.Display();

}