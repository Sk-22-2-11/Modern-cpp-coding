#include <iostream>

const int val1 {33};
constexpr int val2{34};
int val3 {35}; // Run time value

constinit int age = 88; // This is initialized at compile time
const constinit int age1 {val1}; // const and constinit can be combined
constinit int age2 {age1}; // Initializing with age would lead to a compiler error
                                // age is not const
//constinit int age3 {val3}; // Error : val3 is evaluated at run time
                        // can't const initialize age3
                        
const constinit double weight {33.33};
//constexpr constinit double scale_factor{3.11};// Can't combine constexpr and constinit

class Show_Consts{
    private:


    public:

        int const_literal(){
            //Literal types : u and l combinations for unsigned and long.
            unsigned char unsigned_char {53u};// 555U would fail because of narrowing            
            //2 Bytes
            short short_var {-32768} ; //  No special literal type for short
            short int short_int {455} ; //  No special literal type for short
            signed short signed_short {122}; // No special literal type for short
            signed short int signed_short_int {-456}; // No special literal type for short
            unsigned short int unsigned_short_int {5678U };            
            // 4 Bytes
            const int int_var {55} ;            //
            signed signed_var {66};             //
            signed int signed_int {77};         //
            unsigned int unsigned_int {555U};       //    
            //4 or 8 Bytes
            long long_var {88L}; // 4 OR 8 Bytes
            long int long_int {33L};
            signed long signed_long {44l};
            signed long int signed_long_int {44l};
            unsigned long int unsigned_long_int {555ul};
            long long long_long {888ll};// 8 Bytes
            long long int long_long_int {999ll};
            signed long long signed_long_long {444ll};
            signed long long int signed_long_long_int{1234ll};
            //Grouping Numbers : C++14 and onwards
            unsigned int prize  {1'500'00'0u};
            std::cout << "The prize is : " << prize << std::endl;
            std::cout << " signed_long_long_int : " << signed_long_long_int << std::endl; 
            //Narrowing errors
            //Possible narrowing errors are cought by the braced initializer method.
            //Assignment and functional don't catch that.
            //unsigned char distance {555u}; //Error [0~255]
            //unsigned int game_score {-20}; //Error

            //With number systems - Hex : prefix with 0x
            unsigned int hex_number{ 0x22BU}; // Dec 555
            int hex_number2 {0x400};// Dec 1024
            std::cout << std::hex <<  "The hex number is : " << hex_number << std::endl;
            std::cout << std::dec <<  "The hex number2 is : " << hex_number2 << std::endl;            
            //Representing colors with hex
            int black_color {0xffffff};
            std::cout << "Black color is : " << std::dec << black_color << std::endl;
            //Octal literals : prefix with 0
            int octal_number {0777u}; // 511 Dec
            std::cout << "The octal number is : " << octal_number << std::endl;
            //!!BE CAREFUL NOT TO PREFIX YOUR INTEGERS WITH 0 IF YOU MEAN DEC
            int error_octal {055};// This is not 55 in memory , it is 45 dec
            std::cout << "The erronous octal number is : " << error_octal << std::endl;
            //Binary literals
            unsigned int binary_literal {0b11111111u};// 255 dec
            std::cout << "The binary literal is : " << binary_literal << std::endl;
            // Other literals. 
            char char_literal {'c'};
            int number_literal {15};
            float fractional_literal {1.5f};
            std::string string_literal {"Hit the road"};
            
            std::cout << "The char literal is : " << char_literal << std::endl;
            std::cout << "The number literal is : " << number_literal << std::endl;
            std::cout << "The fractional literal is : " << fractional_literal << std::endl;
            std::cout << "The string literal is : " << string_literal << std::endl;
            std::cout << "========================================" << string_literal << std::endl;
            const int age {34};
            const float height {1.67f};
            //age = 55; // Can't modify
            //height = 1.8f;
            int years { 3 * age};
            std::cout << "age : " << age << std::endl;
            std::cout << "height : " << height << std::endl;
            std::cout << "years : " << years << std::endl;
            return 0;
        }

        int const_expr(){
            constexpr int SOME_LIB_MAJOR_VERSION {1237};	
            constexpr int eye_count {2};            
            constexpr double PI {3.14};
            //eye_count = 4;
            
            std::cout << "eye count : " << eye_count << std::endl;
            std::cout << "PI : " << PI << std::endl;

            //int leg_count {2}; // Non constexpr
                                // leg_count is not known at compile time
            //constexpr int arm_count{leg_count}; // Error 
            constexpr int room_count{10};
            constexpr int door_count{room_count};// OK            
            const int table_count{5};
            constexpr int chair_count{ table_count * 5};// Works
            // static_assert( SOME_LIB_MAJOR_VERSION == 123);
            // int age = 5;
            // static_assert( age == 5);
            std::cout << "App doing its thing..." << std::endl;
                    return 0;
        }

        int const_init(){

            //constinit double height{1.72};

            std::cout << "age : " << age << std::endl;
            std::cout << "age1 : " << age1 << std::endl;
            std::cout << "age2 : " << age2 << std::endl;
            
            age =33; // Can change a const init variable
            std::cout << "age : " << age << std::endl;
            
            //Combining const and constinit
            std::cout << "weight : " << weight << std::endl;
            //weight = 44.44; // Compiler error

            return 0;
        }

};


class Show_Case{
    private:
        Show_Consts const_show;
    public:
        int flag {0};

        int show_menu(){
            std::clog << "--- Data operations testing table: ---" << std::endl;
            std::clog << "- 1 - Literal and Const" << std::endl;
            std::clog << "- 2 - Constexpr" << std::endl;
            std::clog << "- 3 - Constinit" << std::endl;
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
                const_show.const_literal();
            }
            else if(flag == 2){
                const_show.const_expr();
            }
            else if (flag == 3){
                const_show.const_init();
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