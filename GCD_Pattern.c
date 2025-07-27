#include <stdio.h>
#include <string.h>

int calculateGcd (int a, int b)
{
while(b != 0) {
    int r = a % b; // Calculate remainder
    a = b;         // Change value of a to b
    b = r;         // Change value of b to r
}
return a;          // Return GCD
}

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
    scanf("%d", &numX);
    printf("How many 0's?: ");
    scanf("%d", &num0);

    // Create a checker for if the number is negative and not an integer

    char result[100]; // Making sure there's enough room to store 
    make_chars(result, 'X', numX); // Fills beginning with X's
    make_chars(result + numX, '0', num0); // Fills Rest with 0's


    int current_line_count = 0;
    int num_sum = numX + num0;
    const int line_limit = num_sum; 

   

    for(int i = 0; i < num_sum; i++) // Print out X's and 0's until desired amount.
    {
        putchar(result[i]);

        current_line_count += 1; // Tracks number of X's and 0's printed.

        if (current_line_count == line_limit) // Check if line limit has been reached.
        {
            printf("\n");
            current_chars = 0; // Reset counter for new line.
        }

    }
}    
