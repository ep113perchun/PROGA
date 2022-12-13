#pragma once
#include <SFML/Graphics.hpp>


class ISnake {
public:
    void virtual cut() = 0;
    void virtual die() = 0;
};

class Snake_cannibal : public ISnake {
public:
    void cut() override;
    void die() override;
};

class Snake_hedonist : public ISnake {
public:
    void cut() override;
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

    static const int MAX_SIZE = 20;

    SNAKE* Arr[MAX_SIZE];

public:
    void crowl(ISnake & Snake); 
};