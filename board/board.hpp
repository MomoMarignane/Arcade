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
        int **getBoardMap() {
            return this->boardMap;
        }
        void loadBoard(char *);
    protected:
        int **boardMap;
};