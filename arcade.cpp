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

// int initDynamicLib(void *dynamicLib, char *src)
// {
//     if (!dynamicLib) {
//         printf("%s\n", dlerror());
//         return 0;
//     }
//     // snake name_;
//     // nibbler nib_;
//     // if (myStrCmp(src, "./lib/nibbler.so") == 0)
//     //     nib_.init();
//     dlclose(dynamicLib);
//     return 0;
// }

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    // DLloader::DLloader();
    // void *dynamicLib;
    // for (int i = 1; av[i]; i += 1) {
    //     dynamicLib = dlopen(av[i], RTLD_LAZY);
    //     initDynamicLib(dynamicLib, av[i]);
    // }
    DLloader <IGameModule> loaderGa;
    DLloader <IDisplayModule> loaderGr;
    IDisplayModule *graph;
    IGameModule *game;
    loaderGa.openLoader("lib/solarFox.so");
    loaderGr.openLoader(av[1]);
    graph = loaderGr.getInstance();
    game = loaderGa.getInstance();
    graph->init();
    game->init();
    sleep(3);

    return 0;
}