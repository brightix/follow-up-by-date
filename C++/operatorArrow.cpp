#include <iostream>
#include <vector>
class Entity{
    private:
        int x = 0;
    public:
        void print(){
            std::cout << "Hello" << std :: endl;
        }
};

class scopedPtr{
    private:
        Entity* m_ptr;
    public:
        scopedPtr(Entity* obj) : m_ptr(obj){}

        ~scopedPtr(){
            delete m_ptr;
        }

        Entity* operator->(){
            return m_ptr;
        }
};

class Vectex{
    public:
        float x,y,z;

};
std::ostream& operator<<(std::ostream& stream,const Vectex& vectex){
    stream << vectex.x << "," << vectex.y << "," << vectex.z << std::endl;
    return stream;

}

int main(){ 
    int offset = (long long)&((Vectex*)0)->z;
    std::cout << offset << std::endl;
    std::vector<Vectex> verctices;
    verctices.push_back({1,2,3});
    verctices.push_back({4,5,6});
    for(int i = 0;i<verctices.size();i++){
        std::cout << verctices[i] << std::endl;
    }
    //verctices.erase(verctices.begin() + 1);
    //verctices.pop_back();
    for(auto& v : verctices){
        std::cout << v << std::endl;
    }
    std::cin.get();
}