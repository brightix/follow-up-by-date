#include <iostream>
#include <array>
#define MAIN int main()\
{

#define END std::cin.get();\
}

void Print(){
    std::cout << "Hello world!" << std::endl;
}

MAIN

    typedef void(*HelloWorldPrint)(); 
    HelloWorldPrint function = &Print;
    function();
    std::array<int,2> array;
    for(int& x : array){
        std::cin >> x;
    }
    for(int i : array){
        std::cout << i << std::endl;
    }
    std::cout << "hello world" << std::endl;
END