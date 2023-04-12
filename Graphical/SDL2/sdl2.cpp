/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** sdl2.cpp
*/

#include "sdl2.hpp"

extern "C" void initSdl2() __attribute__ ((constructor));
extern "C" void closeSdl2() __attribute__ ((destructor));
extern "C" arc::IDisplayModule *entryPoint();

extern "C" void initSdl2()
{
    // printf("[sdl2] Loading sdl2 library...\n");
}

extern "C" void closeSdl2()
{
    // printf("[sdl2] sdl2 closing.\n");
}

extern "C" arc::IDisplayModule *entryPoint()
{
    // printf("[sdl2] entry point !\n");
    return new sdl2();
}

sdl2::sdl2()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    TTF_Init();
    SDL_Rect destRectBorne = { 1920/4, -20, 1080, 1080 };
    SDL_Rect destRectSnakeB = {780, 420, 230, 350};
    SDL_Rect destRectSolarB = {1040, 420, 230, 350};
    this->window_ = SDL_CreateWindow("Ma fenêtre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
    this->renderer_ = SDL_CreateRenderer(this->window_, -1, SDL_RENDERER_ACCELERATED);
    this->texture_ = IMG_LoadTexture(this->renderer_, "assets/backBGmenu.jpg");
    this->music_ = Mix_LoadMUS("assets/arcadeZike.mp3");
    SDL_Texture *borneTexture = IMG_LoadTexture(this->renderer_, "assets/arcadeMenu.png");
    SDL_Texture *snakeButton = IMG_LoadTexture(this->renderer_, "assets/snakeButton.png");
    SDL_Texture *solarFoxButton = IMG_LoadTexture(this->renderer_, "assets/solarFoxButton.png");
    Mix_PlayMusic(this->music_, -1);
    SDL_RenderClear(this->renderer_);
    SDL_RenderCopy(this->renderer_, this->texture_, nullptr, nullptr);
    SDL_RenderCopy(this->renderer_, borneTexture, nullptr, &destRectBorne);
    SDL_RenderCopy(this->renderer_, snakeButton, nullptr, &destRectSnakeB);
    SDL_RenderCopy(this->renderer_, solarFoxButton, nullptr, &destRectSolarB);

    SDL_RenderPresent(this->renderer_);
}

sdl2::~sdl2()
{
    TTF_CloseFont(this->font_);
    TTF_Quit();
    SDL_DestroyRenderer(this->renderer_);
    SDL_DestroyWindow(this->window_);
    Mix_FreeMusic(this->music_);
    Mix_CloseAudio();
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
{

}

void sdl2::update()
{
    SDL_RenderCopy(this->renderer_, this->message_, NULL, &rectMessage_);
    SDL_RenderPresent(this->renderer_);
}

bool sdl2::gameOver()
{}

void sdl2::display_object(arc::Obj obj)
{
    SDL_Texture* texture = nullptr;
    SDL_Surface* surface = IMG_Load(obj._path.c_str());
    texture = SDL_CreateTextureFromSurface(this->renderer_, surface);
    SDL_FreeSurface(surface);
    SDL_Rect destRect = { obj.x, obj.y, 0, 0 };
    SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);
    SDL_RenderCopy(this->renderer_, texture, nullptr, &destRect);
    SDL_DestroyTexture(texture);
    // SDL_RenderPresent(renderer);
}

void sdl2::display_board(board *board)
{
    int pos_x = 0;
    int pos_y = 0;
    this->font_ = TTF_OpenFont("assets/stocky.ttf", 48);
    this->surfaceMessage_ = TTF_RenderText_Solid(this->font_, "ARCADE SDL2", this->colorW_);
    this->message_ = SDL_CreateTextureFromSurface(this->renderer_, this->surfaceMessage_);
    this->rectMessage_ = { 10, 10, this->surfaceMessage_->w, this->surfaceMessage_->h };

    SDL_RenderClear(this->renderer_);
    // SDL_RenderCopy(this->renderer_, message, NULL, &rectMessage);
    for (size_t i = 0; i < board->_Object.size(); i++) {
        display_object(board->_Object[i]);
    }
    SDL_RenderPresent(this->renderer_);
}


bool sdl2::isOpen()
{}

arc::Input sdl2::handle_key()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        SDL_Delay(150);
        if (event.type == SDL_QUIT)
        {
            exit(0);
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_UP:
                    prviousValue = arc::Input::UP;
                    return arc::Input::UP;
                    break;
                case SDLK_DOWN:
                    prviousValue = arc::Input::DOWN;
                    return arc::Input::DOWN;
                    break;
                case SDLK_LEFT:
                    prviousValue = arc::Input::LEFT;
                    return arc::Input::LEFT;
                    break;
                case SDLK_RIGHT:
                    prviousValue = arc::Input::RIGHT;
                    return arc::Input::RIGHT;
                    break;
                case SDLK_RETURN:
                    prviousValue = arc::Input::ENTER;
                    return arc::Input::ENTER;
                    break;
                case SDLK_SPACE:
                    prviousValue = arc::Input::SPACE;
                    return arc::Input::SPACE;
                    break;
                case SDLK_1:
                case SDLK_QUOTE:
                    prviousValue = arc::Input::StartSnake;
                    return arc::Input::StartSnake;
                    break;
                case SDLK_2:
                    prviousValue = arc::Input::StartSfox;
                    return arc::Input::StartSfox;
                    break;
                case SDLK_g:
                    prviousValue = arc::Input::nextLib;
                    return arc::Input::nextLib;
                    break;
                default:
                    break;
            }
        }
    }
    return prviousValue;
}

void display_text(std::string text)
{}