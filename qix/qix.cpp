/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** qix.c
*/

#include <stdio.h>


void initQix() __attribute__((constructor));
void closeQix() __attribute__((destructor));

void initQix()
{
    printf("[libQIX] Loading QIX library...\n");
}

void closeQix()
{
    printf("[libQIX] QIX closing.\n");
}