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
        sfml() {

        };
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
            // this->window_->create(sf::VideoMode(800, 600), "My window");
            window_ = new sf::RenderWindow(sf::VideoMode(1920, 1080), "My Game", sf::Style::Resize | sf::Style::Close);
            
        };
        void close_window() override {
                this->window_->close();
        };
        void destruct_window() override {};
        IDisplayModule::Input handle_key() override { window_->display(); sleep(5); return IDisplayModule::Input::SPACE;};
        //DISPLAY//
        void display_board(int **board, std::map<int, char> tab_conversion) override {};
        void display_text(std::string text) override {};

        //EVENT//
        bool gameOver() override {
            return false;
        };
    protected:
        sf::Window *window_;
};