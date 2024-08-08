#include "contact.h"

void InitContact(Contact* pcon)
{
    pcon->count=0;
    memset(pcon->data,0,sizeof(pcon->data));
}

void addContact(Contact* pcon)
{
    assert(pcon);
    if(pcon->count == MAX_DATA)
    {
        printf("The menber of the contact list is fill\n");
        return;
    }
    printf("Enter contact name:>");
    scanf("%s",pcon->data[pcon->count].name);
    printf("Enter contact age:>");
    scanf("%s",pcon->data[pcon->count].age);
    printf("Enter contact sex:>");
    scanf("%s",pcon->data[pcon->count].sex);
    printf("Enter contact tele:>");
    scanf("%s",pcon->data[pcon->count].tele);
    printf("Enter contact address:>");
    scanf("%s",pcon->data[pcon->count].addr);
    pcon->count++;
    printf("Contact addition successful\n");
}

void showOne(Contact* pc,int i)
{
    printf("%20s\t%5s\t%10s\t%12s\t%30s\t\n","name","age","sex","telephone","address");
    printf("%20s\t%5s\t%10s\t%12s\t%30s\t\n",   pc->data[i].name,
                                                pc->data[i].age,
                                                pc->data[i].sex,
                                                pc->data[i].tele,
                                                pc->data[i].addr);
}


int findWay()//返回搜索方式的下标
{
    int way=0;
    printf("How to search:\n"
            "%10s\t%10s\t%10s\t\n%10s\t%10s\t%10s\t\n",
            "1.By name","2.By age","3.By sex","4.By tele","5.By addr","0.return to menu");
    scanf("%d",&way);
    return way;
}

int find(Contact* pcon,char input[MAX_NAME],int way)
{                      //用户输入的内容     
    //返回所有匹配的下标，没找到则返回-1
    int i;
    switch(way)
    {
        case 1:    
            for(i=0;i<MAX_DATA;i++)
            {
                if(strcmp(pcon->data[i].name,input)==0)
                return i;
            }
            break;
        case 2:    
            for(i=0;i<MAX_DATA;i++)
            {
                if(strcmp(pcon->data[i].age,input)==0)
                return i;
            }
            break;
        case 3:    
            for(i=0;i<MAX_DATA;i++)
            {
                if(strcmp(pcon->data[i].sex,input)==0)
                return i;
            }
            break;
        case 4:    
            for(i=0;i<MAX_DATA;i++)
            {
                if(strcmp(pcon->data[i].tele,input)==0)
                return i;
            }
            break;
        case 5:    
            for(i=0;i<MAX_DATA;i++)
            {
                if(strcmp(pcon->data[i].addr,input)==0)
                return i;
            }
            break;
    }

    return -1;
}

void delete(Contact* pc)
{
    assert(pc);
    char input[30]={0};
    int i;
    int way=findWay(way);
    printf("Enter the information:>");
    scanf("%s",&input);
    int cons=find(pc,input,way);
    if(pc->count==0)
    {
        printf("You have not created any contact yet\n");
    }
    else if(cons==-1)
    {
        printf("Failure to find contact\n");
    }
    else
    {
        for(i=cons;i<pc->count-1;i++)
        {
            pc->data[i]=pc->data[i+1];
        }
        pc->count--;
        printf("Successfully deleted\n");
    }

}

void search(Contact* pc)
{
    assert(pc);
    char input[MAX_NAME]={0};
    int way=0;
    do
    {    
        way=findWay();
        if(way>0 && way<=5)
        {    
            printf("Search:>");
            scanf("%s",&input);
            int cons=find(pc,input,way);
            if(cons==-1)
            {
                printf("Failure to find contact\n");
                way=-1;
            }
            else if(cons!=-1)
            {
                showOne(pc,cons);
                //buffering();//缓冲后进入菜单
                return;       
            }

        }
        else if(way==0)
        {
            return;
        }
        else
            printf("Enter error,please try again.\n");
    } while (way < 0 || way > 5);
}

void modify(Contact* pc)
{
    assert(pc);
}

void showAll(Contact* pc)
{
    assert(pc);
    int i;
    //while(*(pc-1)!=pc->data->addr)
    /*    for(i=0;i<pcon->count;i++)
    {
        printf("Contact %d\n",i+1);
        printf("name:%s\n",pc->data[i].name);
        printf("age:%d\n",pc->data[i].age);
        printf("sex:%s\n",pc->data[i].sex);
        printf("tele:%s\n",pc->data[i].tele);
        printf("addr%s\n",pc->data[i].addr);
    }*/
        printf("%-20s\t%-5s\t%-10s\t%-12s\t%-30s\t\n","name","age","sex","telephone","address");
    for(i=0;i<pc->count;i++)
    {   
        printf("%-20s\t%-5s\t%-10s\t%-12s\t%-30s\t\n",  pc->data[i].name,
                                                        pc->data[i].age,
                                                        pc->data[i].sex,
                                                        pc->data[i].tele,
                                                        pc->data[i].addr);
    }
}

void sort(Contact* pc)
{
    assert(pc);
}