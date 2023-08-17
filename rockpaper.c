#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//computer generating
int gen(int x)
{
    srand(time(NULL));
    return rand() % x;
}

//comparing outcomes
int greater(char c1, char c2)
{
    //returns 1 if c1>c2, 0 otherwise. And return -1 if c1==c2
    if (c1 == c2)
    {
        return -1;
    }
    else if ((c1 == 'r') && (c2 == 's'))
    {
        return 1;
    }
    else if ((c2 == 'r') && (c1 == 's'))
    {
        return 0;
    }
    else if ((c1 == 'p') && (c2 == 'r'))
    {
        return 1;
    }
    else if ((c2 == 'p') && (c1 == 'r'))
    {
        return 0;
    }
    else if ((c1 == 's') && (c2 == 'p'))
    {
        return 1;
    }
    else if ((c2 == 's') && (c2 == 'p'))
    {
        return 0;
    }
}

int main()
{
    int a;
    int playerscore, compscore;
    char player, comp;
    char dict[] = {'r', 'p', 's'};

    printf("Welcome to Rock-Paper-Scissors\n\n");

    for (int i = 0; i < 3; i++)
    {
        //player turns
        printf("Player Turns\n");
        printf("Enter\n 1 for Rock\n 2 for Paper\n 3 For Scissor\n");
        scanf("%d", &a);
        getchar();
        player = dict[a - 1];
        printf("You chose %c\n\n", player);

        //computer turns
        printf("Computer Turns\n");
        a = gen(3) + 1;
        comp = dict[a - 1];
        printf("Computer chose %c\n\n", comp);

        //comparing Scores
        if (greater(comp, player) == 1)
        {
            compscore +=1;
            printf("Computer got the point\n\n");
        }
        else if (greater(comp, player) == -1)
        {
            playerscore +=1;
            compscore +=1;
            printf("DRAW\n\n");
        }
        else
        {
            playerscore +=1;
            printf("Player got the point\n\n");
        }

        // printf("Player: %d\n Computer: %d\n", playerscore, compscore); //Displaying points  
    }

    //Checking total points
    if (playerscore > compscore)
    {
        printf("Player wins the game\n");
    }
    else if (playerscore < compscore)
    {
        printf("Computer wins the game\n");
    }
    else
    {
        printf("Its a Draw\n");
    }

    return 0;
}