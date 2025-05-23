#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAXLINES 5000     /* max #lines to be sorted */

char *lineptr[MAXLINES];  /* pointers to text lines */
int readlines(char *lineptr[], int nlines, char *);
int readlines_p(char *lineptr[], int nlines, char *);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

#define MAXLEN 1000  /* max length of any input line */

int reverse = 0;
int fold = 0;
int directory = 0;
int df = 0;

int main(int argc, char *argv[])
{
    int nlines;     /* number of input lines read */
    char stored_line[MAXLINES];

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-')
                if (isalpha((++argv[i])[0]))
                {
                    for (int j = 0; argv[i][j] != 0; j++)
                    {
                        switch(argv[i][j])
                        {
                            case 'r':
                                reverse = 1;
                                break;
                            case 'f':
                                fold = 1;
                                break;
                            case 'd':
                                directory = 1;
                                break;
                            case 'D':
                                df = 1;
                                break;
                            default:
                                printf("unknown option: %c\n", argv[i][j]);
                                return 1;
                        }
                    }
                }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES, stored_line)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 1;
    } else {
        printf("error: input too big to sort\n");
        return 0;
    }
}

int getlines(char *, int);
char *alloc(int);

/* readlines:  read input lines */
int readlines(char *lineptr[], int maxlines, char *stored_line)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines=0;
    p = stored_line + strlen(stored_line);

    while ((len = getlines(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (stored_line + MAXLEN - len) < 0)
            return -1;
        else {
            line[len-1] = '\0';  /* delete newline */
            strcpy(p,line);
            lineptr[nlines++] = p;
            p += len; // the pointer has not been moved ...
        }

    return nlines;
}

/* writelines:  write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

/* qsort:  sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)  /* do nothing if array contains */
        return;         /* fewer than two elements */

    swap(v, left, (left + right)/2); // pivot the left to middle
    last = left;

    for (i = left+1; i <= right; i++)
    {
        int recover = 0;

        if (reverse == 0 && strcmp(*v[i] > 96 ? v[i] : v[i] + 32, \
                *v[left] > 96 ? v[left] : v[left] + 32) < 0)
            swap(v, ++last, i);
        else if (reverse == 1 && strcmp(*v[i] > 96 ? v[i] : v[i] + 32, \
                *v[left] > 96 ? v[left] : v[left] + 32) > 0)
            swap(v, ++last, i);

    }
    
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);

}

/* swap:  interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
 /* getline:  read a line into s, return length  */
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

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    // Free memories >= n
    if (allocbuf + ALLOCSIZE - allocp >= n )
        {
            allocp += n;
            return allocp - n;
        } else
            return 0;

}