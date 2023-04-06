/*
 EPITECH PROJECT, 2022
 Arcade
 File description:
 lib.hpp
*/

#pragma once
#include <iostream>
#include <vector>
#include <stdio.h>
#include <dlfcn.h>
#include <iostream>
#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../include/IGameModule.hpp"

extern "C" {
    void initSnake();
    void closeSnake();
}

// Définition des constantes pour la taille de la fenêtre
const int HEIGHT = 10;
const int WIDTH = 20;

class snake : public IGameModule
{
    public:
        snake() {
        body = {{10, 10}, {10, 9}, {10, 8}}; // tête, corps, queue
        direction = 'r'; // direction initiale
        };
        ~snake() {};

        void init() override;

        void stop() override {
            exit(0);
        };

        virtual bool gameOver() override;

        const std::string& getName() const override {
            static const std::string name = "Snake";
            return name;
        };

        struct playerPos
        {
            int xPos;
            int yPos;
        };

        char direction; // la direction dans laquelle le serpent se déplace

        void move(char dir);

        void grow();

        const std::vector<playerPos>& getBody() const {
            return body;
        }

        bool ate(playerPos food) const;

        bool collision() const;

        playerPos generateFood()
        {
            int x = rand() % (WIDTH - 1) + 1;
            int y = rand() % (HEIGHT - 1) + 1;
            return {x, y};
        }

        std::vector<playerPos> body; // le corps du serpent

    protected:
        int _life;
        int _score;
        std::vector<int> _lifeMob;
        std::vector<int> _map1;
        std::vector<int> _map2;
        std::vector<int> _map3;
};