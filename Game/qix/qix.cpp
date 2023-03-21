/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** qix.c
*/

#include <stdio.h>
#include "qix.hpp"

void initQix() __attribute__((constructor));
void closeQix() __attribute__((destructor));
extern "C" IGameModule *entryPoint();

void initQix()
{
    printf("[libQIX] Loading QIX library...\n");
}

void closeQix()
{
    printf("[libQIX] QIX closing.\n");
}

extern "C" IGameModule *entryPoint()
{
    printf("[libQIX] entry point !\n");
    return 0;
}