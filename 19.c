// 10. Recursive Game Score Tracker

// Scenario: In a game, the player earns points each level. Some levels have bonus points.
// Task: Write calculateScore(level, basePoints, bonusLevels[], bonusPoints[]) recursively to 
// print the score after each level and total score.

// Concepts: Base case is last level; recursion handles incremental score updates and conditional bonuses.

#include <stdio.h>

int calculateScore(int level, int totalLevels, int basePoints, int bonusLevels[], int bonusPoints[], int bonusCount){
    if(level > totalLevels) {
        return 0;  // Base case: no more levels
    }
        int score = basePoints;

    // Check if current level has a bonus
    for(int i = 0; i < bonusCount; i++) {
        if(bonusLevels[i] == level) {
            score += bonusPoints[i];
            break;
        }
    }

    printf("Level %d: Score = %d\n", level, score);

    // Recursive call for next level
    return score + calculateScore(level + 1, totalLevels, basePoints, bonusLevels, bonusPoints, bonusCount);
}

int main(){
    int totalLevels, basePoints, bonusCount;

    printf("Enter total levels: ");
    scanf("%d", &totalLevels);

    printf("Enter base points per level: ");
    scanf("%d", &basePoints);

    printf("Enter number of bonus levels: ");
    scanf("%d", &bonusCount);

    int bonusLevels[bonusCount], bonusPoints[bonusCount];

        for(int i = 0; i < bonusCount; i++) {
        printf("Enter bonus level and points: ");
        scanf("%d %d", &bonusLevels[i], &bonusPoints[i]);
    }

    int totalScore = calculateScore(1, totalLevels, basePoints, bonusLevels, bonusPoints, bonusCount);
    printf("Total Score: %d\n", totalScore);

    return 0 ;
}