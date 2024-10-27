#include <iostream>

class player
{
    private:
        std::string name;
    public:
        player(){
            std::cout << "in" <<std::endl;
        }
        ~player(){
            std :: cout << "out" << std::endl;
        }
};

int main(){
    player* playerArr = new player[4];
    delete [] playerArr;
    return 0;
}