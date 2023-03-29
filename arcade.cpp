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
    graph = loaderGr.getInstance();
    game = loaderGa.getInstance();
    graph->create_window();
    // game->init();
    while (1) {
        // if (graph->handle_key() == IDisplayModule::Input::SPACE && myStrCmp(graph->getName(), "sfml") == 0) {
        //     loaderGr.closeLoader();
        //     loaderGr.openLoader("lib/ncurses.so");
        // }
        if (graph->handle_key() == IDisplayModule::Input::SPACE ) {
            graph->close_window();
            if (myStrCmp(graph->getName(), "sfml") == 0) {
                delete graph;
                loaderGr.closeLoader();
                loaderGr.openLoader("lib/ncurses.so");
            }
            if (myStrCmp(graph->getName(), "ncurses") == 0) {
                delete graph;
                loaderGr.closeLoader();
                loaderGr.openLoader("lib/sfml.so");
            }
            graph = loaderGr.getInstance();
            std::cout <<    "titi"  << std::endl;
        }
        // sleep(3);
    }

}

int main(int ac, char **av)
{
    if (ac != 2)
        Error::err_("invalid arguments");
    arcade(av[1]);
    return 0;
}