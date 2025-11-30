// 3. Recursive Savings Plan

// Scenario: You deposit a fixed amount into a bank every month, which earns interest monthly.
// Task: Create a recursive function savingsPlan(months, deposit, interestRate) that prints the 
// balance each month and returns the final amount.

// Concepts: Tracks cumulative savings recursively; base case is 0 months.

#include <stdio.h>

void savingplans(int months , float deposit , float interestrate , int month , float balance ){

    if(months == 0){
        printf("Final Savings : %f", balance) ;
        return ;
    }

    balance = balance + deposit ;
    balance = balance + ( balance * interestrate ); 

    printf("Month %d: Balance = %.2f\n", month, balance);

    savingplans(months - 1, deposit, interestrate, month + 1, balance);
}

int main(){
    int months ;
    float deposit ;
    float interestrate ;
    float balance = 0 ;

    printf("Enter The Number Of Months : ");
    scanf("%d",&months);

    printf("Enter Deposit : ");
    scanf("%f",&deposit);

    printf("Enter Interest Rate : ");
    scanf("%f",&interestrate);

    savingplans(months , deposit , interestrate , 1 , balance );
}