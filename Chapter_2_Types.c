#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>


main() {
    // long signed l_int;
    // long unsigned lu_int;
    // short signed s_int;
    // short unsigned su_int;
    // signed char l_ch;
    // unsigned char s_ch;
    // float fo;
    // double d_double;
    // long double l_double;

    // printf("long int size : %lu, short int size: %lu\n", sizeof(l_int), sizeof(s_int));
    // printf("long unsigned int size : %lu, short unsigned int size: %lu\n", sizeof(lu_int), sizeof(su_int));
    // printf("long char size : %lu, short char size: %lu\n", sizeof(l_ch), sizeof(s_ch));
    // printf("float size : %lu, double size: %lu, long double size : %lu\n", sizeof(fo), sizeof(d_double), sizeof(l_double));

    printf("Signed int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int range: %u to %u\n", 0, UINT_MAX);
    printf("Signed short range: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short range: %u to %u\n", 0, USHRT_MAX);
    printf("Signed char range: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char range: %u to %u\n", 0, UCHAR_MAX);
    

}