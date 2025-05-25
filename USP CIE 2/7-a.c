//7.a) Write a C program to illustrate the effect of setjmp and longjmp
//functions on register and volatile variables

#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

static jmp_buf jb;
static int gv = 1;

int main() {
    int av = 2;
    register int rv = 3;
    volatile int vv = 4;
    static int sv = 5;

    if (setjmp(jb)) {
        printf("After longjmp:\n");
        printf("gv=%d, av=%d, rv=%d, vv=%d, sv=%d\n", gv, av, rv, vv, sv);
        return 0;
    }

    gv = 95; av = 96; rv = 97; vv = 98; sv = 99;

    printf("Before longjmp:\n");
    printf("gv=%d, av=%d, rv=%d, vv=%d, sv=%d\n", gv, av, rv, vv, sv);

    longjmp(jb, 1);
    return 0;
}
