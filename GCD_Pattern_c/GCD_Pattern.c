#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Euclid's Algorithm states that if a is the sum of two given numbers and b is the largest of those two numbers and r is the smallest then a / b = a = b * q + r.
// If we continuosly move over the b value to the a value and r value to the b value until r = 0 then we will have found the GCD of those two given numbers.
// For this program though we will be stopping once r = 1.

make_chars(char *buffer, char c, int count) { 
    for(int i = 0; i < count; i++) {
        buffer[i] = c; 
    }
    buffer[count] = '\0';
}

int main() { 
    int numX, num0;
    int currentCharCount = 0;

    printf("How many X's?: ");
        if(scanf("%d", &numX) != 1 || numX < 0) {
            printf("Invalid input for X's.\n");
            return 1;
        }
    printf("How many 0's?: ");
    if(scanf("%d", &num0) != 1 || num0 < 0) {
        printf("Invalid input of 0's.\n");
        return 1;
    } 

    int GCD_b; // Makes sure the b always is the greater of the two numbers
    if(numX > num0) {
        GCD_b = numX;
    } else {
        GCD_b = num0;
    }

    int GCD_s; // Finds smallest number.
    if(numX < num0)
    {
        GCD_s = numX;
    } else {
        GCD_s = num0;
    }

    int GCD_a = numX + num0;
    int GCD_r = GCD_b % GCD_s;
    int GCD_q = numX / num0;

    char *result = malloc(GCD_a + 1); // Making sure there's enough room to store 
    make_chars(result, 'X', numX); // Fills beginning with X's
    make_chars(result + numX, '0', num0); // Fills Rest with 0's

    int current_line_count = 0;

    for(int i = 0; i < GCD_a; i++) // Print out X's and 0's until desired amount.
    {
        current_line_count += 1; // Tracks number of X's and 0's printed.
        if (current_line_count > GCD_b) // Check if line limit has been reached.
        {                              
            printf("\n");
            current_line_count = 0; // Reset counter for new line.
        }
        putchar(result[i]);   
    }
    free(result);
}    
