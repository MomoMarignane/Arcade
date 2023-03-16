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

class pacman : public Core
{
    public:
        pacman();
        ~pacman();
        void *goUp();
        void *goDown();
        void *goLeft();
        void *goRight();
        int lostLife();
        int resetLife();
        int upScore();

    private:
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

pacman::pacman()
{
    _life = 3;
    _score = 0;
    for (int i = 0; i < 5; i += 1)
        _lifeMob.push_back(2);
    playerPos player;
    player.xPos = 0;
}

extern "C" pacman* createpacman() {
    return new pacman();
}