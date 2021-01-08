#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "namegen.h"

#define MAXLEN 64
char name[MAXLEN];

int
main(int argc, char **argv)
{
    unsigned long seed;
    char *pattern;

    pattern = (argc > 1 && argv[1][0]) ? argv[1] : "!sV'i";
    seed = argc > 2? atol(argv[2]) : time(NULL);
    srandom(seed);
    namegen(name, sizeof(name), pattern, &seed);
    puts(name);
    return 0;
}
