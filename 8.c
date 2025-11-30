// Write a C program that takes a list of positive integers from the user until -1 is entered. For each positive
// integer, compute its Collatz Conjecture sequence and print the sequence. You are required to implement a
// function with the following signature:
// int* collatzsequence(int input);
// The function collatzSequence receives an input positive integers and retums a pointer (int") that stores the
// Collatz Conjecture sequence for the number. The returned sequence must end with 1 to indicate termination.
// Your program should take input until -1 is entered and print the Collatz Conjecture sequence for each
// positive number entered by the user.
// Input Sample
// 20
// 13
// 40
// -1
// Output Sample 26 5 -> 16 -> 8 -> 4 -> 2 - 1
// 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8-> 4-> 2 -> 1
// 40-> 20 -> 10 -> 5 -> 16-> 8-> 4 -> 2 -> 1
// The collatzSequence function will handle the calculation of the sequence for each number and retum a
// pointer to pointers, each representing a sequence. It will terminate each sequence with -1 to indicate the
// end of the sequence.
// The function is defined as:
// If the current number n is even, divide it by 2: (n / 2).
// If the current number n is odd, multiply it by 3 and add 1: (3n + 1).
// The Collatz function is applied repeatedly to the result obtained from the previous iteration until the sequence
// reaches the value 1

#include <stdio.h>
#include <stdlib.h>

int *collatzsequence(int input)
{
    int capacity = 10;
    int *sequence;

    sequence = malloc(capacity * sizeof(int));

    if (!sequence)
    {
        printf("Memory Allocation Failed !!!");
        return NULL;
    }

    int count = 0;
    int n = input;

    while (n != 1)
    {
        sequence[count++] = n;

        if (count >= capacity)
        {
            capacity *= 2;
            sequence = realloc(sequence, capacity * sizeof(int));

            if (!sequence)
            {
                printf("Memory Re-Allocation Failed !!!");
                return NULL;
            }
        }

        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = 3 * n + 1;
        }
    }
    sequence[count++] = 1;

    return sequence; 
}

int main()
{
    int num;

    printf("Enter positive integers (-1 to exit):\n");

    while (1)
    {                      // loop indefinitely
        scanf("%d", &num); // read input

        if (num == -1)
        { // stop if user enters -1
            break;
        }

        if (num <= 0)
        { // handle invalid input
            printf("Please enter a positive integer or -1 to exit.\n");
            continue;
        }

        int *sequence = collatzsequence(num);

        int i = 0;
        while (1)
        {
            printf("%d", sequence[i]);
            if (sequence[i] == 1)
                break;
            printf(" -> ");
            i++;
        }
        printf("\n");

        free(sequence);
    }

    printf("All inputs processed.\n");
    return 0;
}