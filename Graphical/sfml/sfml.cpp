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

// CONSTRUCTOR DESTRUCTOR //

int check_lib()
{
    return 0;
}

sfml::sfml()
{
    this->_window.create(sf::VideoMode(1900, 1080), "My SFML Window");
    this->_window.setFramerateLimit(60);
    this->_window.setKeyRepeatEnabled(true);
    if (check_lib() > 0)
        std::cout << "Load SFML librairie : failed" << std::endl;
}

sfml::~sfml()
{
    this->_window.close();
}

// // WINDOW//

void sfml::init()
{

}

void sfml::update()
{
    _window.display();
}

void sfml::stop()
{
    this->_window.clear(sf::Color::Black);
}

// void sfml::create_window()
// {
//     // this->_window.create(sf::VideoMode(1920, 1080), "My SFML Window");
//     this->_window.create(sf::VideoMode(1900, 1080), "My SFML Window");
// }

// void sfml::close_window()
// {
//     this->_window.close();
// }

// // DISPLAY //
sf::Sprite sfml::char_to_sprite(char c)
{
    switch (c) {
        case '*':
            this->_texture.loadFromFile("sprite_a.png");
            this->_sprite.setTexture(_texture);
            this->_window.draw(_sprite);
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
        case ' ':
            //BG //
            break;
        default:
            Error::err_("Invalid map");
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
        while (this->_window.pollEvent(_event))
        {
            if (_event.type == sf::Event::Closed) {
                this->_window.close();
                exit (0);
            }
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Space) {
                std::cout << "space" << std::endl;
                return IDisplayModule::Input::SPACE;
            }
        }
    return IDisplayModule::NONE;
}

bool sfml::gameOver()
{
    return false;
}

bool sfml::isOpen()
{
    return this->_window.isOpen();
}