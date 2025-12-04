#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX_NUMBERS 100

int numberList[MAX_NUMBERS];
int numberCount = 0;

void inputNumbers(){
    int num;
    int oldCount = numberCount;
    
    if (numberCount > 0){
        printf("\nCurrent numbers: ");
        for (int i = 0; i < numberCount; i++)
        {
            printf("%d", numberList[i]);
            if (i < numberCount - 1)
                printf(", ");
        }
        printf("\n");
    }
    
    printf("Enter numbers to add (0 to stop):\n");
    
    while (1){
        if (scanf("%d", &num) != 1) {
            printf("Invalid input! Please enter a number (0 to stop).\n");
            while(getchar() != '\n');
            continue;  
        }

        if (num == 0)
            break;
        if (numberCount < MAX_NUMBERS){
            numberList[numberCount] = num;
            numberCount++;
        }
        else{
            printf("Maximum limit reached!\n");
            break;
        }
    }
    
    int newNumbers = numberCount - oldCount;
    if (newNumbers == 0)
        printf("No new numbers added.\n");
    else
        printf("%d number(s) added! Total: %d\n", newNumbers, numberCount);
}

void displayNumberList(){
    if (numberCount == 0){
        printf("\nNo numbers in the list.\n");
        return;
    }
    
    printf("\nThe numbers are: ");
    for (int i = 0; i < numberCount; i++){
        printf("%d", numberList[i]);
        if (i < numberCount - 1)
            printf(", ");
    }
    printf("\n");
}

void clearNumberList(){
    numberCount = 0;
    printf("\nNumber list cleared!\n");
}

void displayResults(char* operation){
    if (numberCount == 0){
        printf("\nNo numbers in the list. Please input numbers first (Option 1).\n");
        return;
    }
    
    printf("\nThe numbers are: ");
    for (int i = 0; i < numberCount; i++){
        printf("%d", numberList[i]);
        if (i < numberCount - 1)
            printf(", ");
    }
    printf("\nThe operator is: %s\n", operation);
}

void findLargest(){
    if (numberCount == 0){
        printf("\nNo numbers in the list. Please input numbers first (Option 1).\n");
        return;
    }
    
    int largest = numberList[0];
    for (int i = 1; i < numberCount; i++){
        if (numberList[i] > largest)
            largest = numberList[i];
    }
    
    displayResults("Find Largest");
    printf("The answer is: %d\n", largest);
}

void reverseNumbers(){
    if (numberCount == 0){
        printf("\nNo numbers in the list. Please input numbers first (Option 1).\n");
        return;
    }
    
    displayResults("Reverse Number");
    printf("The answers are:\n");
    
    for (int i = 0; i < numberCount; i++){
        int num = numberList[i];
        int reversed = 0, remainder;
        int isNegative = 0;
        
        // Handle negative numbers
        if (num < 0) {
            isNegative = 1;
            num = -num;
        }
        
        int temp = num;
        
        // Handle zero specially
        if (temp == 0) {
            printf("  %s%d -> 0\n", isNegative ? "-" : "", 0);
            continue;
        }
        
        while (temp != 0){
            remainder = temp % 10;
            reversed = reversed * 10 + remainder;
            temp /= 10;
        }
        
        if (isNegative) {
            printf("  -%d -> -%d\n", num, reversed);
        } else {
            printf("  %d -> %d\n", num, reversed);
        }
    }
}

void strongNumbers(){
    if (numberCount == 0){
        printf("\nNo numbers in the list. Please input numbers first (Option 1).\n");
        return;
    }
    
    displayResults("Strong Number Check");
    
    for (int i = 0; i < numberCount; i++){
        int num = numberList[i];
        
        // Strong numbers are only defined for non-negative integers
        if (num < 0) {
            printf("  %d is NOT a Strong number (negative numbers not applicable)\n", num);
            continue;
        }
        
        int temp = num;
        int sum = 0;
        
        while (temp != 0){
            int remainder = temp % 10;
            int fact = 1;
            for (int j = 1; j <= remainder; j++)
            {
                fact *= j;
            }
            sum += fact;
            temp /= 10;
        }
        
        if (sum == num)
            printf("  %d is a Strong number! (sum: %d)\n", num, sum);
        else
            printf("  %d is NOT a Strong number (sum: %d)\n", num, sum);
    }
}

void cubeRoots(){
    if (numberCount == 0){
        printf("\nNo numbers in the list. Please input numbers first (Option 1).\n");
        return;
    }
    
    displayResults("Cube Root");
    printf("The answers are:\n");  
    double sum = 0;
    
    for (int i = 0; i < numberCount; i++){
        double result = cbrt(numberList[i]);
        sum += result;
        printf("  cbrt(%d) = %.4lf\n", numberList[i], result);  
    }
    printf("The sum is: %.4lf\n", sum);
}


int main(){
    int choice;
    char tryAgain;
    
    while (1){
        printf("\n=== Group 5 Super Calculator ===\n");
        printf("[1] Input numbers\n");
        printf("[2] View number list\n");
        printf("[3] Find largest\n");
        printf("[4] Reverse numbers\n");
        printf("[5] Strong number check\n");
        printf("[6] Cube root\n");
        printf("[7] Clear number list\n");
        printf("[0] Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number (0-7).\n");
            while(getchar() != '\n');
            continue;
        }
        
        if (choice == 0){
            printf("The program will now close.\n");
            return 0;
        }

        if (choice == 1){
            inputNumbers();
            continue;
        }
        else if (choice == 2){
            displayNumberList();
            continue;
        }
        else if (choice == 7){
            clearNumberList();
            continue;
        }
        else if (choice < 0 || choice > 7){
            printf("Invalid choice. Please select 0-7.\n");
            continue;
        }
        
        switch (choice)
        {
        case 3:
            findLargest();
            break;
        case 4:
            reverseNumbers();
            break;
        case 5:
            strongNumbers();
            break;
        case 6:
            cubeRoots();
            break;
        }
        
        // Ask if user wants to continue
        while (1) {
            printf("\nDo you want to continue using the calculator? (Y/N): ");
            scanf(" %c", &tryAgain);
            tryAgain = toupper(tryAgain);
            
            if (tryAgain == 'Y' || tryAgain == 'N') {
                break;
            }
            printf("Invalid input. Please enter Y or N.\n");
        }

        if(tryAgain == 'N') {
            printf("The program will close now.\n");
            return 0;
        }
    }
    return 0;
}