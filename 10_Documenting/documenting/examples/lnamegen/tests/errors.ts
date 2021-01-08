#include "namegen.h"

#define MAXLEN 64
char name[MAXLEN];
unsigned long seed = 42;

#suite Errors
#test angle_unclosed
    int res;
    res = namegen(name, sizeof(name), "a>", &seed);
    ck_assert_int_eq(res, NAMEGEN_INVALID);

#test parenth_unclosed
    int res;
    res = namegen(name, sizeof(name), "(|", &seed);
    ck_assert_int_eq(res, NAMEGEN_INVALID);
