/* Instructions for Students
Part 1: Complete the Author and Book structure definitions by filling in the appropriate fields.
Part 2: Initialize the library array with at least 5 books, each with complete author details.
Part 3: Fill in the function prototypes for displayBooks, checkOutBook, returnBook, and searchBookByTitle.
Part 4: Implement the main function to handle user input and call the appropriate functions based on the user's choice.
Part 5: Define the four functions (displayBooks, checkOutBook, returnBook, and searchBookByTitle) to perform the necessary operations on the library.
*/
#include <stdio.h>
#include <string.h>

/* 1. Define the Author structure */
typedef struct {
    char firstName[30];  // first name (array of 30 characters)
    char lastName[30];  // last name (array of 30 characters)
    char nationality[30];  // nationality (array of 30 characters)
} Author;

/* 2. Define the Book structure */
typedef struct {
    char title[100];  // title (array of 100 characters)
    Author author;  // nested Author structure
    char ISBN[13];  // ISBN (array of 13 characters)
    int availability;  // availability status (integer: 1 for available, 0 for checked out)
} Book;

/* 3. Declare the function prototypes */
void displayBooks(Book library[], int size);
void checkOutBook(Book *book);  // Pass by reference to modify the original book
void returnBook(Book *book);    // Pass by reference to modify the original book
int searchBookByTitle(Book library[], int size, char title[]);

int main() {
    /* 4. Initialize the library array with sample books */
    Book library[5] = {
        {"The Great Gatsby", {"F. Scott", "Fitzgerald", "American"}, "9780743273565", 1},
        {"To Kill a Mockingbird", {"Harper", "Lee", "American"}, "9780446310789", 1},
        {"1984", {"George", "Orwell", "British"}, "9780451524935", 1},
        {"Pride and Prejudice", {"Jane", "Austen", "British"}, "9781503290563", 1},
        {"Moby Dick", {"Herman", "Melville", "American"}, "9781503280786", 1},
    };

    int choice;
    char title[100];
    int index;
    int size = sizeof(library) / sizeof(library[0]);

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. View All Books\n");
        printf("2. Check Out a Book\n");
        printf("3. Return a Book\n");
        printf("4. Search for a Book by Title\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Flush the input buffer

        switch (choice) {
            case 1:
                displayBooks(library, size);
                break;
            case 2:
                printf("Enter the title of the book to check out: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                index = searchBookByTitle(library, size, title);
                if (index != -1) {
                    checkOutBook(&library[index]);  // Pass by reference to modify the book
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 3:
                printf("Enter the title of the book to return: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                index = searchBookByTitle(library, size, title);
                if (index != -1) {
                    returnBook(&library[index]);  // Pass by reference to modify the book
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 4:
                printf("Enter the title of the book to search: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                index = searchBookByTitle(library, size, title);
                if (index != -1) {
                    printf("Book Found:\n");
                    printf("Title: %s\n", library[index].title);  // Print book title
                    printf("Author: %s %s\n", library[index].author.firstName, library[index].author.lastName);  // Print author's first and last name
                    printf("Nationality: %s\n", library[index].author.nationality);  // Print author's nationality
                    printf("ISBN: %s\n", library[index].ISBN);  // Print ISBN
                    printf("Status: %s\n", library[index].availability ? "Available" : "Checked Out");  // Print availability status
                } else {
                    printf("Book not found.\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

/* 5. Define the displayBooks function */
void displayBooks(Book library[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
}

/* 6. Define the checkOutBook function */
void checkOutBook(Book *book) {
    if (book->availability == 1) {
        book->availability = 0;
        printf("Book checked out successfully.\n");
    } else {
        printf("The book is already checked out.\n");
    }
}

/* 7. Define the returnBook function */
void returnBook(Book *book) {
    if (book->availability == 0) {
        book->availability = 1;
        printf("Book returned successfully.\n");
    } else {
        printf("The book is already returned.\n");
    }
}

/* 8. Define the searchBookByTitle function */
int searchBookByTitle(Book library[], int size, char title[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(library[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}