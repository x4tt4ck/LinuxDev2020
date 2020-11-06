#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

typedef int (* intvoid)(int, char *, int);

int
unlinkat(int fd, char *name, int foo)
{
    intvoid oldunlinkat;
    if(strstr(name, "FIX") == NULL) {
        oldunlinkat = dlsym(RTLD_NEXT, "unlinkat");
        return oldunlinkat(AT_FDCWD, name, 0);
    } else {
        return EPERM;
    }
}
