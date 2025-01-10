Type Coversions :
- float -> double
  char & short -> int
    Thus, we have declared function arguments to be int and double
      even when the functino is called with char and float

- casting : (type name) expression

- prefix & suffix ++/-- : suffix will increment the variable after used

- bitwise operator : No idea how this is operated.
 need to perform exercises or some tutorials to understand the concept

- binary operator : op=
    op: + - * / % << >> & ^ |
      example:
          x *= y + 1 is equivalent to x = x * (y + 1)
          x = x * y + 1 is incorrect
- Precedence & Order of Evaluation :
    no rules for function calls evaluation such as f() and g()
    Orders depending on the compiler
      e.g:
        printf("%d %d", ++n, power(2, n )); <--- WRONG !
      fix:
        ++n;
        printf("%d %d", n, power(2, n);

- Pointers & Arrays
  & = " the address of the pointer "
  * = " value of the pointer pointing "

  Array-and-Index expression is equivalent to one written as a pointer and offset.
  a[i] is literatlly equal to *(a + i)

  NULL is special case in pointer
  e.g.
    void strcpy(char *s, char *t) {
      while ( *s++ = *t++)
        ;
    }

  - Creating buffer to store input
    getch() and ungetch()

  [Interesting !]:
    When decrementing a pointer array inside a pointer function, the
    array element's int value will be NEGATIVE.
    Distinguishing between pointers and arrays string.

- functions :
If the function takes arguments, declare them; if it takes no arguments, use void.




Personal Notes :
1. Set pointers and move pointers are two operations.


Unsolved problems :
Exercises 1-11 : How to test the count program?

Exer 1-14: kinda tedious and challenging problem