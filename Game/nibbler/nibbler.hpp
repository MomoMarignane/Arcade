/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** nibbler.hpp
*/

#pragma once
#include "../../Core/include/Core.hpp"

extern "C" {
    void initQix();
    void closeQix();
}

class nibbler : public IGameModule
{
    public:
        nibbler() {};
        ~nibbler() {};
        void init() override {
            printf("_________\nNIBBLER\n_______\n");
        }

        void stop() override {}

        const std::string& getName() const override {
            static const std::string name = "Pacman";
            return name;
        }
};