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
            initscr();
            noecho();
        };
        void stop() override {
            endwin();
        };
        const std::string& getName() const override {
            static const std::string name = "ncurses";
            return name;
        };
        bool gameOver() override {
            return false;
        };
        void setCmd()
        {
            this->cmd_ = getch();
        };
        int getCmd()
        {
            return this->cmd_;
        };
    protected:
        int cmd_;
};