/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** solarFox.c
*/

#include <stdio.h>

void initSolarFox() __attribute__((constructor));
void closeSolarFox() __attribute__((constructor));
extern "C" int entryPoint(void *dynamicLib);

void initSolarFox()
{
    printf("[libSolarFox] Loading SolarFox library...\n");
}

void closeSolarFox()
{
    printf("[libSolarFox] SolarFox closing.\n");
}

extern "C" int entryPoint(void *dynamicLib)
{
    printf("[libSolarFox] entry point !\n");
    return 0;
}