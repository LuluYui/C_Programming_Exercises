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
}