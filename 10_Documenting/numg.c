#include <stdio.h>
#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

int
main()
{
    int left = 1, right = 100, flag;
    setlocale (LC_ALL, "");
    bindtextdomain ("numg", ".");
    textdomain ("numg");
    printf(_("I will guess the number X from 1 to 100.\n"));

    while(left < right) {
        printf(_("X > %d? "), (left + right)/2);
        scanf("%d", &flag);
        if(flag) {
        	left = (left + right) / 2 + 1;
        } else {
            right = (left + right) / 2;
        }
    }

    printf(_("I guessed. Number is %d, right?\n"), right);
    return 0;
}
