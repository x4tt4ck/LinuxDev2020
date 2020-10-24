#include <stdio.h>

extern int N;
void fun(char *);

int
main(int argc, char *argv[])
{
    N = 5;
    fun("Hello, world");
    return 0;
}
