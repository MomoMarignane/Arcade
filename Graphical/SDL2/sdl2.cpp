/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** sdl2.cpp
*/

#include "sdl2.hpp"

extern "C" void initSdl2() __attribute__ ((constructor));
extern "C" void closeSdl2() __attribute__ ((destructor));
extern "C" IDisplayModule *entryPoint();

extern "C" void initSdl2()
{
    printf("[sdl2] Loading sdl2 library...\n");
}

extern "C" void closeSdl2()
{
    printf("[sdl2] sdl2 closing.\n");
}

extern "C" IDisplayModule *entryPoint()
{
    printf("[sdl2] entry point !\n");
    return new sdl2();
}

sdl2::sdl2()
{
    SDL_Init(SDL_INIT_VIDEO);
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        exit(84);
    }

    sdl2::window_ = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);

    if(!sdl2::window_)
    {
        std::cout << "Failed to create window\n";
        exit(84);
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(sdl2::window_);

    if(!window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        exit(84);
    }

    SDL_UpdateWindowSurface(sdl2::window_);
    SDL_Delay(5000);
}

sdl2::~sdl2()
{
    SDL_DestroyWindow(this->window_);
    SDL_Quit();
}

void sdl2::stop()
{}

const std::string& sdl2::getName() const 
{
    static const std::string name = "sdl2";
    return name;
}

void sdl2::init()
{}

void sdl2::update()
{}

bool sdl2::gameOver()
{}

void sdl2::display_board(std::vector<std::string> board)
{}

bool sdl2::isOpen()
{}

IDisplayModule::Input sdl2::handle_key()
{
    SDL_Event event;
    bool running = true;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                    case SDLK_SPACE:
                        // Faire quelque chose lorsque la touche espace est appuyée
                        break;
                    // Ajouter d'autres cas selon les touches que vous voulez prendre en compte
                    }
                break;
        }
    }
}

void display_text(std::string text)
{}