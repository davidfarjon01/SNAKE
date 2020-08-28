#include "snake.hpp"

void Snake::snake_init(void)
{
    music.openFromFile("media/music.ogg");
    soundbuf.loadFromFile("media/eat.ogg");
    font.loadFromFile("media/font.ttf");
    text.setFont(font);
    sound.setBuffer(soundbuf);
    music.setLoop(true);
    way = NONE;
    pause = false;
    apple = 0;
    max_apple = 1;
    life = true;
    eat = false;
}

Snake::Snake() : window(sf::VideoMode(800, 800), "SNAKE")
{
    snake_init();
    map.push_back(fill_line_exit());
    for (int y = 1; y != HEIGHT_MAP - 1; y++)
        map.push_back(fill_line());
    map.push_back(fill_line_exit());
    for (int i = START; i != 0; i--)
        perso.push_back(new_case(((WIDTH_MAP / 2) - 1), ((HEIGHT_MAP / 2) - i), UP));
}

Snake::~Snake() {}

void Snake::game(void)
{
    music.play();
    while (window.isOpen()) {
        controls();
        if (pause == false && life == true) {
            time = clock.getElapsedTime();
            if (time.asSeconds() >= 0.15f) {
                refresh();
                clock.restart();
            }
        }
        if (life == false)
            score_screen();
        window.clear();
        display();
        window.display();
    }
}

int main(void)
{
    Snake snake;
    std::srand(std::time(nullptr));

    snake.game();
    return (0);
}