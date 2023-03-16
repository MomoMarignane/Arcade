/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade.cpp
*/

#include "Core/include/Core.hpp"



typedef void (*func_t)();

int initDynamicLib(void *dynamicLib)
{
    if (!dynamicLib) {
        printf("1\n");
        return 84;
    }
    func_t initpcm;
    if ((initpcm = (func_t)dlsym(dynamicLib, "entryPoint")) == NULL) {
        printf("2\n");
        return 84;
    }
    initpcm();
    dlclose(dynamicLib);
    return 0;
}

int main()
{

    void *dynamicLib = dlopen("solarFox.so", RTLD_LAZY);
    if (initDynamicLib(dynamicLib) == 84)
        return 84;
    void *dynamicLib1 = dlopen("pacman.so", RTLD_LAZY);
    if (initDynamicLib(dynamicLib1) == 84)
        return 84;
    void *dynamicLib2 = dlopen("qix.so", RTLD_LAZY);
    if (initDynamicLib(dynamicLib2) == 84)
        return 84;
    return 0;
}