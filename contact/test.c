#include "contact.h"
//make contact

void menu(Contact* pc)
{
    printf("***************************************\n");
    printf("******   1.add        2.del      ******\n");
    printf("******   3.search     4.modify   ******\n");
    printf("******   5.showAll    6.sort     ******\n");
    printf("******   0.exit                  ******\n");
    printf("******  You have %3d contact(s)  ******\n",pc->count);
    printf("***************************************\n");
}
int main()
{
    int input=0;
    Contact con;
    InitContact(&con);
    do
    {
        
        menu(&con);

        scanf("%d",&input);
        switch(input)
        {
            case 1://add
                addContact(&con);
                break;
            case 2://delete
                delete(&con);
                break;
            case 3://search
                search(&con);
                break;
            case 4://modify
                modify(&con);
                break;
            case 5://show
                showAll(&con);
                break;
            case 6://sort
                sort(&con);
                break;
            case 0:
                printf("exit content\n");
                break;
            default:
                printf("input error,please try again\n");
        }
        while(getchar()!='\n');      
    } while (input);
    return 0;
}