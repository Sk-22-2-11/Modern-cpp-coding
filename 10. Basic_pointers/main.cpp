#include <iostream>
#include <string>
#include <iomanip>

class Show_pointers{
    private:


    public:

        int pt_init(){
            
            //Declare and initialize pointer
            int* p_number {}; // Will initialize with nullptr
            double*  p_fractional_number{};

            //Explicitly initialize with nullptr
            int* p_number1{nullptr};
            int* p_fractional_number1{nullptr};

            //Pointers to different variables are  of the same size
            std::cout << "sizeof(p_number1) : " << sizeof(p_number1) << std::endl;
            std::cout << "sizeof(p_fractional_number1) : " << sizeof(p_fractional_number1) << std::endl;

            int *p_number5{}, other_int_var{};
            int* p_number6{}, other_int_var6{};	// Confusing as you wonder if other_int_var6
                                                //is also a pointer to int. It is not
                                                // The structure is exactly the same for the
                                                //previous statement
            //It is better to separate these declarations on different lines though
            int *p_number7{};
            int other_int_var7{}; // No room for confusion this time

            //Initializing pointers and assigning them data
            int int_var {43};
            int *p_int{&int_var};// The address of operator (&);
            //You can also change the address stored in a pointer any time
            int int_var1 {65};
            p_int = &int_var1; // Assign a different address to the pointer
            std::cout << "p_int (with different address)  : " << p_int << std::endl;

            //Can't cross assign between pointers of different types
            //Dereferencing a pointer : 
            int* p_int2 {nullptr};
            int int_data {56};
            p_int2 = &int_data;

            std::cout << "value : " << *p_int2 << std::endl; // Dereferencing a pointer  

            const char * message {"Hello World!"};
            std::cout << "message : " << message << std::endl;
            //*message = "B"; // Compiler error
            std::cout << "*message : " << *message << std::endl;

            //Allow users to modify the string
            char message1[] {"Hello World!"};
            message1[0] = 'B';
            std::cout << "message1 : " << message1 << std::endl;
            return 0;
        }

        int pt_array(){
            //srand() has to run once per program run
            std::srand(std::time(0)); // Seed

            // METHOD3.
            const char * predictions []  {
                "a lot of kids running in the backyard!",
                "a lot of empty beer bootles on your work table.",
                "you Partying too much with kids wearing weird clothes.",
                "you running away from something really scary",
                "clouds gathering in the sky and an army standing ready for war",
                "dogs running around in a deserted empty city",
                "a lot of cars stuck in a terrible traffic jam",
                "you sitting in the dark typing lots of lines of code on your dirty computer",
                "you yelling at your boss. And oh no! You get fired!",
                "you laughing your lungs out. I've never seen this before." 
            };

            bool end{ false };

            const int  max_length{ 15 };
            char name[max_length]{};

            std::cout << "What's your name dear :" << std::endl;

            std::cin.getline(name, max_length); // Get input with spaces

            while (!end) {
                std::cout << "Oh dear " << name << ", I see ";

                size_t rand_num = static_cast<size_t>((std::rand() % std::size(predictions)));

                std::cout << predictions[rand_num] << std::endl;

                std::cout << "Do you want me to try again ? (Y | N) : ";

                char go_on;
                std::cin >> go_on;

                end = ((go_on == 'Y') || (go_on == 'y')) ? false : true;

            }

            std::cout << "That's all I have for you today dear. Best wishes" << std::endl;
            
            
            int scores[10] {11,12,13,14,15,16,17,18,19,20};
    
            int * p_score { scores};
            return  0;

            //Print the address
            std::cout << "scores : " << scores << std::endl; // Array
            std::cout << "p_score : " << p_score << std::endl;// Pointer
            std::cout << "&scores[0]  : " << &scores[0] << std::endl;
            
            //Print the content at that address
            std::cout << std::endl;
            std::cout << "Printing out data at array address : " << std::endl;
            std::cout << "*scores : " << *scores << std::endl;
            std::cout << "scores[0] : " << scores[0] << std::endl;
            std::cout << "*p_score : " << *p_score << std::endl;
            std::cout << "p_score[0] : " << p_score[0] << std::endl;


            //Differences
            int number {21};
            p_score = &number;
            
            //scores = &number; // The array name is a pointer, but a special pointer that kind of identifies
                            // the entire array. You'll get the error  : incompatible types in assignment
                            // of 'int*' to 'int[10]'
            
            std::cout << "p_score : " << p_score << std::endl;// Pointer	

            //std::size() doesn't work for raw pointers
            std::cout << "size : " << std::size(scores) << std::endl;
            //std::cout << "size : " << std::size(p_score) << std::endl; // Compiler error.

            int arr0[5]{ 1,2,3,4,5 };
            int arr1[5]{ 6,7,8,9,10 };
            int * p_arr1 {arr1};
            int * p_arr0 {arr0};

            //Print arr0
            std::cout << "arr0 : ";
            for (size_t i{}; i < std::size(arr0); ++i) {
                std::cout << p_arr0[i] << " ";
            }
            std::cout << std::endl;

            //Print arr1
            std::cout << "arr1 : ";
            for (size_t i{}; i < std::size(arr1); ++i) {
                std::cout << p_arr1[i] << " ";
            }
            std::cout << std::endl;

            int * temp{nullptr};

            temp = p_arr1;
            p_arr1 = p_arr0;
            p_arr0 = temp;

            //Print arr0
            std::cout << "arr0 : ";
            for (size_t i{}; i < std::size(arr0); ++i) {
                std::cout << p_arr0[i] << " ";
            }
            std::cout << std::endl;

            //Print arr1
            std::cout << "arr1 : ";
            for (size_t i{}; i < std::size(arr1); ++i) {
                std::cout << p_arr1[i] << " ";
            }
            std::cout << std::endl;
            return 0;
        }


        int pt_const(){

            //Pointer to const
            //Pointer pointing to constant data : You can't modify the data through pointer
            
            std::cout << "Pointer is modifiable , pointed to value is constant : " << std::endl;
            int number3 {632}; // Although you can omit the const on number3 here and it is still 
                                    // going to compile, it is advised to be as explicit as possible in
                                    // your code and put the const in front. Make your intents CLEAR.
                                    
            const int* p_number3 {&number3}; // Can't modify number3 through p_number3
            
            std::cout << "p_number3 :" << p_number3 << std::endl;
            std::cout << "*p_number3 : " << *p_number3 << std::endl;
            
            std::cout << std::endl;
            std::cout << "Modifying the value pointed to by p_number3 through the pointer (Compile Error) : " << std::endl;
            //*p_number3 = 444; // Compile error 
                            
            //Although we can't change what's pointed to by p_number3,
            //we can still change where it's pointing

            std::cout << std::endl;
            std::cout << "Changing the address pointed to by p_number3 : " << std::endl;
            int number4 {872};
            p_number3 = &number4;
            
            std::cout << "p_number3 :" << p_number3 << std::endl;
            std::cout << "*p_number3 : " << *p_number3 << std::endl;
            
            std::cout << std::endl;     

            //const keyword applies to the variable name.
            
            std::cout << "const keyword applies to a variable name : " << std::endl;
            
            int protected_var {10}; // Can make it const to protect it if we want.Show this
            
            //p_protected_var is a pointer to const data, we can't
            //modify the data through this pointer : regardless of
            //whether the data itself is declared const or not.
            const int* p_protected_var {&protected_var};
            
            //*p_protected_var = 55;
            protected_var = 66;
            std::cout << "protected_var : " << protected_var << std::endl;
            std::cout << "p_protected_var : " << p_protected_var << std::endl;
            std::cout << "*p_protected_var : " << *p_protected_var << std::endl;
            std::cout << std::endl;

            //You can't set up a modifiable pointer to const data though,
            //You'll get a compiler error :Invalid convertion from 'const type*' to 'type*'.
            const int some_data{55};
            //int * p_some_data {&some_data}; // Compiler error.
            //*p_some_data = 66;
            


            //Both pointer and pointed to value are constant
            
            const int number5 {459};
            const int* const p_number5 {&number5 };
            std::cout << "Pointer is constant, value pointed to is constant : " << std::endl;
            std::cout << "p_number5 :" << p_number5 << std::endl;
            std::cout << "*p_number5 : " << *p_number5 << std::endl;
            
            //Can't modify the pointed to value through the pointer
            std::cout << "Changing value pointed to by p_number5 through the pointer (Compile Error) " << std::endl;
            //*p_number5 = 222; // Error : Trying to assign to read only location
            
            //Can't change where the pointer is pointing to : The pointer is now itself constant
            std::cout << "Changing the pointer p_number5 address itself (Compile Error) "<< std::endl;
            int number6 {333};
            //p_number5 = &number6;  // Error : Trying to assign to read only location
            
            std::cout << std::endl;
            


            //Pointer is constant (can't make it point anywere else)
            //but pointed to value can change
            std::cout << "Pointer is contant, pointed to value can change : " << std::endl;
            int number7 {982};
            
            int * const p_number7 { &number7};
            
            std::cout << "p_number7 :" << p_number7 << std::endl;
            std::cout << "*p_number7 : " << *p_number7 << std::endl;
            std::cout << "Changing value pointed to through p_number7 pointer : " << std::endl;
            
            *p_number7 = 456;
            std::cout << "The value pointed to by p_number7 now is : " << *p_number7 << std::endl;
            
            int number8 {2928};
            std::cout << "Changing the address where p_number7 is pointing (Compile Error)." << std::endl;
            //p_number7 = &number8;

            const  char * const   students [] {
                "Daniel Gray",
                "Tuna Philbe",
                "The Rock",
                "Kumar Singh",
                "Sam Ali",
                "Dave Mahoro"
            };            

            //Print out the students
            std::cout << std::endl;
            std::cout << "Printing out the students : " << std::endl;
            for ( const char * student : students){
                std::cout << student << std::endl;
            }

            // *students[0] = 'K';

            //Can swap for new student though.
            const char * new_student {"Bob the Great"};
            //students[0] = new_student; // Compiler error


            //Print out the students
            std::cout << std::endl;
            std::cout << "Printing out the students : " << std::endl;
            for ( const char * student : students){
                std::cout << student << std::endl;
            }
            return 0;
        }
};


class Show_Case{
    private:
        Show_pointers pt_show;

    public:
        int flag {0};

        int show_menu(){
            std::clog << "--- Testing table: ---" << std::endl;
            std::clog << "- 1 - Pointers" << std::endl;
            std::clog << "- 2 - Array of pointers" << std::endl;
            std::clog << "- 3 - Const and pointers" << std::endl;
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
                pt_show.pt_init();
                
            }
            else if(flag == 2){
                pt_show.pt_array();
            }
            else if (flag == 3){
                pt_show.pt_const();
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