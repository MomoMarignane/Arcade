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
#include "../../Core/include/Core.hpp"

extern "C" {
    void initPacman();
    void closePacman();
}

class pacman : public IGameModule
{
    public:
        pacman() {
            _life = 3;
            _score = 0;
            for (int i = 0; i < 5; i += 1)
                _lifeMob.push_back(2);
            playerPos player;
            player.xPos = 0;
        };
        ~pacman() {};
        void init() override {
            printf("_________\nPACMAN\n________\n");
        }

        void stop() override {}

        const std::string& getName() const override {
            static const std::string name = "Pacman";
            return name;
        }
    protected:
        void *goUp();
        void *goDown();
        void *goLeft();
        void *goRight();
        int lostLife();
        int resetLife();
        int upScore();
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