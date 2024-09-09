
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// === Stage 1: Swapping Positions ===
// Function: swap_positions
// Description: This function swaps the values of two integers using pointers.
void swap_positions(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// === Stage 2: The Desert of Shifting Sands ===
// Function: update_position
// Description: This function updates the coordinates (x, y) based on the provided deltas (delta_x, delta_y).
void update_position(int *x, int *y, int delta_x, int delta_y) {
    *x += delta_x;
    *y += delta_y;
}

// === Stage 3: The Cave of Secrets ===
// Function: find_secret_string
// Description: This function searches for the secret string within the text string.
int find_secret_string(const char *text, const char *secret) {
    const char *original_text = text; // Keep a pointer to the start of the text
    const char *secret_ptr;           // Pointer to traverse the secret string
    const char *start_ptr;            // Pointer to mark the start of the matching sequence

    // Traverse the text until the end
    while (*text != '\0') {
        // Check if the first characters match
        if (*text == *secret) {
            start_ptr = text;    // Mark the potential starting position
            secret_ptr = secret; // Reset the secret pointer to the beginning

            // Traverse both strings while characters match
            while (*text == *secret_ptr && *secret_ptr != '\0') {
                text++;
                secret_ptr++;
            }

            // If the end of the secret string is reached, a full match is found
            if (*secret_ptr == '\0') {
                return start_ptr - original_text; // Return the index of the starting position
            }

            // Reset text to one character after start_ptr
            text = start_ptr;
        }

        // Move to the next character in the text
        text++;
    }

    // If the secret string is not found, return -1
    return -1;
}


// === Stage 4: The Temple of Numbers ===
// Helper function: is_prime
// Description: This function returns true if the number is prime.
bool is_prime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function: sum_of_primes
// Description: This function computes the sum of all prime numbers in the array.
int sum_of_primes(int *arr, int size) {
    int sum = 0;
    //int *ptr = arr; // Pointer to traverse the array

    // Traverse the array using pointer arithmetic
    for (int i = 0; i < size; i++) {
        if (is_prime(*(arr + i))) {
            sum += *(arr + i);
        }
    }

    return sum;
}

// === Stage 1 Grading Function ===
bool grade_stage1() {
    int a = 5, b = 10;
    swap_positions(&a, &b);
    
    // Expected result: a should now be 10, b should now be 5
    if (a == 10 && b == 5) {
        return true;
    } else {
        printf("swap_positions() failed! Expected a=10, b=5 but got a=%d, b=%d\n", a, b);
        return false;
    }
}

// === Stage 2 Grading Function ===
bool grade_stage2() {
    int x = 5, y = 10;
    update_position(&x, &y, 3, -2);
    
    // Expected result: x should be 8, y should be 8
    if (x == 8 && y == 8) {
        return true;
    } else {
        printf("update_position() failed! Expected x=8, y=8 but got x=%d, y=%d\n", x, y);
        return false;
    }
}

// === Stage 3 Grading Function ===
bool grade_stage3() {
    const char *text = "In the halls of the forgotten kings, lies the golden chalice.";
    const char *secret = "golden chalice";
    
    int position = find_secret_string(text, secret);
    
    // Expected position of "golden chalice" is 46
    if (position == 46) {
        return true;
    } else {
        printf("find_secret_string() failed! Expected position 46 but got %d\n", position);
        return false;
    }
}

// === Stage 4 Grading Function ===
bool grade_stage4() {
    int numbers[] = {3, 4, 5, 6, 7, 8, 11, 13};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int prime_sum = sum_of_primes(numbers, size);

    // Expected sum of primes is 39
    if (prime_sum == 39) {
        return true;
    } else {
        printf("sum_of_primes() failed! Expected sum 39 but got %d\n", prime_sum);
        return false;
    }
}

// === Main Program ===
int main() {
    printf("Welcome to the Quest for the Hidden Treasure!\n\n");

    // Stage 1: Swap Positions
    printf("Stage 1: Swapping Positions\n");
    if (grade_stage1()) {
        printf("Stage 1 completed successfully!\n\n");
    } else {
        printf("Stage 1 failed. Please review your swap_positions() implementation.\n\n");
        return 0;
    }

    // Stage 2: Update Position
    printf("Stage 2: The Desert of Shifting Sands\n");
    if (grade_stage2()) {
        printf("Stage 2 completed successfully!\n\n");
    } else {
        printf("Stage 2 failed. Please review your update_position() implementation.\n\n");
        return 0;
    }

    // Stage 3: Find Secret String
    printf("Stage 3: The Cave of Secrets\n");
    if (grade_stage3()) {
        printf("Stage 3 completed successfully!\n\n");
    } else {
        printf("Stage 3 failed. Please review your find_secret_string() implementation.\n\n");
        return 0;
    }

    // Stage 4: Sum of Primes
    printf("Stage 4: The Temple of Numbers\n");
    if (grade_stage4()) {
        printf("Stage 4 completed successfully!\n\n");
    } else {
        printf("Stage 4 failed. Please review your sum_of_primes() implementation.\n\n");
        return 0;
    }

    printf("Congratulations, brave explorer! You have completed all stages and found the hidden treasure.\n");
    return 0;
}
    