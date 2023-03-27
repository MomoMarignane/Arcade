/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** ncurses.cpp
*/

#include "ncurses.hpp"

extern "C" void initNcurses() __attribute__((constructor));
extern "C" void closeNcurses() __attribute__((destructor));
extern "C" IDisplayModule *entryPoint();

extern "C" void initNcurses()
{
    printf("[ncurses] Loading Snake library...\n");
}

extern "C" void closeNcurses()
{
    printf("[ncurses] Snake closing.\n");
}

extern "C" IDisplayModule *entryPoint()
{
    printf("[ncurses] entry point !\n");
    return new ncurses();
}