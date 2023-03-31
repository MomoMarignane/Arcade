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
    std::cout << "[before while 1]" << std::endl;                      //
    while (1) {
        if (graph->handle_key() == IDisplayModule::Input::SPACE) {
            std::cout << "[SPACE] Detected" << std::endl;
            if (myStrCmp(graph->getName(), "sfml") == 0) {

                std::cout << "getName SFML" << std::endl;               //
                std::cout << "> graph->close_window() [sfml]" << std::endl;     //
                graph->close_window();

                std::cout << "> delete graph [sfml]" << std::endl;      //
                delete graph;

                std::cout << "loaderGT.closeLOader() [sfml]" << std::endl;      //
                loaderGr.closeLoader();

                std::cout << "loaderGT.openLoader(ncurses)" << std::endl;       //
                loaderGr.openLoader("lib/ncurses.so");

            } else if (myStrCmp(graph->getName(), "ncurses") == 0) {

                std::cout << "getName ncurses" << std::endl;             //
                std::cout << "> graph->close_window()" << std::endl;     //
                graph->close_window();

                std::cout << "> delete graph [ncurses]" << std::endl;

                std::cout << "loaderGT.closeLoader() [ncurses]" << std::endl;      //
                loaderGr.closeLoader();

                std::cout << "openLoader(lib/sfml)" << std::endl;     //
                loaderGr.openLoader("lib/sfml.so");
            } else {
                Error::err_("Library not founding");
            }
            std::cout << "GET INSTANCE" << std::endl;               //
            graph = loaderGr.getInstance();
            std::cout << "create_window" << std::endl;              //
            graph->create_window();
            std::cout << "window created " << std::endl;            //
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