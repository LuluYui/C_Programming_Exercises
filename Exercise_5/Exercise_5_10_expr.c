#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 1000
#define NUMBER '0'

void push(int);
int pop();

char readtoken(char *);


int re=0;
// Polish Expr
int main(int argc, char *argv[]) {
  if (argc < 1) {
    printf(" Not enough input ! expected more than one arguements");
  }

  char c;

  int op2;

  while ( --argc > 0 && (c = readtoken((++argv)[0]))) {
    switch(c) {
      case NUMBER:
        push(re);
        re=0;
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        op2 = pop();
        push(pop() * op2);
        break;
      case '\n':
        break;
      default:
        break;
    }
  }


  return 0;
}

int stack[MAXLEN];
int p=-1;


// use: read the input token and returning the signals for operations
char readtoken(char *token) {
  int i=0;

  while(token[i] == ' ')
    ;


  if (!isdigit(token[i]) && token[i] != '-' && token[i] != '+' && token[i] != '*')
  {
    return -1;
  }

  if ( !isdigit(token[i]) && ( token[i] == '-' || token[i] == '*' || token[i] == '+') )
  {
    return token[i];
  }


  while (isdigit(token[i]) && token[i] != '\0')
    re = re * 10 + token[i++] - '0';

  return '0';
}

void push(int i) {
  if ( p < MAXLEN)
    stack[++p] = i;
  else
    printf(" Stack is full ! \n");
}

int pop() {
  if ( p > -1 )
    return stack[p--];
  else
    printf(" Stack is empty ! \n");
}