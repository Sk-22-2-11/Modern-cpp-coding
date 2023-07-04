#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <optional>
//Marking a function as constexpr gives it the potential 
//to be evaluated at compile time
constexpr int get_value(int multiplier){
    return 3 * multiplier;
}

void greet_teacher(std::string_view name_sv = "teacher" , int homeworks =12,
    int exams = 4, double pass_rate = 0.5, std::string_view first_dpmt = "Computer Sce");

std::optional<size_t> find_character_v2(const std::string & str, char c){
    //If found set the return index, else return an empty std::optional
    for (size_t i{} ; i < str.size()  ; ++i){
        if(str.c_str()[i] == c){
            return i;
        }
    }
   return {}; //Or std::nullopt
   //std::nullopt;
}


//Specify default character to  search for

std::optional<size_t> find_character_v3(const std::string & str,
										std::optional<char> c = std::nullopt){
    //If found set return index, else return empty
    //If c is specified, find it else just find 'z'
    /*
    char char_to_find;
    if(c.has_value()){
        char_to_find = c.value();
    }else{
        char_to_find = 'z'; // Will find z by default
    }
    */
   char char_to_find = c.value_or('z');
    
    for (size_t i{} ; i < str.size()  ; ++i){
        //std::cout << "str[i] : " << str.at(i) << " , c : " << c << std::endl;
        if(str.c_str()[i] == char_to_find){
            return i;
        }
    }
   return {};// Or std::nullopt
}

class Show_function{
    private:


    public:

        int io_fun(){
            //Call and use default arguments
            greet_teacher();
            greet_teacher("Mr Bean");
            greet_teacher("Mr Hamston",7);
            greet_teacher("Mr Walker",7,3);
            greet_teacher("Mr Paku",7,3,0.7);
            greet_teacher("Mr Kojo",7,3,0.7,"Applied Mathematics");

            /*
            For the evaluation to take place at compile time, we have 
            to remember to store the return value in a constexpr result variable
            Thanks to Reza for catching this error and reporting it. 
            */
            constexpr int result = get_value(4); // Compile time
            std::cout << "result : " << result << std::endl;
            /*
            int some_var{5}; // Run time variable
            int result = get_value(some_var); // Run time
            std::cout << "result : " << result << std::endl;
            */

            return 0;
        }
        int optional_out(){
            std::string str1 {"Hello World in C++20!"};
            char c{'C'};

            /*
            std::optional<size_t> result = find_character_v2(str1,c);

            if(result.has_value()){
                std::cout << "Found our character at index : " << result.value() << std::endl;
            }else{
                std::cout << "Didn't find our character" << std::endl;
            }
            */

            str1 = "Hello Worldz in C++20!";
            
            auto result1 = find_character_v3(str1,'o'); //Will search for 'z' if you don't specify 
                                                    // the character so search for
            if(result1.has_value()){
                std::cout << "Found character 'o' at index " << result1.value() << std::endl;
            }else{
                std::cout << "Could not find character 'o' in the string : " << str1 << std::endl;
            }
   
            return  0;
        }
};



class Show_Case{
    private:
        Show_function fun_show;

    public:
        int flag {0};

        int show_menu(){
            std::clog << "--- Testing table: ---" << std::endl;
            std::clog << "- 1 - parameters and outputs" << std::endl;
            std::clog << "- 2 - arguments to main" << std::endl;
            std::clog << "- 3 - optional outputs" << std::endl;
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
                fun_show.io_fun();
                
            }
            else if(flag == 2){
                //fun_show.str_litral();
            }
            else if (flag == 3){
                fun_show.optional_out();
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

void greet_teacher(std::string_view name_sv,int homeworks,
                    int exams, double pass_rate, std::string_view first_dpmt){
    std::cout << std::endl;
    std::cout << "Good morning " << name_sv << "!" << std::endl;
    std::cout << "In the past semester, we had " << homeworks << " homeworks, and "
                << exams << " exams. The pass rate was around : " << pass_rate << std::endl;
    std::cout << "The best performing department is : " << first_dpmt << std::endl;
}