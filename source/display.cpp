#include "snake.hpp"

void Snake::display(void)
{
    for (int y = 0; y != HEIGHT_MAP; y++) {
        for (int x = 0; x != WIDTH_MAP; x++) {
            sf::RectangleShape rectangle(sf::Vector2f(CASE_WIDTH, CASE_HEIGHT));
            rectangle.setPosition(sf::Vector2f(CASE_WIDTH * x, CASE_HEIGHT * y));
            if (map[y][x] == APPLE)
                rectangle.setFillColor(sf::Color::Magenta);
            else if (map[y][x] == NONE)
                rectangle.setFillColor(sf::Color::Black);
            else if (map[y][x] == EXIT)
                rectangle.setFillColor(sf::Color::Red);
            else if (map[y][x] == HEAD)
                rectangle.setFillColor(sf::Color::Blue);
            else
                rectangle.setFillColor(sf::Color::Green);
            window.draw(rectangle);
        }
    }
    if (life == false)
        window.draw(text);
}

std::string Snake::display_score(void)
{
    std::string str("Good Game !\n\nScore: ");

    str.append(std::to_string((int)perso.size() - START));
    return (str);
}

void Snake::score_screen(void)
{
    std::string msg;

    time = clock.getElapsedTime();
    for (int x = 0; x != WIDTH_MAP; x++)
            map[0][x] = EXIT;
    for (int y = 1; y != HEIGHT_MAP - 1; y++) {
        map[y][0] = EXIT;
        for (int x = 1; x != WIDTH_MAP - 1; x++)
            map[y][x] = NONE;
        map[y][WIDTH_MAP - 1] = EXIT;
    }
    for (int x = 1; x != WIDTH_MAP; x++)
        map[WIDTH_MAP - 1][x] = EXIT;
    text.setString(display_score());
    text.setPosition(sf::Vector2f(50, 50));
    if (time.asSeconds() >= 5.0f)
        window.close();
}