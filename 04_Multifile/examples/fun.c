#include <stdio.h>

int N, K;
static int M=1;

void
fun(char *str)
{
    printf("!%d/%d: %s!\n", N, M, str);
}
