#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>

#define ERROR -1
#define START 5
#define CASE_WIDTH 20
#define CASE_HEIGHT 20
#define WIDTH_MAP 40
#define HEIGHT_MAP 40

enum Info {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    APPLE,
    HEAD,
    EXIT,
    NONE
};

typedef struct position_s {
    int x;
    int y;
    Info way;
} pos_t;

class Snake
{
    private:
        sf::RenderWindow window;
        sf::Music music;
        sf::SoundBuffer soundbuf;
        sf::Sound sound;
        sf::Font font;
        sf::Text text;
        sf::Event event;
        sf::Time time;
        sf::Clock clock;
        std::vector<std::vector<Info>> map;
        std::vector<pos_t> perso;
        Info way;
        bool life;
        bool pause;
        bool eat;
        int apple;
        int max_apple;
    public:
        Snake();
        ~Snake();
        void snake_init(void);
        void game(void);
        void controls(void);
        void pause_game(void);
        void refresh(void);
        void clear_map(void);
        void make_snake(void);
        void move_head_up(void);
        void move_head_right(void);
        void move_head_down(void);
        void move_head_left(void);
        void move_head(void);
        void move_body(int i);
        void add_body(void);
        void move(void);
        void add_apple(void);
        void direction(void);
        void score_screen(void);
        std::string display_score(void);
        void display(void);
};

pos_t new_case(int x, int y, Info way);
std::vector<Info> fill_line(void);
std::vector<Info> fill_line_exit(void);

#endif /* SNAKE_H */