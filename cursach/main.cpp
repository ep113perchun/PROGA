#include "class.h"

int main() {
    srand(time(NULL));
    
    Snake_cannibal snake1;
    Snake_hedonist snake2;

    Sprint start("start.png");
    Sprint next("next.png");
    Sprint finish("finish.png");

    Game snake;

    start.menu();
    snake.crowl(snake1);
    next.menu();
    snake.set_SIZE(1);
    snake.crowl(snake2);
    finish.menu();

	return 0;
}
