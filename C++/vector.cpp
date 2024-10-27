#include <iostream>
#include <vector>
class Vectex{
    private:
        float x , y, z;
    public:
        Vectex(float x,float y,float z)
        : x(x) , y(y) , z(z){}
        Vectex(const Vectex& Vectex): 
        x(Vectex.x),y(Vectex.y),z(Vectex.z)
        {
            std::cout << "Copied!!" << std::endl;
        }
};

int main(){
    std::vector<Vectex> vecteries;
    //vecteries.reserve(3);
    vecteries.push_back(Vectex(1,2,3));
    vecteries.push_back(Vectex(4,5,6));
    vecteries.push_back(Vectex(7,8,9));

    std::cin.get();
}