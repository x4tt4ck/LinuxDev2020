#include <stdio.h>

void f()
{
    int j=20;
    int* a = &j;
    *(a+12)+=7;
    *(a+12+4)+=7;
    *(a+12+8)+=7;
    *(a+12+12)+=7;
    *(a+12+16)+=7;
    *(a+12+20)+=7;
    *(a+12+24)+=7;
}

int main()
{
    int i;
    i=20;
    printf("\n i = %d \n", i);
    f();
    printf("\n i = %d \n", i);
    return 0;
}

/*
  j+0   00000014h
  j+4   Saved EBP
  j+8   ret
  j+12  ???
  j+16  ???
  j+20  ???


*/
