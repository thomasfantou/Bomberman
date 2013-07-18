#pragma once
#include "constantes.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Intersections
{
public:
	Intersections(void);
	~Intersections(void);
	bool intersectPixel(const sf::Sprite& s1, const sf::Sprite& s2, const int AlphaMax = -1);
};
