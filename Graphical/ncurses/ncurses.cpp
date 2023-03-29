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

extern "C" void initNcurses()
{
    printf("[ncurses] Loading Snake library...\n");
}

extern "C" void closeNcurses()
{
    printf("[ncurses] Snake closing.\n");
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
    nodelay(stdscr, true);
    curs_set(0);
    ncurses::init_color();
    noecho();
    keypad(stdscr, true);
    ncurses::is_Open = true;
}


// //DISPLAY//

void ncurses::display_board(int **board, std::map<int, char> tab_conversion)
{
    int h = 20;
    int w = 20;

    clear();
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            int value = board[i][j];
            char character = tab_conversion[value];
            mvaddch(i, j, character);
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
    if (getch() == KEY_UP)
        return IDisplayModule::Input::UP;
    else if (getch() == KEY_DOWN)
        return IDisplayModule::Input::DOWN;
    else if (getch() == KEY_LEFT)
        return IDisplayModule::Input::LEFT;
    else if (getch() == KEY_RIGHT)
        return IDisplayModule::Input::RIGHT;
    else if (getch() == 10)
        return IDisplayModule::Input::ENTER;
    else if (getch() == 32)
        return IDisplayModule::Input::SPACE;

    return ncurses::IDisplayModule::Input::SPACE;
}
