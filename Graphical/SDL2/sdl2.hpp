/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** sdl2.hpp
*/

#pragma once
#include <map>
#include <SDL2/SDL.h>
#include "../include/IDisplayModule.hpp"

class sdl2 : public IDisplayModule
{
    public:
        sdl2();
        ~sdl2();
        void stop() override;
        const std::string& getName() const override;
        void init() override;
        void update() override;
        bool gameOver() override;
        bool isOpen() override;
        IDisplayModule::Input handle_key() override;

        //DISPLAY//
        void display_text(std::string text, int x, int y) override;
        void display_board(std::vector<std::string> board) override;
        int getSizeWindowX() override {};
        int getSizeWindowY() override {};
    
    protected:
        SDL_Window* window_;
};