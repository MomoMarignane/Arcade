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

//CONSTRUCOT DESTRUCTOR//

ncurses::ncurses()
{
    initscr();
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    this->is_Open = true;
    curs_set(0);

    init_color();
}

ncurses::~ncurses()
{
    endwin();
}


//INIT NCURSES ELEMENT //

void ncurses::init_color()
{
    if (!has_colors()) {
        // la console ne supporte pas les couleurs
        return;
    }

    start_color();  // initialisation des couleurs
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

//WINDOW//

void ncurses::init()
{
    ncurses::display_text("MENU", 10, 10);
    // clear();
    const char *titleA = "ARCADE";
    const char *titleS = "[1]Snake";
    const char *titleSF = "[2] -> SolarFOX";
    refresh();

    int menu_height = 10;
    int menu_width = 40;
    int menu_y = LINES / 2 - menu_height / 2;
    int menu_x = COLS / 2 - menu_width / 2;

    mvprintw(menu_y, menu_x, "########################################");
    mvprintw(menu_y + menu_height - 1, menu_x, "########################################");
    mvprintw(menu_y + menu_height / 2, COLS / 2 - 4, titleA);

    int sB_y = menu_y + menu_height / 2 - 2;
    int pB_y = menu_y + menu_height / 2 + 2;
    int B_width = 20;
    int B_x = menu_x + menu_width / 2 - B_width / 2;

    mvprintw(sB_y, B_x, titleS);
    mvprintw(pB_y, B_x, titleSF);
    // refresh(); // rafraîchissement de l'écran
}

void ncurses::update()
{
    wrefresh(stdscr);
}

void ncurses::stop()
{
    wclear(stdscr);
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

void ncurses::display_text(std::string text, int x, int y)
{
    mvprintw(ncurses::getSizeWindowY() / 2, ncurses::getSizeWindowY() / 2, text.c_str());
}

// EVENT //

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
    // if (c == EOF) {
    //     endwin();
    //     exit(0);
    // }


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

int ncurses::getSizeWindowX()
{
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    return max_x;
}

int ncurses::getSizeWindowY()
{
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    return max_y;
}