#include <iostream>

int main(){
    struct Vector2
    {
        float x, y;
    };
    struct Vector4
    {
        union
        {
            struct 
            {
                float x, y, z, w;
            };
            struct
            {
                Vector2 a, b;
            };
        };
    };
    Vector4 vector = {1.0,2.0f,3.0f,4.0f};
    std::cout << vector.x << ',' << vector.y << ',' << vector.z << ',' << vector.w << std::endl;
    vector.b.x = 8.0f;
    std::cout << vector.x << ',' << vector.y << ',' << vector.z << ',' << vector.w << std::endl;
    std::cin.get();
}