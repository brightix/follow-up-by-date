#include <iostream>
#include <string>

using namespace std;

class person{
private:
    string name;
    int age;
public:
    person(string n,int a):name(n),age(a){}
    void printInfo(){
        cout<< "name:" << name << " "<< "age:" << age << endl;
    }
    ~person(){
        cout << "destroyPersonInfo" << endl;
    }

};




int main(){
    person zhangsan("zhangsan",18);
    person lisi("lisi",24);
    zhangsan.printInfo();
    lisi.printInfo();
    return 0;
}