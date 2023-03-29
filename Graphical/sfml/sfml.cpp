/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** sfml.cpp
*/

#include "sfml.hpp"

extern "C" void initSfml() __attribute__ ((constructor));
extern "C" void closeSfml() __attribute__ ((destructor));
extern "C" IDisplayModule *entryPoint();

// // MANAGE LIBRAIRIE //

extern "C" void initSfml()
{
    printf("[sfml] Loading sfml library...\n");
}

extern "C" void closeSfml()
{
    printf("[sfml] sfml closing.\n");
}

extern "C" IDisplayModule *entryPoint()
{
    printf("[sfml] entry point !\n");
    return new sfml();
}

// // WINDOW//

void sfml::create_window()
{
    this->_window.create(sf::VideoMode(1920, 1080), "My SFML Window");
}

void sfml::close_window()
{
    this->_window.close();
}

void sfml::destruct_window()
{
    this->_window.clear();
}

// // DISPLAY //

void sfml::display_board(int **board, std::map<int, char> tab_conversion)
{

}

void sfml::display_text(std::string text)
{

}

// // EVENT //

IDisplayModule::Input sfml::handle_key()
{
    _window.display();
    sleep(5); 
    return IDisplayModule::Input::SPACE;
}

bool sfml::gameOver()
{
    return false;
}

bool sfml::isOpen()
{
    return this->_window.isOpen();
}