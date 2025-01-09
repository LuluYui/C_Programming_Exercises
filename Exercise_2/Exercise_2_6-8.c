#include <string.h> 
#include <stdio.h> 

// Exercise 2-6. Write a function setbits(x,p,n,y) that 
// returns x with the n bits that begin at position p set to the rightmost n bits of y, 
// leaving the other bits unchanged.

int setbits(unsigned x, int p, int n, unsigned y);

// Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
int invert(int x, int p, int n); 

// Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions
int rightrot(int x, int n);

void printBinary(unsigned int num) {
    // Define the number of bits in an unsigned int
    int bits = sizeof(num) * 8; // 8 bits per byte

    // Loop through each bit from MSB to LSB
    for (int i = bits - 1; i >= 0; i--) {
        // Use bitwise AND to check if the ith bit is set
        if (num & (1 << i)) {
            putchar('1'); // Print '1' if the bit is set
        } else {
            putchar('0'); // Print '0' if the bit is not set
        }
    }
    putchar('\n'); // Newline for better output formatting
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

main() {
    unsigned x = 0b11010000; // Example binary number
    unsigned y = 0b10100000; // Example binary number
    int p = 7;              // Start position
    int n = 4;              // Number of bits to extract
    
    unsigned s = setbits(x, p, n, y);
}


/* getbits:  get n bits from position p */

int setbits(unsigned x, int p, int n, unsigned y) 
{
    // ~0 all 1-bits
    // ~0<<n places 0 at the rightmost n bits
    // ~(~0<<n) a mask with 1-bits at the rightmost n bits

    unsigned t = 0;
    int width = (p + 1 - n );
    // Clear n bits in x at position p
    // shift the bits to the rightmost n bits
    t = x >> ( width );
    printBinary(t);

    // x = x & ~(~0 << (p+1)) | ~(~0 << (p+1-n));

    // Insert n bits from y at position p
    x = x | (y & ~(~0 << n)) << (p+1-n);

    return x;
      
}