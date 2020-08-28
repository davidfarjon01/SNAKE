#include "snake.hpp"

void Snake::direction(void)
{
    if (way != DOWN && (event.key.code == sf::Keyboard::Up ||
        event.key.code == sf::Keyboard::Z))
        way = UP;
    if (way != LEFT && (event.key.code == sf::Keyboard::Right ||
        event.key.code == sf::Keyboard::D))
        way = RIGHT;
    if (way != UP && (event.key.code == sf::Keyboard::Down ||
        event.key.code == sf::Keyboard::S))
        way = DOWN;
    if (way != RIGHT && (event.key.code == sf::Keyboard::Left ||
        event.key.code == sf::Keyboard::Q))
        way = LEFT;
}

void Snake::pause_game(void)
{
    if (event.key.code == sf::Keyboard::Space &&
        pause == false)
        pause = true;
    else if (event.key.code == sf::Keyboard::Space &&
        pause == true)
        pause = false;
}

void Snake::controls(void)
{
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
            pause_game();
            if (pause == false)
                direction();
        }
    }
}