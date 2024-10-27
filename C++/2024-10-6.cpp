#include <iostream>



class Entity{
    private:
        int x,y;
    public:
        void printEntity(const Entity& e);
        Entity(int x,int y){
            this->x = x;
            this->y = y;
            printEntity(*this);
        }
        void print() const {
            std::cout << this->x << ',' << this->y << std::endl;
        }
        
};

void printEntity(const Entity& e){
    e.print();
}

int main(){
    Entity e(2,3);
    e.print();
    return 0;
}