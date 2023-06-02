#include <iostream>
#include <iomanip>

class Basic_Oprt{
    private:
        int number1 {2};
        int number2 {7};

        int a {6};
        int b {3};
        int c {8};
        int d {9};
        int e {3};
        int f {2};
        int g {5};

    public:
        int display_op(){
            std::clog << "--- basic oprators ---" << std::endl;

            std::cout << "number 1: " << number1 << " and number 2: " << number2 << std::endl;
            //Addition
            int result = number1 + number2;
            std::cout << "result of addition: " << result << std::endl;
            //Subtraction
            result = number1 - number2;
            std::cout << "result of subtraction: " << result << std::endl;
            //Multiplication
            result = number1 * number2;
            std::cout << "result of multiplication: " << result << std::endl;
            //Division
            result = number2 / number1;
            std::cout << "result of division: " << result << std::endl;
            //Modulus
            result = number2 % number1; // 7 % 2
            std::cout << "result of modulus: " << result << std::endl; // 1
            std::cout << "---------------------------" << std::endl;
            return 0;
        }

        int prcd_asct(){
            std::clog << "--- precedence and associativity ---" << std::endl;

            int result = a + b * c -d/e -f + g; // 6 + 24 - 3 - 2 + 5
            std::cout << "result of '6+3*8-3-2+5' : " << result << std::endl;
            result = a/b*c +d - e + f;  // 16 + 9 - 3 + 2
            std::cout << "result of '6/3*8+9-3+2': " << result << std::endl;
            result = (a + b) * c -d/e -f + g; // 72 - 3 - 2 + 5
            std::cout << "result of '(6+3)*8-3-2+5': " << result << std::endl;
            std::cout << "------------------------------------" << std::endl;
            return 0;
        }
        int incre_decre(){
            std::clog << "--- prefix and postfix of in/decrement ---" << std::endl;

            int value {5};
    
            //Increment by one
            value = value + 1; //6
            std::cout << "The value is : " << value << std::endl; // 6
            //Decrement by one
            value = value - 1; // 5
            std::cout << "The value is : " << value << std::endl; //5
            std::cout << "------------------------------------------"<< std::endl;
            //Increment with prefix and postfix
            std::cout << "The value++ is : " << value++ << std::endl; // 5
            std::cout << "The value is : " << value << std::endl; // 6
            std::cout << "The ++value is : " << ++value << std::endl; // 7
            std::cout << "The value is : " << value << std::endl; // 7
            //Decrement with prefix and postfix
            std::cout << "The value-- is : " << value-- << std::endl; //7
            std::cout << "The value is : " << value << std::endl; // 6
            std::cout << "The --value is : " << --value << std::endl; //5
            std::cout << "The value is : " << value << std::endl; // 5
            std::cout << "------------------------------------------" << std::endl;

            return 0;
        }
        int compound_op(){
            std::clog << "--- Compound assignment operators ---" << std::endl;

            int value {45};
    
            std::cout << "The value is : " << value << std::endl;
            
            std::cout << std::endl;
            value += 5; // equivalent to value = value + 5
            std::cout << "The value is (after +=5) : " << value << std::endl; // 50

            value -= 5; // equivalent to value = value - 5
            std::cout << "The value is (after -=5) : " << value << std::endl; // 45 

            value *= 2;
            std::cout << "The value is (after *=2) : " << value << std::endl; // 90

            value /= 3;
            std::cout << "The value is (after /=3) : " << value << std::endl; // 30

            value %= 11;
            std::cout << "The value is (after %=11) : " << value << std::endl;// 8
            std::cout << "------------------------------------------" << std::endl;

            return 0;
        }

        
};

class Spec_Oprt{
    private:
            bool a {true};
            bool b {false};
            bool c {true};
            int d{45};
            int e{20};
            int f{11};
    public:

        int relational_op(){
            std::clog << "--- Relational operators ---" << std::endl;

            int number1 {20};
            int number2 {20};
            
            std::cout << "number1 : " << number1 << std::endl;
            std::cout << "number2 : " << number2 << std::endl;
                       
            std::cout << std::boolalpha ; // Make bool show up as true/false instead of 1/0
            //Stress the need for parentheses here
            std::cout << "number1 < number2 : " << (number1 < number2) << std::endl;
            std::cout << "number1 <= number2 : " << (number1 <= number2) << std::endl;
            std::cout << "number1 > number2 : " << (number1 > number2) << std::endl;
            std::cout << "number1 >= number2 : " << (number1 >= number2) << std::endl;
            std::cout << "number1 == number2 : " << (number1 == number2) << std::endl;
            std::cout << "number1 != number2 : " << (number1 != number2) << std::endl;

            std::cout << "store comparison result and use it later" << std::endl;            
            bool result = (number1 == number2);            
            std::cout <<  number1 << " == " << number2 << " : " << result <<  std::endl;
            std::cout << "------------------------------------------" << std::endl;

            return 0;
        }

        int logical_op(){
           
            std::cout << std::boolalpha; // true / false
            std::cout << "a : " << a << std::endl;
            std::cout << "b : " << b << std::endl;
            std::cout << "c : " << c << std::endl;
            //AND : Evaluates to true when all operands are true.
            //      A single false operand will drag 
            //      the entire expression to evaluating false.
            
            std::cout << std::endl;
            std::cout << "Basic AND operations" << std::endl;

            std::cout << " a && b : " << (a && b) << std::endl; // false
            std::cout << " a && c : " << (a && c ) << std::endl; // true
            std::cout << " a && b && c :" << (a && b && c) << std::endl; // false


            //OR : Evaluates to true when at least one operand true.
            //      A single true operand will push 
            //      the entire expression to evaluating true.
            std::cout << std::endl;
            std::cout << "Basic OR operations" << std::endl;
            std::cout << " a || b : " << (a || b) << std::endl;
            std::cout << " a || c : " << (a || c ) << std::endl;
            std::cout << " a ||b || c :" << (a || b || c) << std::endl;
            //NOT : Negates whateve operand you put it with
            std::cout << std::endl;
            std::cout << "Basic NOT operations" << std::endl;	
            std::cout << "!a : " << !a << std::endl;
            std::cout << "!b : " << !b << std::endl;
            std::cout << "!c : " << !c << std::endl;
            //Combinations of all these operators
            std::cout << "Combining logical operators" << std::endl;
            // !(a &&b) || c
            std::cout << "!(a &&b) || c : " << (!(a &&b) || c) << std::endl; // true
            //Combining logical operators with relational operators
            std::cout << "Relational and logic operations on integers" << std::endl;
            std::cout << "d : " << d << std::endl;
            std::cout << "e : " << e << std::endl;
            std::cout << "f : " << f << std::endl;
            std::cout << "(d > e) && (d > f) : " << ((d > e) && (d > f)) << std::endl; // true
            std::cout << "(d==e) || (e <= f ) : " << ((d==e) || (e <= f ) ) << std::endl;
            std::cout << "(d < e) || (d > f) : " << ((d < e) || (d > f)) << std::endl;
            std::cout << "(f > e) || (d < f) : " << ((f > e) || (d < f)) << std::endl;
            std::cout << "(d > f) && (f <= d) : " << ((d > f) && (f <= d)) << std::endl;
            std::cout << "(d > e) && (d <= f) : " << ((d > e) && (d <= f)) << std::endl;
            std::cout << "(! a) && (d == e) : " << ((! a) && (d == e)) << std::endl;
            std::cout << "(! a) && (d == e) : " << ((! a) && (d == e)) << std::endl;
            return 0;
        }

};

class Out_Format{
    private:


    public:
    int show_farmats(){

        //std::flush : flushes the output buffer to its final destination. 
        std::cout << "This is a nice message...." << std::endl << std::flush;
        //After this std::flush, we're sure that at this line, the message has been sent 
        //to the stream. This may be important in some applications.
        
        //===================================================================
        //std::setw() : Adjusts the field with for the item about to be printed. 
        //The setw() manipulator only affects the next value to be printed.        
        std::cout << "Formatted table : " << std::endl;        
        int col_width{14};        
        
        std::cout << std::setw(col_width) <<  "Lastname"  << std::setw(col_width) << "Firstname" << std::setw(col_width/2) << "Age" << std::endl;
        std::cout << std::setw(col_width) << "Daniel"  << std::setw(col_width) << "Gray" << std::setw(col_width/2) << "25" << std::endl;
        std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width)  << "Woods" << std::setw(col_width/2) <<  "33" << std::endl;
        std::cout << std::setw(col_width) <<  "Jordan" << std::setw(col_width)  << "Parker" << std::setw(col_width/2) << "45" << std::endl;

        //===================================================================
        //Justify : Values can be justified in their fields. There are three manipulators
        //          for adjusting the justification: left, right, and internal. 
        
        //Left justified
        std::cout << "Left justified table :  " << std::endl;
        
        col_width = 20;        
        std::cout << std::left;
        std::cout << std::setw(col_width) <<  "Lastname"  << std::setw(col_width) << "Firstname" << std::setw(col_width/2) << "Age" << std::endl;
        std::cout << std::setw(col_width) << "Daniel"  << std::setw(col_width) << "Gray" << std::setw(col_width/2) << "25" << std::endl;
        std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width)  << "Woods" << std::setw(col_width/2) <<  "33" << std::endl;

        //Internal justified : sign is left justified , data is right justified
        std::cout << "Internal justified : " << std::endl;
        std::cout << std::right;
        std::cout << std::setw(10) << -123.45 << std::endl;
        std::cout << std::internal;
        std::cout << std::setw(10) << -123.45 << std::endl;
        
        //===================================================================
        //setfill
        std::cout << "Table with fill characters :  " << std::endl;
        col_width = 20;

        std::cout << std::setfill('*'); // The fill character
        std::cout << std::setw(col_width) <<  "Lastname"  << std::setw(col_width) << "Firstname" << std::setw(col_width/2) << "Age" << std::endl;
        std::cout << std::setw(col_width) << "Daniel"  << std::setw(col_width) << "Gray" << std::setw(col_width/2) << "25" << std::endl;
        std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width)  << "Woods" << std::setw(col_width/2) <<  "33" << std::endl;

        //==================================================================
        //boolalpha and noboolapha : control bool output format : 1/0 or true/false
        bool condition {true};
        bool other_condition {false};
        
        std::cout << std::boolalpha;
        std::cout << "condition : " << condition << std::endl;
        std::cout << "other_condition : " << other_condition << std::endl;
        
        std::cout << std::noboolalpha;
        std::cout << "condition : " << condition << std::endl;
        std::cout << "other_condition : " << other_condition << std::endl;
        
        //===================================================================
        //showpos and noshowpos : show or hide the +  sign for positive numbers
        int pos_num {34};
        int neg_num {-45};
          
        std::cout << std::showpos;
        std::cout << "pos_num : " << pos_num << std::endl;
        std::cout << "neg_num : " << neg_num << std::endl; 
        std::cout << std::noshowpos;
        std::cout << "pos_num : " << pos_num << std::endl;
        std::cout << "neg_num : " << neg_num << std::endl;   

        //===================================================================
        //different number systems : std::dec, std::hex, std::oct
        
        int pos_int {717171};
        int neg_int {-47347};
        double double_var {498.32};
        
        std::cout << "default base format : " << std::endl;
        std::cout << "pos_int : " << pos_int << std::endl;
        std::cout << "neg_int : " << neg_int << std::endl;
        std::cout << "double_var : " << double_var << std::endl;
        
        std::cout << "pos_int in different bases : " << std::endl;
        std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
        std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
        std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;
        
        std::cout << "neg_int in different bases : " << std::endl;
        std::cout << "neg_int (dec) : " << std::dec << neg_int << std::endl;
        std::cout << "neg_int (hex) : " << std::hex << neg_int << std::endl;
        std::cout << "neg_int (oct) : " << std::oct << neg_int << std::endl;
        
        std::cout << "double_var in different bases : " << std::endl;
        std::cout << "double_var (dec) : " << std::dec << double_var << std::endl;
        std::cout << "double_var (hex) : " << std::hex << double_var << std::endl;
        std::cout << "double_var (oct) : " << std::oct << double_var << std::endl;
        
        
        //===================================================================
        //uppercase and nouppercase

        pos_int = 717171;
        
        std::cout << "pos_int (nouppercase : default) : " << std::endl;
        std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
        std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
        std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;
        std::cout << "pos_int (uppercase) : " << std::endl;
        std::cout << std::uppercase;
        std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;
        std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;
        std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;
        
        
        //===================================================================
        //fixed and scientific : for floating point values
        
        double a{ 3.1415926535897932384626433832795 };
        double b{ 2006.0 };
        double c{ 1.34e-10 };

        std::cout << "double values (fixed) : " << std::endl;
        std::cout << std::fixed;
        std::cout << "a : " << a << std::endl;
        std::cout << "b : " << b << std::endl;
        std::cout << "c : " << c << std::endl;
        
        std::cout << "double values (scientific) : " << std::endl;
        std::cout << std::scientific;
        std::cout << "a : " << a << std::endl;
        std::cout << "b : " << b << std::endl;
        std::cout << "c : " << c << std::endl;

        std::cout << "double values (back to defaults) : " << std::endl;
        std::cout.unsetf(std::ios::scientific | std::ios::fixed); // Hack
        std::cout << "a : " << a << std::endl;
        std::cout << "b : " << b << std::endl;
        std::cout << "c : " << c << std::endl;
        
        
        //===================================================================
        //setprecision() : the number of digits printed out for a floating point. Default is 6
        
        a = 3.1415926535897932384626433832795;
        
        std::cout << "a (default precision(6)) : " << a <<  std::endl;
        std::cout << std::setprecision(10);
        std::cout << "a (precision(10)) : " << a << std::endl;
        std::cout << std::setprecision(20);
        std::cout << "a (precision(20)) : " << a << std::endl;
        
        //If the precision is bigger than supported by the type, you'll just print garbage.
        //===================================================================
        //showpoint and noshowpoint : show trailing zeros if necessary
        //Force output of the decimal point
        
        double d {34.1};
        double e {101.99};
        double f {12.0};
        int    g {45};
        
        std::cout << "noshowpoint (default) : " << std::endl;
        std::cout << "d : " << d << std::endl;
        std::cout << "e : " << e << std::endl;
        std::cout << "f : " << f << std::endl; // 12
        std::cout << "g : " << g << std::endl;

        std::cout << "showpoint: " << std::endl;
        std::cout << std::showpoint;
        std::cout << "d : " << d << std::endl;
        std::cout << "e : " << e << std::endl;
        std::cout << "f : " << f << std::endl; // 12.0
        std::cout << "g : " << g << std::endl;

        return 0;
    }

};

class Show_Case{
    private:
        Basic_Oprt basic_op;
        Spec_Oprt spec_op;
    public:
        int flag {0};

        int show_menu(){
            std::clog << "--- Data operations testing table: ---" << std::endl;
            std::clog << "- 1 - c++ opraters and precedence" << std::endl;
            std::clog << "- 2 - relational and logical operators" << std::endl;
            std::clog << "- 3 - output formatting" << std::endl;
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
                basic_op.display_op();
                basic_op.prcd_asct();
                basic_op.incre_decre();
                basic_op.compound_op();
            }
            else if(flag == 2){
                spec_op.relational_op();
                spec_op.logical_op();
            }
            else if (flag == 3){

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

    return 0;
}