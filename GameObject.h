#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(void);
	~GameObject(void);
	sf::Vector2<int> position;
	sf::Rect<int> spriteRect;
	sf::Image image;
	int colonne;
	int row;
};
