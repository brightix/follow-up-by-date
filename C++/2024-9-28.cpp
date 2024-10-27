#include <iostream>
/*class singleton{
public:
    static singleton& get(){
        static singleton instance;
        return instance;
    }
    void hello(){}
};

int main(){
    singleton::get().hello();
    return 0;
}*/

class singleton{
    private:
        static singleton* s_instance;
    public:
        static singleton& get(){
            return *s_instance;
        }
    void hello(){}
};
singleton* singleton :: s_instance = nullptr;
int main(){

    singleton::get().hello();
    return 0;
}
