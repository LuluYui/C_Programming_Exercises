#include <stdio.h>


/* squeeze:  delete all c[] from s */
void squeeze(char s1[], char s2[])
{
    int i, j;
    char c;
     
    for (i = j = 0; s1[i] != '\0'; i++) {
        // loop through all characters in s2 to find the matched string
        for (int k = 0; s2[k] != '\0' && (c = s2[k]); k++) {
            if (s1[i] == c) 
                break;
        }
        if (s1[i] != c) 
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

int main() {
    char str[] = " This is a test string";
    char str_to_del[] = "tra";

    squeeze(str, str_to_del);
    printf("Modified string: %s\n", str);
}