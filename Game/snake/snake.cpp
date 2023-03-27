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
extern "C" IGameModule *entryPoint();

void initSnake()
{
    printf("[libSnake] Loading Snake library...\n");
}

void closeSnake()
{
    printf("[libSnake] Snake closing.\n");
}

extern "C" IGameModule *entryPoint()
{
    printf("[libSnake] entry point !\n");
    return new snake();
}

void snake::lostLife()
{
    snake::_life -= 1;
}

void snake::upScore()
{
    _score += 1;
}

void snake::resetLife()
{
    snake::_life = 3;
}
