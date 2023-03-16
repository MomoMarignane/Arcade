/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** solarFox.hpp
*/

#pragma once
#include "../../Core/include/Core.hpp"

extern "C" {
    void initSolarFox();
    void closeSolarFox();
}

class solarFox : public Core
{
    public:
        solarFox();
        ~solarFox();
}

extern "C" solarFox* createsolarFox() {
    return new solarFox();
}