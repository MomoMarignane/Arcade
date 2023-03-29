/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-raphael.de-monchy
** File description:
** ncurses.cpp
*/

#include "ncurses.hpp"

extern "C" void initNcurses() __attribute__((constructor));
extern "C" void closeNcurses() __attribute__((destructor));
extern "C" IDisplayModule *entryPoint();

// // MANAGE LIBRAIRIE //


extern "C" void initNcurses()
{
    printf("[ncurses] Loading ncurses library...\n");
}

extern "C" void closeNcurses()
{
    printf("[ncurses] ncurses closing.\n");
}

extern "C" IDisplayModule *entryPoint()
{
    printf("[ncurses] entry point !\n");
    return new ncurses();
}


//INIT NCURSES ELEMENT //

void ncurses::init_color()
{
    if (!has_colors()) {
        // la console ne supporte pas les couleurs
        return;
    }

    start_color();  // initialisation des couleurs

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

// //WINDOW//

void ncurses::create_window()
{
    initscr();
    init_color();
    noecho();
    keypad(stdscr, true);
    is_Open = true;
    curs_set(0);
}


// //DISPLAY//


void ncurses::display_board(std::vector<std::string> board)
{
    clear();
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[i].size(); j++) {
            char ptr = board[i][j];
            mvaddch(i, j, ptr);
        }
    }
    refresh();
}

void ncurses::display_text(std::string text)
{

}

// // EVENT //

void ncurses::update()
{
    wrefresh(stdscr);
}

ncurses::IDisplayModule::Input ncurses::handle_key()
{
    int c = getch();
    if (c == KEY_UP)
        return IDisplayModule::Input::UP;
    if (c == KEY_DOWN)
        return IDisplayModule::Input::DOWN;
    if (c == KEY_LEFT)
        return IDisplayModule::Input::LEFT;
    if (c == KEY_RIGHT)
        return IDisplayModule::Input::RIGHT;
    if (c == 10)
        return IDisplayModule::Input::ENTER;
    if (c == 32) {
        return IDisplayModule::Input::SPACE;
    }
    return ncurses::IDisplayModule::NONE;
}

bool ncurses::gameOver()
{
    return false;
}

bool ncurses::isOpen()
{
    return this->is_Open;
}
