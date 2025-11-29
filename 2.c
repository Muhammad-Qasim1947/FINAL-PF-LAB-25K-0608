// Q3: Write a C program that calculates the sum of the elements along the border of a given square
// matrix of size nxn where n is an odd number.
// The program should:
// -Take an input from the user to create a 2D array/matrix.
// Calculate the sum of the elements along the border (including corners).
// - Display the calculated sum to the user.
// Expected Input: (as a 2D matrix) 123
// 456
// 789
// (1+2+3)+(1+4+7)+(7+8+9) + (3+6+9).
// Expected Output: Sum: 60

#include <stdio.h>
int main(){
    int n , m ;
    printf("Enter The Number Of Rows You Want To Enter : ");
    scanf("%d",&n);
    printf("Enter The Number Of Columns You Want To Enter : ");
    scanf("%d",&m);

    int arr[n][m] ;

    for (int i = 0; i < n ; i++){
        printf("Enter The Elements For Row %d",i+1);
        for (int j = 0; j < m ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < m ; j++){
            printf("%d",arr[i][j]);
        } 
        printf("\n");
    }

    int sum = 0 ;

    for (int j = 0; j < m ; j++){
        sum += arr[0][j];
    }

    for (int j = 0; j < m ; j++){
        sum += arr[n-1][j];
    }

    for (int i = 0; i < n ; i++){
        sum += arr[i][0];
    }

    for (int i = 0; i < n ; i++){
        sum += arr[i][m-1];
    }
    
    printf("Sum of border elements: %d\n", sum);
    
}