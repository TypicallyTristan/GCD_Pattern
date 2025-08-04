#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to hold list of rows
typedef struct {
    char **rows;
    int num_rows;
} Pattern;

Pattern createBalancedPattern(int numX, int num0);
char* concatenateFinalPattern(const Pattern *pattern);
int getRowLengthDifference(const Pattern *pattern);
void free_pattern(Pattern *p);
int find_max(int a, int b);
int find_min(int a, int b);

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

    Pattern final_pattern = createBalancedPattern(numX, num0);

    char *result = concatenateFinalPattern(&final_pattern);

    printf("\nFinal Result: %s\n", result);

}    



// Main Functions

Pattern createBalancedPattern(int numX, int num0) {
    // ---Step 1: Create first two rows---
    Pattern p;
    p.num_rows = 2;
    p.rows = malloc(p.num_rows * sizeof(char*));

    int max_count = find_max(numX, num0);
    int min_count = find_min(numX, num0);
    char max_char = (numX > num0) ? 'X' : '0';
    char min_char = (numX < num0) ? 'X' : '0';

    p.rows[0] = malloc(max_count + 1);
    p.rows[1] = malloc(min_count + 1);
    memset(p.rows[0], max_char, max_count);
    p.rows[0][max_count] = '\0';
    memset(p.rows[1], min_char, min_count);
    p.rows[1][min_count] = '\0';

    // ---Step 2: The Balancing Loop---
    while (getRowLengthDifference(&p) > 1) {
        int shortest = INT_MAX;
        for (int i = 0; i < p.num_rows; i++) { // Finds the length of the shortest row
            shortest = find_min(shortest, strlen(p.rows[i]));
        }
        int difference = getRowLengthDifference(&p);

        
        int additions_count = 0;
        for (int i = 0; i < p.num_rows; i++) { // Counts how many rows are longer than the shortest
            if (strlen(p.rows[i]) > shortest) {
                additions_count++;
            }
        }

        // Create new pattern to hold transformed rows
        int new_num_row = p.num_rows + additions_count;
        Pattern new_p;
        new_p.num_rows = new_num_row;
        new_p.rows = malloc(new_num_row * sizeof(char*));

        int addition_idx = 0;
        int trimp_point = find_max(shortest, difference); // Calculates the new lenght for the long rows we trim

        for (int i = 0; i < p.num_rows; i++) { // Iterates through old pattern p and builds new pattern
            int current_len = strlen(p.rows[i]);
            if (current_len > shortest) {
                // This row is too long so we trim it
                new_p.rows[i] = malloc(trimp_point + 1);
                strncpy(new_p.rows[i], p.rows[i], trimp_point);
                new_p.rows[i][trimp_point] = '\0';

                // Creates new row from trim
                int cut_off_len = current_len - trimp_point;
                new_p.rows[p.num_rows + addition_idx] = malloc(cut_off_len + 1);
                strcpy(new_p.rows[p.num_rows + addition_idx], p.rows[i] + trimp_point);
                addition_idx++;
                } else { // If row was already short enough
                    new_p.rows[i] = malloc(current_len + 1);
                    strcpy(new_p.rows[i], p.rows[i]);
                }

        }

        // Replace old pattern with new balance one.
        free_pattern(&p); 
        p = new_p;
    }

    return p;
}

// Step 3: --- Concatenate the balanced pattern---

char* concatenateFinalPattern (const Pattern *pattern) {
    // First scans to find total number of characters and the length of the longest row
    int maxColLength = 0, total_chars = 0; 
    for(int i = 0; i < pattern->num_rows; i++) {
        int len = strlen(pattern->rows[i]);
        total_chars += len;
        if(len > maxColLength) maxColLength = len;
    }
    if (total_chars == 0) {
        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }
    char *result = malloc(total_chars + 1);
    int result_idx = 0;
    for (int col = 0; col < maxColLength; col++) {
        for (int row = 0; row < pattern->num_rows; row++) {
            if (col < strlen(pattern->rows[row])) {
                result[result_idx++] = pattern->rows[row][col];
            }
        }
    }
    result[result_idx] = '\0';
    return result;
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

void free_pattern(Pattern *p) {
    if (!p || !p->rows) return;
    for (int i = 0; i < p->num_rows; i++) {
        free(p->rows);
        p->rows = NULL;
        p->num_rows = 0;
    }
}

int find_max(int a, int b) { return (a > b) ? a : b; }  // Finds largest number
int find_min(int a, int b) { return (a < b) ? a : b; }  // Finds smallest number
