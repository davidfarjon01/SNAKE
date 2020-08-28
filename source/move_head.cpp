#include "snake.hpp"

void Snake::move_head_up(void)
{
    if (map[perso[0].y - 1][perso[0].x] == NONE) {
        map[perso[0].y][perso[0].x] = NONE;
        perso[0].y--;
    } else if (map[perso[0].y - 1][perso[0].x] == APPLE) {
        map[perso[0].y][perso[0].x] = NONE;
        perso[0].y--;
        apple--;
        eat = true;
    } else
        life = false;
}

void Snake::move_head_right(void)
{
    if (map[perso[0].y][perso[0].x + 1] == NONE) {
        map[perso[0].y][perso[0].x] = NONE;
        perso[0].x++;
    } else if (map[perso[0].y][perso[0].x + 1] == APPLE) {
        map[perso[0].y][perso[0].x] = NONE;
        perso[0].x++;
        apple--;
        eat = true;
    } else
        life = false;
}

void Snake::move_head_down(void)
{
    if (map[perso[0].y + 1][perso[0].x] == NONE) {
        map[perso[0].y][perso[0].x] = NONE;
        perso[0].y++;
    } else if (map[perso[0].y + 1][perso[0].x] == APPLE) {
        map[perso[0].y][perso[0].x] = NONE;
        perso[0].y++;
        apple--;
        eat = true;
    } else
        life = false;
}

void Snake::move_head_left(void)
{
    if (map[perso[0].y][perso[0].x - 1] == NONE) {
        map[perso[0].y][perso[0].x] = NONE;
        perso[0].x--;
    } else if (map[perso[0].y][perso[0].x - 1] == APPLE) {
        map[perso[0].y][perso[0].x] = NONE;
        perso[0].x--;
        apple--;
        eat = true;
    } else
        life = false;
}

void Snake::move_head(void)
{
    switch (way) {
        case UP:
            move_head_up();
            perso[0].way = UP;
            break;
        case RIGHT:
            move_head_right();
            perso[0].way = RIGHT;
            break;
        case DOWN:
            move_head_down();
            perso[0].way = DOWN;
            break;
        case LEFT:
            move_head_left();
            perso[0].way = LEFT;
            break;
        default:
            break;
    }
}