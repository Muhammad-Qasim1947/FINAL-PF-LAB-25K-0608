#include <stdio.h>

void calculate_repayment(int installment , float interestrate , int years , float loan , int year){
    if (years <= 0 || loan == 0 ){
        printf("No Loan Or Years Remaining");
        return ;
    }

    loan = loan + ( loan * interestrate );
    loan = loan - installment ;

    printf("Year %d : Remaining Loan = %.2f\n",year,loan);

    calculate_repayment(installment , interestrate , years - 1 , loan , year + 1);
    
}

int main(){
    int installment = 30000 ;
    float interest = 0.05 ;
    float loan = 100000 ;
    int years = 3 ;

    calculate_repayment(installment , interest , years , loan , 1);

    return 0 ;
}