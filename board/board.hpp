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
        void setBoardMapSnake(const std::string& filename);
        void setBoardMapSfox(const std::string& filename);
        void updateSnake() {};
        void updateSfox() {};
        std::vector<std::string> getBoardMapSnake();
        std::vector<std::string> getBoardMapSfox();
    protected:
        std::vector<std::string> boardMapSnake;
        std::vector<std::string> boardMapSfox;
};