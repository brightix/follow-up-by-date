<<<<<<< HEAD
#include <iostream>
#include <string>

using namespace std;
class person{
private:
    std :: string name;
    int age;
public:
    person(std::string n,int a) : name(n),age(a) {}//构造函�?

    void setName(std::string n){
        name = n;
    }
    std::string getName() const {
        return name;
    }

    void setName(int a){
        age = a;
    }
    int getAge() const {
        return age;
    }
    void printInfo() const {
        std::cout <<"name: "<< name << " age: " << age <<endl;
    }
};
int main()
{
    std::cout << "hello world" << endl;
    person person1("����",21);
    person person2("����",28);
    person1.printInfo();
    person2.printInfo();
    return 0;
=======
#include <iostream>
#include <string>

using namespace std;
class person{
private:
    std :: string name;
    int age;
public:
    person(std::string n,int a) : name(n),age(a) {}//构造函�?

    void setName(std::string n){
        name = n;
    }
    std::string getName() const {
        return name;
    }

    void setName(int a){
        age = a;
    }
    int getAge() const {
        return age;
    }
    void printInfo() const {
        std::cout <<"name: "<< name << " age: " << age <<endl;
    }
};
int main()
{
    std::cout << "hello world" << endl;
    person person1("����",21);
    person person2("����",28);
    person1.printInfo();
    person2.printInfo();
    return 0;
>>>>>>> main
}