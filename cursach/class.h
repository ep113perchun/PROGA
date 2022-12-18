#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class ISnake {
public:
    void virtual edge_of_screen() = 0;
    void virtual die() = 0;
};

class Snake_cannibal : public ISnake {
public:
    void edge_of_screen() override;
    void die() override;
};

class Snake_hedonist : public ISnake {
public:
    void edge_of_screen() override;
    void die() override;
};

class SNAKE : public Snake_cannibal, public Snake_hedonist{
public:
	int X;
	int Y;
	int Dx;
	int Dy;
	sf::CircleShape shape; 
	sf::CircleShape TRIANGLE_f;
public:
	SNAKE(int X, int Y);
	void draw(sf::RenderWindow &window);
	void draw_head(sf::RenderWindow &window);
	void direct_movement(int Right, int Up);
	void assignment();
};

class Game {
private:
    void creation_object();
    void draw_object(sf::RenderWindow &window);
    void rotate_object();

    int coordinate_X = 20;
    int coordinate_Y = 0;

    static const int VERTICAL_SCREEN = 1080;
    static const int HORIZONTALLY_SCREEN = 1920;
    static const int DELAY = 10;
    static const int MAX_SIZE = 200;
    int SIZE = 1;


    SNAKE apple = SNAKE(20 * (rand()%95), 20 * (rand()%53));
    SNAKE* Arr[MAX_SIZE];

public:
    void crowl(ISnake & Snake); 
    void set_SIZE(int size);
};

class Sprint {
private:
    sf::Image heroimage;
    sf::Texture herotexture;
    sf::Sprite herosprite;
public:
    Sprint(std::string Screensaver);
    void menu();
};