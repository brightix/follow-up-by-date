#include <iostream>

class w{
    public:

};
void add(int& x){
    x+=3;
}
int main(){
    using namespace std::string_literals;
    //const char* s = "hello world";
    //std::string s1 = "hello world"s + " hi";
    std::string s3 = R"(line1
line2
line3)";
    int* num = new int;
    *num = 3;
    add(*num);
    std::cout << *num << std::endl;
    std::cout << s3 << std::endl;
    std::cin.get();
}