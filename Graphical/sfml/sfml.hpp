/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** sfml.hpp
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/IDisplayModule.hpp"
#pragma once

class sfml : public IDisplayModule
{
    public:
        sfml() {};
        ~sfml() {};
        void init() override {
            window_ = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade - SFML", sf::Style::Resize | sf::Style::Close);
            window_->setFramerateLimit(60);
        };
        void stop() override {};
        const std::string& getName() const override {
            static const std::string name = "sfml";
            return name;
        };

        //WINDOW//
        void create_window() override {};
        void close_window() override {};
        void destruct_window() override {};
        IDisplayModule::Input handle_key() override {return IDisplayModule::Input::SPACE;};
        //DISPLAY//
        void display_board(int **board, std::map<int, char> tab_conversion) override {};
        void display_text(std::string text) override {};

        //EVENT//
        bool gameOver() override {
            return false;
        };
    protected:
        sf::RenderWindow *window_;


};