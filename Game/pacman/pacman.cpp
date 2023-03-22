/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** lib.c
*/

#include <stdio.h>
#include "pacman.hpp"

void initPacman() __attribute__((constructor));
void closePacman() __attribute__((destructor));
extern "C" IGameModule *entryPoint();


void initPacman()
{
    printf("[libPacman] Loading Pacman library...\n");
}

void closePacman()
{
    printf("[libPacman] Pacman closing.\n");
}

extern "C" IGameModule *entryPoint()
{
    printf("[libPacman] entry point !\n");
    return 0;
}