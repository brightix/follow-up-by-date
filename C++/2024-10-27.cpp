#include <iostream>

int main()
{
    int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int* arrptr[3] = {arr[0],arr[1],arr[2]};
    int* arrptr2[3] = {&arr[0][0],&arr[1][0],&arr[2][0]};
    int (*arrptr3) [4] = {arr};
    std::cout << arrptr[0] << std::endl;
    std::cout << arrptr2[0] << std::endl;
    std::cout << arrptr3 << std::endl;
    std::cin.get();
}