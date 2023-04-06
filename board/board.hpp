/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** board.hpp
*/

#pragma once
#include <map>
#include <vector>
#include <iostream>

class board
{
    public:
        board();
        ~board();
        void setBoardMap(char *);
        std::vector<std::string> getBoardMap() {
            return this->boardMap;
        }
        void loadBoard(std::vector<std::string> &_board);
    protected:
        std::vector<std::string> boardMap;
};