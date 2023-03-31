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
        void stop() override {};
        const std::string& getName() const override {
            static const std::string name = "sdl2";
            return name;
        };
        bool gameOver() override {};
        void create_window() override {};
        void close_window() override {};
        IDisplayModule::Input handle_key() override {};

            //DISPLAY//
        void display_text(std::string text) override {};
};