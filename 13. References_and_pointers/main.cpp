#include <iostream>
#include <string>
#include <iomanip>

class Show_ref{
    private:


    public:

        int ini_ref(){
            int int_data{33};
            double double_data{55};

            //References
            int& ref_int_data{int_data};
            double& ref_double_data{double_data};

            //Print stuff out
            std::cout << "int_data : " << int_data << std::endl;
            std::cout << "&int_data : " << &int_data << std::endl;
            std::cout << "double_data : " << double_data << std::endl;
            std::cout << "&double_data : " << &double_data << std::endl;
            std::cout << "=======================" << std::endl;
            std::cout << "ref_int_data : " << ref_int_data << std::endl;
            std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
            std::cout << "ref_double_data : " << ref_double_data << std::endl;
            std::cout << "&ref_double_data : " << &ref_double_data << std::endl;

            int_data = 111;
            double_data = 67.2;
            //Print stuff out
            std::cout << std::endl;
            std::cout << "int_data : " << int_data << std::endl;
            std::cout << "&int_data : " << &int_data << std::endl;
            std::cout << "double_data : " << double_data << std::endl;
            std::cout << "&double_data : " << &double_data << std::endl;
            std::cout << "=======================" << std::endl;
            std::cout << "ref_int_data : " << ref_int_data << std::endl;
            std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
            std::cout << "ref_double_data : " << ref_double_data << std::endl;
            std::cout << "&ref_double_data : " << &ref_double_data << std::endl;

            return 0;
        }

        int const_ref(){           
            //Declare pointer and reference
            double double_value {12.34};
            double& ref_double_value {double_value}; // Reference to double_value
            double* p_double_value {&double_value}; //Pointer to double_value
            
            //Reading
            std::cout << "double_value : " << double_value << std::endl;
            std::cout << "ref_double_value : " << ref_double_value << std::endl;
            std::cout << "p_double_value : " << p_double_value << std::endl;
            std::cout << "*p_double_value : " << *p_double_value << std::endl;
            
            //Writting through pointer
            *p_double_value = 15.44;            
            std::cout << std::endl;
            std::cout << "double_value : " << double_value << std::endl;
            std::cout << "ref_double_value : " << ref_double_value << std::endl;
            std::cout << "p_double_value : " << p_double_value << std::endl;
            std::cout << "*p_double_value : " << *p_double_value << std::endl;
            
            //Writting through reference
            ref_double_value = 18.44;            
            std::cout << std::endl;
            std::cout << "double_value : " << double_value << std::endl;
            std::cout << "ref_double_value : " << ref_double_value << std::endl;
            std::cout << "p_double_value : " << p_double_value << std::endl;
            std::cout << "*p_double_value : " << *p_double_value << std::endl;

            double some_other_double{78.45};

            //Make the reference reference something else.
            ref_double_value = some_other_double;
            std::cout << "Making the reference reference something else..." << std::endl;
            std::cout << std::endl;
            std::cout << "double_value : " << double_value << std::endl;
            std::cout << "ref_double_value : " << ref_double_value << std::endl;
            std::cout << "p_double_value : " << p_double_value << std::endl;
            std::cout << "*p_double_value : " << *p_double_value << std::endl;

            //Make the pointer point to something else
            p_double_value = &some_other_double;
            std::cout << "Making the pointer point somewhere else..." << std::endl;
            std::cout << std::endl;
            std::cout << "double_value : " << double_value << std::endl;
            std::cout << "ref_double_value : " << ref_double_value << std::endl;
            std::cout << "&double_value : " << &double_value << std::endl;
            std::cout << "&ref_double_value : " << &ref_double_value << std::endl;
            std::cout << "p_double_value : " << p_double_value << std::endl;
            std::cout << "*p_double_value : " << *p_double_value << std::endl;

            //Non const reference
            std::cout << std::endl;
            std::cout << "Non const reference : " << std::endl;
            int age {27};
            const int& ref_age{age};
            /*
            std::cout << "age : " << age << std::endl;
            std::cout << "ref_age : " << ref_age << std::endl;            
            
            //Can modify original variable through reference
            std::cout << std::endl;
            std::cout << "Modify original variable through reference : " << std::endl;
            
            ref_age++; //Mofify through reference            
            std::cout << "age : " << age << std::endl;
            std::cout << "ref_age : " << ref_age << std::endl;
            */

            return 0;
        }

        int loop_ref(){
            int scores[] {1,2,3,4,5,6,7,8,9,10};
    
            //Printing positions
            std::cout << std::endl;
            
            std::cout << "Scores : ";
            for ( auto score : scores){
                std::cout << " " << score ;
            }
            std::cout << std::endl;

            for ( auto& score : scores){
                score = score * 10;
            }

            //Printing after change
            std::cout << std::endl;
            std::cout << "Scores : ";
            for ( auto score : scores){
                std::cout << " " << score ;
            }
            std::cout << std::endl;
            return  0;
        }
};


class Show_Case{
    private:
        Show_ref ref_show;

    public:
        int flag {0};

        int show_menu(){
            std::clog << "--- Testing table: ---" << std::endl;
            std::clog << "- 1 - References initiation" << std::endl;
            std::clog << "- 2 - References and pointer and const" << std::endl;
            std::clog << "- 3 - References and loops" << std::endl;
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
                ref_show.ini_ref();
                
            }
            else if(flag == 2){
                ref_show.const_ref();
            }
            else if (flag == 3){
                ref_show.loop_ref();
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