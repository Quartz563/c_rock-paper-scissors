//
// Created by quart on 17/03/2024.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int score = 0;
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

int main()
{

}



