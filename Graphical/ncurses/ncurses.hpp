/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ncurses.hpp
*/

#include "../include/IDisplayModule.hpp"
#pragma once

class ncurses : public IDisplayModule
{
    public:
        ncurses();
        ~ncurses();
        void init() override {};
        void stop() override {};
        const std::string& getName() const override {
            return "sdl2";
        };
        void gameOver() override {};
};