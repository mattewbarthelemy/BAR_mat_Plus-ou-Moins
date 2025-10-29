#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int difficulty = 0;
int randomMax;
bool help = false;
bool gameon = false;
char str[100];
int secret;
int gamenb;

int main()
{
    srand(time(0));
    printf("Welcome in More Or Less !\n");
    Menu();
    return 0;
}

int Menu()
{
    while (difficulty < 1 || difficulty > 3)
    {
        printf("\nSelect your difficulty : \n*=*=*=*=*=*=*=*=*=*=*=*\n\n1 = Max 100\n2 = Max 1000\n3 = Max 10000");
        printf("\n\n*=*=*=*=*=*=*=*=*=*=*=*\n\n");
        scanf_s("%d", &difficulty);

        if (difficulty >= 1 && difficulty <= 3)
        {
            if (difficulty == 1)
            {
                randomMax = 100;
            }
            if (difficulty == 2)
            {
                randomMax = 1000;
            }
            if (difficulty == 3)
            {
                randomMax = 10000;
            }
        }
        else
        {
            printf("Please select a difficulty\n");
        }
    }
    printf("you choosed : %d\n", difficulty);
    secret = (rand() % randomMax) + 1;

    while (!gameon)
    {
        printf("Do you want help in the game ? (y/n)\n");
        scanf_s("%s", str, (unsigned)sizeof(str));

        if (strcmp(str, "y") == 0)
        {
            help = true;
            gameon = true;
            printf("I'll help you then\n\nQLet's start !\n\n*=*=*=*=*=*=*=*=*=*=*=*\n\n");
        }
        else if (strcmp(str, "n") == 0)
        {
            help = false;
            gameon = true;
            printf("i'll not help you then\n\nLet's start !\n\n*=*=*=*=*=*=*=*=*=*=*=*\n\n");
        }
        else
        {
            printf("*=*=*=*=*=*=*=*=*=*=*=*\n\nPlease answer with 'y' or 'n' !\n\n*=*=*=*=*=*=*=*=*=*=*=*\n\n");
        }
    }
    Gameplaying();
    return 0;
}

int Gameplaying()
{
    int try = 0;
    int choice = 0;
    bool yes = false;
    int fail = 0;
    gamenb++;
    if (help)
    {
        while (secret != choice)
        {
            scanf_s("%d", &choice);
            try++;
            int dif = abs(secret - choice);
            if (choice > randomMax)
            {
                fail++;

                if (fail >= 3)
                {
                    printf("\nnYou know what, let's stop there\n\n\n\n\n\n\nBye !\n\n\n\n\n\n\n");
                    exit(0);
                }

                printf("Are you serious? The maximum is %d!\n\n", randomMax);
                continue;
            }
            else if (secret < choice)
            {
                if (dif > randomMax * 0.5)
                {
                    printf("it's alot less\n\n");
                }
                else if (dif > randomMax * 0.2)
                {
                    printf("it's less\n\n");
                }
                else if (dif > randomMax * 0.1)
                {
                    printf("it's less, but you're getting close\n\n");
                }
                else if (dif > randomMax * 0.05)
                {
                    printf("Very close, but it's less\n\n");
                }
                else
                {
                    printf("Very very close, but it's less\n\n");
                }
            }
            else if (secret > choice)
            {
                if (dif > randomMax * 0.5)
                {
                    printf("it's alot more\n\n");
                }
                else if (dif > randomMax * 0.2)
                {
                    printf("it's more\n\n");
                }
                else if (dif > randomMax * 0.1)
                {
                    printf("it's more, but you're getting close\n\n");
                }
                else if (dif > randomMax * 0.05)
                {
                    printf("Very close, but it's more\n\n");
                }
                else
                {
                    printf("Very very close, but it's more\n\n");
                }
            }
        }
    }
    else
    {
        while (secret != choice)
        {
            scanf_s("%d", &choice);
            try++;
            if (choice > randomMax)
            {
                fail++;

                if (fail >= 3)
                {
                    printf("\n\nYou know what, let's stop there\n\n\n\n\n\n\n\nBye !\n\n\n\n\n\n\n");
                    exit(0);
                }

                printf("Are you serious? The maximum is %d!\n\n", randomMax);
                continue;
            }
            else if (secret < choice)
            {
                printf("It's less\n\n");
            }
            else if (secret > choice)
            {
                printf("it's more\n\n");
            }
        }
    }
    gamenb++;
    printf("You won! You made it in %d tries\n", try);
    while (!yes)
    {
        printf("Do you want to play again ? (y/n)\n");
        scanf_s("%s", str, (unsigned)sizeof(str));  
        if (strcmp(str, "y") == 0)
        {
            gameon = false;
            difficulty = 0;
            Menu();
            return 0;
        }
        else if (strcmp(str, "n") == 0)
        {
            printf("\n\n*=*=*=*=*=*=*=*=*=*=*=*\n\nThank you for playing my game\n\n*=*=*=*=*=*=*=*=*=*=*=*\n\nYou played %d games\n\n", gamenb);
            yes = true;
        }
        else
        {
            printf("*=*=*=*=*=*=*=*=*=*=*=*\n\nPlease answer with 'y' or 'n' !\n\n*=*=*=*=*=*=*=*=*=*=*=*\n\n");
        }
    }
    return 0;
}