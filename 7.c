// Generate a 2D array with dimensions MxN with dynamically allocated memory. User keeps entering rows of
// matrix until he/she types a '-1'. Number columns will be given in first line.
// Your task is to allocate a new 2D array of dimensions M-2 x N-2, where result(i][} = sum of the 3x3 matrix
// centered at i+1, j+1.
// Example Input:
// 4
// 1234
// 5678
// 12345678
// 1234
// 9874
// -1
// Example Output:
// Resultant matrix dimension= Zx4
// 30 39
// 42 51
// 30 39
// 48 49
// Explanation:
// Let's take result[0][0] as an example. This is the sum of the 3x3 matrix centered at matrix[1][1]:
// 123
// 567
// 123
// By summing the above elements, we get 30. Same is the process for other cells of the resultant
// array.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int N;
    printf("Enter The Number Of columns : ");
    scanf("%d", &N);
    getchar();

    // Dynamic allocation for storing rows
    char **matrix = NULL;
    int rows = 0;
    char storage[1024]; // isme store honge numbers temporarily

    printf("Enter matrix rows (type -1 to end):\n");
    while (1)
    {
        fgets(storage, sizeof(storage), stdin);
        storage[strcspn(storage, "\n")] = '\0';

        if (strcmp(storage, "-1") == 0)
        {
            break;
        }

        // alocating memory for new row
        matrix = realloc(matrix, (rows + 1) * sizeof(char *));
        matrix[rows] = malloc((N + 1) * sizeof(char));
        strncpy(matrix[rows], storage, N);
        matrix[rows][N] = '\0';
        rows++;
    }

    if (rows < 3 || N < 3)
    {
        printf("Matrix too small for 3x3 sum.\n");
        // Free memory
        for (int i = 0; i < rows; i++)
        {
            free(matrix[i]);
            free(matrix);
            return 0;
        }
    }

    // TO ALLOCATE NEW DYNAMIC ARRAY OF DIMENSION M-2 X N-2
    int M2 = rows - 2;
    int N2 = N - 2;
    int **result = malloc(M2 * sizeof( int* ));
    
    for (int i = 0; i < M2; i++)
        result[i] = malloc(N2 * sizeof(int));


    // Compute sum of 3x3 submatrices
    for (int i = 0; i < M2; i++) {
        for (int j = 0; j < N2; j++) {
            int sum = 0;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    sum += matrix[i + x][j + y] - '0'; // convert char to int
                }
            }
            result[i][j] = sum;
        }
    }

    printf("Resultant matrix dimension=%dx%d\n", M2, N2);
    for (int i = 0; i < M2; i++) {
        for (int j = 0; j < N2; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);
    for (int i = 0; i < M2; i++) free(result[i]);
    free(result);

    return 0 ;
    } 