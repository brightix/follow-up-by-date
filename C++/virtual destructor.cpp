#include <iostream>
#include <iomanip>
class Base
{
private:
    int index = 0;
public:
    Base(){ std::cout << "Base construct" << std::endl; }
    void setIndex(int a){ this->index = a; }
    void indexPrint(){ std::cout << index << std::endl; }
    virtual ~Base(){ std::cout << "Base destructor" << std::endl; }
};
class Derived : public Base
{
private:
    int* arr;
public:
    Derived():arr(new int[5]){ std::cout << "Derived construct" << std::endl; }
    ~Derived(){ delete [] arr; std::cout << "Derived destructor" << std::endl; }
};

void test()
{
    {
        Derived derived;
    }
}

void transform()
{
    using namespace std;
    int a = 5;
    float b = static_cast<float>(a);
    cout << fixed << setprecision(3) << "b = " << b << endl;
    cout << fixed << setprecision(3) << "a = " << a << endl;
    int c = static_cast<float>(a);
    cout << fixed << setprecision(3) << "c = " << static_cast<float>(a) << endl;
    float arr[1] = {1};
    int* ptr = reinterpret_cast<int*>(arr);
    cout << "*ptr = "<< *ptr << endl;
    //const Base* base = new Base; 
    //Base* base1 = const_cast<Base*>(base);
    //base1->setIndex(9);
    //base1->indexPrint();
    //delete base1;
    Base* base = new Base;
    Derived* derived = dynamic_cast<Derived*>(base);
    if(!derived)
        cout << "derived:failed" << endl;
    Derived* derived1 = new Derived;
    Base* base2 = dynamic_cast<Base*>(derived1);
    if(!base2)
        cout << "base2:failed" << endl;
    delete base2;
    delete base;
}
void dynamic()
{
    using namespace std;
    Derived* derived1 = new Derived;
    Base* base2 = dynamic_cast<Base*>(derived1);
    if(!base2)
        cout << "base2:failed" << endl;
    delete base2;
}
int main()
{
    //test();
    dynamic();
    //transform();

    std::cin.get();
}