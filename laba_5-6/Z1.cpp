#include <SFML/Graphics.hpp>	
#include <iostream>
#include <ctime>

using namespace std;

class FIGURE //class FIGURE.......................................................................................................................................................class FIGURE
{
public:
	void direct_movement();
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual void Rotation();
    FIGURE();
    FIGURE(int X, int Y, int DX, int DY);
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

FIGURE::FIGURE(): X(0), Y(0), dX(rand() % 20 - 10), dY(rand() % 20 - 10) {
    cout << "constructor FIGURE" << endl;
}

FIGURE::FIGURE(int X, int Y, int DX, int DY) {
    this -> dX = DX;
	this -> dY = DY;
    this -> X = X;
    this -> Y = Y;
}

void FIGURE :: Rotation(){
    cout << " " << endl;
}

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
	void draw(sf::RenderWindow &window) override;
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
	void draw(sf::RenderWindow &window) override;
	void Rotation() override;
};

LINE::LINE(int x, int y)
{
	dX = 5;
	dY = 0;
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
	void draw(sf::RenderWindow &window) override;
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
	void draw(sf::RenderWindow &window) override;
	void Rotation() override;
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
	void draw(sf::RenderWindow &window)override;
	void Rotation() override;
};

TRIANGLE::TRIANGLE(int x, int y)
{
	dX = 0;
	dY = 7;
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
	rotation += 0;
}

class ELLIPSE : public FIGURE //class ELLIPSE....................................................................................................................................class ELLIPSE
{
public:
	ELLIPSE(int x = 0, int y = 0);
	void draw(sf::RenderWindow &window) override;
	void Rotation()override;
};

ELLIPSE::ELLIPSE(int x, int y)
{
	dX = 0;
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
	void draw(sf::RenderWindow &window) override;
	void Rotation()override;
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


	FIGURE** FIGURE_ARR = new FIGURE*[105];

	for (int i = 0; i < 105; i+=7)
	{
		FIGURE_ARR[i+0] = new POINT(rand() % 1900, rand() % 1060);
		FIGURE_ARR[i+1] = new LINE(rand() % 1900, rand() % 1060);
		FIGURE_ARR[i+2] = new CIRCLE(rand() % 1900, rand() % 1060);
		FIGURE_ARR[i+3] = new RECTANGL(rand() % 1900, rand() % 1060);
		FIGURE_ARR[i+4] = new TRIANGLE(rand() % 1900, rand() % 1060);
		FIGURE_ARR[i+5] = new ELLIPSE(rand() % 1900, rand() % 1060);
		FIGURE_ARR[i+6] = new RHOMBUS(rand() % 1900, rand() % 1060);
	}
	cout << endl;

	while (window.isOpen())
	{
		for (int i = 0; i < 105; i++)
		{
			FIGURE_ARR[i]->direct_movement();
	    	FIGURE_ARR[i]->Rotation();
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
 
		window.clear();
		for (int i = 0; i < 105; i++)
		{
			FIGURE_ARR[i]->draw(window);
		}
		window.display();
	}
	return 0;
}