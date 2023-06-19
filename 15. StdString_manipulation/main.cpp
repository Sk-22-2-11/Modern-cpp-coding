#include <iostream>
#include <string>
#include <iomanip>

class Show_stdstr{
    private:


    public:

        int init_stdstr(){
            std::string full_name;//Empty string
            std::string planet {"Earth. Where the sky is blue"};//Initialize with string literal
            std::string prefered_planet{planet};//Initialize with other existing string
            std::string message {"Hello there",5};	//Initialize with part of a string literal.
                                        //Contains hello
            std::string weird_message(4,'e');//Initialize with multiple copies of a char
                                    // contains eeee
            std::string greeting{"Hello World"};
            std::string saying_hello{ greeting,6,5};//Initialize with part of an existing std::string
                                        // starting at index 6, taking 5 characters.
                                        //Will contain World.

            std::cout << "full_name : " << full_name << std::endl;
            std::cout << "planet : " << planet << std::endl;
            std::cout << "prefered_planet : " << prefered_planet << std::endl;
            std::cout << "message : " << message << std::endl;
            std::cout << "weird_message : " << weird_message << std::endl;
            std::cout << "greeting : " << greeting << std::endl;
            std::cout << "saying_hello : " << saying_hello << std::endl;

            //Changing std::string at runtime
            planet = "Earth. Where the sky is blue Earth. Where the sky is blue Earth. Where ";
            std::cout << "planet : " << planet << std::endl;

            //Concatenating two strings : The + operator            
            std::cout << std::endl;
            std::cout << "Concatenating two strings : " << std::endl;

            std::string str1{"Hello"};
            std::string str2{"World"};

            message = str1 + " my " + str2;
                
            std::cout << "message : " << message << std::endl; 
        
            //A few ways around string literal concatenation
            
            std::cout << std::endl;
            std::cout << "A few ways around string literal concatenation" << std::endl;
                    
            std::string str5 {"Hello World"}; 	// Make the string one literal
                                                //in the first place
            std::string str6 {"Hello" " World"};// Put the literals side by side
                                                //without the + in between
            std::string str7{std::string{"Hello"} + " World"};//Turn one or both into a std::string
                                                            //object  and do the concatenation
            std::cout << "str5 : " << str5 << std::endl;
            std::cout << "str6 : " << str6 << std::endl;
            std::cout << "str7 : " << str7 << std::endl;
                                                                                                        
            //A better way to not polute the namespace
            std::string str9;
            {
                using namespace std::string_literals;
                str9 = "Hello"s + " World";
            }
            std::cout << "str9 : " << str9 << std::endl;          

            //std::string is a compound type, it has properties and behaviors
            //one of the behaviors is append. We access the behaviors using
            //the . operator after the std::string variable name            
            std::cout << std::endl;
            std::cout << "Using the append method : " << std::endl;
            std::string str10 {"Hello"};
            std::string str11 {" World"};
            std::string str12 = str10.append(str11);
            std::cout << "str12 : " << str12 << std::endl;
                
            std::string str13{std::string{"Hello"}.append(" World")};
            std::cout << "str13 : " << str13 << std::endl;   

            //Append can do more than the + operator
            //The + operator is just a convenience for basic concatenation            
            std::cout << std::endl;
            std::cout << "Append method can do more than + operator : " << std::endl;
            std::string str14 {"Hello "};
            std::string str15 {str14.append(5,'?')}; // Appends 5 '?' characters
            std::cout << "str15 : " << str15 << std::endl;
                
                
            std::string str16{"The world is our shared home."};
            std::string str17{"Hello "};
            std::string str18{str17.append(str16,4,5)};// Append a sub-section of another string
                                                        // starting from index 4 , 5 characters
            std::cout << "str18 : " << str18 << std::endl;
            
            //Direct output
            std::string str19{"Hello "};
            std::cout << "Direct output : " << str19.append(str16,4,5) << std::endl;
            
            //Appending C-strings and char arrays
            
            std::cout << std::endl;
            std::cout << "Appending C-Strings and char arrays : "<<std::endl;
            const char message1[] {"World"};
            const char * message2 {"World"};
                
            std::cout <<" + char array : "  <<  std::string{"Hello "} + message1 << std::endl;
            std::cout <<" + C-String : "  <<  std::string{"Hello "} + message2 << std::endl;
            std::cout <<"append char array : "  <<  std::string{"Hello "}.append(message1) << std::endl;
            std::cout <<"append C-String : "  <<  std::string{"Hello "}.append( message2)<< std::endl;

            return 0;
        }

        int basic_stdstr(){                
            std::string str1 {"Hello World"};
            std::string str2;
            std::string str3{};            
            //Empty
            std::cout << std::endl;
            std::cout << "std::string::empty() : " << std::endl;
            std::cout << "str1 is empty : " << std::boolalpha << str1.empty() << std::endl;
            std::cout << "str2 is empty : " << std::boolalpha << str2.empty() << std::endl;
            std::cout << "str3 is empty : " << std::boolalpha << str3.empty() << std::endl;
            //Size
            std::cout << std::endl;
            std::cout << "std::string::size() : " << std::endl;
            std::cout << "str1 contains " << str1.size() << " characters" << std::endl; //11
            std::cout << "str2 contains " << str2.size() << " characters" << std::endl; // 0
            std::cout << "str3 contains " << str3.size() << " characters" << std::endl; // 0
            //Length
            std::cout << std::endl;
            std::cout << "std::string::length() : " << std::endl;
            std::cout << "str1 contains " << str1.length() << " characters" << std::endl; //11
            std::cout << "str2 contains " << str2.length() << " characters" << std::endl; // 0
            std::cout << "str3 contains " << str3.length() << " characters" << std::endl; // 0 
            //max_size : max number of characters a string can have on the system
            //Prints : 2147483647 on my system
            str1 ="Hello World";
            std::cout << "std::string can hold " << str1.max_size() << " characters" << std::endl;
            //Capacity       
            std::cout << "str1 capacity : " << str1.capacity() << std::endl;
            std::cout << "str2 capacity : " << str2.capacity() << std::endl;            
            str1 = "The sky is so blue, the grass is green. Kids are running all over the place";
            std::cout << "str1 size : " << str1.size() << std::endl;
            std::cout << "str1 capacity : " << str1.capacity() << std::endl;            

            //Reserve : Update the capacity      
            std::cout << "str1 capacity : " << str1.capacity() << std::endl; // 15
            std::cout << "str1 size : " << str1.size() << std::endl;

            str1.reserve(100);
            
            std::cout << "str1 after reserve : " << str1 << std::endl; 
            std::cout << "str1 capacity : " << str1.capacity() << std::endl; // 100
            std::cout << "str1 size : " << str1.size() << std::endl;   

            //shrink_to_fit
            str1.reserve(100);

            std::cout << "str1 capacity : " << str1.capacity() << std::endl; //100
            std::cout << "str1 size : " << str1.size() << std::endl; // 11

            str1.shrink_to_fit();
        
            std::cout << "str1 capacity : " << str1.capacity() << std::endl; //11
            std::cout << "str1 size : " << str1.size() << std::endl;//11
            
            //Size of a string : doesn't count the null terminator
            std::cout << "str1.size() : " << str1.size() << std::endl;
            
            //Reading characters in std::string : array index operator
            //Regular indexed loop. Can also be adapted to use while and do-while
            //This is left as an exercise.
            std::cout << std::endl;
            std::cout << "For loop with array index notation : "<< std::endl;
            
            std::cout << "str1(for loop) : " ;
            for(size_t i{}; i < str1.size(); ++i){
                std::cout << " " << str1[i] ;
            }
            std::cout << std::endl;
            
            //at() syntax to target characters     
            std::cout << std::endl;
            std::cout << "Using the std::string::at() method : "<< std::endl;

            std::cout << "str1 : (for loop with at()) : " ;

            for(size_t i{}; i < str1.size(); ++i){
                std::cout << " " << str1.at(i) ;
            }
            std::cout << std::endl;
            
            //Modifying with operator[] and at()
            str1[0] = 'B';
            str1.at(1) = 'a';
            std::cout << "str1(modified) : " << str1 << std::endl;            

            //Getting the front and back characters  
            char& front_char = str2.front();
            char& back_char = str2.back();
            std::cout << "The front char in str2 is : " << front_char << std::endl;
            std::cout << "The back char in str2 is : " << back_char << std::endl;

            front_char = 'r';
            back_char = 'd';

            std::cout << "str2 : " << str2 << std::endl;

            return  0;
        }
        int modi_stdstr(){                
            //Clear : Removes all characters from the string.
            std::string str1 {"The Lion Dad"};
            
            std::cout << "str1 is : " << str1 << std::endl;
            std::cout << "str1 size : " << str1.size() << std::endl;
            std::cout << "str1 capacity : " << str1.capacity() << std::endl;
            
            str1.clear();

            std::cout << std::endl;
            std::cout << "str1 is : " << str1 << std::endl;
            std::cout << "str1 size : " << str1.size() << std::endl;
            std::cout << "str1 capacity : " << str1.capacity() << std::endl;

            //Insert (1)
            //(1)basic_string& insert( size_type index, size_type count, CharT ch );
            //Inserts count characters in the string starting at index index
            
            std::string str2 {"122"};
            std::cout << "str2 : " << str2 << std::endl;
            
            str2.insert(1,4,'3');//Count can be 1,2,5,..
            
            std::cout << std::endl;
            std::cout << "str2 : " << str2 << std::endl;//1322

            //Insert (2)
            //(2)basic_string& insert( size_type index, const CharT* s );
            //Inserts null-terminated character string pointed to by s
            //at the position index. The length of the string is determined 
            //by the first null character.
            std::string str3 {"Hello!"};
            const char * txt3{" World"};
            
            std::cout << "str3 : " << str3 << std::endl;//Hello
            
            str3.insert(5,txt3);
            
            std::cout << std::endl;
            std::cout << "str3 : " << str3 << std::endl;//Hello World!

            //Insert (3)
            //(3)basic_string& insert( size_type index, const CharT* s, size_type count );
            //Inserts the characters in the range [s, s+count) at the position index.
            //The range can contain null characters.
            std::string str4{"Hello!"};
            const char * txt4{" World Health Organization"};
            
            std::cout << "str4 : " << str4 << std::endl;

            str4.insert(5,txt4,6);
            
            std::cout << std::endl;
            std::cout << "str4 : " << str4 << std::endl;

            //Insert (4)
            //(4)basic_string& insert( size_type index, const basic_string& str );
            //Inserts string str at the position index
            std::string str5{" World"};
            std::string str6{"Hello!"};
            
            std::cout << "str6 : " << str6 << std::endl;

            str6.insert(5,str5);
            
            std::cout << std::endl;
            std::cout << "str6 : " << str6 << std::endl;

            //Insert (5)
            //(5)basic_string& insert( size_type index, const basic_string& str,
            //                  size_type index_str, size_type count = npos);
            //Inserts a string, obtained by str.substr(index_str, count) at the position index
            std::string str7{"Hello!"};
            std::string str8{"Statistical Analysis of the World Population."};
            
            std::cout << "str7 : " << str7 << std::endl;

            str7.insert(5,str8,27,6);
            
            std::cout << std::endl;
            std::cout << "str7 : " << str7 << std::endl;

            //Erase
            //basic_string& erase( size_type index = 0, size_type count = npos );
            //Starting at index index, erase count characters from the string
            //Notice that this function returns a referennce
            std::string str9 {"Hello World is a message used to start off things when learning programming!"};;
            
            str9.erase(11,str9.size() - 12);
            std::cout << "str9 : " << str9 << std::endl;
            
            //Reset str9.
            str9 = "Hello World is a message used to start off things when learning programming!";
            
            //Direct print out.Because this method returns a reference to the modified string
            std::cout << "str9 : " << str9.erase(11,str9.size() - 12) << std::endl;

            //push_back
            //void push_back( CharT ch );
            //Appends the given character ch to the end of the string. 
            std::string str10 {"Hello World"};
            str10.push_back('!');
            std::cout << "str10 : " << str10 << std::endl;

            //pop_back
            //void pop_back();
            //Removes the last character from the string. 
            std::string str11 {"Hello World!!"};
            str11.pop_back();
            std::cout << "str11 : " << str11 << std::endl;

            return  0;
        }
};


class Show_Case{
    private:
        Show_stdstr str_show;

    public:
        int flag {0};

        int show_menu(){
            std::clog << "--- Testing table: ---" << std::endl;
            std::clog << "- 1 - Danling pointers" << std::endl;
            std::clog << "- 2 - Dynamic allocate" << std::endl;
            std::clog << "- 3 - Memory leak" << std::endl;
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
                str_show.init_stdstr();
                
            }
            else if(flag == 2){
                str_show.basic_stdstr();
            }
            else if (flag == 3){
                str_show.modi_stdstr();
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