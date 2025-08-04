#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Euclid's Algorithm states that if a is the sum of two given numbers and b is the largest of those two numbers and r is the smallest then a / b = a = b * q + r.
// If we continuosly move over the b value to the a value and r value to the b value until r = 0 then we will have found the GCD of those two given numbers.
// For this program though we will be stopping once r = 1.

// Structure to hold list of rows
typedef struct {
    char **rows;
    int num_rows;
} Pattern;

// int max(int a, int b) { return (a > b) ? a : b; }  // Finds largest number
// int min(int a, int b) { return (a < b) ? a : b; }  // Finds smallest number

int main() { 
    int numX, num0;

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

}    



// Main Functions

Pattern createBalancedPattern(int numX, int num0) {
    // ---Step 1: Create first two rows---
    Pattern p;
    p.num_rows = 2;
    p.rows = malloc(p.num_rows * sizeof(char*));

    int max_count = max(numX, num0);
    int min_count = min(numX, num0);
    char* max_char = (numX > num0) ? 'X' : '0';
    char* min_char = (numX < num0) ? 'X' : '0';

    p.rows[0] = malloc(max_count + 1);
    p.rows[1] = malloc(min_char + 1);
    memset(p.rows[0], max_char, max_count);
    p.rows[0][max_count] = '\0';
    memset(p.rows[1], min_char, min_count);
    p.rows[1][min_count] = '\0';

    // ---Step 2: The Balancing Loop---





}



// Helper Functions

int getRowLengthDifference(const Pattern *pattern) {
    if(pattern->num_rows < 2) return 0;
    int longest = 0, shortest = INT_MAX;
    for(int i = 0; i < pattern->num_rows; i++) {
        int len = strlen(pattern->rows[i]);
        if(len > longest) longest = len;
        if(len < shortest) shortest = len;
    }
    return longest - shortest;
}