//
// Created by quart on 17/03/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char selection;


int game(char user, char comp)
{
    if(user == comp)
    {
        return -1;
    }
    if(user == 'r')
    {
        if(comp == 'p')
        {
            return 0;
        }
        if( comp == 's')
        {
            return 1;
        }

    }
    if(user == 'p')
    {
        if(comp == 's')
        {
            return 0;
        }
        if(comp == 'r')
        {
            return 1;
        }
    }
    if(user == 's')
    {
        if(comp == 'r')
        {
            return 0;
        }
        if(comp == 'p')
        {
            return 1;
        }
    }
    return -1;
}

int continue_game()
{
    char response;
    printf("Would you like to play again? y/n\n");
    scanf("%c", &response);
    if(response == 'y'){
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    while(1){
        char comp_select;
        int rng, result;
        printf("Enter your selection of (r)ock, (p)aper, (s)cissors.\n");
        scanf("%c", &selection);
        srand(time(NULL));
        rng = rand() % 100;
        if(rng < 33) {
            comp_select = 's';
        } else if(rng > 33 && rng < 66) {
            comp_select = 'p';
        } else {
            comp_select = 'r';
        }
        result = game(selection, comp_select);
        if(result == -1){
            printf("The game was a draw! User: %c, Computer: %c\n", selection, comp_select);
        } else if(result == 0) {
            printf("You have lost this game. User: %c, Computer: %c\n", selection, comp_select);
        } else {
            printf("You have won this game. User: %c, Computer: %c\n", selection, comp_select);
        }

        if(continue_game() != 1){
            break;
        }
    }

    return 0;
}



