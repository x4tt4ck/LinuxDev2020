#include <ncurses.h>
#include <stdlib.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);
void get_file_size(const char* path, int* lines, int* size);
char** get_storage(int lines, int w);
void read_file(char** storage, int l, int w, const char* path);
void print_file(int head, int starty, int startx, int height, char** storage, int lines);

int
main(int argc, char **argv)
{
    if(argc != 2) {
        printf("usage: %s FILE\n", argv[0]);
        return 1;
    }

    WINDOW *my_win;
    int startx, starty, width, height, ch, lines, size;
    char** storage;
    int head = 0;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    height = 46;
    width = 92;
    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;

    get_file_size(argv[1], &lines, &size);
    storage = get_storage(lines, width-1);
    read_file(storage, lines, width-2, argv[1]);

    printw("File: %s\nLines: %d\nSize: %d", argv[1], lines, size);
    refresh();
    my_win = create_newwin(height, width, starty, startx);

    print_file(head, starty+1, startx+1, height-2, storage, lines);

    while((ch = getch()) != '\x1b') {
        switch(ch) {
            case ' ':
                if (head + height - 2 != lines) {
                    ++head;
                }
                destroy_win(my_win);
                my_win = create_newwin(height, width, starty, startx);
                print_file(head, starty+1, startx+1, height-2, storage, lines);
                break;
        }
    }

    endwin();
}

WINDOW
*create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;
    local_win = newwin(height, width, starty, startx);
    box(local_win, 0, 0);
    wrefresh(local_win);
    return local_win;
}

void
destroy_win(WINDOW *local_win)
{
    wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(local_win);
    delwin(local_win);
}

void
get_file_size(const char* path, int* lines, int* size)
{
    int s = 0, l = 0;
    char ch;
    FILE *fp = fopen(path, "r");
    if(!fp) {
        printf("WOW WTF\n");
        return;
    }
    while(TRUE) {
        ch = fgetc(fp);
        if(ch == EOF) {
            break;
        } else if(ch == '\n') {
            l++;
        }
        s++;
    }
    *lines = l;
    *size = s;
    fclose(fp);
}

char**
get_storage(int lines, int w)
{
    char **storage = (char **)malloc(lines * sizeof(char *));
    for(int i = 0; i < lines; ++i) {
        storage[i] = (char *)malloc(w * sizeof(char));
    }
    return storage;
}

void
read_file(char **storage, int l, int w, const char* path)
{
    char ch;
    FILE *fp = fopen(path, "r");
    if(!fp) {
        printf("WOW WTF\n");
        return;
    }

    for(int i = 0; i < l; ++i) {
        for(int j = 0; j < w; ++j) {
            ch = fgetc(fp);
            if(ch == EOF || ch == '\n') {
                storage[i][j] = 0;
                break;
            } else {
                storage[i][j] = ch;
            }
        }
        storage[i][w] = 0;
    }

    fclose(fp);
}

void
print_file(int head, int starty, int startx, int height, char **storage, int lines)
{
    for(int i = head, j = 0; i < lines; ++i, ++j) {
        if(i == height+head) {
            break;
        }
        mvprintw(starty+j, startx, "%s", storage[i]);
    }
}
