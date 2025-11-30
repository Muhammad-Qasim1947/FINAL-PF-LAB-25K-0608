#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    int popularity;
} Book;

void add_book(Book shelf[], int *size, int capacity, int id, int popularity) {
    // Check if book already exists
    for(int i = 0; i < *size; i++) {
        if(shelf[i].id == id) {
            shelf[i].popularity = popularity; // Update popularity
            return;
        }
    }

    // If shelf is full, remove least recently accessed (last book)
    if(*size == capacity) {
        // Shift all books left to remove the last book
        for(int i = 0; i < *size - 1; i++) {
            shelf[i] = shelf[i + 1];
        }
        (*size)--;
    }

    // Add new book at the end (most recently accessed)
    shelf[*size].id = id;
    shelf[*size].popularity = popularity;
    (*size)++;
}

int access_book(Book shelf[], int *size, int capacity, int id) {
    for(int i = 0; i < *size; i++) {
        if(shelf[i].id == id) {
            int popularity = shelf[i].popularity;

            // Move accessed book to the end (most recently accessed)
            Book temp = shelf[i];
            for(int j = i; j < *size - 1; j++) {
                shelf[j] = shelf[j + 1];
            }
            shelf[*size - 1] = temp;

            return popularity;
        }
    }
    return -1; // Book not found
}

int main() {
    int capacity, Q;
    scanf("%d %d", &capacity, &Q);

    Book shelf[capacity];
    int size = 0;

    for(int i = 0; i < Q; i++) {
        char op[10];
        scanf("%s", op);

        if(strcmp(op, "ADD") == 0) {
            int id, popularity;
            scanf("%d %d", &id, &popularity);
            add_book(shelf, &size, capacity, id, popularity);
        } else if(strcmp(op, "ACCESS") == 0) {
            int id;
            scanf("%d", &id);
            int result = access_book(shelf, &size, capacity, id);
            printf("%d\n", result);
        }
    }

    return 0;
}
