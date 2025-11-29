// Q4 (Modified): Team Record Management System – Without File Handling

// You are required to implement the functionalities of a Team record management system for a number of players,
// each with the following attributes:

// Team ID (integer)
// Name (string, max length 50)
// Total wins (int)
// Total losses (int)

// Your program should implement the following functions:

// Add a New Team: Add a new team record to the array of structures.
// Update a Team's Record: Update an existing team's new match played by searching with the team ID and increment either
//  wins or losses by 1.
// Read the Team's Record: Read and print all the teams with the highest wins and the team with the
//  highest win percentage (wins / total matches) where total matches = wins + losses.
// Create a menu-driven program that allows the user to:

// Add a new team
// Update a team's record
// Print the data

// Note: Use an array of structures, switch statements, and functions. You are not allowed to use global variables.

#include <stdio.h>
#include <string.h>

#define maxteams 100 

struct team {
    int id ;
    char name[50];
    int totalwins ;
    int totallosses ;
    int choice ;
};

int add(struct team teams[] , int teamcount){
    if (teamcount >= maxteams){
        printf("You Cannot Add More Teams ALREADY FULL");
        return teamcount ;
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

    teams[teamcount] = Newteam ;
    teamcount++ ;

    printf("Team Added Successfully");

    return teamcount ;
}

int update(struct team teams[] , int teamcount){
    if (teamcount == 0){
        printf("No Teams Available");
        return 0 ;
    }
    
    int id , choice ;
    int found = 0 ;

    printf("Enter The ID Of The Team : ");
    scanf("%d",&id);
    printf("Enter Your Choice For Latest Match (1 for Win , 2 for Loss) : ");
    scanf("%d",&choice);

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
    return teamcount ;
}

void record(struct team teams[], int teamcount) {
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

    struct team teams[maxteams];

    int id ;
    char name[50];
    int totalwins ;
    int totallosses ;
    int choice ;
    int teamcount = 0 ;

    do {
        printf("\n--- Team Management Menu ---\n");
        printf("1. ADD NEW TEAM\n2. UPDATE TEAM RECORD\n3. READ TEAM RECORD\n4. EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
    
    switch (choice){
    case 1 :
        teamcount = add(teams , teamcount);
        break;
    case 2 :
        teamcount = update(teams, teamcount);
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
}