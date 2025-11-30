// 9. Pollution Monitoring

// Scenario: A pollution control board records pollution levels at N stations daily.

// Input rows until -1.

// Create a matrix showing maximum pollution in each 3x3 block.

// Focus: 2D DMA, pointer arithmetic, nested loops, using max instead of sum.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int N;
    printf("Enter The Number Of Stations ( COLUMNS ) : ");
    scanf("%d", &N);

    int **matrix = NULL;
    int rows = 0;

    while (1)
    {
        int storage;
        printf("Enter For Row %d ( -1 to exit )", rows + 1);
        scanf(" %d", &storage);

        if (storage == -1)
        {
            return;
        }

        matrix = realloc(matrix, (rows + 1) * sizeof(int *));
        matrix[rows] = malloc(N * (rows + 1));
        matrix[rows][0] = storage;

        for (int j = 0; j < N; j++)
        {
            scanf("%d", &matrix[rows][j]);
        }
        rows++;
    }
    int *totals = malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        totals[i] = 0;
        for (int j = 0; j < N; j++)
        {
            totals[i] += matrix[i][j];
        }
    }

    // Print totals
    printf("\nDaily totals:\n");
    for (int i = 0; i < rows; i++)
    {
        printf("Day %d: %d\n", i + 1, totals[i]);
    }

    // Free memory
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    free(totals);

    return 0;
}