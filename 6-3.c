#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORD 100
#define MAXLEN 1000

struct wnodes {
    char *word;
    int count;
    int ln_list[MAXLEN];
    struct wnodes *left;
    struct wnodes *right;
};

int getword(char *, int);
struct wnodes *addnode(struct wnodes *, char *, int);

int main(int argc, char *argv[])
{
    char word[MAXWORD];
    struct wnodes *root = NULL;
    int c, line_num;

    while ((c = getword(word, MAXWORD)) != EOF && ++line_num < MAXLEN )
     if (isalpha(c))
            root = addtree(root, word, line_num);
    return 0;
}

struct wnodes *addnode(struct wnodes *root, char *word, int line_num) {
    struct wnodes *p;
    p = root;
    
    if (p == NULL) 
    {
        p = talloc();
        p->word = strdup(word);
        p->count++;
        // fill in line number
        char *ln_ptr = p->ln_list;
        *ln_ptr++ = line_num;
        p->left = p->right = NULL;
    }
    else 
    {
        // search for the left right side 
        
        // 
        

    }
    
    


    return p;
}

/* talloc:  make a tnode */
struct wnodes *talloc(void)
{
    return (struct wnodes *) malloc(sizeof( struct wnodes ));
}

char *strdup(char *s)   /* make a duplicate of s */
{
    char *p;
    p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}

/* getword:  get next word or character from input */
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