/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** sdl2.hpp
*/

#include "../include/IDisplayModule.hpp"
#pragma once

class sdl2 : public IDisplayModule
{
    public:
        sdl2();
        ~sdl2();
        void init() override {};
        void stop() override {};
        const std::string& getName() const override {
            return "sdl2";
        };
        void gameOver() override {};
};