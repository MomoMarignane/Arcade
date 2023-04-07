/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** utils.hpp
*/

#include <iostream>
#pragma once

int myStrCmp(const std::string, const std::string);

namespace arc {
    enum Input {LEFT, RIGHT, UP, DOWN, ENTER, SPACE, ESCAPE, nextGame, prevGame, nextLib, prevLib, StartSnake, StartSfox, NONE};
};