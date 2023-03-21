/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGameModule.hpp
*/

#include <iostream>

class IGameModule
{
    public:
        virtual ~IGameModule() = default;
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual const std::string& getName() const = 0;
};