#include <stdio.h>

//who is the murder

int main()
{
    int killer = 0;

    for(killer='a';killer<='d';killer++)
    {
        if((killer!='a')+(killer=='c')+(killer=='d')+(killer!='d')==3)
        {
            printf("killer is %c\n",killer);
            break;            
        }

    }       
    return 0;
}