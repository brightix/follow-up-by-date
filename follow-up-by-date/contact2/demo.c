#include "contact.h"

void menu(Con* pc)
{   
    time_t now;
    struct tm localTime;
    time(&now);
    localtime_s(&localTime,&now);

    printf("************************************\n");
    printf("****     %4d/%02d/%02d   %02d:%02d     ****\n",localTime.tm_year + 1900,localTime.tm_mon + 1,localTime.tm_mday,localTime.tm_hour,localTime.tm_min);
    printf("************************************\n");
    printf("****    1.增加        2.删除    ****\n");
    printf("****    3.查找        4.修改    ****\n");
    printf("****    5.展示        6.整理    ****\n");
    printf("****    0.保存并退出            ****\n");
    printf("************************************\n");
    printf("****  您当前已收录%3d位 联系人  ****\n",pc->count);
    printf("************************************\n");
    printf("请输入你想要进行的操作:>");
}

int main()
{
    char input=0;
    Con con;
    initContact(&con);
    loadContact(&con);
    do
    {
        menu(&con);
        if(scanf(" %c",&input)!=1)//用户选择输入
            {
                while(getchar()!='\n');
                printf("操作指令输入错误，请重试\n");
                continue;
            }
        switch(input)
        {
            case ADD:
                addContact(&con);
                break;
            case DEL:
                delContact(&con);
                break;
            case SEARCH:
                searchContact(&con);
                break;
            case MODIFY:
                modContact(&con);
                break;
            case SHOW:
                showContact(&con);
                break;
            case SORT:
                sortContact(&con);
                break;
            case EXIT:
                saveContact(&con);
                destroy(&con);

                break;
            default:
                printf("操作指令输入错误，请重试\n");
                break;
        }
        printf("———————————————————————————分隔符———————————————————————————\n");
    }while(input!=48);
    printf("按任意键退出...\n");
    while(getchar() != '\n');
    getchar();
    return 0;
}