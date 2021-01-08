/* COMMENT:: InteractivRE, 1.0: Fri Jan  8 14:48:29 MSK 2021 */
#ifndef PCRE2_CODE_UNIT_WIDTH
   #define PCRE2_CODE_UNIT_WIDTH 8
#endif

#include <ncurses.h>
#include <pcre2.h>
#include <string.h>
#include <locale.h>
#include "config.h"

void pcre(WINDOW *, char *, char *);
