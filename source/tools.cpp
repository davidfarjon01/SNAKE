#include "snake.hpp"

std::vector<Info> fill_line_exit(void)
{
    std::vector<Info> map;

    for (int x = 0; x != WIDTH_MAP; x++)
        map.push_back(EXIT);
    return (map);
}

std::vector<Info> fill_line(void)
{
    std::vector<Info> map;

    map.push_back(EXIT);
    for (int x = 1; x != WIDTH_MAP - 1; x++)
        map.push_back(NONE);
    map.push_back(EXIT);
    return (map);
}

pos_t new_case(int x, int y, Info way)
{
    pos_t perso;

    perso.x = x;
    perso.y = y;
    perso.way = way;
    return (perso);
}