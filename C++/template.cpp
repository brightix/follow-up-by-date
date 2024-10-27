#include <iostream>

template<int N>
class Array
{
private:
    int m_array[N];
public:
    int getSize() const { return N; }
};

template<typename T>
class Print
{
private:
public:
    Print(const T& t){
        std::cout << t << std::endl;
    }
};
int main(){
    Print<const char*> p("Unknown");
    Array<3> array;
    std::cout << array.getSize() << std::endl;
    std::cout << sizeof(array) << std::endl;
    std::cin.get();
}