#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS, NOENDBRACKET, ARGUMENT};

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
char qualifier[MAXTOKEN];
char arguments[MAXTOKEN];
char out[1000];


/*
1. handle qualifier Ok
2. handle argument type in function 
3. handle complex datatype, be it object, struct or whatever NA
4. handle spurios blanks OK
5. invalid declaration
*/
int main() /* convert declaration to words */
{
  while (gettoken() != EOF) {
    if (!strcmp(token, "const")) 
    {
      strcpy(qualifier, token); /* handle const */
      gettoken(); 
    }
    /* 1st token on line */
    strcpy(datatype, token); /* is the datatype */
    out[0] = '\0';
    dcl();

    /* parse rest of line */
    if (tokentype != '\n')
      printf("syntax error\n");
      printf("%s: %s %s %s\n", name, out, qualifier, datatype);
    }

    return 0;
}

/* dcl: parse a declarator */
void dcl(void)
{
  int ns;
  int a;

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
  printf("type; %d, token: %s\n", type, token);
  if (tokentype == '(') {
    /* ( dcl ) */
    dcl();
    if (tokentype != ')')
      printf("error: missing \")\"\n");
  } else if (tokentype == NAME) /* variable name */
    strcpy(name, token);
   else if (tokentype == ARGUMENT) {  
    strcpy(arguments, token);
   } else 
    printf("error: expected name or (dcl)\n");

  while ( (type=gettoken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
    {
      strcat(out, " function");
      strcat(out, arguments);
      strcat(out, " returning");
    }
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
    // handle spurious spaces before dereference operators 
    while ((c = getch()) == ' ' || c == '\t')
      ;

    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']';  )
        if(*(p-1) == ' ' || *(p-1) == '\t' || *(p-1) == '\n') p--;
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch());)
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else
  {
    return tokentype = c;
  }
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