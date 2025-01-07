#include <stdio.h>


void strcat(char [], char []);
void strcat_p(char *, char *);
int strend(char *, char *);

int main() {
    char s[] = "hello world";
    char t[] = " programming";
    strcat_p(s,t);

    printf("%d", s[-1]);
    printf("%s \n", s);
    
    char p[] = " world";

    printf("%s \n", p);
    printf("%d \n", strend(s, p));
    
    return 0;
}

int strend(char *s, char *t) {
    while (*s++ != '\0')
        ;
    while (*s-- != '\n')
        ;

    while (*t++ != '\0')
        ;
    while (*t-- != '\n')
        ;
    
    t--;s--;
    printf("s: %d, t: %d \n", *s, *t);
    
    while ((*s-- == *t--) != '\0')
        if (*t == '\0')
            return 1;

    return 0;
}

void strcat_p(char *s, char *t)
{
    while ( *s != '\0') 
        s++;

    while ((*s++ = *t++) != '\0') 
        ;
}

/* strcat:  concatenate t to end of s; s must be big enough */
void strcat(char s[], char t[])
{
 
    int i, j;
    i = j = 0;
    while (s[i] != '\0') /* find end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ; 
}