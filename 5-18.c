<<<<<<< HEAD
#include <string.h>
#include <ctype.h>

#define NUMERIC  1  /* numeric sort */
#define DECR    2   /* sort in decreasing order */
#define FOLD    4   /* fold upper and lower case */
#define MDIR    8   /* directory order */
#define LINES   100 /* maximum number of lines to be sorted */

int main(int argc, char *argv[]) 
{

}

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;

    if (c != EOF)
        *w++ = c;

    if (!isalpha(c)) {
        *w = '\0';
        return c; 
    }
    
    for ( ; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
        ungetch(*w);
        break; 
    }
    *w = '\0';
    return word[0];
=======
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype;

/* type of last token */
char token[MAXTOKEN];
/* last token string */
char name[MAXTOKEN];
/* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000];

int main() /* convert declaration to words */
{
  while (gettoken() != EOF) {
    /* 1st token on line */
    strcpy(datatype, token); /* is the datatype */
    out[0] = '\0';
    dcl();

    /* parse rest of line */
    if (tokentype != '\n')
      printf("syntax error\n");
      printf("%s: %s %s\n", name, out, datatype);
    }

    return 0;
}

/* dcl: parse a declarator */
void dcl(void)
{
  int ns;

  for (ns = 0; gettoken() == '*'; ) /* count *'s */
    ns++;

  dirdcl();
  while (ns-- > 0)
    strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
  int type;
  if (tokentype == '(') {
    /* ( dcl ) */
    dcl();
    if (tokentype != ')')
      printf("error: missing \")\"\n");
  } else if (tokentype == NAME) /* variable name */
    strcpy(name, token);
  else
    printf("error: expected name or (dcl)\n");

  while ( (type=gettoken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
      strcat(out, " function returning");
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
}

int gettoken(void) /* return next token */
{
  int c, getch(void);
  void ungetch(int);
  char *p = token;

  while ((c = getch()) == ' ' || c == '\t')
    ;

  if (c == '(') {
    if ((c = getch()) == ')') {
    strcpy(token, "()");
    return tokentype = PARENS;
    } else {
    ungetch(c);
    return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']'; )
      ;
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch()); )
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else
    return tokentype = c;
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
>>>>>>> origin/main
}