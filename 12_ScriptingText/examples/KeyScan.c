#include <ncurses.h>
#include <unistd.h>
#include <error.h>
#include "config.h"

#define DX 3

void
main()
{
    WINDOW *win;
    int c = 0;

    if(!isatty(0)) {
        error(1, 0, "Not a tty");
    }

    initscr();
    noecho();
    cbreak();
    printw("Window:");
    refresh();

    win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);
#ifdef KEYPAD
    keypad(win, TRUE);
#else
    keypad(win, FALSE);
#endif
    scrollok(win, TRUE);
    do {
        wprintw(win, " Key: %d, Name: %s\n", c, keyname(c));
        box(win, 0, 0);
        wrefresh(win);
    } while((c = wgetch(win)) != 27);

    endwin();

}
