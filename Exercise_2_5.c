#include <stdio.h>
#include <string.h>

#define YES 1
#define NO 0

int any(char s1[], char s2[]) {
    int i, j, k;
    int matched = NO;
    
    for ( i = 0; s1[i] != '\0'; i++) {
        if ( s1[i] == s2[0]) {
            for ( j = k = 0; s1[i+j] != '\0' && s2[k] != '\0' ; j++) {
                if (s1[i+j]!=s2[k]) {
                    matched = NO;
                    break;
                }

                k++;
                matched = YES;
            }
            if (matched == YES) 
                return i;
        } else if (s1[i] == '\0') 
            return -1;
    }
}

main() 
{
    char s1[] = "Hello, World!";
    char s2[] = "!";

    // printf("First occurrence of '%s' in '%s' is at index: %s\n", s2, s1, strpbrk(s1, s2));
    printf("First occurrence of '%s' in '%s' is at index: %d\n", s2, s1, any(s1, s2));

    return 0;

}