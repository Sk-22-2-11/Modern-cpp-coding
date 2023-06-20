#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

class Show_string{
    private:


    public:

        int comp_str(){
            //Compare (1)
            //int compare( const basic_string& str ) const noexcept;(1)
            //Compares this string to str.
            
            std::string str1{"Hello"};
            std::string str2{"World"};

            std::cout << "str1 : " << str1 << std::endl;
            std::cout << "str2 : " << str2 << std::endl;
            std::cout << "str1.compare(str2) : " << str1.compare(str2) << std::endl; // negative
            std::cout << "str2.compare(str1) : " << str2.compare(str1) << std::endl; // positive
            

            //Compare (2)
            //int compare( size_type pos1, size_type count1,const basic_string& str ) const; (2)
            //Compares a  substring  of this string(from pos1, going count1 positions) to str
            
            std::string str3 = "Hello";
            std::string str4{"Hello World"};
            std::cout << "Comparing 'World' to 'Hello' : " << str4.compare(6,5,str3) << std::endl;//1
            

            //Compare (3)
            //int compare( const CharT* s ) const;(4)
            //Compares this string to the null-terminated character sequence beginning 
            //at the character pointed to by s.
            std::string str5{"Hello"};
            const char* message {"World"};
            std::cout << "Comparing Hello to World : " << str5.compare(message) << std::endl;//-1
            std::cout << "Comparing Hello to World : " << str5.compare("World") << std::endl; //-1
                   
            return 0;
        }

        int man_str(){           
            //Replacing (1)
            //basic_string& replace( size_type pos, size_type count,const basic_string& str );
            //Replace the range [pos, pos + count] with str            
            std::string str1 {"Finding Nemo"}; // Replace Finding with 'Searching For'
            std::string str1_2 {"Searcing For"};
            std::cout << "str1 : " << str1 << std::endl;
            std::cout << "Replacing..." << std::endl;
            str1.replace(0,7,str1_2);
            std::cout << "str1 : " << str1 << std::endl;
            
            //Replacing - (2)
            //basic_string& replace( size_type pos, size_type count,
                        //const basic_string& str,
                        //size_type pos2, size_type count2 = npos );                               
            //Replace in part of str, not its entirety
            std::string str2 {"Finding Nemo"};
            std::string str3 {"The Horse was Found in the Fields Searching For Food"};
            std::cout << "str2 : " << str2 << std::endl;
            std::cout << "Replacing..." << std::endl;
            str2.replace(0,7,str3,34,13);
            std::cout << "str2 : " << str2 << std::endl;            

            //Copying
            //size_type copy( CharT* dest,size_type count,size_type pos = 0)
            //Copy a subsection of *this string to dest. Dest is pre-allocated
            // The resulting character string is not null-terminated. Be careful            
            std::string str4{"Climbing Kirimanjaro"};
            char txt4[15] {}; //Initialized with zero equivalent for characters which is '\0'
            std::cout << "std::size(txt4) : " << std::size(txt4) << std::endl;
            std::cout << "txt4 : " << txt4 << std::endl;
            std::cout << "Copying..." << std::endl;
            str4.copy(txt4,11,9);
            //Safe to print because the char array was initialized with '\0' s.
            std::cout << "txt4 : " << txt4 << std::endl;   

            //Resizing
            //std::resize(            
            std::string str5{"Hello"};

            std::cout << "null char : " << '\0' << std::endl;
            std::cout << "str5 : " << str5 << std::endl;
            std::cout << "str5.size() : " << str5.size() << std::endl;
            std::cout << "str5.capacity() : " << str5.capacity() << std::endl;

            std::cout << "Resizing..." << std::endl;
            str5.resize(8); // This fills new char place holders with
                        //null character by default, you can't print and see them

            std::cout << "str5 : " << str5 << std::endl;
            std::cout << "str5.size() : " << str5.size() << std::endl;
            std::cout << "str5.capacity() : " << str5.capacity() << std::endl;

            //Prove that they are indeed null characters
            std::cout << "Printing through loop : " << std::endl;
            for(size_t i{} ; i < str5.size() ; ++i){
            std::cout << i << ":" << str5[i] << std::endl;
            }

            //Resize and specify autofill character
            std::cout << "Resize and specify autofill character : " << std::endl;
            str5.resize(10,'*');
            std::cout << "str5 : " << str5 << std::endl;
            std::cout << "str5.size() : " << str5.size() << std::endl;
            std::cout << "str5.capacity() : " << str5.capacity() << std::endl;

            //Resize down
            std::cout << "Resize down : " << std::endl;
            str5.resize(5);
            std::cout << "str5 : " << str5 << std::endl;
            std::cout << "str5.size() : " << str5.size() << std::endl;
            std::cout << "str5.capacity() : " << str5.capacity() << std::endl;  

            //Swapping
            std::string str_a{"This is a string stored in A"};
            std::string str_b{"This is a string stored in B and it's really great to be able to do that."};

            //Before swap
            std::cout << "str_a : " << str_a << std::endl;
            std::cout << "str_b : " << str_b << std::endl;
            std::cout << "str_a.size() :" << str_a.size() << std::endl;
            std::cout << "str_a.capaity() : " << str_a.capacity() << std::endl;
            std::cout << "str_b.size() :" << str_b.size() << std::endl;
            std::cout << "str_b.capaity() : " << str_b.capacity() << std::endl;

            std::cout << "Swapping..." << std::endl;
            str_a.swap(str_b);

            //After swap
            std::cout << "str_a : " << str_a << std::endl;
            std::cout << "str_b : " << str_b << std::endl;
            std::cout << "str_a.size() :" << str_a.size() << std::endl;
            std::cout << "str_a.capaity() : " << str_a.capacity() << std::endl;
            std::cout << "str_b.size() :" << str_b.size() << std::endl;
            std::cout << "str_b.capaity() : " << str_b.capacity() << std::endl;
   
            return 0;
        }

        int ad_str(){
            //Find(1)
            //std::string::find()
            //size_type find( const basic_string& str, size_type pos = 0 ) const
            //Finds the starting index where the str substring is found in
            //the string where we call the method.            
            std::string string1{"Water was poured in the heater"};
            std::string search_for{"ter"};

            size_t found_pos = string1.find(search_for);
            std::cout << "find('ter') : index [" << found_pos << "]" << std::endl;// index : 2

            //find red
            search_for = "red";
            found_pos = string1.find(search_for);
            std::cout << "find('red') : index [" << found_pos << "]" << std::endl;// 13

            //Find something that isn't there
            search_for = "chicken";
            found_pos = string1.find(search_for);
            std::cout << "find('chicken') : index ["<< found_pos << "]" << std::endl;//huge number

            //std::string::npos
            std::cout << "npos : " << std::string::npos << std::endl;

            size_t large = -1;
            std::cout << "large : " << large << std::endl;   

            //Using std::string::npos to check if search was successfull or failed            
            std::string string1{"Water was poured in the heater"};
            std::string search_for{"red"};

            size_t found_pos = string1. find(search_for);
            if(found_pos == std::string::npos){
            std::cout << "Could not find the string 'red' : " << std::endl;
            }else{
            std::cout << "'red' found starting at position : " << found_pos << std::endl;
            }
            //Search for chicken and check result against std::string::npos
            search_for = "chicken";
            found_pos = string1.find(search_for);

            if(found_pos == std::string::npos){
            std::cout << "Could not find the string 'chicken'. " << std::endl;
            }else{
            std::cout << "'chicken' found starting at position : " << found_pos << std::endl;
            }
            
            //Find(2)	
            //Can specify the position where we want the search to start
            //using the second parameter of the method            
            std::string string1{"Water was poured in the heater"};
            std::string search_for{"ter"};

            size_t found_pos = string1.find(search_for); 
            std::cout << "ter found at position : " << found_pos << std::endl;

            found_pos = string1.find(search_for,0);
            std::cout << "ter found at position : " << found_pos << std::endl;

            found_pos = string1.find(search_for,10);
            std::cout << "ter found at position : " << found_pos << std::endl;
            
            //Find(3)
            //size_type find( const CharT* s, size_type pos = 0 ) const;
            //Finds the first substring equal to the character string pointed to by s
            //pos : the position where we start searching in the std::string
            std::string string2 = "beer is packaged by her in beer cans around here.";
            const char * c_string2{"her"};

            size_t found_pos = string2.find(c_string2,2);
            if( found_pos!= std::string::npos){
            std::cout <<c_string2 <<  " found at position : " << found_pos << std::endl;
            }else{
            std::cout << "Could not find the string :  " << (c_string2) <<  std::endl;
            }

            std::string message {"Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!Hello world!vvHello world!Hello world!Hello world!Hello world!Hello world!"};
            std::string& message_copy{message};

            char * p1 = message.data();
            char * p2 = message_copy.data();

            std::cout << "&message[0] : " << (void*)p1 << std::endl;
            std::cout << "&message_copy[0] : " << (void*) p2 << std::endl;
            
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
            std::clog << "- 1 - std string compare" << std::endl;
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
                str_show.comp_str();
                
            }
            else if(flag == 2){
                str_show.man_str();
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