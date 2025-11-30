#include <stdio.h>

int main()
{
    int arr[5][4] = {
        {33, 3, 159, 0},
        {234, 122, 351, 0},
        {100, 140, 19, 0},
        {53, 310, 76, 0},
        {111, 2, 4, 0}};

    int capacity[3] = {300, 500, 200};

    int totals[5];  // store total customers of each district

    int maxDistrict = 0, minDistrict = 0;
    int maxTotal = 0, minTotal = 999999;

    // ---------- TOTAL CUSTOMERS PER DISTRICT ----------
    printf("\n--- TOTAL CUSTOMERS PER DISTRICT ---\n");

    for (int i = 0; i < 5; i++)
    {
        int sum = 0;

        for (int j = 0; j < 4; j++)
        {
            sum += arr[i][j];
        }

        totals[i] = sum;

        printf("District %d total customers = %d\n", i, sum);

        // Track max profit district
        if (sum > maxTotal)
        {
            maxTotal = sum;
            maxDistrict = i;
        }

        // Track min profit district
        if (sum < minTotal)
        {
            minTotal = sum;
            minDistrict = i;
        }
    }

    // ---------- MAX CUSTOMER OF EACH ROW ----------
    printf("\n--- MAX CUSTOMER VALUE PER DISTRICT (BRANCH) ---\n");

    for (int i = 0; i < 5; i++)
    {
        int maxprofit = arr[i][0];

        for (int j = 1; j < 4; j++)
        {
            if (arr[i][j] > maxprofit)
            {
                maxprofit = arr[i][j];
            }
        }

        printf("District %d max branch customers = %d\n", i, maxprofit);
    }

    // ---------- MOST & LEAST PROFIT DISTRICT ----------
    printf("\n--- MOST & LEAST PROFIT DISTRICT ---\n");

    printf("Most profit: District %d (%d customers)\n", maxDistrict, maxTotal);
    printf("Least profit: District %d (%d customers)\n", minDistrict, minTotal);

    // ---------- CAPACITY UTILIZATION ----------
    printf("\n--- CAPACITY UTILIZATION PER DISTRICT ---\n");

    for (int i = 0; i < 5; i++)
    {
        printf("\nDistrict %d:\n", i);

        float maxUtil = -1;
        int maxBranch = 0;

        for (int j = 0; j < 3; j++)
        {
            float util = (arr[i][j] / (float)capacity[j]) * 100;

            printf("  Branch %d utilization = %.2f%%\n", j + 1, util);

            if (util > maxUtil)
            {
                maxUtil = util;
                maxBranch = j;
            }
        }

        printf("  -> Branch %d has HIGHEST utilization in district %d (%.2f%%)\n",
               maxBranch + 1, i, maxUtil);
    }

    return 0;
}

