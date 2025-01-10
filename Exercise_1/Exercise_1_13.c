#define IN 1
#define OUT 0

// historgram to display the length of words in a string
int histo_gram(char str[]) {
    int len, inSpace;
    char words[100];

    inSpace = OUT; // inital not in space
    
    for (int i = 0; str[i] != '\0'; i++) {
        // reset word len to 0 at every space 
        if(inSpace == OUT) {
            len = 0;
            words[0] = '\0';
        }

        if (str[i] != ' ') {
            inSpace = IN;
            words[len++] = str[i];
        }

        // In condition out of the word, print histogram  
        if(str[i] == ' ' && inSpace == IN) {
            inSpace = OUT;
            char bar[100];
            words[len] = '\0';

            printf(" %10s : ", words);

            // print the historgram
            for (int j = 0; j < len; j++) {
                putchar('=');
            }
            putchar('\n');
        }
    }
}

