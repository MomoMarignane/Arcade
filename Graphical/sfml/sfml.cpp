/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** sfml.cpp
*/

#include "sfml.hpp"

extern "C" void initSfml() __attribute__ ((constructor));
extern "C" void closeSfml() __attribute__ ((destructor));
extern "C" arc::IDisplayModule *entryPoint();

// MANAGE LIBRAIRIE //

extern "C" void initSfml()
{
    // printf("[sfml] Loading sfml library...\n");
}

extern "C" void closeSfml()
{
    // printf("[sfml] sfml closing.\n");
}

extern "C" arc::IDisplayModule *entryPoint()
{
    // printf("[sfml] entry point !\n");
    return new sfml();
}

// CONSTRUCTOR DESTRUCTOR //

int check_lib()
{
    return 0;
}

sfml::sfml()
{
    this->_window.create(sf::VideoMode(1920, 1080), "My SFML Window", sf::Style::Close);
    this->_window.setFramerateLimit(60);
    this->_window.setKeyRepeatEnabled(true);
    // this->_music.setLoop(false);
    // this->_music.stop();
    if (check_lib() > 0)
        std::cout << "Load SFML librairie : failed" << std::endl;
}

sfml::~sfml()
{
    this->_window.close();
}

// WINDOW//

void sfml::init()
{
    sf::Vector2u windowSize = this->_window.getSize();
    sf::FloatRect spriteBounds = this->_sprite.getLocalBounds();
    float windowMidX = windowSize.x / 2.0f;
    float windowMidY = windowSize.y / 2.0f;
    float spriteMidX = spriteBounds.width / 2.0f;
    float spriteMidY = spriteBounds.height / 2.0f;
    float spritePosX = windowMidX - spriteMidX;
    float spritePosY = windowMidY - spriteMidY;


    if (!this->_texture.loadFromFile("Graphical/assets/arcadeMenu.png") || !this->_TSnakeB.loadFromFile("Graphical/assets/snakeButton.png") 
    || !this->_TsolarFoxB.loadFromFile("Graphical/assets/solarFoxButton.png") || !this->_bgText.loadFromFile("Graphical/assets/backBGmenu.jpg")) {
        std::cerr << "Erreur load sprite" << std::endl;
        exit(84);
    }

    this->_window.clear();
    // this->_music.setVolume(100);
    // this->_music.setLoop(true);
    // this->_music.play();
    // if (this->_music.getStatus() != sf::SoundSource::Status::Playing) {
    //     exit(84);
    // }
    // SET BG menu
    this->_menuBgSprite.setTexture(this->_bgText);
    this->_window.draw(this->_menuBgSprite);
    sf::Vector2i vector = {sfml::getSizeWindowX(), sfml::getSizeWindowY()};
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setPosition(spritePosX, spritePosY);
    this->_window.draw(this->_sprite);
    //SET SNAKE BUTTON
    this->_SsnakeB.setTexture(this->_TSnakeB);
    this->_SsnakeB.setPosition(720, 350);
    this->_window.draw(this->_SsnakeB);
    //SET SOLARFOX BUTTON
    this->_SsolarFoxB.setTexture(this->_TsolarFoxB);
    this->_SsolarFoxB.setPosition(980, 350);
    this->_window.draw(this->_SsolarFoxB);
}

void sfml::update()
{
    _window.display();
}

void sfml::stop()
{
    this->_window.clear(sf::Color::Black);
}
// DISPLAY //
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

void sfml::display_text(std::string text, int x, int y)
{

}

// EVENT //


arc::Input sfml::handle_key()
{
    _window.display();
        while (this->_window.pollEvent(_event))
        {
            if (_event.type == sf::Event::Closed) {
                this->_window.close();
                exit (0);
            }
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Space) {
                return arc::Input::SPACE;
            }
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::G) {
                return arc::Input::nextLib;
            }
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Num1) {
                return arc::Input::StartSnake;
            }
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Num2) {
                return arc::Input::StartSfox;
            }
        }
    return arc::Input::NONE;
}

bool sfml::gameOver()
{
    return false;
}

bool sfml::isOpen()
{
    return this->_window.isOpen();
}

//WSIZE//

int sfml::getSizeWindowX()
{
    int windowSize = this->_window.getSize().x;
    return windowSize;
}

int sfml::getSizeWindowY()
{
    int windowSize = this->_window.getSize().y;
    return windowSize;
}