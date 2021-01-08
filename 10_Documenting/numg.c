/** @file */

#include <stdio.h>
#include <libintl.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"
#include "toroman.h"

#define _(STRING) gettext(STRING)

#define MANUAL _("Simple number guesser \n\
\n\
Usage: ./numg [OPTIONS] \n\
\n\
    --help    display this help \n\
    --version display version \n\
    -r        use roman numbers instead arabic \n")

/**
 * Get @p Roman corresponding to @p x and return it
 * @param x int from 1 to 100
 */
char *
toRoman(int x)
{
    return Roman[x];
}

/**
 * Play the game against PC. It will guess a number from 1 to 100.
 * Program output is written in @p en_US and @p ru_RU.
 * To run russian version run with @p LOCALE=ru_RU environment variable.
 * Function main receives 1 input parameter in @p argv.
 * @param -r toggle roman numbers ( @p argv[1] ).
 */
int
main(int argc, char **argv)
{
    int romanflag = 0;
    if(argc == 2) {
        if(!strcmp(argv[1], "--help")) {
            return !printf(MANUAL);
        } else if(!strcmp(argv[1], "--version")) {
            return !printf("%s\n", VERSION);
        } else if(!strcmp(argv[1], "-r")) {
            romanflag = 1;
        }
    }

    int left = 1, right = 100, flag;
    setlocale (LC_ALL, "");
    bindtextdomain ("numg", ".");
    textdomain ("numg");
    printf(_("I will guess the number X from 1 to 100.\n"));

    char buf[64];
    while(left < right) {
        sprintf(buf, "%d", (left+right)/2);
        printf(_("X > %s? "), romanflag ? toRoman((left + right)/2) : buf);
        scanf("%d", &flag);
        if(flag) {
        	left = (left + right) / 2 + 1;
        } else {
            right = (left + right) / 2;
        }
    }

    sprintf(buf, "%d", right);
    printf(_("I guessed. Number is %s, right?\n"), romanflag ? toRoman(right) : buf);
    return 0;
}
