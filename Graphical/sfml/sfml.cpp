/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** sfml.cpp
*/

#include "sfml.hpp"

extern "C" void initSfml() __attribute__ ((constructor));
extern "C" void closeSfml() __attribute__ ((destructor));
extern "C" IDisplayModule *entryPoint();

extern "C" void initSfml()
{
    printf("[sfml] Loading sfml library...\n");
}

extern "C" void closeSfml()
{
    printf("[sfml] sfml closing.\n");
}

extern "C" IDisplayModule *entryPoint()
{
    printf("[sfml] entry point !\n");
    return new sfml();
}