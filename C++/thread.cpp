#include <iostream>
#include <thread>


/*class Worker{
private:
    bool going = true;
public:
    void doWork(){
        while(going){

            std::cout << "Worker keep going..." << std::endl;
        }
        std::cout << "Works done." << std::endl;
    }
    void stop(){
        going = false;
    }
    void statusPrint(){
        std::cout << going << std::endl;
    }
};*/
bool going = true;
void work(){
    while(going){
        std::cout<< "keep working..." << std::endl;
    }
}
int main(){
    std::thread doJob(work);

    std::cin.get();
    going = false;
    
    doJob.join();

    std::cin.get();
}