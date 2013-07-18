#ifndef constantes.h

#define WINDOW_WIDTH			800 // Largeur de la fenetre en pixel
#define WINDOW_HEIGHT			600 // Hauteut de la fenetre en pixel
#define BYTE_PER_PIXEL			32 // Nombre d'octets par pixel
#define WINDOW_TITLE			"Bomberman"
#define SQUARE_SIZE				38 // Taille d'une case en pixel
#define WIDTH_SQUARES_COUNT		15 // Nombre de cases en largeur
#define HEIGHT_SQUARES_COUNT	15 // Nombre de cases en hauteur
#define GAME_AREA_WIDTH			SQUARE_SIZE * WIDTH_SQUARES_COUNT //espace r�serv� au plateau de jeu dans la fen�tre
#define GAME_AREA_HEIGHT		SQUARE_SIZE * HEIGHT_SQUARES_COUNT //espace r�serv� au plateau de jeu dans la fen�tre
#define BORDER_SIZE				(WINDOW_HEIGHT - GAME_AREA_WIDTH) / 2 //La bordur qui s�pare le cadre du plateau, ici = 15
#define POSITION_X				WINDOW_WIDTH - (BORDER_SIZE + GAME_AREA_WIDTH) //On d�finit la position du plateau de jeu, dans la configuration actuel, on a 215
#define POSITION_Y				WINDOW_HEIGHT - (BORDER_SIZE + GAME_AREA_HEIGHT) //on a 15
#define FPS						60.f

//STRINGS

#define STR_SCREEN_MENU_PLAY "Commencer une nouvelle partie"
#define STR_SCREEN_MENU_COMMANDE "Aide"
#define STR_SCREEN_MENU_QUIT "Quitter"

#define STR_SCREEN_COMMANDE_TITLE "Aide"
#define STR_SCREEN_COMMANDE_SUBTITLE "R�gle du jeu"
#define STR_SCREEN_COMMANDE_INFO "Bomberman est un jeu de strat�gie arcade se d�roulant sur la plan�te \n \"Bomber\" dans lequel des joueurs, r�els ou pilot�s par l�ordinateur,\n s�affrontent sur un plateau de jeu lors de tours de jeu en posant\n des bombes leur permettant de se frayer un chemin sur le plateau\n et de faire exploser les autres joueurs.\n\n Le gagnant d�un tour de jeu est le dernier joueur en vie sur le plateau.\n Une partie est d�finie par un ensemble de tours de jeu gagnant qu\�un\n joueur doit remporter pour �tre d�clar� vainqueur de cette\n derni�re."
#define STR_SCREEN_COMMANDE_INFO2 "D�placer le Bomberman.\n\n\n Poser une bombe."
#define STR_SCREEN_COMMANDE_INDEX 
#define STR_SCREEN_COMMANDE_RETURN "Retour"
#define STR_SCREEN_COMMANDE_CLAVIER "Commandes clavier Joueur "
#define STR_SCREEN_COMMANDE_JOYSTICK "Commandes du Joystick"

#define STR_SCREEN_SETUP_TITLE "R�glage"
#define STR_SCREEN_SETUP_RETOUR	"Retour"
#define STR_SCREEN_SETUP_JOUER "Jouer"
#define STR_SCREEN_SETUP_MSG1 "Nombre de joueur : "
#define STR_SCREEN_SETUP_MSG2 "Nombre de round gagnant : "


#endif