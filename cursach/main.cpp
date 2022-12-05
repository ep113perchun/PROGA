#include <SFML/Graphics.hpp>
#include <iostream>
#include "class.h"
#include "queue.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "LABA");
	window.setFramerateLimit(20);
	int Right = 20;
	int Up = 0;
	int N = 20;
	tPoint* Arr[N];

	for (int i = 0; i < N; i++)
	{
		Arr[i] = new tPoint(500 + (20 * i), 500);
	}
	cout << endl;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Arr[0]->assignment();
		Arr[0]->direct_movement(Right, Up);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){Right = -20; Up = 0;} 
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){Right = 20; Up = 0;} 
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){Right = 0; Up = -20;} 
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){Right = 0; Up = 20;}

		
		window.clear();
		Arr[0]->draw_head(window);
		for (int i = 1; i < N; i++)
		{
			Arr[i]->assignment();
			Arr[i]->X = Arr[i-1]->Dx;
			Arr[i]->Y = Arr[i-1]->Dy;
			Arr[i]->draw(window);
		}
		window.display(); 
             
	}
	return 0;
}
