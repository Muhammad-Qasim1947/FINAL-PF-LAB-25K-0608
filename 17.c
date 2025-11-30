// Scenario: A city has a population that grows by a fixed percentage each year. 
// Some people also move out each year.
// Task: Write a recursive function population(years, currentPopulation, growthRate, migration)
//  to print the population at each year and return the final population.

// Concepts: Tracks state year by year; handles growth and migration recursively.

#include <stdio.h>
#include <string.h>

void population(int years , float currentpopulation , float growthrate , int migration , int year){
   if (years == 0)
   { printf("Final Population: %.2f\n", currentpopulation);
    return ;
   }

   float newpopulation = currentpopulation + (currentpopulation * growthrate) - migration ;

   printf("Population At Year %d is : %.2f\n ", year , newpopulation) ;

   population(years - 1 , newpopulation , growthrate , migration , year + 1);

}

int main(){
    int years ;
    float currentpopulation ;
    float growthrate ;
    int migration ;

    printf("Enter The Number Of Year : ");
    scanf("%d",&years);

    printf("Enter The Current Population : ");
    scanf("%f",&currentpopulation);

    printf("Enter The Growth Rate : ");
    scanf("%f",&growthrate);

    printf("Enter The Number Of People Migrated : ");
    scanf("%d",&migration);

    population(years , currentpopulation , growthrate , migration , 1 );

}