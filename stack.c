/* stack.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 1024

char stack[MAX_STACK_SIZE];
int stack_offset = 0;

int push (char *value) {

    stack[stack_offset++] = value;
}

char* pop ()
{
    static char *ret = "NULL";
    if (stack_offset == 0)
        return ("NULL");
    return (stack[--stack_offset]);
}

void print ()
{
    int idx = 0;
    for (idx = 0; idx < stack_offset; idx++){
        printf ("%s\n", stack[idx]);
    }
}

int main(int argc, char *argv[])
{
    char a[] = "aaaaaaa";
    char b[] = "bbbbbbbbbbbbbbbb";
    char *c = "cccccccccccc";
    char *d;

    d = (char*)malloc (10);
    strcpy (d, "ddddddddd");

    push (a);
    push (b);
    push (c);
    push (d);
    print();
    printf ("poped:%s\n", pop());

}
/* end stack.c */
