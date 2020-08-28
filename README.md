# SNAKE
Basic snake game

Write in C++ with SFML library.

For play the game you need to install the SFML library on your computer and make/Makefile for compile the game.

For compile:

$ make

For execute:

$ ./snake

# Gameplay

We can move the head of snake and all squares follow the direction of the next one.

If the head hit map border or himself, this ends the game and that display the score screen.

For increase the score the head need eat purple squares.

The number of purple squares increase in terms of the lenght of the snake.

Purple squares spawn appears randomly but never on the snake or in the border.

# Controls

For move use ZQSD or directional keys.

For pause press SPACE.

For exit the game press ESCAPE (esc).
