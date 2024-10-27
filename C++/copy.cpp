#include <iostream>
#include <string.h>

class String{
    private:
        char* m_buffer;
        unsigned int m_size;
    public:
        String(const char* s){
            m_size = strlen(s);
            m_buffer = new char[m_size + 1];
            memcpy(m_buffer,s,m_size);
            m_buffer[m_size] = 0;
        }
        String(const String& other){
            m_size = other.m_size;
            m_buffer = new char[m_size + 1];
            memcpy(m_buffer,other.m_buffer,m_size + 1);
        }
        ~String(){
            delete []m_buffer;
        }
        char& operator[](unsigned int index){
            return m_buffer[index];
        }
        friend std::ostream& operator<<(std::ostream& stream,const String& string);
};

std::ostream& operator<<(std::ostream& stream,const String& string){
    stream << string.m_buffer;
    return stream;
}

void printString(const String& s){
    std::cout << s << std::endl;
}

int main(){
    String e = "Unknown";
    String e0 = e;
    e0[2] = 'a';
    printString(e);
    printString(e0);
    return 0;
}