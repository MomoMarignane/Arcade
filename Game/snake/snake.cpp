/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** lib.c
*/

#include <stdio.h>
#include "snake.hpp"

void initSnake() __attribute__((constructor));
void closeSnake() __attribute__((destructor));
extern "C" arc::IGameModule *entryPoint();

void initSnake()
{
    // printf("[libSnake] Loading Snake library...\n");
}

void closeSnake()
{
    // printf("[libSnake] Snake closing.\n");
}

extern "C" arc::IGameModule *entryPoint()
{
    // printf("[libSnake] entry point !\n");
    return new snake();
}

void snake::init()
{
    _life = 3;
    _score = 0;
    for (int i = 0; i < 5; i += 1)
        _lifeMob.push_back(2);
    playerPos player;
    player.xPos = 0;
    printf("initied\nSNAKE\n__\n");
}

void snake::move(char dir)
{
    // mise à jour de la direction
    if ((dir == 'u' && direction != 'd') ||
        (dir == 'd' && direction != 'u') ||
        (dir == 'l' && direction != 'r') ||
        (dir == 'r' && direction != 'l')) {
        direction = dir;
    }
    // déplacement de la tête
    playerPos head = body[0];
    switch (direction) {
        case 'u':
            head.yPos--;
            break;
        case 'd':
            head.yPos++;
            break;
        case 'l':
            head.xPos--;
            break;
        case 'r':
            head.xPos++;
            break;
    }
        // ajout de la nouvelle tête
    body.insert(body.begin(), head);

        // suppression de la queue
    body.pop_back();
}

void snake::grow()
{
    playerPos tail = body.back();
    body.push_back(tail);
}

bool snake::ate(playerPos food) const
{
    return body[0].xPos == food.xPos && body[0].yPos == food.yPos;
}

bool snake::collision() const {
    const playerPos head = body[0];
    // vérification si le serpent a touché les murs
    if (head.xPos < 1 || head.xPos > WIDTH || head.xPos < 1 || head.yPos > HEIGHT || head.yPos < 1) {
        return true;
        }
    // vérification si le serpent a touché sa queue
    for (unsigned long int i = 1; i < body.size(); i++) {
        if (head.xPos == body[i].xPos && head.yPos == body[i].yPos) {
            return true;
            }
    // vérification si le serpent a touché sa queue
    for (unsigned long int i = 1; i < body.size(); i++) {
        if (head.xPos == body[i].xPos && head.yPos == body[i].yPos) {
            return true;
            }
        }
        return false;
    }
    return true;
}

bool snake::gameOver()
{
    if (!this->collision())
        return false;
    return true;
}

std::vector<std::string> snake::update(arc::Input key, std::vector<std::string> board)
{
    if (key == arc::Input::UP) {
        snake::move('u');
    }
    return board;
}