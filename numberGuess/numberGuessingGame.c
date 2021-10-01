#include <time.h>
#include <stdio.h>
#include <stdbool.h>

int mainGame(int *userInput)
{
    printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\nEnter Here: ");
    scanf("%d", userInput);
    return 0;
}

int main()
{
    int input;
    int randomNumber;
    int MaxNumber = 10;
    char check;
    bool endgame = false; 
    time_t t;
    srand((unsigned) time(&t));

    while(!endgame)
    {
        mainGame(&input);
        randomNumber = rand() % MaxNumber;
        //printf("%d", input);
        if(input == 1)
        {
            while(!endgame)
            {
                printf("Enter a number: ");
                scanf("%d", &input);
                check = getchar();
                if(check == 'q')
                {
                    break;
                } else
                {
                    if(input == randomNumber)
                    {
                        printf("You won the game\n");
                        break;
                    } else if(input < randomNumber)
                    {
                        printf("Your guess was too low\n");
                    } else if(input > randomNumber)
                    {
                        printf("Your guess was too high\n");
                    }
                }
                
            }
        } else if(input == 2)
        {
            bool validValue = false;
            while(!validValue)
            {
                printf("Enter a new Max Value: ");
                scanf("%d", &MaxNumber);
                if(MaxNumber > 10 || MaxNumber < 1)
                {
                    printf("Invalid Value\n");
                } else
                {
                    validValue = true;
                    break;
                }
            }
        } else if(input == 3)
        {
            printf("Leaving");
            break;
        }
    }
    return 0;
}