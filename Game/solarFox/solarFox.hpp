/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** solarFox.hpp
*/

#pragma once
#include "../include/IGameModule.hpp"
#include <vector>
#include <ctime>
#include "../../board/board.hpp"
#include "../../utils/utils.hpp"

extern "C" {
    void initSolarFox();
    void closeSolarFox();
}

    class solarFox : public arc::IGameModule
    {
        public:
            solarFox();
            ~solarFox();
            void init(board *) override;
            void stop() override {exit(0);};
            const std::string& getName() const override;
            void collision();
            bool gameOver() override;
            void update(arc::Input, board*) override;
            void moveUp(board*);
            void moveDown(board*);
            void moveLeft(board*);
            void moveRight(board*);
            void shoot(board*);
            void moveMobUp(board*);
            void moveMobDown(board*);
            void moveMobLeft(board*);
            void moveMobRight(board*);
            void mobShoot(board*);
            void mobShootTop(board*);
            void mobShootLeft(board*);
            void mobShootRight(board*);
            void mobShootBot(board*);
            void deleteShoot(board*);
            void moveMobShoot(board*);
            void moveMobShootTop(board*);
            void moveMobShootBot(board*);
            void moveMobShootLeft(board*);
            void moveMobShootRight(board*);
            void checkGameWin(board*);
            int coin_;
            bool gameOver_;
            int posX;
            int posY;
            int posXmob;
            int posYmob;
            //mobmove
            void moveMob(board*);
            bool mobUp;
            bool mobDown;
            bool mobLeft;
            bool mobRight;
    };