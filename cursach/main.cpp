#include "class.h"

int main() {
    srand(time(NULL));
    
    Snake_cannibal snake1;
    Snake_hedonist snake2;

    Game snake;
    snake.crowl(snake1);
    snake.crowl(snake2);
	return 0;
}
