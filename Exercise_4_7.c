#include <stdio.h>
#include <stdlib.h>  /* for  atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */
#define VAR '@'
#define VARSET '_'
#define VARGET 'a'

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void swap(void);
void clear(void);
int gets(char line[], int limit);
void ungets(char line[]); // to be written Exec 4-7 tbc


char var = '0';
int varindex = 0;
double varbuf[MAXOP];

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop(); // make sure that it is first - second operand
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2!= 0.0)
                    push(fmod(pop(), op2));
                break;
            case VARSET:
                varbuf[varindex++] = pop();
                printf("variable %c: %.3f\n", 'a' + varindex - 1, varbuf[varindex - 1]);
                break;
            case VARGET:
                if ( var - 'a' <= varindex - 1 )
                {
                    push(varbuf[varindex - 1]);
                } else
                {
                    printf("error: undefined variables \n=");
                }
                break;
            case 'D':
                clear();
                break;
            case 'W':
                swap(); // Exec 4-4: swap the top two elements
                break;
            case 'S': // Exec 4-5 : impl math functions
                push(sin(pop()));
                break;
            case 'E':
                push(exp(pop()));
                break;
            case 'P':
                op2 = pop(); // get the power
                push(pow(pop(), op2));
                break;
            case '\n':
                printf("results \t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;

}


/* getop:  get next character or numeric operand */
int getop(char s[])
{
    int i=0, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    // skipped all spaces

    if (islower(c))
    {
        var = c;
        return VARGET;
    }

    if (c == '-') {
        s[++i] = c = getch();
        if (!isdigit(c) && c != '.') {
            ungetch(c);
            s[i--] = '\0';
            c = s[i];
            return c;
        }
    }

    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    if (isdigit(c))    /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')      /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;

    // Return special operations
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}


#define MAXVAL  100  /* maximum depth of val stack */
int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */
/* push:  push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */

void swap(void) {
    if (sp > 1) {
        double temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    } else
        printf("%s", "error: less than 2 elements in stack\n");
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        return 0.0;
    }
}


void clear(void) {
    if (sp > 0)
        sp=0;
    else
        printf("%s", "error: stack already empty");
}


#define BUFSIZE 1
char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void)  /* get a (possibly pushed-back) character */
{
    int tmp;
    tmp = (bufp > 0) ? buf[--bufp] : getchar();
    if (feof(stdin))
    {
      puts("EOF entered, programme abort");
      return EOF;
    }
    else
      return tmp;
}

void ungetch(int c)   /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else if (c == EOF)
      printf("error: an EOF is caught on input, ignoring");
    else
        buf[bufp++] = c;
}

void ungets(char *s)
{
    int i=0;

    while (*s++ != '\n')
    {
      i++;
    }

    s-= (2 + i - 1);

    while(i)
    {
      ungetch(s[--i]);
    }

}

int gets(char *s, int limits)
{
  int c, i;

  for (i=0; i < limits && (c = getch()) != EOF && c != '\n'; i++)
    s[i] = c;

  if( c == '\n')
    s[i++] = c;

  s[i] = '\0';

  return 1;
}
