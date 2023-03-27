/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** board.hpp
*/

#include <map>
#pragma once

class board
{
    public:
        board();
        ~board();
        void loadBoard(char *);
    protected:
        int **boardMap;
};