/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade.cpp
*/

#include "Core/include/Core.hpp"
#include "Game/pacman/pacman.hpp"
#include "Game/qix/qix.hpp"
#include "Game/solarFox/solarFox.hpp"

typedef IGameModule *(*func_t)();

int myStrCmp(const char *src1, const char *src2)
{
    for (int i = 0; src1[i] != '\0'; i += 1)
        if (src1[i] != src2[i])
            return -1;
    return 0;
}

int initDynamicLib(void *dynamicLib, char *src)
{
    if (!dynamicLib) {
        printf("%s\n", dlerror());
        return 0;
    }
    func_t initpcm;
    if ((initpcm = (func_t)dlsym(dynamicLib, "entryPoint")) == NULL) {
        printf("%s\n", dlerror());
        return 0;
    }
    initpcm();
    pacman pac_;
    qix qix_;
    solarFox solarFox_;
    if (myStrCmp(src, "./lib/pacman.so") == 0)
        pac_.init();
    if (myStrCmp(src, "./lib/qix.so") == 0)
        qix_.init();
    if (myStrCmp(src, "./lib/solarFox.so") == 0)
        solarFox_.init();
    dlclose(dynamicLib);
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    void *dynamicLib;
    for (int i = 1; av[i]; i += 1) {
        dynamicLib = dlopen(av[i], RTLD_LAZY);
        initDynamicLib(dynamicLib, av[i]);
    }
    return 0;
}