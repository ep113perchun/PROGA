#include <SFML/Graphics.hpp>	
#include <iostream>
#include <ctime>

using namespace std;
 
class tPoint
{
public:
	tPoint(int x = 0, int y = 0);
	void direct_movement();
	sf::CircleShape POINT_f; 
	sf::CircleShape LINE_f;
	sf::CircleShape CIRCLE_f; 
	sf::CircleShape RECTANGL_f;
	sf::CircleShape TRIANGLE_f;
	sf::CircleShape ELLIPSE_f;
	sf::CircleShape RHOMBUS_f;
protected:
	int dX;
	int dY;
	int X;
	int Y;
};

// class POINT : public tPoint
// {
// public:
// 	sf::CircleShape POINT_f; 
// };

// class LINE : public tPoint
// {
// public:
// 	sf::CircleShape LINE_f;
// };

// class CIRCLE : public tPoint
// {
// public:
// 	sf::CircleShape CIRCLE_f; 
// };

// class RECTANGL : public tPoint
// {
// public:
// 	sf::CircleShape RECTANGL_f;
// };

// class TRIANGLE : public tPoint
// {
// public:
// 	sf::CircleShape TRIANGLE_f;
// };

// class ELLIPSE : public tPoint
// {
// public:
// 	sf::CircleShape ELLIPSE_f;
// };

// class RHOMBUS : public tPoint
// {
// public:
// 	sf::CircleShape RHOMBUS_f;
// };

void tPoint :: direct_movement()
{
	X += dX;
	if(X >= 1900 || X <= 0){
		dX = dX * -1;
	}
	Y += dY;
	if(Y >= 1060 || Y <= 0){
		dY = dY * -1;
	}
}
tPoint::tPoint(int x, int y, sf::CircleShape &figure)
{
	dX = 6;
	dY = 6;
	X = x;
	Y = y;
	figure.setRadius(10.f); 
	figure.setPointCount(20); 
	figure.setFillColor(sf::Color(rand()%256, rand()%256, rand()%256));
}

void tPoint :: draw(sf::RenderWindow &window, sf::CircleShape &figure) {
	figure.setPosition(X, Y);
	figure.setFillColor(sf::Color(100, 250, 50));
	window.draw(figure);
}

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "LABA");
	window.setFramerateLimit(30);

	tPoint* POINT[10];
	tPoint* LINE[10];
	tPoint* CIRCLE[10];
	tPoint* RECTANGL[10];
	tPoint* TRIANGLE[10];
	tPoint* ELLIPSE[10];
	tPoint* RHOMBUS[10];

	for (int i = 0; i < 10; i++)
	{
		POINT[i] = new tPoint(rand() % 1900, rand() % 1060, POINT_f);
		LINE[i] = new tPoint(rand() % 1900, rand() % 1060);
		CIRCLE[i] = new tPoint(rand() % 1900, rand() % 1060);
		RECTANGL[i] = new tPoint(rand() % 1900, rand() % 1060);
		TRIANGLE[i] = new tPoint(rand() % 1900, rand() % 1060);
		ELLIPSE[i] = new tPoint(rand() % 1900, rand() % 1060);
		RHOMBUS[i] = new tPoint(rand() % 1900, rand() % 1060);
	}
	cout << endl;

	while (window.isOpen())
	{
		for (int i = 0; i < 10; i++)
		{
			POINT[i]->direct_movement();
	    	POINT[i]->Rotation();

			LINE[i]->direct_movement();
	    	LINE[i]->Rotation();

			CIRCLE[i]->direct_movement();
	    	CIRCLE[i]->Rotation();

			RECTANGL[i]->direct_movement();
	    	RECTANGL[i]->Rotation();

			TRIANGLE[i]->direct_movement();
	    	TRIANGLE[i]->Rotation();

			ELLIPSE[i]->direct_movement();
	    	ELLIPSE[i]->Rotation();

			RHOMBUS[i]->direct_movement();
	    	RHOMBUS[i]->Rotation();
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
 
		window.clear();
		for (int i = 0; i < 10; i++)
		{
			POINT[i]->draw(window);
			LINE[i]->draw(window);
			CIRCLE[i]->draw(window);
			RECTANGL[i]->draw(window);
			TRIANGLE[i]->draw(window);
			ELLIPSE[i]->draw(window);
			RHOMBUS[i]->draw(window);
		}
		window.display();
	}
	return 0;
}