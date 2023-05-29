#include <iostream>
#include <string>

consteval int get_flag(){
    return 0;
}

std::string get_name(){
    std::string name;
    std::getline(std::cin,name);
    return name;
}

int get_value(int flag){
    int value;
    while(1){
        std::cin >> value;
        //std::cout << value << std::endl;
        if(value > flag){
            return value;
        }
        else{
            std::cerr << "Error msg: value should be above "<< flag << std::endl;
            std::cin.clear();
            std::cin.get();
        }
    }
    
    
}

int get_sum(int val1, int val2){
    return val1 + val2;
}

int main(){
    std::clog << "C++ New features" << std::endl;

    constexpr int flag = get_flag();
    int value_1 = 0;
    int value_2 {0};
    int sum = 0;

    std::cout << "please input your name: " << std::endl;
    std::string name = get_name();

    std::cout << "Hi, " << name<< ". Please input first value: " << std::endl;
    value_1 = get_value(flag);

    std::cout << "Great, please input second value: " << std::endl;
    value_2 = get_value(flag);

    sum = get_sum(value_1, value_2);
    std::cout << "The sum is : " << sum << std::endl;
    return 0;
}