#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
typedef struct contact
{
    char name[20];
    int age;
    char tele[12];
}Contact;



void writeCon(Contact* con) 
{
    scanf("%s %d %s", con->name, &(con->age), con->tele);
}
int main()
{

    
    FILE* ptr = fopen("C:\\Users\\21811\\Desktop\\test.txt","r+");
    if(ptr==NULL)
    {
        perror("fopen");
        return 1;
    }
    Contact con;

    writeCon(&con);//用户输入信息

    fprintf(ptr,"%s %d %s",con.name,con.age,con.tele);//输出至文件
    
    rewind(ptr);
    Contact con_r;
    fscanf(ptr,"%s %d %s",con_r.name,&(con_r.age),con_r.tele);
    printf("%s %d %s\n",con_r.name,con_r.age,con_r.tele);
    
    fclose(ptr);//关闭文件
    ptr=NULL;
    return 0;
}