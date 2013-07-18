#include "ScreenSetup.h"
#include <sstream>

ScreenSetup::ScreenSetup(void)
{
	Init();
}

ScreenSetup::~ScreenSetup(void)
{
}

void ScreenSetup::Init()
{
	background.LoadFromFile("Sprites\\backgroundMenu.png");
	backgroundSprite.SetImage(background);

	playerCount = 1;
	roundCount = 1;
	selected = 1;

	//Set text
	setupTitle.SetText(STR_SCREEN_SETUP_TITLE);
	setupMsg1.SetText(STR_SCREEN_SETUP_MSG1);
	setupMsg2.SetText(STR_SCREEN_SETUP_MSG2);
	setupPlayer.SetText("1");
	setupRound.SetText("2");
	setupPlay.SetText(STR_SCREEN_SETUP_JOUER);
	setupReturn.SetText(STR_SCREEN_MENU_QUIT);

	//Set size
	setupTitle.SetSize(45);
	setupMsg1.SetSize(32);
	setupMsg2.SetSize(30);
	setupPlayer.SetSize(32);
	setupRound.SetSize(30);
	setupPlay.SetSize(35);
	setupReturn.SetSize(35);


	//Set font
	setupTitle.SetFont(myFont);
	setupMsg1.SetFont(myFont2);
	setupMsg2.SetFont(myFont2);
	setupPlayer.SetFont(myFont2);
	setupRound.SetFont(myFont2);
	setupPlay.SetFont(myFont);
	setupReturn.SetFont(myFont);

	//Set color
	setupTitle.SetColor(sf::Color(255,255,0));
	/*setupMsg1.;
	setupMsg2.;
	setupPlayer.;
	setupRound.;
	setupPlay.;
	setupReturn.;*/

	//Set position
	setupTitle.SetPosition(100.f, 50.f);
	setupMsg1.SetPosition(100.f, 220.f);
	setupMsg2.SetPosition(100.f, 370.f);
	setupPlayer.SetPosition(400.f, 220.f);
	setupRound.SetPosition(520.f, 370.f);
	setupPlay.SetPosition(650.f, 500.f);
	setupReturn.SetPosition(500.f, 500.f);
}

int ScreenSetup::Run(sf::RenderWindow &App)
{
	//playerCount = 1;
	//roundCount = 1;
	//int tabRoundCount[] = { 1, 3, 5, 7, 9, 12, 15 };
	//int cursorTabRoundCount = 0;
	//int selected = 1;

	//sf::Event Event;

	//sf::Image background;
	//background.LoadFromFile("Sprites\\backgroundMenu.png");
	//sf::Sprite backgroundSprite;
	//backgroundSprite.SetImage(background);

	//sf::Font myFont;
	//sf::Font myFont2;
	//myFont.LoadFromFile("Policies\\CROOBIE_.TTF");
	//myFont2.LoadFromFile("Policies\\hemi-head.ttf");

	//sf::String menuSetup("Réglage", myFont, 45);
	//menuSetup.SetPosition(100.f, 50.f);
	//menuSetup.SetColor(sf::Color(255,255,0));
	//sf::String retour("Retour", myFont, 35);
	//retour.SetPosition(500.f, 500.f);
	//sf::String jouer("Jouer", myFont, 35);
	//jouer.SetPosition(650.f, 500.f);
	//sf::String message1("Nombre de joueur : ", myFont2, 32);
	//message1.SetColor(sf::Color(0,255,0));
	//message1.SetPosition(100.f, 220.f);
	//sf::String message2("Nombre de round gagnant : ", myFont2, 30);
	//message2.SetPosition(100.f, 370.f);
	//sf::String strPlayerCount("1", myFont2, 32);
	//strPlayerCount.SetPosition(400.f, 220.f);
	//strPlayerCount.SetColor(sf::Color(0,255,0));
	//sf::String strRoundCount("1", myFont2, 30);
	//strRoundCount.SetPosition(520.f, 370.f);

	////Initialiser la page
	//App.Clear();
	//App.Draw(backgroundSprite);
	//App.Draw(menuSetup);
	//App.Draw(retour);
	//App.Draw(jouer);
	//App.Draw(message1);
	//App.Draw(message2);
	//App.Draw(strPlayerCount);
	//App.Draw(strRoundCount);
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
			if ((Event.Type == sf::Event::KeyPressed) && ((Event.Key.Code == sf::Key::Down)))
			{
				if(selected != 4)
					selected++;
				else
					selected = 1;
			}
			if ((Event.Type == sf::Event::KeyPressed) && ((Event.Key.Code == sf::Key::Up)))
			{
				if(selected != 1)
					selected--;
				else
					selected = 4;
			}
			if((Event.Type == sf::Event::KeyPressed) && ((Event.Key.Code == sf::Key::Right)))
			{
				switch(selected)
				{
				case 1:
					if(playerCount < 4)
						playerCount++;
					break;

				case 2:
					if(roundCount < 15)
						roundCount++;
					break;
				case 3:
					selected++;
					break;
				case 4:

					selected--;
					break;
				}
			}
			if((Event.Type == sf::Event::KeyPressed) && ((Event.Key.Code == sf::Key::Left)))
			{
				switch(selected)
				{
				case 1:
					if(playerCount > 1)
						playerCount--;
					break;
				case 2:
					if(roundCount > 1)
						roundCount--;
					break;
				case 3:
					selected++;
					break;
				case 4:
					selected--;
					break;
				}
			}
			if((Event.Type == sf::Event::KeyPressed) && ((Event.Key.Code == sf::Key::Return)))
			{
				if(selected == 3)
				{
					return (SCREEN_MENU);
				}
				if(selected == 4)
				{
					Config cfg;
					cfg.cfgPlayerCount = playerCount;
					cfg.cfgRoundCount = roundCount;
					return (SCREEN_GAME);
				}
			}

			//Joystick

			if((Event.Type == sf::Event::JoyMoved) && (Event.JoyMove.JoystickId == 0))
			{
				if((Event.JoyMove.Axis == sf::Joy::Axis::AxisY))
				{
					if(Event.JoyMove.Position == 100)
					{
						if(selected != 4)
							selected++;
						else
							selected = 1;
					}
					if(Event.JoyMove.Position == -100)
					{
						if(selected != 1)
							selected--;
						else
							selected = 4;
					}
				}
			}
			if((Event.Type == sf::Event::JoyMoved) && (Event.JoyMove.JoystickId == 0))
			{
				if((Event.JoyMove.Axis == sf::Joy::Axis::AxisX))
				{
					if(Event.JoyMove.Position == 100)
					{
						if(selected == 1)
						{
							if(playerCount < 4)
								playerCount++;
						}
						if(selected == 2)
						{
							if(roundCount < 15)
								roundCount++;
						}
					}
					if(Event.JoyMove.Position == -100)
					{
						if(selected == 1)
						{
							if(playerCount > 1)
								playerCount--;
						}
						if(selected == 2)
						{
							if(roundCount > 1)
								roundCount--;
							
						}
					}
				}
			}
			if((Event.Type == sf::Event::JoyButtonPressed) && (Event.JoyMove.JoystickId == 0))
			{
				if(selected == 3)
				{
					return (SCREEN_MENU);
				}
				if(selected == 4)
				{
					return (SCREEN_GAME);
				}
			}

			//Update

			switch(selected)
			{
			case 1:
				setupMsg1.SetColor(sf::Color(0,255,0));
				setupPlayer.SetColor(sf::Color(0,255,0));
				setupMsg1.SetSize(32);
				setupPlayer.SetSize(32);
				setupMsg2.SetColor(sf::Color(255,255,255));
				setupRound.SetColor(sf::Color(255,255,255));
				setupMsg2.SetSize(30);
				setupRound.SetSize(30);
				setupReturn.SetColor(sf::Color(255,255,255));
				setupPlay.SetColor(sf::Color(255,255,255));
				break;
			case 2:
				setupMsg1.SetColor(sf::Color(255,255,255));
				setupPlayer.SetColor(sf::Color(255,255,255));
				setupMsg1.SetSize(30);
				setupPlayer.SetSize(30);
				setupMsg2.SetColor(sf::Color(255,255,0));
				setupRound.SetColor(sf::Color(255,255,0));
				setupMsg2.SetSize(32);
				setupRound.SetSize(32);
				setupReturn.SetColor(sf::Color(255,255,255));
				setupPlay.SetColor(sf::Color(255,255,255));
				break;
			case 3:
				setupMsg1.SetColor(sf::Color(255,255,255));
				setupPlayer.SetColor(sf::Color(255,255,255));
				setupMsg1.SetSize(30);
				setupPlayer.SetSize(30);
				setupMsg2.SetColor(sf::Color(255,255,255));
				setupRound.SetColor(sf::Color(255,255,255));
				setupMsg2.SetSize(30);
				setupRound.SetSize(30);
				setupReturn.SetColor(sf::Color(255,0,0));
				setupPlay.SetColor(sf::Color(255,255,255));
				break;
			case 4:
				setupMsg1.SetColor(sf::Color(255,255,255));
				setupPlayer.SetColor(sf::Color(255,255,255));
				setupMsg1.SetSize(30);
				setupPlayer.SetSize(30);
				setupMsg2.SetColor(sf::Color(255,255,255));
				setupRound.SetColor(sf::Color(255,255,255));
				setupMsg2.SetSize(30);
				setupRound.SetSize(30);
				setupReturn.SetColor(sf::Color(255,255,255));
				setupPlay.SetColor(sf::Color(0,0,255));
				break;
			}

			

		}

		Draw(App);
		App.SetFramerateLimit(FPS);
	}
}

void ScreenSetup::Draw(sf::RenderWindow &App)
{
	std::ostringstream oss; // On utilise oss pour convertir nos int en chaine de caractères
	std::ostringstream oss2;
	oss << playerCount;
	oss2 << roundCount;
	setupPlayer.SetText(oss.str());
	setupRound.SetText(oss2.str());

	App.Clear();
	App.Draw(backgroundSprite);
	App.Draw(setupTitle);
	App.Draw(setupMsg1);
	App.Draw(setupMsg2);
	App.Draw(setupPlay);
	App.Draw(setupReturn);
	App.Draw(setupPlayer);
	App.Draw(setupRound);
	App.Display();
}