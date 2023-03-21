/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** qix.hpp
*/

#pragma once
#include "../../Core/include/Core.hpp"

extern "C" {
    void initQix();
    void closeQix();
}

class qix : public IGameModule
{
    public:
        qix() {};
        ~qix() {};
        void init() override {
            printf("_________\nQIX\n_______\n");
        }

        void stop() override {}

        const std::string& getName() const override {
            static const std::string name = "Pacman";
            return name;
        }
};