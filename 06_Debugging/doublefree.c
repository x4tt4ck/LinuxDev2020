#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    int *df = (int *) malloc(12 * sizeof(int));
    for(int i = 0; i < 12; ++i) {
        df[i] = 0xdeadbeef;
    }
    free(df);
    free(df);
    return 0;
}
