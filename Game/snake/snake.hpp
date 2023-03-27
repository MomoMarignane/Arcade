/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** lib.hpp
*/

#pragma once
#include <iostream>
#include <vector>
#include <stdio.h>
#include <dlfcn.h>
#include "../include/IGameModule.hpp"

extern "C" {
    void initSnake();
    void closeSnake();
}

class snake : public IGameModule
{
    public:
        snake() {};
        ~snake() {};
        void init() override {
            _life = 3;
            _score = 0;
            for (int i = 0; i < 5; i += 1)
                _lifeMob.push_back(2);
            playerPos player;
            player.xPos = 0;
            printf("initied\nSNAKE\n____________\n");
        };
        void stop() override {
            exit(0);
        };
        const std::string& getName() const override {
            static const std::string name = "Snake";
            return name;
        };
        void goUp();
        void goDown();
        void goLeft();
        void goRight();
        void lostLife();
        void resetLife();
        void upScore();
    protected:
        struct playerPos
        {
            int xPos;
            int yPos;
        };
        int _life;
        int _score;
        std::vector<int> _lifeMob;
        std::vector<int> _map1;
        std::vector<int> _map2;
        std::vector<int> _map3;
};