#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>


#define N 10 
#define MAXLINES 1000 
#define MAXLEN 1000
#define ALLOCSIZE 10000 /* size of available space */


static char allocbuf[ALLOCSIZE]; // storage for alloc
static char *allocp = allocbuf; // next free position

int readlines(char *lineptr[], int nlines);
void writelines(char *[], int );
int getlines(char [], int);

int n = N;
int main(int argc, char *argv[]) {
    int nlines;
    char *lines_ptr[MAXLINES];
    char buffer_m[MAXLEN];
    

    if (argc > 1 && argv[1][0] == '-') 
    {
        n = atoi(++argv[1]);
    }

    if ((nlines = readlines(lines_ptr, MAXLINES)) >= 0)
    {
        writelines(lines_ptr, nlines);
        return 0;
    }
    
    return 0;
}


char *alloc(int n) 
{
    if ( allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    } else 
        return 0;
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int readlines(char *lines_ptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;

    while ((len = getlines(line, MAXLEN)) > 0)
        if (nlines >= maxlines || ( p = alloc(len) ) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lines_ptr[nlines++] = p;
        }

    return nlines;
}
void writelines(char * lines_ptr[], int nlines) {
    int i=0;
    if (n != N) 
    {
        i = nlines - n;
    }

    for (; i < nlines; i++)
        printf("%s \n", lines_ptr[i]);
}

int getlines(char s[],int lim)
{
    int c, i;
    for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}
