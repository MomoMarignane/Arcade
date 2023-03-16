/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** lib.c
*/

#include <stdio.h>

void initPacman() __attribute__((constructor));
void closePacman() __attribute__((destructor));
extern "C" int entryPoint(void *dynamicLib);

void initPacman()
{
    printf("[libPacman] Loading Pacman library...\n");
}

void closePacman()
{
    printf("[libPacman] Pacman closing.\n");
}

extern "C" int entryPoint(void *dynamicLib)
{
    printf("[libPacman] entry point !\n");
    return 0;
}

