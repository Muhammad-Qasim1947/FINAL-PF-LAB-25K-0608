// 1. Student Result Management

// Scenario: You are designing a system to manage student exam results. Each student has a roll number,
// name, marks in 5 subjects, and a total score.
// Tasks:

// Create a structure Student to store the information.

// Write a function to input student details.

// Write a function to calculate total marks.

// Write a function to find the topper in the class.

// Write a function to display student details.

// Optional: Use dynamic memory to store n students.

#include <stdio.h>

typedef struct
{
    int roll;
    char name[30];
    int marks[5];
    float totalscore;
} student;

void enterdetails(student record[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter The Details For Student %d : ", i + 1);

        printf("\nEnter The Roll Number : ");
        scanf("%d", &record[i].roll);

        printf("\nEnter The Name : ");
        scanf(" %[^\n]", record[i].name);

        record[i].totalscore = 0;
        for (int j = 0; j < 5; j++)
        {
            printf("\nEnter The Marks : ");
            scanf("%d", &record[i].marks[j]);

            record[i].totalscore += record[i].marks[j];
        }
    }
}

void topper(student record[], int n)
{

    float maxscore = record[0].totalscore;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (record[i].totalscore > maxscore)
        {
            maxscore = record[i].totalscore;
            index = i;
        }
    }
    printf("\nTopper is:\n");
    printf("Roll: %d\n", record[index].roll);
    printf("Name: %s\n", record[index].name);
    printf("Total Score: %.2f\n", record[index].totalscore);
}

void display(student record[], int n)
{
    printf("\nAll Students Details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll Number: %d\n", record[i].roll);
        printf("Name: %s\n", record[i].name);
        printf("Marks: ");
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", record[i].marks[j]);
        }
        printf("\nTotal Score: %.2f\n", record[i].totalscore);
    }
}

void updatemarks(student record[], int n , int rollnum){
    for (int i = 0; i < n ; i++)
    {
        if (record[i].roll == rollnum)
        {
            record[i].totalscore = 0 ;
            for (int j = 0; j < 5 ; j++)
            {
                printf("Enter new mark %d for %s: ", j + 1, record[i].name);
                scanf("%d", &record[i].marks[j]);
                record[i].totalscore += record[i].marks[j];
            }
            printf("Marks updated for %s.\n", record[i].name);
            return;
            
        }
        
    }
    printf("Student with roll %d not found.\n", rollnum);
}

int main()
{
    int n;
    printf("Enter The Number Of Students : ");
    scanf("%d", &n);

    student record[n];

    enterdetails(record, n);
    topper(record, n);
    display(record, n);

    return 0;
}