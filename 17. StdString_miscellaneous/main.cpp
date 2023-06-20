#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

class Show_string{
    private:


    public:

        int tonum_str(){
            //Number to String : the std::to_string function.            
            float float_var {22.3f};
            double double_var {1.34847e5};
            int int_var {223};

            std::string float_str {std::to_string(float_var)};;
            std::string double_str{std::to_string(double_var)};;
            std::string int_str{std::to_string(int_var)};

            std::cout << "size of float_str : " << float_str.size()<< std::endl;
            std::cout << "float_var : " << float_var << std::endl;
            std::cout << "float_str : " << float_str<< std::endl;

            std::cout << "double_var : " << double_var << std::endl;
            std::cout <<"double_str : " << double_str<< std::endl;

            std::cout << "int_var : " << int_var << std::endl;
            std::cout << "int_str : " << int_str<< std::endl;

            //std::string to number (integral types)
            //int, long , long long
            //std::stoi, std::stol, std::stoll
            std::string number_str{"34.567"};//Could even be negative

            int int_var = std::stoi(number_str);
            std::cout << "int_var : " << int_var << std::endl;
            std::cout << "sizeof(int_var) : " << sizeof(int_var) << std::endl;

            long long_var = std::stol(number_str);
            std::cout << "long_var : " << long_var << std::endl;
            std::cout << "sizeof(long_var) : " << sizeof(long_var) << std::endl;

            long long long_long_var = std::stoll(number_str);
            std::cout << "long_long_var : " << long_long_var << std::endl;
            std::cout << "sizeof(long_long_var) : " << sizeof(long_long_var) << std::endl;

            //unsigned long , unsigned long long
            //std::stoul, std::stoull
            //Underflows when the std::string contains a negative number
            std::string number_str = "34.567";
            //std::string number_str = "-34.567"; // Resulting unsigned long and long long underflow
                            // and become huge numbers of their type
            std::cout << std::endl;
            std::cout << "unsigned long, unsigned long long : " << std::endl;

            unsigned long u_l_var = std::stoul(number_str);
            std::cout << "u_l_var : " << u_l_var << std::endl;
            std::cout << "sizeof(u_l_var) : " << sizeof(u_l_var) << std::endl;

            unsigned long long u_ll_var = std::stoull(number_str);
            std::cout << "u_ll_var : " << u_ll_var << std::endl;
            std::cout << "sizeof(u_ll_var) : " << sizeof(u_ll_var) << std::endl;

            //float, double,long double : 
            //std::stof, std::stod, std::stold
            std::string number_str = "34.567";

            float float_var = std::stof(number_str);
            std::cout << "float_var : " << float_var << std::endl;
            std::cout << "sizeof(float_var) : " << sizeof(float_var) << std::endl;

            double double_var = std::stod(number_str);
            std::cout << "double_var : " << double_var << std::endl;
            std::cout << "sizeof(double_var) : " << sizeof(double_var) << std::endl;

            long double long_double_var = std::stold(number_str);
            std::cout << "long_double_var : " << long_double_var << std::endl;
            std::cout << "sizeof(long_double_var) : " << sizeof(long_double_var) << std::endl;
   
            return 0;
        }
        int str_litral(){
            //The bad way to do things
            std::string todo_list {"\tClean the house\n\tWalk the dog\n\tDo laundry\n\tpick groceries"};
            std::string windows_path {"D:\\sandbox\\testProject\\hello.txt"};
            std::string linux_path {"/home/username/files/hello.txt"};
            std::string hint {" \"\\\\\" escapes a backslash character like \\."};

            std::cout << "todo_list : " << std::endl;
            std::cout << todo_list << std::endl;
            std::cout << "windows_path : " << windows_path << std::endl;
            std::cout << "linux_path : " << linux_path << std::endl;
            std::cout << "hint : " << hint << std::endl;

            //Use raw string literals
            std::string to_do_list {R"(  Clean the house
            Walk the dog
            Do laundry
            Pick groceries)"};

            std::cout << "to_do_list : " << std::endl;
            std::cout << to_do_list << std::endl;

            //Raw string literals with assignments
            std::string to_do_list =   R"(
            Clean the house
            Walk the dog
            Do Laundry
            Pick groceries
            )";

            std::cout << "to_do_list : " << std::endl;
            std::cout << to_do_list << std::endl;

            //Raw string literals with assignments
            const char* c_string {  R"(
            Clean the house
            Walk the dog
            Do Laundry
            Pick groceries
            )"} ;

            std::cout << "to_do_list : " << std::endl;
            std::cout << c_string << std::endl;

            //Fixing other escaped strings
            std::string windows_path1 {R"(D:\sandbox\testProject\hello.txt)"};
            std::string linux_path1 {R"(/home/username/files/hello.txt)"};
            std::string hint1 {R"("\\" escapes a backslash character like \.)"};	

            std::cout << "windows_path1 : " << windows_path1 << std::endl;
            std::cout << "linux_path1 : " << linux_path1 << std::endl;
            std::cout << "hint1 : " << hint1 << std::endl;
            
            //Problematic raw string literals
            std::string sentence {R"--(The message was "(Stay out of this!)")--"};

            std::cout << "sentence : " << sentence << std::endl;

            return 0;
        }
        int ad_str(){
            std::string message {"Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!vvHello world!Hello world!Hello world!Hello world!Hello world!"};
            std::string& message_copy{message};

            char * p1 = message.data();
            char * p2 = message_copy.data();

            std::cout << "&message[0] : " << (void*)p1 << std::endl;
            std::cout << "&message_copy[0] : " << (void*) p2 << std::endl;
            
            //Showing the problem
            std::string string {"Hello"};
            std::string string1 {string}; // Copy
            std::string string2 {string}; // Copy

            std::cout  << "address of string : " <<  &string << std::endl;
            std::cout  << "address of string1 : " <<  &string1 << std::endl;
            std::cout  << "address of string2 : " <<  &string2 << std::endl;

            //Using string_view
            std::string_view sv {"Hellooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"};
            std::string_view sv1 {sv}; // View viewing the hello literal
            std::string_view sv2 {sv1}; // Another view viewing hello 

            std::cout << "Size of string_view : " << sizeof(std::string_view) << std::endl;
            std::cout << "size of sv1 : " << sizeof(sv1) << std::endl;

            std::cout << "sv : " << sv << std::endl;
            std::cout << "sv1 : " << sv1 << std::endl;
            std::cout << "sv2 : " << sv2 << std::endl;

            //Constructing string_view's
            std::string string3 {"Regular std::string"};
            const char * c_string {"Regular C-String"};
            const char char_array[]{"Char array"}; // Null terminated
            char char_array2[]{'H','u','g','e'}; // Non null terminated char array

            std::string_view sv3{"String litteral"};
            std::string_view sv4{string3};
            std::string_view sv5{c_string};
            std::string_view sv6{char_array};
            std::string_view sv7{sv3}; 
            std::string_view sv8{char_array2,std::size(char_array2)};//Non null terminated char array
                                                                //Need to pass in size info
            std::cout << "sv3 : " << sv3 << std::endl;
            std::cout << "sv4 : " << sv4 << std::endl;
            std::cout << "sv5 : " << sv5 << std::endl;
            std::cout << "sv6 : " << sv6 << std::endl;
            std::cout << "sv7 (constructed from other string_view) : " << sv7 << std::endl;
            std::cout << "Non null terminated string with std::string_view : " << sv8 << std::endl;
           
            //Changes to the original string are reflected in the string_view
            char word [] {"Dog"};
            std::string_view sv9{word};

            std::cout << "word : " << sv9 << std::endl;

            std::cout << "Changing data... " << std::endl;
            //Change the data
            word[2] = 't';

            std::cout << "word : " << sv9 << std::endl;

            //Changing the view window : SHRINKING
            const char * c_string1 { "The animals have left the region" };
            std::string_view sv10{c_string1};

            std::cout << "sv10 : " << sv10 << std::endl;

            sv10.remove_prefix(4); // Removes "The"

            //Prints : animals have left the region
            std::cout << "View with removed prefix(4) : " << sv10 << std::endl;

            sv10.remove_suffix(10); // Removes "the region"

            //Prints : animals have left
            std::cout << "View with removed suffix(10) : " << sv10 << std::endl;

            //Changing the view doesn't change the viewed string : 
            std::cout << "Original sv10 viewed string : " << c_string1 << std::endl;

            //String_view shouldn't outlive whatever it is viewing
            std::string_view sv11;

            {
            std::string string4{"Hello there"};
            sv11 = string4;
            std::cout << "INSIDE --- sv11 is viewing : " << sv11 << std::endl;


            //string4 goes out of scope here.
            }
            std::cout << "OUTSIDE --- sv1 is viewing : " << sv11 << std::endl;

            //data
            std::string_view sv13 {"Ticket"};
            std::cout << "sv13 : " << sv13 << std::endl;
            std::cout << "std::strlen(sv13.data()) : " << std::strlen(sv13.data()) << std::endl;

            //Don't use data() on a modified view (through remove_prefix or remove_suffix)
            std::string_view sv14 {"Ticket"};
            sv14.remove_prefix(2);
            sv14.remove_suffix(2);

            //Length info is lost when you modify the view
            std::cout << sv14 << " has " << std::strlen(sv14.data()) << " characters(s)" << std::endl;
            std::cout << "sv14.data() is " << sv14.data() << std::endl;
            std::cout << "sv14 is " << sv14 << std::endl;

            //Don't view non null terminated strings
            char char_array3[] {'H','e','l','l','o'};
            std::string_view sv15 {char_array3,std::size(char_array3)};

            std::cout << sv15 << " has " << std::strlen(sv15.data()) << " characters(s)" << std::endl;
            std::cout <<"sv15.data is  : " <<  sv15.data() << std::endl;
            std::cout << "sv15 is : " << sv15 << std::endl;

            //std::string behaviors
            std::string_view sv16{"There is a huge forest in that area"};

            std::cout << "sv16 is " << sv16.length() << " characters long" << std::endl;
            std::cout << "The front character is : " << sv16.front() << std::endl;
            std::cout << "The back character is : " << sv16.back() << std::endl;
            std::cout << "Substring : " << sv16.substr(0,22) << std::endl;
            return  0;
        }
};


class Show_Case{
    private:
        Show_string str_show;

    public:
        int flag {0};

        int show_menu(){
            std::clog << "--- Testing table: ---" << std::endl;
            std::clog << "- 1 - std string to numbers" << std::endl;
            std::clog << "- 2 - other manipulations" << std::endl;
            std::clog << "- 3 - more methods" << std::endl;
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
                str_show.tonum_str();
                
            }
            else if(flag == 2){
                str_show.str_litral();
            }
            else if (flag == 3){
                str_show.ad_str();
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