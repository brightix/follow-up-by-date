#include <stdio.h>
#include <stdbool.h>

struct stu
{
    char name[20];
    int age;
};

int main()
{
    struct stu zhangsan={"张三",18},lisi={"李四",24};
    printf("%s\n",zhangsan.name);
    printf("%s\n",lisi.name);
    printf("%d\n",sizeof(bool));
    return 0;
}