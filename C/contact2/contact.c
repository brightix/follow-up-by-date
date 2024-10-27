#include "contact.h"


//����һ��Ҫ���size_t���Ż�const

void capacityExpansion(Con* pc)//���ݲ���
{
    PeoInfo* ptr=(PeoInfo*)realloc(pc->data,(pc->capacity+EPT)*sizeof(PeoInfo));
    if(ptr==NULL)
    {
        perror("realloc"); 
        printf("����ʧ��\n");
        return;
    }
    pc->data=ptr;
    pc->capacity+=3;
    printf("���ݳɹ�\n");
}
int* search(const char* input,Con* pc)//�������з���inputֵ��data��ϵ�˵��±������
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
void showSearchResult(const int* ret, Con* pc)//չʾ�������
{
    int i=0,j=1;
    printf("%-3s\t%-20s\t%-3s\t%-10s\t%-12s\t%-30s\n","���","����","�Ա�","����","�绰","��ַ");
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
void DeleteOperate(size_t ID,Con* pc)//ִ��ɾ������
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
    printf("����'1'�����ɾ��ta��,ȷ����?\n");
    scanf(" %d",&isDel);
    if(isDel==1)
    {
        DeleteOperate(ID,pc);
        printf("ɾ���ɹ���\n");
    }
    else
    {
        printf("ɾ��ʧ�ܣ���Ȼ���ǲ���ð�~\n");
    }
}
void modify(size_t ID,Con* pc)//ִ���޸Ĳ���
{
    printf("ta��������:>");
    scanf("%s",pc->data[ID].name);
    printf("ta��������:>");
    scanf("%d",&(pc->data[ID].age));
    printf("ta�ĵ绰��:>");
    scanf("%s",pc->data[ID].tele);
    printf("ta�ĵ�ַ��:>");
    scanf("%s",pc->data[ID].addr);
    printf("ta���Ա���(��/Ů):>");
    scanf("%s",pc->data[ID].sex);
    printf("��д�ɹ��ˣ�\n");
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
void initContact(Con* pc)//��ʼ��
{
    assert(pc);
    pc->count=0;
    pc->capacity=3;
    pc->data=(PeoInfo*)calloc(3,sizeof(PeoInfo));//Ϊdata��������λ�ӵĿռ�
    printf("ver.%.1f\n",VERSION);
}
void loadContact(Con* pc)//��������
{
    FILE* ptr = fopen("ContactData.txt","r");
    if(ptr==NULL)
    {
        printf("���ļ�ʧ�ܣ��ڴ˴ΰ�ȫ�˳�ʱ���Զ������ļ�(ָͨ�����˵��ر�)��\n");
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
            break;//���û�ܶ�ȡ���������ݾ�����ѭ��
        }
        pc->count++;
    }
    printf("���ݶ�ȡ�ɹ�\n");
    fclose(ptr);
    ptr=NULL;
}
void addContact(Con* pc)//ADD
{
    if((pc->capacity)<=(pc->count))
    {
        capacityExpansion(pc);
    }
    printf("ta��������:>");
    scanf("%s",pc->data[pc->count].name);
    printf("ta��������:>");
    scanf("%d",&(pc->data[pc->count].age));
    printf("ta�ĵ绰��:>");
    scanf("%s",pc->data[pc->count].tele);
    printf("ta�ĵ�ַ��:>");
    scanf("%s",pc->data[pc->count].addr);
    printf("ta���Ա���(��/Ů):>");
    scanf("%s",pc->data[pc->count].sex);
    strcpy(pc->data[pc->count].description,"��");
    if(strcmp(pc->data[pc->count].sex,"��") == 0)
        printf("̫���ˣ��ֳɹ����һλ˧�����ϵ��ʽ�أ�\n");
    else if(strcmp(pc->data[pc->count].sex,"Ů") == 0)
        printf("̫���ˣ��ֳɹ����һλ��Ů����ϵ��ʽ�أ�\n");
    else
        printf("��Ȼû�и㶮����ʲô�Ա𣬵����ǹ�ϲ����ӳɹ���\n");
    pc->count++;
}
void delContact(Con* pc)//DEL
{
    char input[30];

    if(pc->count==0)
    {
        printf("��û������κ���ϵ����\n");
        return;
    }
    printf("������Ҫ�������Ǹ�ta:>");
    scanf("%s",input);
    int* ret=search(input,pc);//�������з���inputֵ��data��ϵ�˵��±������
    int i=0,retCount=0;
    while(*(ret+i++)!=-1)//����ҵ�������
    {
        retCount++;
    }
    showSearchResult(ret,pc);
    size_t ID = 0;
    if(*(ret+1)==-1)//�ҳ�����һ������Ҫ��
    {   
        ID = 1;
        delete(ID,pc);
    }
    else if(*ret==-1)//û�з���Ҫ�����
    {
        printf("�������С������û���ҵ�����˵���ϢŶ~\n");
        return;
    }
    else//�ж������Ҫ�����ϵ��
    {
        printf("������������ֹһ���һ����Ҫɾ����һ���أ�:>");
        do{
            scanf(" %zu",&ID);
            if(ID<=0 || ID>retCount)
            {
                printf("��Խ����!!������һ�ΰ�:>");
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
    printf("��Ҫ���ҵ���Ϣ��:>");
    scanf("%s",input);
    int* ret = search(input,pc);
    showSearchResult(ret,pc);
}
void modContact(Con* pc)//MODIFY
{
    char input[30]={0};
    printf("���������������Ҫ�޸�˭����Ϣ��:>");
    scanf("%s",input);
    int* ret = search(input,pc);
    showSearchResult(ret,pc);
    int i=0,retCount=0;
    while(*(ret+i++)!=-1)//����ҵ�������
    {
        retCount++;
    }    
    size_t ID = 0;
    if(*(ret+1)==-1)//�ҳ�����һ������Ҫ��
    {   
        ID = 1;
        modify(ID,pc);
    }
    else if(*ret==-1)//û�з���Ҫ�����
    {
        printf("�������С������û���ҵ�����˵���ϢŶ~\n");
        return;
    }
    else//�ж������Ҫ�����ϵ��
    {
        printf("�ƺ��ҵ��˲�ֹһ���һ����Ҫ�޸���һ���أ�:>");
        do{
            scanf(" %zu",&ID);
            if(ID<=0 || ID>retCount)
            {
                printf("��Խ����!!������һ�ΰ�:>");
                continue;
            }
            modify(ID,pc);
        }while(ID<=0 || ID>retCount);
    }

}
void showContact(Con* pc)//SHOW
{
    int i=0,j=1;
    printf("%-3s\t%-20s\t%-3s\t%-10s\t%-12s\t%-30s\n","���","����","�Ա�","����","�绰","��ַ");
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
    printf("����Ҫ��ʲô��׼����?\n"
            "1.����ͨ���������򣡣�\n"
            "2.�������\n"
            "3.�Ա�����\n");
    scanf(" %d",&input);
    sort(input,pc);
    printf("������\n");
}
void saveContact(Con* pc)//��������
{
    FILE* ptr = fopen("contactData.txt","w");
    if(ptr==NULL)
    {
        perror("fopen");
        printf("����д��ʧ�ܣ���\n");
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
    printf("���ݴ洢�ɹ�\n");
    fclose(ptr);
    ptr=NULL;
}
void destroy(Con* pc)//�ͷ������ڴ�
{
    if(pc->data!=NULL)
    {
        free(pc->data);
        pc->data=NULL;
    }
}