#include "ScreenMenu.h"

ScreenMenu::ScreenMenu(void)
{
	Init();
}

ScreenMenu::~ScreenMenu(void)
{
}

void ScreenMenu::Init()
{

	background.LoadFromFile("Sprites\\backgroundMenu.png");
	backgroundSprite.SetImage(background);

	//Set text
	menuPlay.SetText(STR_SCREEN_MENU_PLAY);
	menuCommandes.SetText(STR_SCREEN_MENU_COMMANDE);
	menuQuit.SetText(STR_SCREEN_MENU_QUIT);

	//Set size
	menuPlay.SetSize(37);
	menuCommandes.SetSize(35);
	menuQuit.SetSize(35);

	//Set font
	menuPlay.SetFont(myFont);
	menuCommandes.SetFont(myFont);
	menuQuit.SetFont(myFont);

	//Set color
	menuPlay.SetColor(sf::Color(0,255,0));
	menuCommandes.SetColor(sf::Color(255,255,255));
	menuQuit.SetColor(sf::Color(255,255,255));

	//Set position
	menuPlay.SetPosition(150.f, 150.f);
	menuCommandes.SetPosition(360.f, 280.f);
	menuQuit.SetPosition(340.f, 410.f);
}

int ScreenMenu::Run(sf::RenderWindow &App)
{
	//sf::Event Event;
	//sf::Image background;
	//background.LoadFromFile("Sprites\\backgroundMenu.png");
	//sf::Sprite backgroundSprite;
	//backgroundSprite.SetImage(background);

	//sf::String menuPlay("Commencer une nouvelle partie", myFont, 35);
	//menuPlay.SetPosition(150.f, 150.f);
	//sf::String menuCommandes("Aide", myFont, 35);
	//menuCommandes.SetPosition(360.f, 280.f);
	//sf::String menuQuit("Quitter", myFont, 35);
	//menuQuit.SetPosition(340.f, 410.f);

	//menuPlay.SetColor(sf::Color(0,255,0));
	//menuPlay.SetSize(37);

	////Draw (Initialisation

	//App.Clear();
	//App.Draw(backgroundSprite);
	//App.Draw(menuPlay);
	//App.Draw(menuCommandes);
	//App.Draw(menuQuit);
	//App.Display();

	int selected = 1;

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
			if ((Event.Type == sf::Event::KeyPressed) && ((Event.Key.Code == sf::Key::Down) || (Event.Key.Code == sf::Key::Right)))
			{
				if(selected != 3)
					selected++;
				else
					selected = 1;
			}
			if ((Event.Type == sf::Event::KeyPressed) && ((Event.Key.Code == sf::Key::Up) || (Event.Key.Code == sf::Key::Left)))
			{
				if(selected != 1)
					selected--;
				else
					selected = 3;
			}

			//Joystick
			if((Event.Type == sf::Event::JoyMoved) && (Event.JoyMove.JoystickId == 0))
			{
				if((Event.JoyMove.Axis == sf::Joy::Axis::AxisX) || (Event.JoyMove.Axis == sf::Joy::Axis::AxisY))
				{
					if(Event.JoyMove.Position == 100)
					{
						if(selected != 3)
							selected++;
						else
							selected = 1;
					}
					if(Event.JoyMove.Position == -100)
					{
						if(selected != 1)
							selected--;
						else
							selected = 3;
					}
				}
			}

			if((Event.Type == sf::Event::JoyButtonPressed) && (Event.JoyMove.JoystickId == 0))
			{
				switch(selected)
				{
				case 1:
					return(SCREEN_SETUP);
					break;
				case 2:
					return(SCREEN_COMMAND);
					break;
				case 3:
					return(SCREEN_EXIT);
					break;
				}
			}



			if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Return))
			{
				switch(selected)
				{
				case 1:
					return(SCREEN_SETUP);
					break;
				case 2:
					return(SCREEN_COMMAND);
					break;
				case 3:
					return(SCREEN_EXIT);
					break;
				}
			}

			//Update

			switch(selected)
			{
			case 1:
				menuPlay.SetColor(sf::Color(0,255,0));
				menuCommandes.SetColor(sf::Color(255,255,255));
				menuQuit.SetColor(sf::Color(255,255,255));
				menuPlay.SetSize(37);
				menuCommandes.SetSize(35);
				menuQuit.SetSize(35);
				break;
			case 2:
				menuPlay.SetColor(sf::Color(255,255,255));
				menuCommandes.SetColor(sf::Color(255,255,0));
				menuQuit.SetColor(sf::Color(255,255,255));
				menuPlay.SetSize(35);
				menuCommandes.SetSize(37);
				menuQuit.SetSize(35);
				break;
			case 3:
				menuPlay.SetColor(sf::Color(255,255,255));
				menuCommandes.SetColor(sf::Color(255,255,255));
				menuQuit.SetColor(sf::Color(255,0,0));
				menuPlay.SetSize(35);
				menuCommandes.SetSize(35);
				menuQuit.SetSize(37);
				break;
			}


		}

		Draw(App);
		App.SetFramerateLimit(FPS);

	}

}

void ScreenMenu::Draw(sf::RenderWindow &App)
{
	App.Clear();
	App.Draw(backgroundSprite);
	App.Draw(menuPlay);
	App.Draw(menuCommandes);
	App.Draw(menuQuit);
	App.Display();
}