    #include <iostream>
    using namespace std;

    class Enity{
        private:
            int age;
            int num;
        public:
            Enity() : age(0), num(0) {}
            Enity(int a) : age(a),num(a) {}
            static Enity creatWithAge(int a){
                return Enity(a);
            }
            static Enity creatWithNum(int n){
                Enity enity;
                enity.num = n;
                return enity;
            }
            void printAge(){
                cout << age << endl;
            }
            void printNum(){
                cout << num << endl;
            }

    };

    int main(){
        Enity luna = Enity :: creatWithAge(3);
        luna.printNum();
        luna.printAge();

        cin.get();
    }