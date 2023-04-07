/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGameModule.hpp
*/

#include <iostream>
#include "../../utils/utils.hpp"
#include "vector"

namespace arc {
    class IGameModule
    {
        public:
            virtual ~IGameModule() = default;
            virtual void init() = 0;
            virtual void stop() = 0;
            virtual const std::string& getName() const = 0;
            virtual bool gameOver() = 0;
            virtual std::vector<std::string> update(arc::Input, std::vector<std::string>) = 0;
    };
};