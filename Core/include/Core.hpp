/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Core.hpp
*/

#pragma once

#include <stdio.h>
#include <dlfcn.h>

#include "../../Game/include/IGameModule.hpp"
#include "../../Graphical/include/IDisplayModule.hpp"

class Core : public IGameModule, public IDisplayModule
{
    public:
        Core();
};