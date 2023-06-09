#include <iostream>



class Show_Converts{
    private:


    public:

        int convt_implicit(){
            double price { 45.6 };
            int units {10};            
            auto total_price = price * units; // units will be implicitly converted to double
            
            std::cout << "Total price : " << total_price << std::endl;
            std::cout << "sizeof total_price : " << sizeof(total_price) << std::endl;
            //Implicit conversions in assignments
            int x;
            double y {45.44};
            x = y; // double to int
            std::cout << "The value of x is : " << x << std::endl; // 45
            std::cout << "sizeof x : " << sizeof(x) << std::endl;// 4

            return 0;
        }

        int convt_explicit(){
            //Implicit cast will add up the doubles,
            //then turn result into int for assignment
            double x { 12.5 };
            double y { 34.6};            
            int sum = x + y;             
            std::cout << "The sum  is : " << sum << std::endl;

            //Explicity cast : cast then sum up
            sum = static_cast<int>(x) + static_cast<int>(y) ;
            std::cout << "The sum  is : " << sum << std::endl;
            //Explicit cast : sum up then cast, same thing as implicit cast
            sum =  static_cast<int> (x + y);
            std::cout << "Sum up then cast, result : " << sum << std::endl;

            //Old style C-cast
            double PI {3.14};            
            int int_pi = (int)(PI);
            //int int_pi = static_cast<int>(PI);
            std::cout << "PI : " << PI << std::endl;
            std::cout << "int_pi : " << int_pi << std::endl;
            return 0;
        }

        int over_underflow(){
            //Overflow 

            unsigned char data {250};

            ++data;
            std::cout << "data : " << static_cast<int>(data) << std::endl;
            ++data;
            std::cout << "data : " << static_cast<int>(data) << std::endl;
            ++data;
            std::cout << "data : " << static_cast<int>(data) << std::endl;
            ++data;
            std::cout << "data : " << static_cast<int>(data) << std::endl;
            ++data; 
            std::cout << "data : " << std::hex <<  static_cast<int>(data) << std::endl; // 255
            ++data;  // Overflow
            std::cout << "data : " << static_cast<int>(data) << std::endl; // 256
            std::cout << std::dec ;

            data = 1;
            --data;
            std::cout << "data : " << static_cast<int>(data) << std::endl;
            --data;
            std::cout << "data : " << static_cast<int>(data) << std::endl;
            return 0;
        }

};


class Show_Case{
    private:
        Show_Converts convt_show;
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
                convt_show.convt_implicit();
            }
            else if(flag == 2){
                convt_show.convt_explicit();
            }
            else if (flag == 3){
                convt_show.over_underflow();
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