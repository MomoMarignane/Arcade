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

class qix : public Core
{
    public:
        qix();
        ~qix();
};