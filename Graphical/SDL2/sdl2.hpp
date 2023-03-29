/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** sdl2.hpp
*/

#include <map>
#include "../include/IDisplayModule.hpp"
#pragma once

class sdl2 : public IDisplayModule
{
    public:
        sdl2() {};
        ~sdl2() {};
        void init() override {
            printf("SDL2 initied!\n");
        };
        void stop() override {};
        const std::string& getName() const override {
            static const std::string name = "sdl2";
            return name;
        };
        bool gameOver() override {};
        void create_window() override {};
        void close_window() override {};
        void destruct_window() override {};

            //DISPLAY//
        void display_board(int **board, std::map<int, char> tab_conversion) override {};
        void display_text(std::string text) override {};
};