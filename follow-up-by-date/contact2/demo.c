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
    printf("****    1.����        2.ɾ��    ****\n");
    printf("****    3.����        4.�޸�    ****\n");
    printf("****    5.չʾ        6.����    ****\n");
    printf("****    0.���沢�˳�            ****\n");
    printf("************************************\n");
    printf("****  ����ǰ����¼%3dλ ��ϵ��  ****\n",pc->count);
    printf("************************************\n");
    printf("����������Ҫ���еĲ���:>");
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
        if(scanf(" %c",&input)!=1)//�û�ѡ������
            {
                while(getchar()!='\n');
                printf("����ָ���������������\n");
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
                printf("����ָ���������������\n");
                break;
        }
        printf("�������������������������������������������������������ָ���������������������������������������������������������\n");
    }while(input!=48);
    printf("��������˳�...\n");
    while(getchar() != '\n');
    getchar();
    return 0;
}