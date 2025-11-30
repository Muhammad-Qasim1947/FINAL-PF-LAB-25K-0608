// 1. Inventory Management

// Scenario: You are making a grocery store inventory system.

// The store has N types of items (columns).

// The user keeps entering rows of stock levels for each day until -1 is entered.

// Create a daily total stock array using DMA (sum of each row).

// Print the totals.

// Focus: 2D array, row sums, dynamic rows.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter The Number Of Columns: ");
    scanf("%d", &N);

    int **matrix = NULL;
    int rows = 0;

    while (1) {
        int firstVal;
        printf("Enter the first value of row %d (or -1 to exit): ", rows + 1);
        scanf("%d", &firstVal);

        if (firstVal == -1) {
            break; // exit input loop
        }

        // Allocate memory for a new row
        matrix = realloc(matrix, (rows + 1) * sizeof(int *));
        matrix[rows] = malloc(N * sizeof(int));

        // Store the first value
        matrix[rows][0] = firstVal;

        // Read remaining N-1 values
        for (int j = 1; j < N; j++) {
            scanf("%d", &matrix[rows][j]);
        }

        rows++;
    }

    // Calculate daily totals
    int *totals = malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        totals[i] = 0;
        for (int j = 0; j < N; j++) {
            totals[i] += matrix[i][j];
        }
    }

    // Print daily totals
    printf("\nDaily total stock:\n");
    for (int i = 0; i < rows; i++) {
        printf("Day %d: %d\n", i + 1, totals[i]);
    }

    // Free memory
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    free(totals);

    return 0;
}
