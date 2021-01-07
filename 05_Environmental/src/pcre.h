#ifndef PCRE2_CODE_UNIT_WIDTH
   #define PCRE2_CODE_UNIT_WIDTH 8
#endif

#include <ncurses.h>
#include <pcre2.h>
#include <string.h>
#include <locale.h>
#include "config.h"

void pcre(WINDOW *, char *, char *);
