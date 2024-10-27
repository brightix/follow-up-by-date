#include <iostream>

using std::cout;
using std::cin;
using std::endl;
namespace fruit{
    namespace apple{
        void Print(std::string s){
            cout << s << endl;
        }
    }
    namespace orange{
        void Print(std::string s){
            cout << s << endl;
        }
    }
}

int main(){
    fruit::apple::Print("apple");
    fruit::orange::Print("orange");
    cin.get();
}