/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** sfml.hpp
*/

#pragma once
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>
#include "../include/IDisplayModule.hpp"

class sfml : public IDisplayModule
{
    public:
        sfml() {

        };
        ~sfml() {};
        void stop() override {};
        const std::string& getName() const override {
            static const std::string name = "sfml";
            return name;
        };

        //WINDOW//
        void create_window() override;
        void close_window() override;
        void destruct_window() override;

        //DISPLAY//
        void display_board(std::vector<std::string> board) override;
        void display_text(std::string text) override;

        //EVENT//
        IDisplayModule::Input handle_key() override;
        bool gameOver() override;
        bool isOpen() override;
    protected:
        sf::RenderWindow _window;
};