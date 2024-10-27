#include "contact.h"


//做完一定要检查size_t和优化const

void capacityExpansion(Con* pc)//扩容操作
{
    PeoInfo* ptr=(PeoInfo*)realloc(pc->data,(pc->capacity+EPT)*sizeof(PeoInfo));
    if(ptr==NULL)
    {
        perror("realloc"); 
        printf("扩容失败\n");
        return;
    }
    pc->data=ptr;
    pc->capacity+=3;
    printf("扩容成功\n");
}
int* search(const char* input,Con* pc)//返回所有符合input值的data联系人的下标的数组
{
    int i,k=0;
    int* arr=(int*)malloc(((pc->count)+1)*sizeof(int));
    for(i=0;i<pc->count;i++)
    {
        if((strcmp(pc->data[i].name,input)==0) ||  (strcmp(pc->data[i].tele,input)==0) || (strcmp(pc->data[i].addr,input)==0))
        {
            *(arr+k++)=i;
        }
    }
    *(arr+k)=-1;
    return arr;
}
void showSearchResult(const int* ret, Con* pc)//展示搜索结果
{
    int i=0,j=1;
    printf("%-3s\t%-20s\t%-3s\t%-10s\t%-12s\t%-30s\n","编号","姓名","性别","年龄","电话","地址");
    while(*(ret+i)!=-1)
    {
        printf("%-3d\t%-20s\t%-3s\t%-10d\t%-12s\t%-30s\n",i+1,
                                                    pc->data[*(ret+i)].name,
                                                    pc->data[*(ret+i)].sex,
                                                    pc->data[*(ret+i)].age,
                                                    pc->data[*(ret+i)].tele,
                                                    pc->data[*(ret+i)].addr);
        i++;        
    }
}
void DeleteOperate(size_t ID,Con* pc)//执行删除操作
{
    int i;
    if(ID!=0)
    {
        for(i=ID-1;i<pc->count;i++)
        {
            pc->data[i]=pc->data[i+1];
        }        
    }
    pc->count--;
}
void delete(size_t ID,Con* pc)//
{    
    int isDel = 0;
    printf("输入'1'就真的删除ta了,确定吗?\n");
    scanf(" %d",&isDel);
    if(isDel==1)
    {
        DeleteOperate(ID,pc);
        printf("删除成功。\n");
    }
    else
    {
        printf("删除失败，果然还是不舍得吧~\n");
    }
}
void modify(size_t ID,Con* pc)//执行修改操作
{
    printf("ta的名字是:>");
    scanf("%s",pc->data[ID].name);
    printf("ta的年龄是:>");
    scanf("%d",&(pc->data[ID].age));
    printf("ta的电话是:>");
    scanf("%s",pc->data[ID].tele);
    printf("ta的地址是:>");
    scanf("%s",pc->data[ID].addr);
    printf("ta的性别是(男/女):>");
    scanf("%s",pc->data[ID].sex);
    printf("覆写成功了！\n");
}
int qsortByName(const void* e1,const void* e2)
{
    const PeoInfo* p1 = (PeoInfo*) e1;
    const PeoInfo* p2 = (PeoInfo*) e2;
    return strcmp(p1->name,p2->name);
}
int qsortByAge(const void* e1,const void* e2)
{
    const PeoInfo* p1 = (PeoInfo*) e1;
    const PeoInfo* p2 = (PeoInfo*) e2;
    return (p1->age)-(p2->age);
}
int qsortBySex(const void* e1,const void* e2)
{
    const PeoInfo* p1 = (PeoInfo*) e1;
    const PeoInfo* p2 = (PeoInfo*) e2;
    return strcmp(p1->sex,p2->sex);
}
void sort(const int input,Con* pc)
{
    int (*sortWay[5])(const void* e1,const void* e2)={NULL,qsortByName,qsortByAge,qsortBySex};//
    qsort(pc->data,pc->count,sizeof(PeoInfo),sortWay[input]);
}
void initContact(Con* pc)//初始化
{
    assert(pc);
    pc->count=0;
    pc->capacity=3;
    pc->data=(PeoInfo*)calloc(3,sizeof(PeoInfo));//为data开辟三个位子的空间
    printf("ver.%.1f\n",VERSION);
}
void loadContact(Con* pc)//加载数据
{
    FILE* ptr = fopen("ContactData.txt","r");
    if(ptr==NULL)
    {
        printf("打开文件失败，在此次安全退出时会自动创建文件(指通过主菜单关闭)。\n");
        return;
    }
    while(1)
    {
        if(pc->capacity<=pc->count)
        {
            capacityExpansion(pc);
        }
        if (fscanf(ptr, "%s %d %s %s %s %s", 
                   pc->data[pc->count].name,
                   &(pc->data[pc->count].age),
                   pc->data[pc->count].tele,
                   pc->data[pc->count].addr,
                   pc->data[pc->count].sex,
                   pc->data[pc->count].description) != 6)
        {
            break;//如果没能读取到完整数据就跳出循环
        }
        pc->count++;
    }
    printf("数据读取成功\n");
    fclose(ptr);
    ptr=NULL;
}
void addContact(Con* pc)//ADD
{
    if((pc->capacity)<=(pc->count))
    {
        capacityExpansion(pc);
    }
    printf("ta的名字是:>");
    scanf("%s",pc->data[pc->count].name);
    printf("ta的年龄是:>");
    scanf("%d",&(pc->data[pc->count].age));
    printf("ta的电话是:>");
    scanf("%s",pc->data[pc->count].tele);
    printf("ta的地址是:>");
    scanf("%s",pc->data[pc->count].addr);
    printf("ta的性别是(男/女):>");
    scanf("%s",pc->data[pc->count].sex);
    strcpy(pc->data[pc->count].description,"无");
    if(strcmp(pc->data[pc->count].sex,"男") == 0)
        printf("太棒了！又成功添加一位帅哥的联系方式呢！\n");
    else if(strcmp(pc->data[pc->count].sex,"女") == 0)
        printf("太棒了！又成功添加一位美女的联系方式呢！\n");
    else
        printf("虽然没有搞懂这是什么性别，单还是恭喜你添加成功！\n");
    pc->count++;
}
void delContact(Con* pc)//DEL
{
    char input[30];

    if(pc->count==0)
    {
        printf("还没有添加任何联系人呢\n");
        return;
    }
    printf("搜索你要遗忘的那个ta:>");
    scanf("%s",input);
    int* ret=search(input,pc);//返回所有符合input值的data联系人的下标的数组
    int i=0,retCount=0;
    while(*(ret+i++)!=-1)//求得找到的人数
    {
        retCount++;
    }
    showSearchResult(ret,pc);
    size_t ID = 0;
    if(*(ret+1)==-1)//找出来就一个符合要求
    {   
        ID = 1;
        delete(ID,pc);
    }
    else if(*ret==-1)//没有符合要求的人
    {
        printf("我在你的小本本里没有找到这个人的信息哦~\n");
        return;
    }
    else//有多个符合要求的联系人
    {
        printf("搜索出来好像不止一个家伙，你想要删除哪一个呢？:>");
        do{
            scanf(" %zu",&ID);
            if(ID<=0 || ID>retCount)
            {
                printf("你越界了!!再输入一次吧:>");
                continue;
            }
            delete(ID,pc);
        }while(ID<=0 || ID>retCount);
    }
    free(ret);
    ret=NULL;
}
void searchContact(Con* pc)//SEARCH
{
    char input[30]={0};
    printf("你要查找的信息是:>");
    scanf("%s",input);
    int* ret = search(input,pc);
    showSearchResult(ret,pc);
}
void modContact(Con* pc)//MODIFY
{
    char input[30]={0};
    printf("是哪里出错了吗？你要修改谁的信息呢:>");
    scanf("%s",input);
    int* ret = search(input,pc);
    showSearchResult(ret,pc);
    int i=0,retCount=0;
    while(*(ret+i++)!=-1)//求得找到的人数
    {
        retCount++;
    }    
    size_t ID = 0;
    if(*(ret+1)==-1)//找出来就一个符合要求
    {   
        ID = 1;
        modify(ID,pc);
    }
    else if(*ret==-1)//没有符合要求的人
    {
        printf("我在你的小本本里没有找到这个人的信息哦~\n");
        return;
    }
    else//有多个符合要求的联系人
    {
        printf("似乎找到了不止一个家伙，你想要修改哪一个呢？:>");
        do{
            scanf(" %zu",&ID);
            if(ID<=0 || ID>retCount)
            {
                printf("你越界了!!再输入一次吧:>");
                continue;
            }
            modify(ID,pc);
        }while(ID<=0 || ID>retCount);
    }

}
void showContact(Con* pc)//SHOW
{
    int i=0,j=1;
    printf("%-3s\t%-20s\t%-3s\t%-10s\t%-12s\t%-30s\n","编号","姓名","性别","年龄","电话","地址");
    while(pc->count-i)
    {
        printf("%-3d\t%-20s\t%-3s\t%-10d\t%-12s\t%-30s\n",i+1,
                                                    pc->data[i].name,
                                                    pc->data[i].sex,
                                                    pc->data[i].age,
                                                    pc->data[i].tele,
                                                    pc->data[i].addr);
        i++;        
    }
}
void sortContact(Con* pc)//SORT
{
    int input=0;
    printf("你想要以什么标准排序?\n"
            "1.我想通过名字排序！！\n"
            "2.年纪排序\n"
            "3.性别排序\n");
    scanf(" %d",&input);
    sort(input,pc);
    printf("整好了\n");
}
void saveContact(Con* pc)//保存数据
{
    FILE* ptr = fopen("contactData.txt","w");
    if(ptr==NULL)
    {
        perror("fopen");
        printf("数据写入失败！！\n");
        return;
    }
    int i;
    for(i=0;i<pc->count;i++)
    {
        fprintf(ptr,"%s %d %s %s %s %s\n",    pc->data[i].name,
                                            pc->data[i].age,
                                            pc->data[i].tele,
                                            pc->data[i].addr,
                                            pc->data[i].sex,
                                            pc->data[i].description);  
    }
    printf("数据存储成功\n");
    fclose(ptr);
    ptr=NULL;
}
void destroy(Con* pc)//释放数据内存
{
    if(pc->data!=NULL)
    {
        free(pc->data);
        pc->data=NULL;
    }
}