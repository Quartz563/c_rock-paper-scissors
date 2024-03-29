//
// Created by quart on 17/03/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char selection;


int game(char user, char comp)
{
    if(user == comp){
        return -1;
    }
    if(user == 'r'){
        if(comp == 'p'){
            return 0;
        }
        if( comp == 's'){
            return 1;
        }

    }
    if(user == 'p'){
        if(comp == 's'){
            return 0;
        }
        if(comp == 'r'){
            return 1;
        }
    }
    if(user == 's'){
        if(comp == 'r'){
            return 0;
        }
        if(comp == 'p'){
            return 1;
        }
    }
    return -1;
}

int validate_inputs(char input, char options[])
{
    for(int i = 0; i < sizeof(options)/sizeof(options[0]); i++){
        if(options[i] == input){
            return 1;
        }
    }
    return 0;
}

int continue_game()
{
    char response,  yn_options[] = {'y', 'n'};;
    printf("Would you like to play again? y/n\n");
    scanf(" %c", &response);
    if(validate_inputs(selection, yn_options) != 1){
        printf("Incorrect option provided. Please re-read the message and select a correct option.");
        return -1;
    }
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
        char rps_options[] = {'r', 'p', 's'};
        printf("Enter your selection of (r)ock, (p)aper, (s)cissors.\n");
        scanf(" %c", &selection);
        if(validate_inputs(selection, rps_options) != 1){
            printf("Incorrect option provided. Please re-read the message and select a correct option.");
            continue;
        }
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
        if(continue_game() == -1){
            continue;
        }
        if(continue_game() != 1){
            break;
        }
    }
    return 0;
}



