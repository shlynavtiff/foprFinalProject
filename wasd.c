#include <stdio.h>
#include <math.h>

void findLargest()
{
    int num, largest = -999999;

    printf("\nEnter numbers (0 to stop):\n");
    while (1)
    {
        scanf("%d", &num);
        if (num == 0)
            break;
        if (num > largest)
            largest = num;
    }

    printf("The largest number is: %d\n", largest);
}

void reverseNumber()
{
    int num, reversed = 0, remainder;

    printf("\nEnter a number to reverse: ");
    scanf("%d", &num);

    while (num != 0)
    {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    printf("Reversed number: %d\n", reversed);
}

void strongNumber()
{
    int num, temp, remainder;
    int sum = 0;
    int i, fact;

    printf("\nEnter a number: ");
    scanf("%d", &num);
    temp = num;

    while (temp != 0)
    {
        remainder = temp % 10;
        fact = 1;
        for (i = 1; i <= remainder; i++)
        {
            fact *= i;
        }
        sum += fact;
        temp /= 10;
    }

    if (sum == num)
        printf("%d is a Strong number!\n", num);
    else
        printf("%d is NOT a Strong number.\n", num);
}

void cubeRoot()
{
    double num;
    printf("\nEnter a number to find its cube root: ");
    scanf("%lf", &num);

    double result = cbrt(num);

    printf("Cube root of %.2lf is %.4lf\n", num, result);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n=== GROUP 5 MENU ===\n");
        printf("[1] Largest number\n");
        printf("[2] Reverse number\n");
        printf("[3] Strong number\n");
        printf("[4] Cube root\n");
        printf("[0] Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            findLargest();
            break;
        case 2:
            reverseNumber();
            break;
        case 3:
            strongNumber();
            break;
        case 4:
            cubeRoot();
            break;
        case 0:
            printf("The program will now close.\n");
            return 0;
        default:
            printf("Invalid choice. Please Try again.\n");
        }
    }

    return 0;
}
