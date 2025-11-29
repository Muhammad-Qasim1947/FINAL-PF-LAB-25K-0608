// Create a C program that helps students calculate SGPA and CGPA. Student will provide the following input
// via console, course_id, gpa, credit_hours, semester_number. SGPA is product sum of gpa and credit_hours
// divided by the sum of credit_hours for a particular semester. CGPA is same but for all the courses. For
// repeated course_id count the one with highest gpa for CGPA, also remember to include the credit_hours
// only once when taking sum of credit_hours. You must use structures to hold information for one course.
// Make an array of this structure to store information of all courses.
// Input Sample
// 101 3.00 31
// 102 2.3331
// 108 1.3311
// 108 2.3312
// 201 3.33 32
// 202 3.6712
// Output Sample
// Semester 1:2.47
// Semester 2: 2.75
// CGPA: 2.71

#include <stdio.h>
#include <string.h>

#define maxcourse 50

typedef struct
{
    int course_id;
    float gpa;
    int credit_hours;
    int semester_number;
    int sgpa;
} course;

int main()
{
    course courses[maxcourse];

    int n;
    int sem;

    printf("Enter The Number Of Courses : ");
    scanf("%d", &n);

    printf("Enter The Following Details : \n1. Course Id \n2. GPA \n3. Credit Hours\n4. Semester Number\n");

    for (int i = 0; i < maxcourse; i++)
    {
        scanf("%d %f %d %d", &courses[i].course_id, &courses[i].gpa,
              &courses[i].credit_hours, &courses[i].semester_number);
    }

    // calculating sgpa

    for (sem = 1; sem < 8; sem++)
    {
        float gpaxcredit = 0;
        int sumofcredit = 0;
        int has_courses = 0;

        for (int i = 0; i < n; i++)
        {
            if (courses[i].semester_number == sem)
            {
                gpaxcredit += courses[i].gpa * courses[i].credit_hours;
                sumofcredit += courses[i].credit_hours;
                has_courses = 1;
            }
        }

        if (has_courses)
        {
            printf("Semester %d: %.2f\n", sem, gpaxcredit / sumofcredit);
        }
    }

    // calculating cgpa
    float cgpa_total = 0;
    int cgpa_credits = 0;
    int counted[n];

    for (int i = 0; i < n; i++)
    {
        counted[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (counted[i] == 0)
        {
            int best = i;
            for (int j = i + 1; j < n; j++)
            {
                if (courses[j].course_id == courses[i].course_id && courses[j].gpa > courses[best].gpa)
                {
                    best = j;
                }
            }
            cgpa_total += courses[best].gpa * courses[best].credit_hours;
            cgpa_credits += courses[best].credit_hours;
            // Mark all courses with same course_id as counted
            for (int j = i; j < n; j++)
            {
                if (courses[j].course_id == courses[i].course_id)
                    counted[j] = 1;
            }
        }
    }

float CGPA = cgpa_total / cgpa_credits;
printf("CGPA: %.2f\n", CGPA);

return 0 ;
}