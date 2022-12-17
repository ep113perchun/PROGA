#include "class.h"
#include <iostream>
#include <ctime>

void Snake_cannibal::cut(){
    std :: cout << "Snake_cannibal cut" << std :: endl;
}

void Snake_cannibal::die(){
    std :: cout << "Snake_cannibal die" << std :: endl;
}

///////////////////////

void Snake_hedonist::cut(){
	std :: cout << "Snake_hedonist cut" << std :: endl;
}

void Snake_hedonist::die(){
	std :: cout << "Snake_hedonist die" << std :: endl;
}

///////////////////////

SNAKE::SNAKE(int X, int Y)
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

void SNAKE::direct_movement(int Right, int Up)
{
	X += Right;				
	Y += Up;			
}

void SNAKE::assignment()
{
	Dx = X;
	Dy = Y;
}

void SNAKE::draw(sf::RenderWindow &window) {
	shape.setPosition(X, Y);
	window.draw(shape);
}

void SNAKE::draw_head(sf::RenderWindow &window) {
	TRIANGLE_f.setPosition(X, Y);
	window.draw(TRIANGLE_f);
}

///////////////////////

void Game::crowl(ISnake & Snake) {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "LABA");
    window.setFramerateLimit(20);

    creation_object();

    while (window.isOpen())
    {
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Arr[0]->assignment();
        Arr[0]->direct_movement(coordinate_X, coordinate_Y);
            
        rotate_object();

        if(Arr[0]->X == apple.X && Arr[0]->Y == apple.Y){
            apple.X = 20 * (rand()%95);
            apple.Y = 20 * (rand()%53);
            SIZE++;
        }

            
        window.clear();
        Arr[0]->draw_head(window);
        draw_object(window);
        window.display();
    }
}

void Game::creation_object() {
    for (int i = 0; i < MAX_SIZE; i++)
    {
        Arr[i] = new SNAKE(500 + (20 * i), 500);
    }
}
void Game::draw_object(sf::RenderWindow &window) {
    apple.draw(window);
    for (int i = 1; i < SIZE; i++)
    {
        Arr[i]->assignment();
        Arr[i]->X = Arr[i-1]->Dx;
        Arr[i]->Y = Arr[i-1]->Dy;
        Arr[i]->draw(window);
       // apple.draw(window);
    }
}
void Game::rotate_object() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){coordinate_X = -20; coordinate_Y = 0;} 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){coordinate_X = 20; coordinate_Y = 0;} 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){coordinate_X = 0; coordinate_Y = -20;} 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){coordinate_X = 0; coordinate_Y = 20;}
}

///////////////////////