/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade.cpp
*/

#include "Core/include/Core.hpp"
#include "Game/snake/snake.hpp"
#include "Game/nibbler/nibbler.hpp"
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
    snake name_;
    nibbler nib_;
    if (myStrCmp(src, "./lib/nibbler.so") == 0)
        nib_.init();

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