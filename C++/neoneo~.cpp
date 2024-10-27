#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <variant>
#include <vector>
#include <iomanip>

class Neo{
public:
    static Neo& NeoRevive()
    {
        static Neo instance;
        return instance;
    }
    void menu()
    {
        std::cout << "************************************" << std::endl;
        std::cout   << "*name:" << std::left << std::setw(20) << name
                    << "Energy" << std::right << std::setw(3) << Energy
                    << "*" << std::endl;
        std::cout << "*                                  *" << std::endl;
        std::cout << "*                                  *" << std::endl;
        std::cout << "*                                  *" << std::endl;
        std::cout << "*                                  *" << std::endl;
        std::cout << "*                                  *" << std::endl;
        std::cout << "************************************" << std::endl;
        std::cout   << "1.status" << std::left << std::setw(12)
                << "2.feed" << std::left << std::setw(12)
                << "3.play" << std::left << std::setw(12)
                << "4.rename" << std::left << std::setw(12)
                << "0.quit" << std::endl;
    }
    void feed(std::string food)
    {
        if(foodList.find(food) != foodList.end())
        {
            if(Energy+foodList[food]<121)
                    Energy+=foodList[food];
            else
                Energy=120;
        }
    }
    void energyStatus() const
    {
        int status = Energy%20;
        switch(status)
        {
            case 0:
                std::cout << "（似了）" << std::endl;
                break;
            case 1:
                std::cout << "（似乎还有呼吸）" << std::endl;
                break;
            case 2:
                std::cout << "主人我要饿死了喵~(╥﹏╥)" << std::endl;
                break;
            case 3:
                std::cout << "饿了，来食喵~" << std::endl;
                break;
            case 4:
                std::cout << "8分饱最好喵~" << std::endl;
                break;
            case 5:
                std::cout << "吃饱了喵~" << std::endl;
                break;
            case 6:
                std::cout << "不行了，肚子好重喵！" << std::endl;
                break;
        }
    }
    void rename()
    {
        std::cout << "改名字" << std::endl;
        std::getline(std::cin,name);
        std::cout << "修改完成" << std::endl;
    }
    void printFoodList()
    {
        int n = foodList.size();
        int i = 1;
        for(auto pair : foodList)
        {
            std::cout << i++ << pair.first << "  " << pair.second << std::endl;
        }
    }
    void play()
    {
        std::cout << "还没有定义" << std::endl;
    }


private:
    Neo(const Neo&) = delete;
    Neo& operator=(const Neo&) = delete;


    std::string name;
    int playDays;
    int Energy;//max 120
    std::vector<std::variant<std::string*,int*>> info = {&name,&playDays,&Energy};
    //std::vector<std::vector<std::variant<std::string,int>>> info = {{"name =",name},{"playDays =",playDays},{"Energy =",Energy}};
    std::map<std::string,double> foodList = {{"小饼干",5.0}};
    Neo()
    {
        std::string filename = "C:\\Users\\21811\\Desktop\\Infomation.txt";
        std::ifstream InfoFile(filename);
        if(!InfoFile)
        {
            //std::ofstream outfile(filename);
            std::cout << "未找到信息文件，程序自然结束后将自动创建文件" << std::endl;
            std::cout << "下面开始注册信息" << std::endl;
            std::cin >> name;
            playDays = 0;
            Energy = 80;
        }
        else
        {
            std::string line;
            int i = 0;
            while(std::getline(InfoFile,line) && i < info.size())
            {
                if (std::holds_alternative<std::string*>(info[i])) {
                    *std::get<std::string*>(info[i]) = line; // 处理字符串
                }
                else if (std::holds_alternative<int*>(info[i])) {
                    *std::get<int*>(info[i]) = std::stoi(line); // 处理整数
                }
                i++;
            }
            InfoFile.close();
        }
    }
    ~Neo()
    {
        std::string filename = "C:\\Users\\21811\\Desktop\\Infomation.txt";
        std::ofstream outFile(filename);
        std::string line;
        int i = 0;
        outFile << name << std::endl;
        outFile << playDays << std::endl;
        outFile << Energy << std::endl;
        outFile.close();
    }
};

int main()
{  
    Neo& neo = Neo::NeoRevive();
    int input = 0;
    std::string foodBotton;
    do
    {
        neo.menu();
        std::cin >> input;
        std::cin.ignore();
        switch(input)
        {
            case 1:
                neo.energyStatus();
                break;  
            case 2:
                neo.printFoodList();
                std::cout << "请选择你要投味的食物：";
                std::getline(std::cin,foodBotton);
                neo.feed(foodBotton);
            break;  
            case 3:
                neo.play();
                break;    
            case 4:
                neo.rename();
                break;   
            case 0:
                std::cout << "byebye~小喵会想你的喵" << std::endl;
                break;
            default:
                std::cout << "没有这种选项喵~ " << std::endl;
                break;
        }
    }while(input);
    std::cout << "按任意键退出喵...";
    std::cin.get();
}