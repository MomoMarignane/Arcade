/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade.cpp
*/

#include <unistd.h>
#include <stdio.h>
#include "utils/utils.hpp"
#include "DLloader/DLloader.hpp"
#include "Core/include/Core.hpp"
#include "Game/include/IGameModule.hpp"
#include "Graphical/include/IDisplayModule.hpp"
#include "errorHandling/errorHandling.hpp"

void arcade(char *src)
{
    DLloader <IGameModule> loaderGa;
    DLloader <IDisplayModule> loaderGr;
    IDisplayModule *graph;
    IGameModule *game;
    loaderGr.openLoader(src);
    loaderGa.openLoader("lib/solarFox.so");
    while (1) {
        graph = loaderGr.getInstance();
        game = loaderGa.getInstance();
        graph->init();
        game->init();
        if (graph->handle_key() == IDisplayModule::Input::SPACE && myStrCmp(graph->getName(), "sfml") != 0) {
            loaderGr.closeLoader();
            loaderGr.openLoader("lib/sfml.so");
        }
        sleep(3);
    }

}

int main(int ac, char **av)
{
    if (ac != 2)
        Error::err_("invalid arguments");
    arcade(av[1]);

    return 0;
}