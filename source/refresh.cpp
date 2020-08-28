#include "snake.hpp"

void Snake::clear_map(void)
{
    for (int x = 0; x != WIDTH_MAP; x++)
            map[0][x] = EXIT;
    for (int y = 1; y != HEIGHT_MAP - 1; y++) {
        map[y][0] = EXIT;
        for (int x = 1; x != WIDTH_MAP - 1; x++) {
            if (map[y][x] != APPLE)
                map[y][x] = NONE;
            else
                map[y][x] = APPLE;
        }
        map[y][WIDTH_MAP - 1] = EXIT;
    }
    for (int x = 1; x != WIDTH_MAP; x++)
        map[WIDTH_MAP - 1][x] = EXIT;
}

void Snake::make_snake(void)
{
    map[perso[0].y][perso[0].x] = HEAD;
    for (int i = 1; i != (int)perso.size(); i++)
        map[perso[i].y][perso[i].x] = perso[i].way;
}

void Snake::add_apple(void)
{
    int x = 0;
    int y = 0;

    while (1) {
        x = rand() % WIDTH_MAP;
        y = rand() % HEIGHT_MAP;
        if (map[y][x] == NONE) {
            map[y][x] = APPLE;
            break;
        }
    }
    apple++;
}

void Snake::refresh(void)
{
    clear_map();
    make_snake();
    if (apple < max_apple)
        add_apple();
    max_apple = (perso.size() / 10) + 1;
    if (life == true && way != NONE)
        move();
    clear_map();
    make_snake();
}