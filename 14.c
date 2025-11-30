#include <stdio.h>

void calculate_fuel(int fuel , int consumption , int recharge , int bonus , int planet , int totalplanets ){
    if (fuel <= 0 || (planet > totalplanets) ){
        printf("Either Fuel Exhausted Or No Planets Remaining");
        return;
    }

    fuel = fuel - consumption + recharge ;

    if (planet %4 == 0){
        fuel = fuel + bonus ;
    }

    printf("Planet %d: Fuel Remaining = %d\n", planet, fuel);

    
    calculate_fuel(fuel , consumption , recharge , bonus , planet + 1 , totalplanets );
}

int main(){
    int fuel ;
    int consumption ;
    int recharge ; 
    int bonus ;
    int planet ;
    int totalplanets ;

    printf("Enter Initial Fuel: ");
    scanf("%d", &fuel);
    
    printf("Enter Fuel Consumption per Planet: ");
    scanf("%d", &consumption);
    
    printf("Enter Gravitational Recharge per Planet: ");
    scanf("%d", &recharge);
    
    printf("Enter Solar Bonus every 4th Planet: ");
    scanf("%d", &bonus);

    printf("Enter The Total Number Of Planets : ");
    scanf("%d",&totalplanets);

    calculate_fuel(fuel, consumption, recharge, bonus, 1 , totalplanets);

    return 0;
}