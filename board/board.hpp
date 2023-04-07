/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** board.hpp
*/

#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
// #pragma once

class board
{
    public:
        board();
        ~board();
        void setBoard(board myBoard);
        void setBoardMap(const std::string& filename);
        void updateBoard() {};
        std::vector<std::string> getBoardMap();
    protected:
        std::vector<std::string> boardMap;
};