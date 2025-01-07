#include <stdio.h>
#define MAX 100

int strncpy(char *, char *, int n );

int strncat(char *, char *);
char *strncmp(char *, char *, int);

int main() {
    char s[] = "Hello       ";
    char t[] = "Hello world";
    
    // int j = strncpy(s,t, MAX);
    //  printf("%d %s\n", j, t);

    int j = strncmp(s,t, MAX);
     printf("%d %s\n", j, s);

}

/* strcmp:  return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp(char *s, char *t, int n)
{
    int i=0;
    for ( ; *s == *t && i++ < n; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int strncpy(char *s, char *t, int n) {
    int i = 0;
    while ((*t++ = *s++) != '\0' && i++ < n)
        if (*t == 0)
            return -1;;

    return 0;
}
