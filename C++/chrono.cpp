#include <iostream>
#include <thread>
#include <chrono>

int main(){
    using namespace std::literals::chrono_literals;
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    std::cin.get();
}