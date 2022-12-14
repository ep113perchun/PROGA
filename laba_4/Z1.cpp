#include <SFML/Graphics.hpp>	
#include <iostream>
#include <ctime>

using namespace std;

class FIGURE //class FIGURE.......................................................................................................................................................class FIGURE
{
public:
	void direct_movement();
protected:
	int dX;
	int dY;
	int X;
	int Y;
	int flag = 0;
	int RanX = rand() % 10;
	int RanY = rand() % 10;
	int rotation = 0;

	sf::CircleShape POINT_f; 
	sf::RectangleShape LINE_f;
	sf::CircleShape CIRCLE_f; 
	sf::CircleShape RECTANGL_f;
	sf::CircleShape TRIANGLE_f;
	sf::CircleShape ELLIPSE_f;
	sf::CircleShape RHOMBUS_f;
};

void FIGURE :: direct_movement()
{
	flag += 1;
	X += dX;
	if(X >= 1900 || X <= 0 || flag > RanX){
		dX = dX * -1;
		RanX = rand() % 100;
		flag = 0;
	}
	Y += dY;
	if(Y >= 1060 || Y <= 0 || flag > RanY){
		dY = dY * -1;
		RanY = rand() % 150;
		flag = 0;
	}
}

class POINT : public FIGURE	//class POINT..........................................................................................................................................class POINT
{
public:
	POINT(int x = 0, int y = 0);
	void draw(sf::RenderWindow &window);
};

POINT::POINT(int x, int y)
{
	dX = 6;
	dY = 6;
	X = x;
	Y = y;
	POINT_f.setRadius(4.f); 
	POINT_f.setPointCount(20); 
	POINT_f.setFillColor(sf::Color(255, 215, 0));
}

void POINT::draw(sf::RenderWindow &window) {
	POINT_f.setPosition(X, Y);
	window.draw( POINT_f);
}

class LINE : public FIGURE//class LINE..............................................................................................................................................class LINE
{
public:
	LINE(int x = 0, int y = 0);
	void draw(sf::RenderWindow &window);
	void Rotation();
};

LINE::LINE(int x, int y)
{
	dX = 4;
	dY = 7;
	X = x;
	Y = y;
	LINE_f.setSize(sf::Vector2f(30, 3));
	LINE_f.setFillColor(sf::Color(255, 0, 0));
}

void LINE::draw(sf::RenderWindow &window) {
	LINE_f.setPosition(X, Y);
	window.draw( LINE_f);
}

void LINE :: Rotation()
{
	LINE_f.setRotation(rotation);
	rotation += 5;
}

class CIRCLE : public FIGURE //class CIRCLE.......................................................................................................................................class CIRCLE
{
public:
	CIRCLE(int x = 0, int y = 0);
	void draw(sf::RenderWindow &window);
};

CIRCLE::CIRCLE(int x, int y)
{
	dX = 7;
	dY = 4;
	X = x;
	Y = y;
	CIRCLE_f.setRadius(16.f); 
	CIRCLE_f.setPointCount(20); 
	CIRCLE_f.setFillColor(sf::Color(251, 203, 72));
}

void CIRCLE::draw(sf::RenderWindow &window) {
	CIRCLE_f.setPosition(X, Y);
	window.draw( CIRCLE_f);
}

class RECTANGL : public FIGURE //class RECTANGL.................................................................................................................................class RECTANGL
{
public:
	RECTANGL(int x = 0, int y = 0);
	void draw(sf::RenderWindow &window);
	void Rotation();
};

RECTANGL::RECTANGL(int x, int y)
{
	dX = 6;
	dY = 5;
	X = x;
	Y = y;
	RECTANGL_f.setRadius(20.f); 
	RECTANGL_f.setPointCount(4); 
	RECTANGL_f.setFillColor(sf::Color(41, 93, 107));
}

void RECTANGL::draw(sf::RenderWindow &window) {
	RECTANGL_f.setPosition(X, Y);
	window.draw( RECTANGL_f);
}

void RECTANGL :: Rotation()
{
	RECTANGL_f.setRotation(rotation);
	rotation += 5;
}

class TRIANGLE : public FIGURE //class TRIANGLE.................................................................................................................................class TRIANGLE
{
public:
	TRIANGLE(int x = 0, int y = 0);
	void draw(sf::RenderWindow &window);
	void Rotation();
};

TRIANGLE::TRIANGLE(int x, int y)
{
	dX = 5;
	dY = 6;
	X = x;
	Y = y;
	TRIANGLE_f.setRadius(20.f); 
	TRIANGLE_f.setPointCount(3); 
	TRIANGLE_f.setFillColor(sf::Color(51, 73, 32));
}

void TRIANGLE::draw(sf::RenderWindow &window) {
	TRIANGLE_f.setPosition(X, Y);
	window.draw( TRIANGLE_f);
}

void TRIANGLE :: Rotation()
{
	TRIANGLE_f.setRotation(rotation);
	rotation += 5;
}

class ELLIPSE : public FIGURE //class ELLIPSE....................................................................................................................................class ELLIPSE
{
public:
	ELLIPSE(int x = 0, int y = 0);
	void draw(sf::RenderWindow &window);
	void Rotation();
};

ELLIPSE::ELLIPSE(int x, int y)
{
	dX = 5;
	dY = 6;
	X = x;
	Y = y;
	ELLIPSE_f.setRadius(20.f); 
	ELLIPSE_f.setPointCount(20);
	ELLIPSE_f.setScale(1.f, 0.5f);
	ELLIPSE_f.setFillColor(sf::Color(235, 134, 46));
}

void ELLIPSE::draw(sf::RenderWindow &window) {
	ELLIPSE_f.setPosition(X, Y);
	window.draw( ELLIPSE_f);
}

void ELLIPSE :: Rotation()
{
	ELLIPSE_f.setRotation(rotation);
	rotation += 5;
}

class RHOMBUS : public FIGURE //class RHOMBUS....................................................................................................................................class RHOMBUS
{
public:
	RHOMBUS(int x = 0, int y = 0);
	void draw(sf::RenderWindow &window);
	void Rotation();
};

RHOMBUS::RHOMBUS(int x, int y)
{
	dX = 4;
	dY = 7;
	X = x;
	Y = y;
	RHOMBUS_f.setRadius(20.f); 
	RHOMBUS_f.setPointCount(4);
	RHOMBUS_f.setScale(1.f, 0.5f);
	RHOMBUS_f.setFillColor(sf::Color(232, 51, 247));
}

void RHOMBUS::draw(sf::RenderWindow &window) {
	RHOMBUS_f.setPosition(X, Y);
	window.draw( RHOMBUS_f);
}

void RHOMBUS :: Rotation()
{
	RHOMBUS_f.setRotation(rotation);
	rotation += 5;
}

int main() //MAIN.........................................................................................................................................................................MAIN
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "LABA");
	window.setFramerateLimit(30);

	POINT** POINT_ARR = new POINT*[15];
	LINE** LINE_ARR = new LINE*[15];
	CIRCLE** CIRCLE_ARR = new CIRCLE*[15];
	RECTANGL** RECTANGL_ARR = new RECTANGL*[15];
	TRIANGLE** TRIANGLE_ARR = new TRIANGLE*[15];
	ELLIPSE** ELLIPSE_ARR = new ELLIPSE*[15];
	RHOMBUS** RHOMBUS_ARR = new RHOMBUS*[15];

	for (int i = 0; i < 15; i++)
	{
		POINT_ARR[i] = new POINT(rand() % 1900, rand() % 1060);
		LINE_ARR[i] = new LINE(rand() % 1900, rand() % 1060);
		CIRCLE_ARR[i] = new CIRCLE(rand() % 1900, rand() % 1060);
		RECTANGL_ARR[i] = new RECTANGL(rand() % 1900, rand() % 1060);
		TRIANGLE_ARR[i] = new TRIANGLE(rand() % 1900, rand() % 1060);
		ELLIPSE_ARR[i] = new ELLIPSE(rand() % 1900, rand() % 1060);
		RHOMBUS_ARR[i] = new RHOMBUS(rand() % 1900, rand() % 1060);
	}
	cout << endl;

	while (window.isOpen())
	{
		for (int i = 0; i < 15; i++)
		{
			POINT_ARR[i]->direct_movement();

			LINE_ARR[i]->direct_movement();
	    	LINE_ARR[i]->Rotation();

			CIRCLE_ARR[i]->direct_movement();

			RECTANGL_ARR[i]->direct_movement();
	    	RECTANGL_ARR[i]->Rotation();

			TRIANGLE_ARR[i]->direct_movement();
	    	TRIANGLE_ARR[i]->Rotation();

			ELLIPSE_ARR[i]->direct_movement();
	    	ELLIPSE_ARR[i]->Rotation();

			RHOMBUS_ARR[i]->direct_movement();
	    	RHOMBUS_ARR[i]->Rotation();
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
 
		window.clear();
		for (int i = 0; i < 15; i++)
		{
			POINT_ARR[i]->draw(window);
			LINE_ARR[i]->draw(window);
			CIRCLE_ARR[i]->draw(window);
			RECTANGL_ARR[i]->draw(window);
			TRIANGLE_ARR[i]->draw(window);
			ELLIPSE_ARR[i]->draw(window);
			RHOMBUS_ARR[i]->draw(window);
		}
		window.display();
	}
	return 0;
}