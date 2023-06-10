#include <iostream>
#include <limits>
#include <cmath>

class Num_Process{
    private:


    public:

        int show_limits(){
            std::cout << "The range for short is from " << std::numeric_limits<short>::min() << " to " 
                << std::numeric_limits<short>::max() << std::endl;
            
            std::cout << "The range for unsigned short is from " << std::numeric_limits<unsigned short>::min() << " to " 
                << std::numeric_limits<unsigned short>::max() << std::endl;            
                
            std::cout << "The range for int is from " << std::numeric_limits<int>::min() << " to " 
                << std::numeric_limits<int>::max() << std::endl;
                
            std::cout << "The range for unsigned int is from " << std::numeric_limits<unsigned int>::min() << " to " 
                << std::numeric_limits<unsigned int>::max() << std::endl;
                
            std::cout << "The range for long is from " << std::numeric_limits<long>::min() << " to " 
                << std::numeric_limits<long>::max() << std::endl;
                
            std::cout << "The range for float is from " << std::numeric_limits<float>::min() << " to " 
                << std::numeric_limits<float>::max() << std::endl;
                
            std::cout << "The range(with lowest) for float is from " << std::numeric_limits<float>::lowest() << " to " 
                << std::numeric_limits<float>::max() << std::endl;
                
            std::cout << "The range(with lowest) for double is from " << std::numeric_limits<double>::lowest() << " to " 
                << std::numeric_limits<double>::max() << std::endl;
                
            std::cout << "The range(with lowest) for long double is from " << std::numeric_limits<long double>::lowest() << " to " 
                << std::numeric_limits<long double>::max() << std::endl;

            //Other facilities
            std::cout << "int is signed : " << std::numeric_limits<int>::is_signed << std::endl;
            std::cout << "int digits : " << std::numeric_limits<int>::digits << std::endl;

            return 0;
        }

        int math_funs(){
            double weight { 7.7 };            
            //floor
            std::cout << "Weight rounded to floor is : " << std::floor(weight) << std::endl;            
            //ceil 
            std::cout << "Weight rounded to ceil is : " << std::ceil(weight) << std::endl;            
            //abs
            double savings {-5000 };        
            std::cout << "Abs of weight is : " << std::abs(weight) << std::endl;
            std::cout << "Abs of savings is : " << std::abs(savings) << std::endl;            
            //exp : f(x) = e ^ x , where e = 2.71828 . Test the result here against a calculator
            double exponential = std::exp(10);
            std::cout << "The exponential of 10 is : " << exponential << std::endl;            
            //pow
            std::cout << "3 ^ 4 is : " << std::pow(3,4) << std::endl;
            std::cout << "9^3 is : " << std::pow(9,3) << std::endl;          
            // Try the reverse operation of  e^4 = 54.59 , it will be log 54.59 in base e = ? 
            std::cout << "Log ; to get 54.59, you would elevate e to the power of : "
                    << std::log(54.59) << std::endl;            
            //log10 , 10 ^ 4 = 10000  , to get 10k , you'd need to elevate 10 to the power of ? , this is log in base 10
            std::cout << "To get 10000, you'd need to elevate 10 to the power of : "
                        << std::log10(10000) << std::endl; // 4
            //sqrt
            std::cout << "The square root of 81 is : " << std::sqrt(81) << std::endl;            
            //round. Halfway points are rounded away from 0. 2,5 is rounded to 5 for example
            std::cout << "3.654 rounded to : " << std::round(3.654) << std::endl;
            std::cout << "2.5 is rounded to : " << std::round(2.5) << std::endl;
            std::cout << "2.4 is rounded to : " << std::round(2.4) << std::endl;            
        
            return 0;
        }

        int wierd_int(){
            short int var1 {10}; // 2 bytes
            short int var2 {20};
            
            char var3 {40}; //1
            char var4 {50};
            
            std::cout << "size of var1 : " << sizeof(var1) << std::endl;
            std::cout << "size of var2 : " << sizeof(var2) << std::endl;
            std::cout << "size of var3 : " << sizeof(var3) << std::endl;
            std::cout << "size of var4 : " << sizeof(var4) << std::endl;
            
            auto result1 = var1 + var2 ;
            auto result2 = var3 + var4;
            
            std::cout << "size of result1 : " << sizeof(result1) << std::endl; // 4
            std::cout << "size of result2 : " << sizeof(result2) << std::endl; // 4
            
        
            return 0;
        }
};

class Show_Case{
    private:
        Num_Process num_p;
    public:
        int flag {0};

        int show_menu(){
            std::clog << "--- Testing table: ---" << std::endl;
            std::clog << "- 1 - Numeric limits" << std::endl;
            std::clog << "- 2 - Math functions" << std::endl;
            std::clog << "- 3 - Weird Integral Types" << std::endl;
            std::clog << "- 0 - exit" << std::endl;
            std::clog << "please input: " << std::endl;
            return 0;
        }

        int get_flag(){
            std::cin >> flag;
            return 0;
        }

        int display(){
            if(flag == 1){
                num_p.show_limits();
            }
            else if(flag == 2){
                num_p.math_funs();
            }
            else if (flag == 3){
                num_p.wierd_int();
            }
            else{
                std::cerr << "Wrong input!" << std::endl;
            }
            return 0;
        }

        int say_bye(){
            std::clog << "The End! Bye~" << std::endl;
            return 0;
        }
};

int main(){
    Show_Case show_c;

    while(true){
        show_c.show_menu();
        show_c.get_flag();

        if(show_c.flag == 0){
            break;
        }
        else{
            show_c.display();
        }
        
    }  

    show_c.say_bye();
    return 0;
}