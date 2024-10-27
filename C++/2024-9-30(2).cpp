#include <iostream>

using namespace std;

class Enity{
    private:
        string m_name;
        int* arr;
        int arrSize;
        int age;
    public:
        Enity(int a){
            arrSize = a;
            arr = new int[arrSize];
            for(int i = 0;i<arrSize;i++){
                arr[i] = 0;
            }
        }
        static Enity creatWithAge(int age)
        {
            return Enity(age);
        }

        Enity(string n) : m_name("  unknown   "){ m_name = n;}

        string PrintName(){ return m_name;}
        void setName(string n){
            m_name = n;
        }
        void printClassName(){
            cout << m_name << endl;
        }
        void printAge(){
            cout << age << endl;
        }
        void printArr(){
            for(int i = 0;i<arrSize;i++){
                cout << arr[i] << endl;
            }
        }
        ~Enity(){
            delete [] arr;
        }
};

void printClass(Enity& n){
    cout << n.PrintName() << endl;
}

int main(){
    Enity* e = new Enity(5);
    e->printArr();
    e->printClassName();
    e->setName("lisi");
    e->printClassName();
    printClass(*e);
    Enity luna = (string)"luna";
    luna.printClassName();
    Enity siri(2);
    Enity lafa = Enity :: creatWithAge(4);
    lafa.printAge();
    delete e;
    cin.get();
}