/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** solarFox.hpp
*/

#pragma once
#include "../include/IGameModule.hpp"

extern "C" {
    void initSolarFox();
    void closeSolarFox();
}

class solarFox : public IGameModule
{
    public:
        solarFox() {};
        ~solarFox() {};
        void init() override {
            printf("__________\nSolarFOX\n_________\n");
        };
        void stop() override {};
        const std::string& getName() const override {
            static const std::string name = "Qix";
            return name;
        };
        virtual bool gameOver() override {return false;};
};