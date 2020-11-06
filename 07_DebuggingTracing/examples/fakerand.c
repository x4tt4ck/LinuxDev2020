#define _GNU_SOURCE
#include <stdlib.h>
#include <dlfcn.h>

typedef int (* intvoid)(void);

int rand(void) {
    intvoid oldrand;
    if(getenv("NORAND"))
        return 42;
    // return rand(); not good!
    oldrand = dlsym(RTLD_NEXT, "rand");
    return oldrand();
}
