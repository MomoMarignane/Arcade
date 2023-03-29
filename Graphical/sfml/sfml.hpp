/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** sfml.hpp
*/

#pragma once
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/IDisplayModule.hpp"

class sfml : public IDisplayModule
{
    public:
        sfml() {};
        ~sfml() {};
        void init() override {

        };
        void stop() override {};
        const std::string& getName() const override {
            static const std::string name = "sfml";
            return name;
        };

        //WINDOW//
        void create_window() override {
            std::cout << "create_window" << std::endl;
            this->window_->create(sf::VideoMode(800, 600), "My window");
            // sf::Window window(sf::VideoMode(800, 600), "My window");
        };
        void close_window() override {
                // this->window_->close();
                exit(1);
        };
        void destruct_window() override {};
        IDisplayModule::Input handle_key() override {sleep(5); return IDisplayModule::Input::SPACE;};
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