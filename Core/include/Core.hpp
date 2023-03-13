/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ACore.hpp
*/

#pragma once

#include "../../Game/include/IGameModule.hpp"
#include "../../Graphical/include/IDisplayModule.hpp"

class Core : public IGameModule, public IDisplayModule
{
    public:
        Core();
        ~Core();
};