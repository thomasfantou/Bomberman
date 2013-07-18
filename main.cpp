#include <SFML/Graphics.hpp>

#include <iostream>
#include "constantes.h"
#include "WindowManager.h"
#include "Screen.h"
#include "ScreenMenu.h"
#include "ScreenSetup.h"
#include "ScreenGame.h"
#include "ScreenCommand.h"

int main()
{
	//Applications variables
    std::vector<Screen*> screens;
    int screen = 0;
 
	sf::RenderWindow App(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BYTE_PER_PIXEL), WINDOW_TITLE);

    //Mouse cursor no more visible
    App.ShowMouseCursor(false);

    //Screens preparations
    ScreenMenu sm;
	ScreenSetup st;
	ScreenGame sg;
	ScreenCommand sc;
	screens.push_back(&sm);
	screens.push_back(&st);
	screens.push_back(&sg);
	screens.push_back(&sc);

	//Main loop
	while (screen >= 0)
	{
		screen = screens[screen]->Run(App);
	}
	
	App.Close();
    return EXIT_SUCCESS;

}

