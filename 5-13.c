#include <stdio.h> 

#define N 10 
#define MAXLINES 1000 
#define MAXLEN 1000


int main(int argc, char *argv[]) {
    char c;
    int total = 0;
    char *lines_ptr[MAXLINES];
    char line[MAXLEN];
    int i=0;
    
    while ( (c = getchar()) != EOF)
    {
        if ( i < MAXLEN )
            line[i++] = c;
        
        if (c == '\n')
        {
            char *p = line;
            lines_ptr[total++] = p;
        }
    }
    
    for (int j = 0; j < ; j++)
    {
        printf("%s", lines_ptr[j]);
    }
    return 0;
}
