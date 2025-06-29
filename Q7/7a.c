//7.a) Write a C program to illustrate the effect of setjmp and longjmp
//functions on register and volatile variables

#include<setjmp.h>
#include<stdio.h>

static jmp_buf jb;
static int si=1;

int main()
{
        static int sv=2;
        int av=3;
        register int rv=4;
        volatile int vv=5;

        if(setjmp(jb)){
                printf("After longjump:\n");
                printf("si=%d, sv=%d, av=%d, rv=%d, vv=%d",si,sv,av,rv,vv);
                return 0;
        }

        si=95;
        sv=96;
        av=97;
        rv=98;
        vv=99;

        printf("Before longjump:\n");
        printf("si=%d, sv=%d, av=%d, rv=%d, vv=%d\n",si,sv,av,rv,vv);

        longjmp(jb,1);
        return 0;
}

/*setjmp/longjmp Variable Behavior Explained
Initial Values:
si = 1;     // static global
sv = 2;     // static local
av = 3;     // auto (local)
rv = 4;     // register
vv = 5;     // volatile

Flow:
setjmp(jb) saves control flow, not variable values.
Variables are updated:
si = 95; sv = 96; av = 97; rv = 98; vv = 99;
longjmp(jb, 1) jumps back to setjmp().

After longjmp():
si = 95 ✅ (static global → preserved)
sv = 96 ✅ (static local → preserved)
av = 97 ✅ (auto → may or may not be preserved)
rv = 4  ❌ (register → usually lost)
vv = 99 ✅ (volatile → preserved due to memory access)

Summary:
setjmp/longjmp affect control flow, not variable memory.
Only static, global, and volatile variables are guaranteed to retain changes 
and keep the new values after longjmp(), while register variable rv loses the new value and resets back to the original 4. */


