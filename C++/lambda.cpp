#include <iostream>
#include <functional>
using namespace std;
void m_func(function<void(int)> func){
    for(int i = 0;i < 5;i++){
        func(i);
    }
}

int main(){
    int a = 5;
    function<void(int)> lambda = [&a](int index){ cout << index << a << endl;};
    m_func(lambda);
    cin.get();
}