/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** solarFox.c
*/

#include <stdio.h>
#include "solarFox.hpp"

void initSolarFox() __attribute__((constructor));
void closeSolarFox() __attribute__((destructor));
extern "C" arc::IGameModule *entryPoint();

void initSolarFox()
{
    // printf("[libSolarFox] Loading SolarFox library...\n");
}

void closeSolarFox()
{
    // printf("[libSolarFox] SolarFox closing.\n");
}

extern "C" arc::IGameModule *entryPoint()
{
    // printf("[libSolarFox] entry point !\n");
    return new solarFox();
}

solarFox::~solarFox()
{}