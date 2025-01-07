#define MAXLINE 1000
#include <stdio.h>
#include <string.h> 
#include <ctype.h>


char *c;

int readl(char *buf);

#define SIZE 100
main()
{
    char s[SIZE];
    char p[SIZE];
    
    readl(p);

    printf("%s \n", p);

    return 0; 
}