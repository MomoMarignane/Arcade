/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** board.cpp
*/

#include "board.hpp"

board::board()
{
    this->boardMapSnake = std::vector<std::string>(11, std::string(20, ' '));
    this->boardMapSfox = std::vector<std::string>(11, std::string(20, ' '));
}

board::~board()
{  
    this->boardMapSnake.clear();
    this->boardMapSfox.clear();
}

void board::setBoardMapSnake(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file: " + filename);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
        lines.push_back(line);
    this->boardMapSnake = lines;
}

void board::setBoardMapSfox(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file: " + filename);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
        lines.push_back(line);
    this->boardMapSfox = lines;
}

std::vector<std::string> board::getBoardMapSnake() 
{
    return this->boardMapSnake;
}

std::vector<std::string> board::getBoardMapSfox() 
{
    return this->boardMapSnake;
}