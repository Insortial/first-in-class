/*
    This program uses a while loop to bring up a menu that presents the player with options. The player inputs a number
    which brings them to the three different cases. For the first case it places them in an endless loop which can be 
    exited via guessing the correct number or typing q.  The second case places users in an endless loop that can only
    be exited if you put in a valid max number for the program to randomly pull from. The final case exits users from 
    the program.
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int mainGame(int *userInput)
{
    //Brings up the menu 
    printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\nEnter Here: ");
    scanf("%d", userInput);
    getchar();
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
    
    //Creates an endless loop that can only be broken out of via inputting 3 into the menu 
    while(true)
    {
        mainGame(&input);
        MaxNumber -= 1;
        randomNumber = (rand() % MaxNumber) + 1;
        if(input == 1)
        {
            //Creates an endless loop that will only be broken out of if you have won the game
            while(true)
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
            //Creates an endless loop that can only be broken out of if the user has entered a valid max value
            while(true)
            {
                printf("Enter a new Max Value: ");
                scanf("%d", &MaxNumber);
                if(MaxNumber > 10 || MaxNumber < 1)
                {
                    printf("Invalid Value\n");
                } else
                {
                    break;
                }
            }
        } else if(input == 3)
        {
            printf("Leaving");
            break;
        } else 
        {
            printf("Invalid value\n");
        }
    }
    return 0;
}