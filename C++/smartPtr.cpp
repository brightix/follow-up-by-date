#include <iostream>
#include <memory>

class Entity{
    private:
        int x, y;
    public:
    Entity(int x,int y){
        this->x = x;
        this->y = y;
        std::cout << "creat Entity!" << std::endl;
    }
    void print(){
        std::cout << x << ',' << y << std::endl;
    }
    ~Entity(){
        std::cout << "destory Entity" << std::endl;
    }
};

int main()
{
    {
        std::shared_ptr<Entity> e0 = std::make_shared<Entity>(7,2);
        {
            std::shared_ptr<Entity> e1 = e0;
            std::shared_ptr<Entity> e2 = e1;
            std::unique_ptr<Entity> e = std::make_unique<Entity>(2,3);
            e->print();
        }
        e0->print();
    }
    
    return 0;
}