/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IModules.hpp
*/

#include <iostream>
#include <map>

class IDisplayModule
{
    public:
        virtual ~IDisplayModule() = default;
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual const std::string& getName() const = 0;

        //WINDOW//
        virtual void create_window() = 0;
        virtual void close_window() = 0;
        virtual void destruct_window() = 0;

        //DISPLAY//
        virtual void display_board(int **board, std::map<int, char> tab_conversion) = 0;
        virtual void display_text(std::string) = 0;

        //EVENT//
        virtual bool gameOver() = 0;
    
        enum Input {LEFT, RIGHT, UP, DOWN, ENTER, SPACE, ESCAPE, nextGame, prevGame, nextLib, prevLib, START};
    protected:
};