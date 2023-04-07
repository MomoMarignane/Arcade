/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** solarFox.hpp
*/

#pragma once
#include "../include/IGameModule.hpp"
#include <vector>
#include "../../utils/utils.hpp"

extern "C" {
    void initSolarFox();
    void closeSolarFox();
}

    class solarFox : public arc::IGameModule
    {
        public:
            solarFox() {};
            ~solarFox();
            void init() override {
            };
            void stop() override {};
            const std::string& getName() const override {
                static const std::string name = "solarFox";
                return name;
            };
            bool gameOver() override {return false;};
            std::vector<std::string> update(arc::Input, std::vector<std::string>) override {};
    };