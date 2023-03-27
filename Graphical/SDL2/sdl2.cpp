/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** sdl2.cpp
*/

#include "sdl2.hpp"

extern "C" void initSdl2() __attribute__ ((constructor));
extern "C" void closeSdl2() __attribute__ ((destructor));
extern "C" IDisplayModule *entryPoint();

extern "C" void initSdl2()
{
    printf("[sdl2] Loading Snake library...\n");
}

extern "C" void closeSdl2()
{
    printf("[sdl2] Snake closing.\n");
}

extern "C" IDisplayModule *entryPoint()
{
    printf("[sdl2] entry point !\n");
    return new sdl2();
}