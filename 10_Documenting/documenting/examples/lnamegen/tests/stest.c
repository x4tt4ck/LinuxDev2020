/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "stest.ts" instead.
 */

#include <check.h>

#line 1 "stest.ts"
#include "namegen.h"

#define MAXLEN 64
char name[MAXLEN];
unsigned long seed = 42;

START_TEST(stest)
{
#line 9
    namegen(name, sizeof(name), "!sV'i", &seed);
    ck_assert_str_eq(name, "Turou'twerp");

}
END_TEST

START_TEST(alter)
{
#line 13
    namegen(name, sizeof(name), "!<D|B>Vs (from|of) Bs", &seed);
    ck_assert_str_eq(name, "Peeem from cach");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Fixed");
    TCase *tc1_1 = tcase_create("Fixed");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, stest);
    tcase_add_test(tc1_1, alter);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}