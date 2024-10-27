#include <iostream>
#include <variant>
#include <vector>
enum ErrorCode
{
    theValueCantBeLessThanZero = 0,
    theValueCantBeBiggerThanHundred,
};
std::variant<std::string,int> test1(const int& num)
{
    if(num<0)
        return "theValueCantBeLessThanZero";
    if(num>100)
        return "theValueCantBeBiggerThanHundred";
    else
        return num;
}

int main()
{
    /*std::vector<int> arr;
    std::variant<std::string,int,std::vector<int>> data;
    data = arr;
    std::cout << data.index() << std::endl;*/
    int input = 0;
    std::cin >> input;
    std::variant<std::string,int> data = test1(input);
    std::visit([](auto&& a)
        {
            std::cout << a << std::endl;
        },data);
    std::cin.get();
}