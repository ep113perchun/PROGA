#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace std;
 
class tPoint
{
private:
	int dX;
	int dY;
protected:
	int X;
	int Y;
	int flag = 0;
	int RanX = rand() % 10;
	int RanY = rand() % 10;

	sf::CircleShape shape; 
public:
	tPoint(int x = 0, int y = 0);
	void draw(sf::RenderWindow &window);
	void direct_movement();
	void random_movement();
};

tPoint::tPoint(int x, int y)
{
	dX = 6;
	dY = 6;
	X = x;
	Y = y;
	shape.setRadius(10.f); 
	shape.setPointCount(20); 
	shape.setFillColor(sf::Color(rand()%256, rand()%256, rand()%256));
}

void tPoint::random_movement()
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

void tPoint::direct_movement()
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

void tPoint::draw(sf::RenderWindow &window) {
	shape.setPosition(X, Y);
	window.draw( shape);
}

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "LABA");
	window.setFramerateLimit(30);
	int x;
	int y;
	tPoint* Arr[100];
	for (int i = 0; i < 100; i++)
	{
		x = rand() % 1900;
		y = rand() % 1060;
		Arr[i] = new tPoint(x, y);
	}
	cout << endl;

	while (window.isOpen())
	{
		for (int i = 0; i < 100; i++)
		{
			Arr[i]->random_movement();
			//Arr[i]->direct_movement();
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
 
		window.clear();
		for (int i = 0; i < 100; i++)
		{
			Arr[i]->draw(window);
		}
		window.display();
	}
	return 0;
}
