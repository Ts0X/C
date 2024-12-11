#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100

// Structure to represent a book
struct Book {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
};

// Function prototypes
void addBook(struct Book library[], int *numBooks);
void removeBook(struct Book library[], int *numBooks);
void displayBooks(struct Book library[], int numBooks);
void searchBook(struct Book library[], int numBooks);
void saveLibrary(struct Book library[], int numBooks);
void loadLibrary(struct Book library[], int *numBooks);

int main() {
    struct Book library[MAX_BOOKS];
    int numBooks = 0;
    int choice;

    // Load the library data from file
    loadLibrary(library, &numBooks);

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Display All Books\n");
        printf("4. Search Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &numBooks);
                break;
            case 2:
                removeBook(library, &numBooks);
                break;
            case 3:
                displayBooks(library, numBooks);
                break;
            case 4:
                searchBook(library, numBooks);
                break;
            case 5:
                // Save the library data before exiting
                saveLibrary(library, numBooks);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a book to the library
void addBook(struct Book library[], int *numBooks) {
    if (*numBooks >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    struct Book newBook;
    newBook.id = *numBooks + 1;

    printf("Enter book title: ");
    getchar();  // to consume the newline character left by scanf
    fgets(newBook.title, MAX_TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove the newline character

    printf("Enter author name: ");
    fgets(newBook.author, MAX_AUTHOR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove the newline character

    library[*numBooks] = newBook;
    (*numBooks)++;
    printf("Book added successfully!\n");
}

// Function to remove a book from the library
void removeBook(struct Book library[], int *numBooks) {
    int id, found = 0;
    printf("Enter the book ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < *numBooks; i++) {
        if (library[i].id == id) {
            for (int j = i; j < *numBooks - 1; j++) {
                library[j] = library[j + 1];
            }
            (*numBooks)--;
            found = 1;
            printf("Book removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", id);
    }
}

// Function to display all books in the library
void displayBooks(struct Book library[], int numBooks) {
    if (numBooks == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nList of Books in the Library:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("ID: %d\n", library[i].id);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("----------------------------\n");
    }
}

// Function to search for a book by title or author
void searchBook(struct Book library[], int numBooks) {
    char searchTerm[MAX_TITLE_LEN];
    int found = 0;

    printf("Enter title or author to search: ");
    getchar();  // to consume the newline character
    fgets(searchTerm, MAX_TITLE_LEN, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0; // Remove the newline character

    for (int i = 0; i < numBooks; i++) {
        if (strstr(library[i].title, searchTerm) != NULL || strstr(library[i].author, searchTerm) != NULL) {
            printf("\nBook found:\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("----------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No books found matching \"%s\".\n", searchTerm);
    }
}

// Function to save the library data to a file
void saveLibrary(struct Book library[], int numBooks) {
    FILE *file = fopen("library.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving data.\n");
        return;
    }

    for (int i = 0; i < numBooks; i++) {
        fprintf(file, "%d|%s|%s\n", library[i].id, library[i].title, library[i].author);
    }

    fclose(file);
    printf("Library data saved to file.\n");
}

// Function to load the library data from a file
void loadLibrary(struct Book library[], int *numBooks) {
    FILE *file = fopen("library.txt", "r");
    if (file == NULL) {
        printf("No data file found. Starting with an empty library.\n");
        return;
    }

    while (fscanf(file, "%d|%99[^|]|%99[^\n]\n", &library[*numBooks].id, library[*numBooks].title, library[*numBooks].author) != EOF) {
        (*numBooks)++;
    }

    fclose(file);
    printf("Library data loaded from file.\n");
}
