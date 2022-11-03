/*
Asim Ali
4/8/2022
Mutual Fund Rating & Risk Calculator
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Function prototype computing compounding interest
double compoundInterest(double amount, double principal, double interest, int years);

int main(void)
{
    char ticker[6];
    int inception = 0, capSize = 0, fundType = 0, menuChoice = 0, rating = 5;
    double ER = 0, TR = 0, APY = 0, tenYearAPY = 0;

    do
    {
        printf("Enter a menu choice:\n");
        printf("1. Assess a mutual fund's overall rating\n");
        printf("2. Compare a mutual fund to it's respective index given the last 10 years of returns\n");
        printf("3. Calculate the future value of your portfolio\n");
        printf("4. Exit\n");
        scanf("%d", &menuChoice);

        switch (menuChoice)
        {
        case 1:
        {

            printf("Enter the fund's ticker symbol: ");
            scanf("%s", &ticker);

            printf("Enter %s's inception year: ", ticker);
            scanf("%d", &inception);

            printf("Enter %s's expense ratio: ", ticker);
            scanf("%lf", &ER);

            printf("Enter %s's turnover rate: ", ticker);
            scanf("%lf", &TR);

            printf("Enter %s's average annual rate of return since %d: ", ticker, inception);
            scanf("%lf", &APY);

            printf("Enter %s's average annual rate of return for the last 10 years: ", ticker);
            scanf("%lf", &tenYearAPY);

            // Calculating ratings based off general criteria
            if ((2022 - inception) <= 20)
            {
                rating--;
            }
            if (ER > 0.80)
            {
                rating--;
            }
            if (TR > 40)
            {
                rating--;
            }
            if (APY < 10)
            {
                rating--;
            }
            if (tenYearAPY < 14)
            {
                rating--;
            }
            // Printing results
            if (rating <= 2)
            {
                printf("\n%s's rating of %d is poor!\n\n", ticker, rating);
            }
            else if (rating == 3)
            {
                printf("\n%s's rating of %d is fair!\n\n", ticker, rating);
            }
            else if (rating > 3)
            {
                printf("\n%s's rating of %d is great!\n\n", ticker, rating);
            }
        }
        break;
        case 2:
        {
            printf("Enter the fund's ticker symbol: ");
            scanf("%s", &ticker);

            printf("Enter %s's average annual rate of return for the last 10 years: ", ticker);
            scanf("%lf", &tenYearAPY);

            // Prompting user to enter mutual fund cap size
            printf("\nEquity sizes are broken up into small, medium & large cap.\n");
            printf("Enter 1 for small, 2 for medium, or 3 for large: ");
            scanf("%d", &capSize);
            if (capSize != 1 && capSize != 2 && capSize != 3)
            {
                printf("Invalid entry...\n");
                exit(1);
            }
            // Prompting the user to enter fund style
            printf("\nEquities are classified in three different catagories.\n");
            printf("Enter 1 if the fund is considered value, 2 for blend, or 3 for growth: ");
            scanf("%d", &fundType);
            if (fundType != 1 && fundType != 2 && fundType != 3)
            {
                printf("Inavlid entry...\n");
                exit(1);
            }
            // Declaration & initialization of mutual fund cap size & fund style variables
            double SCV = 12.53, SCB = 12.52, SCG = 11.87;
            double MCV = 12.42, MCB = 13.87, MCG = 13.31;
            double LCV = 11.55, LCB = 14.64, LCG = 17.07;

            // Conditionals for the result of user entry of fund cap size & style
            if (capSize == 1 && fundType == 1)
            {
                printf("\n%s returned %.2f over the last 10 years while its compared index of small cap value returned %.2f\n\n", ticker, tenYearAPY, SCV);
            }
            else if (capSize == 1 && fundType == 2)
            {
                printf("\n%s returned %.2f%% over the last 10 years while its compared index of small cap blend returned %.2f%%\n\n", ticker, tenYearAPY, SCB);
            }
            else if (capSize == 1 && fundType == 3)
            {
                printf("\n%s returned %.2f%% over the last 10 years while its compared index of small cap growth returned %.2f%%\n\n", ticker, tenYearAPY, SCG);
            }
            else if (capSize == 2 && fundType == 1)
            {
                printf("\n%s returned %.2f%% over the last 10 years while its compared index of mid cap value returned %.2f%%\n\n", ticker, tenYearAPY, MCV);
            }
            else if (capSize == 2 && fundType == 2)
            {
                printf("\n%s returned %.2f%% over the last 10 years while its compared index of mid cap blend returned %.2f%%\n\n", ticker, tenYearAPY, MCB);
            }
            else if (capSize == 2 && fundType == 3)
            {
                printf("\n%s returned %.2f%% over the last 10 years while its compared index of mid cap growth returned %.2f%%\n\n", ticker, tenYearAPY, MCG);
            }
            else if (capSize == 3 && fundType == 1)
            {
                printf("\n%s returned %.2f%% over the last 10 years while its compared index of large cap value returned %.2f%%\n\n", ticker, tenYearAPY, LCV);
            }
            else if (capSize == 3 && fundType == 2)
            {
                printf("\n%s returned %.2f%% over the last 10 years while its compared index of large cap blend returned %.2f%%\n\n", ticker, tenYearAPY, LCB);
            }
            else if (capSize == 3 && fundType == 3)
            {
                printf("\n%s returned %.2f%% over the last 10 years while its compared index of large cap growth returned %.2f%%\n\n", ticker, tenYearAPY, LCG);
            }
        }
        break;
        case 3:
        {
            char newTicker[6];
            double A = 0, P = 0, r = 0;
            int n = 0;

            printf("Enter the fund's ticker symbol: ");
            scanf("%s", &newTicker);

            printf("Enter your starting principle: ");
            scanf("%lf", &P);

            printf("Enter %s's anticipated APY: ", newTicker);
            scanf("%lf", &r);

            printf("Enter the years would you like this fund invested: ");
            scanf("%d", &n);

            double result = compoundInterest(A, P, r, n);
            printf("\nIf invested in %s, your total amount in %d years would be $%.2f!\n\n", newTicker, n, result);
        }
        break;
        case 4:
        {
            printf("Exiting program...\n\n");
            exit(1);
        }
        break;
        default:
            printf("Invalid Input\n\n");
            break;
        }
    } while (menuChoice != 11);

    return 0;
}

// Function definition computing compounding interest
double compoundInterest(double amount, double principal, double interest, int years)
{

    amount = principal * pow((1.0 + interest / 100.0), (double)years);

    return amount;
}