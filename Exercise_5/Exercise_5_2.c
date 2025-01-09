#define MAXLINE 1000
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);
float getfloat(float *);

#define SIZE 100
int main()
{
    int n, array[SIZE];
    float f_array[SIZE];
    for (n = 0; n < SIZE && getfloat(&f_array[n]) != EOF; n++)
        printf("%g", f_array[n]);
        ;
}

float getfloat(float *pn) {
    float c, sign, digits, pow10;
    float f, frac;

    while (isspace(c = getch())) /* skip white space */
        ;

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    if (!isdigit(c)) {
        ungetch(c);
        return 0;
    }

    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');

    if (c == '.')
        c = getch();

    // factional part
    for (frac = 1.0; isdigit(c); c = getch()) { 
        *pn = 10.0 * *pn + (c - '0');
        frac *= 10.0;
    }


    if (c != EOF) {
        ungetch(c);
    }

    *pn *= (sign / frac);

    return c;
}

/* getint:  get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch())) /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c); // Push back the character read after sign
            ungetch((sign == -1) ? '-' : '+'); // Push back the sign
            return 0; // Not a valid number
        }
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    }
        
    return c;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}