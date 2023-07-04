#include <iostream>
#include <string>
#include <iomanip>

class Number_T
{
private:
    signed int value1 {10};
    signed int value2 {-300};
    unsigned int value3 {4};
    //unsigned int value4{-5}; // Compiler error.

    //short and long
    short short_var {-32768} ; //  2 Bytes 
    short int short_int {455} ; // 
    signed short signed_short {122}; //
    signed short int signed_short_int {-456}; // 
    unsigned short int unsigned_short_int {456};
    
    int int_var {55} ; // 4 bytes
    signed signed_var {66};//
    signed int signed_int {77};//
    unsigned int unsigned_int{77};
    
    long long_var {88}; // 4 OR 8 Bytes
    long int long_int {33};
    signed long signed_long {44};
    signed long int signed_long_int {44};
    unsigned long int unsigned_long_int{44};

    long long long_long {888};// 8 Bytes
    long long int long_long_int {999};
    signed long long signed_long_long {444};
    signed long long int signed_long_long_int{1234};
    unsigned long long int unsigned_long_long_int{1234};

public:

    int int_show(){
        std::cout << "value1 : " << value1 << std::endl;
        std::cout << "value2 : " << value2 << std::endl;
        std::cout << "sizeof(value1) : " << sizeof(value1) << std::endl;
        std::cout << "sizeof(value2) : " << sizeof(value2) << std::endl;
        std::cout << "---------------------" << std::endl;

        std::cout << "Short variable : " << short_var<<  " , size : "
                    << sizeof (short) << " bytes" << std::endl;
        std::cout << "Short Int : " << short_int << " , size : "
                    << sizeof (short int) << " bytes" << std::endl;
        std::cout << "Signed short : " << signed_short
                    << " , size : " << sizeof (signed short) << " bytes" << std::endl;
        std::cout << "Signed short int :  " << signed_short_int
                    <<  " , size : " << sizeof (signed short int) << " bytes" << std::endl;        
        std::cout << "unsigned short int :  " << unsigned_short_int
                    <<  " , size : " << sizeof (unsigned short int) << " bytes" << std::endl;        
        std::cout << "---------------------" << std::endl;

        std::cout << "Int variable :  " << int_var <<" , size : "
                    << sizeof (int) << " bytes" << std::endl;
        std::cout << "Signed variable " << signed_var <<" , size : "
                    << sizeof (signed) << " bytes" << std::endl;
        std::cout << "Signed int :  " << signed_int <<" , size : "
                    << sizeof (signed int) << " bytes" << std::endl;
        std::cout << "unsigned int :  " << unsigned_int <<" , size : "
                    << sizeof (unsigned int) << " bytes" << std::endl;
        std::cout << "---------------------" << std::endl;

        std::cout << "Long variable :  " << long_var << " , size : "
                    << sizeof (long) << " bytes" <<std::endl;
        std::cout << "Long int :  " << long_int <<" , size : "
                    << sizeof (long int) << " bytes" << std::endl;
        std::cout << "Signed long :  " << signed_long <<" , size : "
                    << sizeof (signed long) << " bytes" << std::endl;
        std::cout << "Signed long int : " << signed_long_int <<" , size : "
                    << sizeof (signed long int) << " bytes" << std::endl;        
        std::cout << "unsigned long int : " << unsigned_long_int <<" , size : "
                    << sizeof (unsigned long int) << " bytes" << std::endl;        
        std::cout << "---------------------" << std::endl;

        std::cout << "Long long : " << long_long <<" , size : "
                    << sizeof (long long) << " bytes" << std::endl;
        std::cout << "Long long int : " << long_long_int <<" , size : "
                    << sizeof (long long int) << " bytes" << std::endl;
        std::cout << "Signed long long : " << signed_long_long <<" , size : "
                    << sizeof (signed long long) << " bytes" <<std::endl;        
        std::cout << "Signed long long int : " << signed_long_long_int <<" , size : "
                    << sizeof (signed long long int) << " bytes" << std::endl;        
        std::cout << "unsigned long long int : " << unsigned_long_long_int <<" , size : "
                    << sizeof (unsigned long long int) << " bytes" << std::endl;        
        std::cout << "---------------------" << std::endl;

        return 0;
    }

    int float_show(){
        //Declare and initialize the variables
        float number1 {1.12345678901234567890f}; // Precision : 7
        double number2 {1.12345678901234567890}; // Precision : 15
        long double number3  {1.12345678901234567890L};
    
        //Print out the sizes
        std::cout << "sizeof float : " << sizeof(float) << std::endl;
        std::cout << "sizeof double : " << sizeof(double) << std::endl;
        std::cout << "sizeof long double : " << sizeof(long double) << std::endl;
        //Precision
        std::cout << std::setprecision(20); // Control the precision from std::cout.
        std::cout << "number1 is : " << number1 << std::endl; //7 digits
        std::cout << "number2 is : " << number2 << std::endl; // 15'ish digits
        std::cout << "number3 is : " << number3 << std::endl; // 15+ digits

        //Float problems : The precision is usually too limited
        //                      for a lot of applications
        float number4 = 192400023.0f;               // Error : narrowing conversion
        std::cout << "number4 : " << number4 << std::endl;

        //Scientific notation
        std::cout << "-------------------------" << std::endl;
    
        double number5 {192400023};
        double number6 {1.92400023e8};
        double number7 {1.924e8};  // Can ommit the lower 00023 for simplicity if our application allows that.
        double number8 {0.00000000003498};
        double number9 {3.498e-11}; // multiply with 10 exp(-11)
    
        std::cout << "number5 is : " << number5 << std::endl;
        std::cout << "number6 is : " << number6 << std::endl;
        std::cout << "number7 is : " << number7 << std::endl;
        std::cout << "number8 is : " << number8 << std::endl;
        std::cout << "number9 is : " << number9 << std::endl;
        std::cout << "-------------------------" << std::endl;

        //Infinity and Nan
        double number10{ -5.6 };
        double number11{};//Initialized to 0
        double number12{};  //Initialized to 0

        //Infinity
        double result { number10 / number11 };
        std::cout << number10 << "/" << number11 << "  yields " << result << std::endl;
        std::cout << result << " + " << number10 << " yields " << result + number10 << std::endl;
        //NaN
        result = number11 / number12;    
        std::cout << number11 << "/" << number12 << " = " << result << std::endl;
        return 0;    
    }

    int ini_show(){
        //braced initialization
        int braced_a {5};
        int braced_b {10};
        int braced_sum {braced_a + braced_b};
        /*int braced_n {dont_exist};//unknown variables
        int braced_decm {2.8};//compile error*/
    
        //assignment initialization
        int asmt_a = 5;
        int asmt_b = 10;
        int asmt_sum = asmt_a + asmt_b;
        /*int braced_n {dont_exist};//unknown variables */
        int asmt_decm = 2.8;//information lost
        //functional initialization
        //  not allowed to be used directly in a class
        int func_a (5);
        int func_b (10);
        int func_sum (func_a + func_b);
        /*int braced_n {dont_exist};//unknown variables */
        int func_decm (2.8);//information lost

        std::cout << "Braced initialization" << std::endl;
        std::cout << "a = " << braced_a 
                    << " ; b = " << braced_b 
                    << " ; sum = " << braced_sum << 
                    "decimal: compile error" 
                    << std::endl;
        std::cout << "Functional initialization" << std::endl;
        std::cout << "a = " << func_a 
                    << " ; b = " << func_b 
                    << " ; sum = " << func_sum
                    << " ; decimal = " << func_decm 
                    << std::endl;
        std::cout << "Assignment initialization" << std::endl;
        std::cout << "a = " << asmt_a 
                    << " ; b = " << asmt_b 
                    << " ; sum = " << asmt_sum
                    << " ; decimal = " << asmt_decm 
                    << std::endl;
        std::cout << "---------------------" << std::endl;
        return 0;
    }
};


class Bool_T{
private:
    bool red_light {false};
    bool green_light{true};
public:
    int bool_show(){
        if(red_light == true){
            std::cout << "Stop!" << std::endl;
        }else{
            std::cout << "Go through!" << std::endl;
        }

        if(green_light){
            std::cout << "The light is green!" << std::endl;
        }else{
            std::cout << "The light is NOT green!" << std::endl;
        }

        //sizeof()
        std::cout << "sizeof(bool) : " << sizeof(bool) << std::endl;


        //Printing out a bool
        //1 -->> true
        //0 -->> false
        std::cout << std::endl;
        std::cout << "red_light : " << red_light << std::endl;
        std::cout << "green_light : " << green_light << std::endl;

        std::cout << std::boolalpha;
        std::cout << "red_light : " << red_light << std::endl;
        std::cout << "green_light : " << green_light << std::endl;
        
        return 0;
    }
};

class Char_T{
private:
    char character1 {'a'};
    char character2 {'r'};
    char character3 {'r'};
    char character4 {'o'};
    char character5 {'w'};


public:
    int char_show(){
        std::cout << character1 << std::endl;
        std::cout << character2 << std::endl;
        std::cout << character3 << std::endl;
        std::cout << character4 << std::endl;
        std::cout << character5 << std::endl;

        //One byte in memory : 2^8 = 256 different values (0 ~ 255)
        std::cout << std::endl;
    
        char value = 65 ; // ASCII character code for 'A'
        std::cout << "value : " << value << std::endl; // A
        std::cout << "value(int) : " << static_cast<int>(value) << std::endl; 

        return 0;
    }

    int auto_show(){
        // 'auto' is not allowed to be used directly in a class
        //    thus, it should be const if used as a class member
        auto var1 {12};
        auto var2 {13.0};
        auto var3 {14.0f};
        auto var4 {15.0l};
        auto var5 {'e'};
    
        //int modifier suffixes
        auto var6 { 123u}; // unsigned
        auto var7 { 123ul}; //unsigned long
        auto var8 { 123ll}; // long long

        std::cout << "var1 occupies : " << sizeof(var1) << " bytes" << std::endl;
        std::cout << "var2 occupies : " << sizeof(var2) << " bytes" << std::endl;
        std::cout << "var3 occupies : " << sizeof(var3) << " bytes" << std::endl;
        std::cout << "var4 occupies : " << sizeof(var4) << " bytes" << std::endl;
        std::cout << "var5 occupies : " << sizeof(var5) << " bytes" << std::endl;
        std::cout << "var6 occupies : " << sizeof(var6) << " bytes" << std::endl;
        std::cout << "var7 occupies : " << sizeof(var7) << " bytes" << std::endl;
        std::cout << "var8 occupies : " << sizeof(var8) << " bytes" << std::endl;
   
        return 0;              

    }
};

int main(){
    int flag {0};
    Number_T num_t;
    Bool_T bool_t;
    Char_T char_t;

    while(true){
        std::clog << "--- Data types testing table: ---" << std::endl;
        std::clog << "- 1 - integers and decimals" << std::endl;
        std::clog << "- 2 - booleans" << std::endl;
        std::clog << "- 3 - characters and text" << std::endl;
        std::clog << "- 4 - exit" << std::endl;
        std::clog << "please input: " << std::endl;
        std::cin >> flag;

        if(flag == 1){
            num_t.ini_show();
            num_t.int_show();
            num_t.float_show();
        }
        else if(flag == 2){
            bool_t.bool_show();
        }
        else if (flag == 3){
            char_t.char_show();
        }
        else if (flag == 4){
            break;
        }
        else{
            std::cerr << "Wrong input!" << std::endl;
        }
        

    }

    



    std::clog << "The End!" << std::endl;

    return 0;
}