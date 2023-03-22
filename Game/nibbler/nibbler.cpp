/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** nibbler.c
*/

#include <stdio.h>
#include "nibbler.hpp"

void initNibbler() __attribute__((constructor));
void closeNibbler() __attribute__((destructor));
extern "C" IGameModule *entryPoint();

void initNibbler()
{
    printf("[libNibbler] Loading Nibbler library...\n");
}

void closeNibbler()
{
    printf("[libNibbler] Nibbler closing.\n");
}

extern "C" IGameModule *entryPoint()
{
    printf("[libNibbler] entry point !\n");
    return 0;
}