#include <stdio.h>
#include <string.h>

typedef struct
{
    int employee_id;
    char name[20];
    char designation[20];
    float salary;
} record;

void displayemployee(record employee[], int n)
{
    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%-10d %-20s %-20s %-10.2f\n",
               employee[i].employee_id,
               employee[i].name,
               employee[i].designation,
               employee[i].salary);
    }
}

void highest_salary(record employee[], int n)
{

    int maxsalary = 0;

    for (int i = 0; i < n; i++)
    {
        if (employee[i].salary > employee[maxsalary].salary)
        {
            maxsalary = i;
        }
    }
    printf("\nEmployee with Highest Salary:\n");
    printf("%-10d %-20s %-20s %-10.2f\n",
           employee[maxsalary].employee_id,
           employee[maxsalary].name,
           employee[maxsalary].designation,
           employee[maxsalary].salary);
}

void search_employee(record employee[], int n)
{
    int choice;
    printf("Enter The Choice : \n");
    printf("1. Name\n");
    printf("2. ID\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        char name[20];
        int found = 0;
        printf("Enter The Name : \n");
        scanf(" %[^\n]", name);

        for (int i = 0; i < n; i++)
        {
            if (strcmp(employee[i].name, name) == 0)
            {
                printf("%-10d %-20s %-20s %-10.2f\n",
                       employee[i].employee_id,
                       employee[i].name,
                       employee[i].designation,
                       employee[i].salary);
                found = 1;
            }
        }
        if (!found)
            printf("Employee with name %s not found.\n", name);
        break;

    case 2:
        int id;
        int found1 = 0;
        printf("Enter The id : \n");
        scanf("%d", &id);

        for (int i = 0; i < n; i++)
        {
            if (employee[i].employee_id == id)
            {
                printf("%-10d %-20s %-20s %-10.2f\n",
                       employee[i].employee_id,
                       employee[i].name,
                       employee[i].designation,
                       employee[i].salary);
                found1 = 1;
            }
        }
        if (!found1)
            printf("Employee with id %d not found.\n", id);
        break;
    default:
        printf("Invalid Choice");
        break;
    }
}

void give_bonus(record employee[], int n, float threshold)
{
    for (int i = 0; i < n; i++)
    {
        if (employee[i].salary < threshold)
        {
            employee[i].salary *= 1.10; // increase by 10%
        }
    }
}

int main()
{
    int n;
    int threshold = 50000;
    printf("Enter Number Of Employees :");
    scanf("%d", &n);

    record employee[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Details For Employee %d : ", i + 1);

        printf("ENTER EMPLOYEE ID : ");
        scanf("%d", &employee[i].employee_id);

        printf("ENTER EMPLOYEE NAME : ");
        scanf(" %[^\n]", employee[i].name);

        printf("ENTER EMPLOYEE DESIGNATION : ");
        scanf(" %[^\n]", employee[i].designation);

        printf("ENTER EMPLOYEE SALARY : ");
        scanf("%f", &employee[i].salary);
    }

    displayemployee(employee, n);
    highest_salary(employee, n);
    search_employee(employee, n);
    give_bonus(employee, n, threshold);
}