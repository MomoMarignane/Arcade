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

void display_arcade_start()
{
    std::cout << "︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻︻" << std::endl;
    std::cout << "          :::        :::::::::       ::::::::           :::        :::::::::       ::::::::::" << std::endl;
    std::cout << "       :+: :+:      :+:    :+:     :+:    :+:        :+: :+:      :+:    :+:      :+:        " << std::endl;
    std::cout << "     +:+   +:+     +:+    +:+     +:+              +:+   +:+     +:+    +:+      +:+          " << std::endl;
    std::cout << "   +#++:++#++:    +#++:++#:      +#+             +#++:++#++:    +#+    +:+      +#++:++#      " << std::endl;
    std::cout << "  +#+     +#+    +#+    +#+     +#+             +#+     +#+    +#+    +#+      +#+            " << std::endl;
    std::cout << " #+#     #+#    #+#    #+#     #+#    #+#      #+#     #+#    #+#    #+#      #+#             " << std::endl;
    std::cout << "###     ###    ###    ###      ########       ###     ###    #########       ##########       " << std::endl;
    std::cout << "︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼︼ " << std::endl;
    std::cout << "˃ Starting [ARCADE]" << std::endl;
    std::cout << "      Make by :" << std::endl;
    std::cout << "          ➫ Mohamed Mansour" << std::endl;
    std::cout << "          ➬ Raphael de Monchy" << std::endl;
    std::cout << "          ➩ Noah Yekken" << std::endl;

}

void arcade(char *src)
{
    int i = 0;
    DLloader <IGameModule> loaderGa;
    DLloader <IDisplayModule> loaderGr;
    IDisplayModule *graph;
    IGameModule *game;
    loaderGr.openLoader(src);
    loaderGa.openLoader("lib/solarFox.so");
    graph = loaderGr.getInstance();
    game = loaderGa.getInstance();
    graph->create_window();
    while (1) {
        if (graph->handle_key() == IDisplayModule::Input::SPACE) {
            if (myStrCmp(graph->getName(), "sfml") == 0) {
                graph->close_window();
                delete graph;
                loaderGr.closeLoader();
                loaderGr.openLoader("lib/ncurses.so");
                std::cout << "occurence numéro " << i++ << std::endl;
            } else if (myStrCmp(graph->getName(), "ncurses") == 0) {
                graph->close_window();
                delete graph;
                loaderGr.closeLoader();
                loaderGr.openLoader("lib/sfml.so");
            } else {
                Error::err_("Library not founding");
            }
            graph = loaderGr.getInstance();
            graph->create_window();
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        Error::err_("invalid arguments");
    arcade(av[1]);
    return 0;
}