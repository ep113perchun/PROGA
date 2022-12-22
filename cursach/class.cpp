#include "class.h"
#include <iostream>
#include <ctime>
#include <string>

void Snake_cannibal::edge_of_screen(int &X, int &Y, int &bo){
    if(X >= 1920){X=0;}
    else if(X < 0){X=1920;}
    if(Y >= 1080){Y=0;}
    else if(Y < 0){Y=1080;}
}

void Snake_cannibal::cut(int X, int Y, int x, int y, int &size, int i){
    if(X == x && Y == y && size != 1){size = i+1;}
}

///////////////////////

void Snake_hedonist::edge_of_screen(int &X, int &Y, int &bo){
	if(X >= 1920 || X < 0 || Y >= 1080 || Y < 0){bo = 0;}
}

void Snake_hedonist::cut(int X, int Y, int x, int y, int &size, int i){
	if(X == x && Y == y && size != 1){size = size;}
}

///////////////////////

SNAKE::SNAKE(int x, int y) : X(0), Y(0)
{
	
	X = x;
    Y = y;
	Dx = x;
	Dy = y;
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
    sf::RenderWindow window(sf::VideoMode(HORIZONTALLY_SCREEN, VERTICAL_SCREEN), "LABA");
    window.setFramerateLimit(DELAY);

    creation_object();

    int bo = 1;

    while (window.isOpen())
    {
        for (int i = 0; i < SIZE; i++)
        {
            Snake.edge_of_screen(Arr[i]->X, Arr[i]->Y, bo);
            Snake.cut(Arr[i+1]->X, Arr[i+1]->Y, Arr[0]->X,  Arr[0]->Y, SIZE, i);
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed  || bo==0)
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
    }
}

void Game::rotate_object() {
    if      (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){coordinate_X = -20; coordinate_Y = 0;} 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){coordinate_X = 20; coordinate_Y = 0;} 
    if      (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))  {coordinate_X = 0; coordinate_Y = -20;} 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){coordinate_X = 0; coordinate_Y = 20;}
}

void Game::set_SIZE(int size){
    SIZE = size;
}

Game::~Game(){
    for (int i = 0; i < MAX_SIZE; i++)
    {
        delete Arr[i];
    }
}

///////////////////////

Sprint::Sprint(std::string Screensaver) {
    heroimage.loadFromFile(Screensaver);
}

void Sprint::menu() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Lesson 3. kychka-pc.ru"); 
    
    herotexture.loadFromImage(heroimage);
    
    herosprite.setTexture(herotexture);
    herosprite.setPosition(0, 0);
    while (window.isOpen())	
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                window.close();
        }
    
        window.clear();
        window.draw(herosprite);
        window.display();
    }
}