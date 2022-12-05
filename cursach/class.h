#pragma once
#include <SFML/Graphics.hpp>

class tPoint
{
public:
	int X;
	int Y;
	int Dx;
	int Dy;
	sf::CircleShape shape; 
	sf::CircleShape TRIANGLE_f;
public:
	tPoint(int X, int Y);
	void draw(sf::RenderWindow &window);
	void draw_head(sf::RenderWindow &window);
	void direct_movement(int Right, int Up);
	void assignment();
};