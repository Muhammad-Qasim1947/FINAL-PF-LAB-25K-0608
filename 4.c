// Q2: Create a C program that manages a structure dynamically. Use the same structure as question
// 4, however, the variable should be allocated Dynamically using Calloc, Give the user the option to
// set the size in the beginning and resizing as well depending upon the number of insertions.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct team {
    int id ;
    char name[50];
    int totalwins ;
    int totallosses ;
};

int add(struct team **teams , int *teamcount , int *capacity){
    if (*teamcount >= *capacity){
        *capacity *= 2 ;
        *teams = realloc(*teams , sizeof(struct team) * (*capacity)) ;

        if (*teams == NULL){
            printf("Memory Allocation Failed\n");
            return *teamcount ;
        }
        printf("Array resized. New capacity: %d\n", *capacity);
        
    }
    
    struct team Newteam ;

    printf("Enter The ID : ");
    scanf("%d",&Newteam.id);
    getchar() ;

    printf("Enter The Name Of Team : ");
    fgets(Newteam.name , 50 , stdin);
    Newteam.name[strcspn(Newteam.name , '\n')] = '\0' ; // remove new line

    Newteam.totalwins = 0 ;
    Newteam.totallosses = 0 ;

    (*teams)[*teamcount] = Newteam ;
    (*teamcount)++ ;

    printf("Team Added Successfully");

    return *teamcount ;
}

void update(struct team *teams , int teamcount){
    if (teamcount == 0){
        printf("No Teams Available");
    }
    
    int id , choice ;
    int found = 0 ;

    printf("Enter The ID Of The Team : ");
    scanf("%d",&id);

    for (int i = 0; i < teamcount; i++) {
        if (teams[i].id == id) {
            found = 1;
            printf("Enter Your Choice For Latest Match (1 for Win, 2 for Loss): ");
            scanf("%d", &choice);

            if (choice == 1) {
                teams[i].totalwins++; 
                printf("Win added. Total Wins: %d\n", teams[i].totalwins);
            } else if (choice == 2) {
                teams[i].totallosses++;
                printf("Loss added. Total Losses: %d\n", teams[i].totallosses);
            } else {
                printf("Invalid choice! No update performed.\n");
            }
            break; 
        }
    }

    if (!found) {
        printf("Team with ID %d not found.\n", id);
    }
}

void record(struct team *teams, int teamcount) {
    if (teamcount == 0) {
        printf("No teams available!\n");
        return;
    }

    int maxWins = 0;
    double maxWinPercent = 0;

    // First, find max wins and max win percentage
    for (int i = 0; i < teamcount; i++) {
        if (teams[i].totalwins > maxWins) {
            maxWins = teams[i].totalwins;
        }

        int totalMatches = teams[i].totalwins + teams[i].totallosses;
        double winPercent = 0;
        if (totalMatches > 0) {
            winPercent = (teams[i].totalwins * 1.0) / totalMatches;
        }

        if (winPercent > maxWinPercent) {
            maxWinPercent = winPercent;
        }
    }

    // Print teams with max wins
    printf("\nTeam(s) with Highest Wins (%d):\n", maxWins);
    for (int i = 0; i < teamcount; i++) {
        if (teams[i].totalwins == maxWins) {
            printf("ID: %d, Name: %s, Wins: %d, Losses: %d\n",
                   teams[i].id, teams[i].name, teams[i].totalwins, teams[i].totallosses);
        }
    }

    // Print teams with max win percentage
    printf("\nTeam(s) with Highest Win Percentage (%.2f%%):\n", maxWinPercent * 100);
    for (int i = 0; i < teamcount; i++) {
        int totalMatches = teams[i].totalwins + teams[i].totallosses;
        double winPercent = 0;
        if (totalMatches > 0) {
            winPercent = (teams[i].totalwins * 1.0) / totalMatches;
        }

        if (winPercent == maxWinPercent) {
            printf("ID: %d, Name: %s, Wins: %d, Losses: %d\n",
                   teams[i].id, teams[i].name, teams[i].totalwins, teams[i].totallosses);
        }
    }
}


int main(){

    int choice ;
    int teamcount = 0 ;
    int capacity ;
    int initialsize = 0 ;

    printf("Enter initial number of teams: ");
    scanf("%d", &initialsize);

    capacity = initialsize ;

    struct team *teams = calloc(capacity , sizeof(struct team)) ;

    if (teams == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do {
        printf("\n--- Team Management Menu ---\n");
        printf("1. ADD NEW TEAM\n2. UPDATE TEAM RECORD\n3. READ TEAM RECORD\n4. EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
    
    switch (choice){
    case 1 :
        teamcount = add(&teams , &teamcount , &capacity);
        break;
    case 2 :
        update(teams, teamcount);
        break;
    case 3 :
        record(teams, teamcount); 
        break;
    case 4 :
        printf("EXITING");
        break;
    default:
        printf("INVALID CHOICE !!!!");
        break;
    }
    } while (choice != 4);

    free(teams);

    return 0;
}