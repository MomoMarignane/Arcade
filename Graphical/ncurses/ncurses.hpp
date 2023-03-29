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
            printf("fenêtre ncurses fermée!\n");
            endwin();
        };
        void init() override {
        };
        void stop() override {
        };
        const std::string& getName() const override {
            static const std::string name = "ncurses";
            return name;
        };
        void setCmd()
        {
            this->cmd_ = getch();
        };
        int getCmd()
        {
            return this->cmd_;
        };
        //INIT COLOR//
        void init_color();

        //WINDOW//
        void create_window();
        void close_window() override {};
        void destruct_window() override {};

        //DISPLAY//
        void display_board(int **board, std::map<int, char> tab_conversion) override {};
        void display_text(std::string) override {};

        //EVENT//
        bool gameOver() override { return false; };
    protected:
        bool is_Open;
        bool is_GameOver;
        int cmd_;
};
