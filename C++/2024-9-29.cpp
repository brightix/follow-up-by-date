#include <iostream>

class Entity{
public:
    virtual std::string getName(){ return "entity"; }
};
class player : public Entity{
private:
    std::string name;
public:
    player(std::string n) : name(n) {}

    std::string getName() override { 
        return name;
    }
};

int main(){
    Entity* e = new Entity();
    std::cout << e->getName() << std :: endl;
    player* p = new player("yoghurt");
    std::cout << p->getName() << std :: endl;
    Entity* o = p;
    std::cout << o->getName() << std :: endl;
    return 0;
}