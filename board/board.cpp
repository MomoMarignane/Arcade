/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** board.cpp
*/

#include "board.hpp"

board::board()
{
    board::boardMap = new int*[20];
    for (int i = 0; i < 20; i++)
        board::boardMap[i] = new int[20];
}

board::~board()
{

}

void board::loadBoard(char *src)
{
    
}