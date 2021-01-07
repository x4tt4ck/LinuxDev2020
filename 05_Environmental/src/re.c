#include "pcre.h"

#define DX 3

void 
update(WINDOW *win)
{
    box(win, 0, 0);
    wrefresh(win);
}

void 
clear_win(WINDOW *win)
{
    werase(win);
    update(win);
}

int
main()
{
    WINDOW *winRe, *winIn, *winOut;
    char regex[128], str[128];

    setlocale(LC_ALL, "");

    initscr();
    cbreak();
    printw("Input:");
    refresh();

    winRe = newwin(DX, (COLS-2*DX)/2, DX, DX);
    winIn = newwin(DX, (COLS-2*DX)/2, DX, DX + (COLS-2*DX)/2);
    winOut = newwin(LINES - DX*3, COLS - 2*DX, 2*DX, DX);

    keypad(winRe, TRUE);
    keypad(winIn, TRUE);
    scrollok(winOut, TRUE);

    wmove(winRe, 1, 0);
    
    update(winRe);
    update(winIn);
    update(winOut);

    do {
        clear_win(winRe);
        clear_win(winIn);

        mvwgetnstr(winRe, 1, 1, regex, 128);
        werase(winIn);
        update(winIn);
        
        mvwgetnstr(winIn, 1, 1, str, 128);

        wprintw(winOut, " Entered: %s : %s\n", regex, str);
        pcre(winOut, regex, str);
        clear_win(winRe); 
        clear_win(winIn);
        update(winOut);
    } while (*regex);

    endwin();
}
