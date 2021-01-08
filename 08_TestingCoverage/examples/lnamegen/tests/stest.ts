#include "namegen.h"

#define MAXLEN 64
char name[MAXLEN];
unsigned long seed = 42;

#suite Fixed
#test stest
    namegen(name, sizeof(name), "!sV'i", &seed);
    ck_assert_str_eq(name, "Turou'twerp");

#test alter
    namegen(name, sizeof(name), "!<D|B>Vs (from|of) Bs", &seed);
    ck_assert_str_eq(name, "Peeem from cach");
