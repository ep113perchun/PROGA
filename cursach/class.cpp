#include "class.h"

tPoint::tPoint(int X, int Y)
{
	
	this->X = X;
	this->Y = Y;
	Dx = X;
	Dy = Y;
	shape.setRadius(10.f); 
	shape.setPointCount(20); 
	shape.setFillColor(sf::Color(240, 21, 40));
	TRIANGLE_f.setRadius(10.f); 
	TRIANGLE_f.setPointCount(20); 
	TRIANGLE_f.setFillColor(sf::Color(72, 105, 147));
}

void tPoint::direct_movement(int Right, int Up)
{
	X += Right;				
	Y += Up;			
}

void tPoint::assignment()
{
	Dx = X;
	Dy = Y;
}

void tPoint::draw(sf::RenderWindow &window) {
	shape.setPosition(X, Y);
	window.draw(shape);
}

void tPoint::draw_head(sf::RenderWindow &window) {
	TRIANGLE_f.setPosition(X, Y);
	window.draw(TRIANGLE_f);
}