#include <stdio.h>

#define A_CAPITAL 65
#define A_ALPHERBAT 97

// Exercise 2-3
int htoi(char s[]) {
    // 0xFFFF number into integer
    int n = 0;
    int i;
    if (s[0] == '0' && s[1] == 'x' || s[1] == 'X') 
        i = 2;
    else 
        i = 0;
    
    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            n = 16 * n + ( s[i++] - '0' );
        } else if ((s[i] >= A_CAPITAL) && (s[i] <= A_CAPITAL + 5)) { 
            n = 16 * n + ( s[i++] - A_CAPITAL + 10);
        } else if (s[i] >= A_ALPHERBAT && s[i] <= A_ALPHERBAT + 5) { 
            n = 16 * n + ( s[i++] - A_ALPHERBAT + 10);
        } else {
            printf("[ERROR] Invalid hex number found s[%d] = %c \n", i, s[i]);
            break;
        }
    }
    return n;
}

main() 
{
    char sp[] = "0x0a";
    char st[] = "3";
    int sp_i = htoi(sp);
    int st_i = htoi(st);
    printf(" sp value : %d \n", sp_i);
    printf(" st value : %d ", st_i);

}