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
    // this->_window.create(sf::VideoMode(1920, 1080), "My SFML Window");
    this->_window.create(sf::VideoMode(100, 100), "My SFML Window");
}

void sfml::close_window()
{
    this->_window.close();
}

// // DISPLAY //
sf::Sprite char_to_sprite(char c)
{
    switch (c) {
        case '*':
            //WALL//
            break;
        case 'o':
            //SNAKE BODY//
            break;
        case 'O':
            //SNAKE HEAD//
            break;
        case '+':
            //SNAKE FOOD//
            break;
        default:
            std::cout << "Invalid Map" << std::endl;
            break;
    }
}

void sfml::display_board(std::vector<std::string> board)
{
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[i].size(); j++) {
            char ptrChar = board[i][j];
            char_to_sprite(ptrChar);
        }
    }

}

void sfml::display_text(std::string text)
{

}

// // EVENT //

IDisplayModule::Input sfml::handle_key()
{
    _window.display();
    sf::Event _event;

    // if (this->_window.pollEvent(_event)) {
    //     if (_event.key.code == sf::Event::KeyPressed) {
    //         if (_event.key.code == sf::Keyboard::Escape) {
    //             std::cout << _event.key.code << std::endl;
    //             return sfml::IDisplayModule::Input::ESCAPE;
    //         }
    //         if (_event.key.code == sf::Keyboard::Up) {
    //             std::cout << _event.key.code << std::endl;
    //             return sfml::IDisplayModule::Input::UP;
    //         }
    //         if (_event.key.code == sf::Keyboard::Down) {
    //             std::cout << _event.key.code << std::endl;
    //             return sfml::IDisplayModule::Input::DOWN;
    //         }
    //         if (_event.key.code == sf::Keyboard::Left)
    //             return sfml::IDisplayModule::Input::LEFT;
    //         if (_event.key.code == sf::Keyboard::Right)
    //             return sfml::IDisplayModule::Input::RIGHT;
    //         if (_event.key.code == sf::Keyboard::Enter)
    //             return sfml::IDisplayModule::Input::ENTER;
    //         if (_event.key.code == sf::Keyboard::Space) {
    //             std::cout << _event.type << std::endl;
    //             return sfml::IDisplayModule::Input::SPACE;
    //         }
    //     }
    sf::Event event;
        while (this->_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->_window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                std::cout << "space" << std::endl;
                return IDisplayModule::Input::SPACE;
            }
        }
        
    // while (this->_window.waitEvent(this->event)) {
    return IDisplayModule::NONE;
    // return IDisplayModule::Input::SPACE;
}

bool sfml::gameOver()
{
    return false;
}

bool sfml::isOpen()
{
    return this->_window.isOpen();
}