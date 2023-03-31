/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ncurses.hpp
*/

#include "../include/IDisplayModule.hpp"
#include <ncurses.h>
#pragma once

class ncurses : public IDisplayModule
{
    public:
        ncurses() {};
        ~ncurses() {
        };
        void stop() override {
        };
        const std::string& getName() const override {
            static const std::string name = "ncurses";
            return name;
        };
        void setCmd()
        {
        };
        int getCmd()
        {
            return this->cmd_;
        };
        //INIT COLOR//
        void init_color();

        //WINDOW//
        void create_window() override;
        void close_window() override;

        //DISPLAY//
        void display_board(std::vector<std::string> board) override;
        void display_text(std::string text) override;

        //EVENT//
        IDisplayModule::Input handle_key() override;
        bool gameOver() override;
        bool isOpen() override;
    protected:
        bool is_Open;
        bool is_GameOver;
        int cmd_;

        //UPDATE
        void update();
};
