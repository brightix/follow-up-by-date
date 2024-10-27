#include <iostream>

class printable{
    public:
        virtual std :: string getClassName() = 0;
};

class Entity : public printable{
    public:
        std :: string getClassName() override {return "Entity"; }
};

class Player : public printable{
    private:
        std :: string name;
    public:
        Player(std::string n) : name(n) {}
        std :: string getClassName() override {return name; }
};

void print(printable* obj){
    std :: cout << obj->getClassName() << std :: endl;
}

int main(){
    Entity* e = new Entity();
    print(e);
    Player* p = new Player("marry"); 
    print(p);
    return 0;
}