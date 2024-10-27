#include <stdio.h>

//牛客网BC111 空心正方形图案

int main() {
    int input;
    int i,j;
    while (scanf(" %d", &input) != EOF) { // 注意 while 处理多个 case
        // 64 位输出请用 printf("%lld") to 
        char arr[20][20]={0};
        for(i=0;i<input;i++)
        {
            for(j=0;j<input;j++)
            {
                arr[i][j]='*';
            }
        }
        for(i=1;i<input-1;i++)
        {
            for(j=1;j<input-1;j++)
            {
                arr[i][j]=' ';
            }
        }
        for(i=0;i<input;i++)
        {
            for(j=0;j<input;j++)
            {
                printf("%c ",arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}