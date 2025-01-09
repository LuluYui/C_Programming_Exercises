#define MAXLINE 1000
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
main()
{
    char *s;
    int i, c;

    s = "abc";

    while(*s) {
        printf("%d", *s++);
    }
}