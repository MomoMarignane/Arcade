/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** lib.c
*/

#include <stdio.h>
#include "snake.hpp"
#include <unistd.h>

void initSnake() __attribute__((constructor));
void closeSnake() __attribute__((destructor));
extern "C" arc::IGameModule *entryPoint();

void initSnake()
{
    // printf("[libSnake] Loading Snake library...\n");
}

void closeSnake()
{
    // printf("[libSnake] Snake closing.\n");
}

extern "C" arc::IGameModule *entryPoint()
{
    // printf("[libSnake] entry point !\n");
    return new snake();
}

void snake::char_to_object(board *board, char ptrChar, int x, int y)
{
    if (ptrChar == 'O') {
        board->_Object.push_back(arc::Obj("SnakeHeadUp", SnakeHeadUp, x, y));
    }
    if (ptrChar == 'R') {
        board->_Object.push_back(arc::Obj("SnakeHeadRight", SnakeHeadRight, x, y));
    }
    if (ptrChar == 'L') {
        board->_Object.push_back(arc::Obj("SnakeHeadLeft", SnakeHeadLeft, x, y));
    }
    if (ptrChar == 'D') {
        board->_Object.push_back(arc::Obj("SnakeHeadDown", SnakeHeadDown, x, y));
    }
    if (ptrChar == 'o') {
        board->_Object.push_back(arc::Obj("SnakeBody", SnakeBody, x, y));
    }
    if (ptrChar == ' ') {
        board->_Object.push_back(arc::Obj("SnakeBG", SnakeBG, x, y));
    }
    if (ptrChar == '#') {
        board->_Object.push_back(arc::Obj("SnakeWall", SnakeWall, x, y));
    }
    if (ptrChar == '+') {
        board->_Object.push_back(arc::Obj("SnakeFood1", SnakeFood1, x, y));
    }
    if (ptrChar == '-') {
        board->_Object.push_back(arc::Obj("SnakeFood2", SnakeFood2, x, y));
    }
    if (ptrChar == '*') {
        board->_Object.push_back(arc::Obj("SnakeFood3", SnakeFood3, x, y));
    }

}

void snake::init(board *board)
{
    // RAPH //
    char ptrChar;
    int pos_x = 0;
    int pos_y = 0;
    
    board->_Object.clear();
    for (int i = 0; i < board->boardMap.size(); i++) {
        pos_x = 0;
        for (int j = 0; j < (board->boardMap[i].size() + 2); j++) {
            ptrChar = board->boardMap[i][j];
            char_to_object(board, ptrChar, pos_x, pos_y);
            pos_x += 50;
        }
        pos_y += 50;
    }
    // - - - //
    _life = 3;
    _score = 0;
    for (int i = 0; i < 5; i += 1)
        _lifeMob.push_back(2);
    xPos = 10;
    yPos = 6;
    // printf("initied\nSNAKE\n__\n");
}

bool snake::gameOver()
{
    return this->gameOver_;
}

void snake::deleteTail(board* board, int x, int y)
{
    int r = 0, l = 0, u = 0, d = 0;
    bool tail = false;
    while (!tail) {
        if (board->boardMap[x][y+1] == 'o' && l == 0) {
            r += 1;
            u = 0, d = 0;
            if (board->boardMap[x+1][y] == 'o' && l == 0)
                d += 1;
            if (board->boardMap[x-1][y] == 'o' && l == 0)
                u += 1;
            y += 1;
        } else if (board->boardMap[x][y-1] == 'o' && r == 0) {
            l += 1;
            u = 0, d = 0;
            if (board->boardMap[x+1][y] == 'o' && l == 0)
                d += 1;
            if (board->boardMap[x-1][y] == 'o' && l == 0)
                u += 1;
            y -= 1;
        } else if (board->boardMap[x+1][y] == 'o' && u == 0) {
            d += 1;
            l = 0, r = 0;
            if (board->boardMap[x][y+1] == 'o' && l == 0)
                l += 1;
            if (board->boardMap[x][y-1] == 'o' && l == 0)
                r += 1;
            x += 1;
        } else if (board->boardMap[x-1][y] == 'o' && d == 0) {
            u += 1;
            l = 0, r = 0;
            if (board->boardMap[x][y+1] == 'o' && l == 0)
                l += 1;
            if (board->boardMap[x][y-1] == 'o' && l == 0)
                r += 1;
            x -= 1;
        } else {
            tail = true;
        }
    }
    board->boardMap[x][y] = ' ';
}

void snake::collision()
{
    this->gameOver_ = true;
}

void snake::moveUp(board* board)
{
    bool deleteTail = true;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'O' || board->boardMap[i][j] == 'R' || board->boardMap[i][j] == 'L' || board->boardMap[i][j] == 'D') {
                this->xPos = i;
                this->yPos = j;
            }
        }
    if (board->boardMap[this->xPos-1][this->yPos] == 'o' || board->boardMap[this->xPos-1][this->yPos] == '#') {
        this->collision();        
    } else if (board->boardMap[this->xPos-1][this->yPos] == '+' || board->boardMap[this->xPos-1][this->yPos] == '-' || board->boardMap[this->xPos-1][this->yPos] == '*') {
            deleteTail = false;
    }
    board->boardMap[this->xPos][this->yPos] = 'o';
    board->boardMap[this->xPos-1][this->yPos] = 'O';
    if (deleteTail)
        this->deleteTail(board, this->xPos, this->yPos);
}

void snake::moveRight(board* board)
{
    bool deleteTail = true;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'O' || board->boardMap[i][j] == 'R' || board->boardMap[i][j] == 'L' || board->boardMap[i][j] == 'D') {
                this->xPos = i;
                this->yPos = j;
            }
        }
    if (board->boardMap[this->xPos][this->yPos+1] == 'o' || board->boardMap[this->xPos][this->yPos+1] == '#') {
        this->collision();
    } else {
        if (board->boardMap[this->xPos][this->yPos+1] == '+' || board->boardMap[this->xPos][this->yPos+1] == '-' || board->boardMap[this->xPos][this->yPos+1] == '*')
            deleteTail = false;
        board->boardMap[this->xPos][this->yPos] = 'o';
        board->boardMap[this->xPos][this->yPos+1] = 'R';
    }
    if (deleteTail)
        this->deleteTail(board, this->xPos, this->yPos);
}

void snake::moveLeft(board* board)
{
    bool deleteTail = true;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'O' || board->boardMap[i][j] == 'R' || board->boardMap[i][j] == 'L' || board->boardMap[i][j] == 'D') {
                this->xPos = i;
                this->yPos = j;
            }
        }
    if (board->boardMap[this->xPos][this->yPos-1] == 'o' || board->boardMap[this->xPos][this->yPos-1] == '#') {
        this->collision();
    } else {
        if (board->boardMap[this->xPos][this->yPos-1] == '+' || board->boardMap[this->xPos][this->yPos-1] == '-' || board->boardMap[this->xPos][this->yPos-1] == '*')
            deleteTail = false;
        board->boardMap[this->xPos][this->yPos] = 'o';
        board->boardMap[this->xPos][this->yPos-1] = 'L';
    }
    if (deleteTail)
        this->deleteTail(board, this->xPos, this->yPos);
}

void snake::moveDown(board* board)
{
    bool deleteTail = true;
    for (int i = 0; i < board->boardMap.size(); i += 1)
        for (int j = 0; j < board->boardMap[i].size(); j += 1) {
            if (board->boardMap[i][j] == 'O' || board->boardMap[i][j] == 'R' || board->boardMap[i][j] == 'L' || board->boardMap[i][j] == 'D') {
                this->xPos = i;
                this->yPos = j;
            }
        }
    if (board->boardMap[this->xPos+1][this->yPos] == 'o' || board->boardMap[this->xPos+1][this->yPos] == '#') {
        this->collision();
    } else {
        if (board->boardMap[this->xPos+1][this->yPos] == '+' || board->boardMap[this->xPos+1][this->yPos] == '-' || board->boardMap[this->xPos+1][this->yPos] == '*')
            deleteTail = false;
        board->boardMap[this->xPos][this->yPos] = 'o';
        board->boardMap[this->xPos+1][this->yPos] = 'D';
    }
    if (deleteTail)
        this->deleteTail(board, this->xPos, this->yPos);
}

void snake::update(arc::Input key, board* board)
{
    srand(time(NULL));
    int Xrand = rand() % 19 + 2;
    int Yrand = rand() % 19 + 2;
    int timeRand = rand() % 6 + 1;
    int foodRand = rand() % 3 + 1;
    if (timeRand == 5 && board->boardMap[Xrand][Yrand] == ' ') {
        switch (foodRand) {
            case 1 : board->boardMap[Xrand][Yrand] = '+';
                break;
            case 2 : board->boardMap[Xrand][Yrand] = '-';
                break;
            case 3 : board->boardMap[Xrand][Yrand] = '*';
                break;
            default:
                break;
        }
    }
    if (key == arc::Input::UP)
        this->moveUp(board);
    if (key == arc::Input::RIGHT)
        this->moveRight(board);
    if (key == arc::Input::DOWN)
        moveDown(board);
    if (key == arc::Input::LEFT)
        moveLeft(board);
    board->_Object.clear();

    char ptrChar;
    int pos_x = 0;
    int pos_y = 0;
    
    for (int i = 0; i < board->boardMap.size(); i++) {
        pos_x = 0;
        for (int j = 0; j < (board->boardMap[i].size() + 2); j++) {
            ptrChar = board->boardMap[i][j];
            char_to_object(board, ptrChar, pos_x, pos_y);
            pos_x += 50;
        }
        pos_y += 50;
    }
}
