#include "snake.hpp"

void Snake::move_body(int i)
{
    if (perso[i].way == UP)
        perso[i].y--;
    if (perso[i].way == RIGHT)
        perso[i].x++;
    if (perso[i].way == DOWN)
        perso[i].y++;
    if (perso[i].way == LEFT)
        perso[i].x--;
}

void Snake::add_body(void)
{
    switch (perso.back().way) {
        case UP:
            perso.push_back(new_case(perso.back().x, perso.back().y + 1, UP));
            break;
        case RIGHT:
            perso.push_back(new_case(perso.back().x - 1, perso.back().y, RIGHT));
            break;
        case DOWN:
            perso.push_back(new_case(perso.back().x, perso.back().y - 1, DOWN));
            break;
        case LEFT:
            perso.push_back(new_case(perso.back().x + 1, perso.back().y, LEFT));
            break;
        default:
            break;
    }
    eat = false;
    sound.play();
}

void Snake::move(void)
{
    move_head();
    if (life == true)
        for (int i = 1; i != (int)perso.size(); i++)
            move_body(i);
    if (eat == true)
        add_body();
    for (int i = 1; i != (int)perso.size(); i++) {
        if (perso[i].y - 1 == perso[i - 1].y)
            perso[i].way = UP;
        if (perso[i].x + 1 == perso[i - 1].x)
            perso[i].way = RIGHT;
        if (perso[i].y + 1 == perso[i - 1].y)
            perso[i].way = DOWN;
        if (perso[i].x - 1 == perso[i - 1].x)
            perso[i].way = LEFT;
    }
}