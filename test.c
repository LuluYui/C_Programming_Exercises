#define MAXLINE 1000
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
main()
{
    
    char l[SIZE] = "heo\0 abc";

    // char *p = l + strlen(l);
    printf("%lu", strlen(l));
}