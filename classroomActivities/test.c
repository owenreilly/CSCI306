
#include <stdio.h>
#include <stdbool.h>
#include <math.h> // For math functions like sqrt, cbrt
#include <string.h> // For strlen

// Function Prototypes
float square_root1(float x); // Using a do-while loop
float square_root2(float x); // Using a for loop
float cube_root(float x); // Returns the cube root of a given number
bool compare_strings(const char str1[], const char str2[]); // Compares two strings without using strcmp
bool is_palindrome(const char str[]); // Checks if a string is a palindrome

int main(void) {
    // Variables for testing
    float test_value1 = 2.0, test_value2 = 3.0;
    char test_str1[] = "test", test_str2[] = "test";
    char test_str3[] = "notpalindrome", test_str4[] = "racecar";

    // Test square_root1 (do-while loop)
    float result1 = square_root1(test_value1);
    if (fabs(result1 - 1.414) < 0.001) { // Expected sqrt(2) is approximately 1.414
        printf("square_root1 test with 2.0: Passed\n");
    } else {
        printf("square_root1 test with 2.0: Failed\n");
    }

    // Test square_root2 (for loop)
    float result2 = square_root2(test_value2);
    if (fabs(result2 - 1.732) < 0.001) { // Expected sqrt(3) is approximately 1.732
        printf("square_root2 test with 3.0: Passed\n");
    } else {
        printf("square_root2 test with 3.0: Failed\n");
    }

    // Test cube_root
    float cube_result = cube_root(8.0); // The cube root of 8.0 is 2.0
    if (fabs(cube_result - 2.0) < 0.001) {
        printf("cube_root test with 8.0: Passed\n");
    } else {
        printf("cube_root test with 8.0: Failed\n");
    }

    // Another cube root test
    cube_result = cube_root(27.0); // The cube root of 27.0 is 3.0
    if (fabs(cube_result - 3.0) < 0.001) {
        printf("cube_root test with 27.0: Passed\n");
    } else {
        printf("cube_root test with 27.0: Failed\n");
    }

    // Test compare_strings
    bool compare_result1 = compare_strings(test_str1, test_str2); // Both are "test"
    if (compare_result1) {
        printf("compare_strings test with \"test\" and \"test\": Passed\n");
    } else {
        printf("compare_strings test with \"test\" and \"test\": Failed\n");
    }

    bool compare_result2 = compare_strings(test_str1, test_str3); // "test" and "notpalindrome" are different
    if (!compare_result2) {
        printf("compare_strings test with \"test\" and \"notpalindrome\": Passed\n");
    } else {
        printf("compare_strings test with \"test\" and \"notpalindrome\": Failed\n");
    }

    // Test is_palindrome
    bool palindrome_result1 = is_palindrome(test_str4); // "racecar" is a palindrome
    if (palindrome_result1) {
        printf("is_palindrome test with \"racecar\": Passed\n");
    } else {
        printf("is_palindrome test with \"racecar\": Failed\n");
    }

    bool palindrome_result2 = is_palindrome(test_str3); // "notpalindrome" is not a palindrome
    if (!palindrome_result2) {
        printf("is_palindrome test with \"notpalindrome\": Passed\n");
    } else {
        printf("is_palindrome test with \"notpalindrome\": Failed\n");
    }

    return 0;
}

// Function Definitions

// Using a do-while loop
float square_root1(float number) {
    float guess = number / 2.0;
    const float epsilon = 0.0001;
    
    do {
        guess = (guess + number / guess) / 2.0;
    } while (fabs(guess * guess - number) > epsilon);
    
    return guess;
}

// Using a for loop
float square_root2(float number) {
    float guess = number / 2.0;
    const float epsilon = 0.0001;
    
    for (; fabs(guess * guess - number) > epsilon;) {
        guess = (guess + number / guess) / 2.0;
    }
    
    return guess;
}

float cube_root(float x) {
    float guess = x / 3.0f; 
    const float epsilon = 0.00001;
    
    while (fabs(guess * guess * guess - x) > epsilon) {
        guess = (2.0f * guess + x / (guess * guess)) / 3.0f;
    }
    
    return guess;
}

bool compare_strings(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

bool is_palindrome(const char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
