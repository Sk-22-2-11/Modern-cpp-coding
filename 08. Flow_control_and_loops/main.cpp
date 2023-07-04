#include <iostream>
#include <string>
#include <iomanip>

class Show_Flow{
    private:
        //const in a class means read-only
        enum Constants{
            Pen = 10  , 
            Marker = 20  ,
            Eraser = 30  ,
            Rectangle = 40  ,
            Circle = 50  ,
            Ellipse = 60  
        };

    public:

        int flow_if(){
            bool red = false;
            bool green {true};
            bool yellow {false};
            bool police_stop{true};            
            /*
            *      If green : go
            *      If red, yellow : stop
            *      If green and police_stop : stop
            * */            
            if(red){
                std::cout << "Stop" << std::endl;
            }
            if(yellow){
                std::cout << "Slow down" << std::endl;
            }
            if(green){
                std::cout << "Go" << std::endl;
            }
            
            int tool {Eraser};

            if (tool == Pen) {
                std::cout << "Active tool is pen" << std::endl;
                //Do the actual painting
            }
            else if (tool == Marker) {
                std::cout << "Active tool is Marker" << std::endl;
            }
            else if (tool == Eraser) {
                std::cout << "Active tool is Eraser" << std::endl;
            }
            else if (tool == Rectangle) {
                std::cout << "Active tool is Rectangle" << std::endl;
            }
            else if (tool == Circle) {
                std::cout << "Active tool is Circle" << std::endl;
            }
            else if (tool == Ellipse) {
                std::cout << "Active tool is Ellipse" << std::endl;
            }

            std::cout << "Moving on" << std::endl;

            return 0;
        }

        int flow_switch(){
            int tool {Eraser};

            switch (tool)
            {
                case Pen : {
                    std::cout << "Active tool is Pen" << std::endl;
                }
                break;

                case Marker : {
                    std::cout << "Active tool is Marker" << std::endl;
                }
                break;


                case Eraser :
                case Rectangle : 
                case Circle : {
                    std::cout << "Drawing Shapes" << std::endl;
                }
                break;

                case Ellipse : {
                    std::cout << "Active tool is Ellipse" << std::endl;
                }
                break;
            
                default: {
                    std::cout << "No match found" << std::endl;
                }
                    break;
            }

            std::cout << "Moving on" << std::endl;

            return 0;

        }

        int flow_special(){
            int max{};
            int a{35};
            int b{200};                      
            /*
            if(a >  b){
                max = a;
            }else{
                max = b;
            }
            */
            max = (a > b)? a : b; // Ternary operator
            constexpr bool condition {false};

            if constexpr (condition){
                std::cout << "Condition is true" << std::endl;
            }else{
                std::cout << "Condition is false" << std::endl;
            }

            bool go {true};

            if(int speed {10};go){
                std::cout << "speed : " << speed << std::endl;
                
                if(speed > 5){
                    std::cout << "Slow down!" << std::endl;
                }else{
                    std::cout << "All good!" << std::endl;
                }
            }else{
                std::cout << "speed : " << speed << std::endl;
                std::cout << "Stop" << std::endl;
            }

            return 0;
        }

};

class Show_Loop{
    private:


    public:

        int for_loop(){
            for (size_t i{0} , x {5}, y{22} ; y > 15 ; ++i , x+=5 , y-=1){
                std::cout << "i: " << i << ", x : " << x << ", y : " << y << std::endl;
            }

            int increment {5};
            int number1 {10};
            int number2 {20};
            int number3 {25};
            int result = (number1 *= ++increment, number2 - (++increment), number3 += ++increment);
            std::cout << "number1 : " << number1 << std::endl; // 60
            std::cout << "number2 : " << number2 << std::endl; // 20
            std::cout << "number3 : " << number3 << std::endl; // 33
            std::cout << "result : " <<  result << std::endl; // 33

            int bag_of_values [] {1,2,3,4,5,6,7,8,9,10}; // This is a collection of integers
            // The variable value will be assigned a value from the values array on each iteration
            /*
            for(size_t i {0} ; i < 10 ; ++i){
                std::cout << "value : " << bag_of_values[i] << std::endl;
            }
            */    
            for (int value : bag_of_values){
                //value holds a copy of the current iteration in the whole bag
                std::cout << " value : " << value << std::endl;
            }


            return 0;
        }

        int while_loop(){
            const size_t COUNT{10};
            size_t i{0}; // Iterator declaration

            while(i < COUNT ){ // Test
            std::cout << i << " : I love C++" << std::endl;

            ++i; // Incrementation 
            }

            i = 0;
            do{
                std::cout << i << " : I love C++" << std::endl;
                ++i; // Incrementation
            }while( i < COUNT);

            std::cout << "Loop done!" << std::endl;

            return 0;

        }

        int complex_loop(){
                        // break and continue : for loops
            const size_t COUNT{20};

            for(size_t i{0} ; i < COUNT ; ++i ){

                if(i==5)
                    continue;

                if(i == 11)
                    break; // Breaks out of the loop
                std::cout << "i : " << i << std::endl;
            }
            std::cout << "Loop done!" << std::endl;

            for(double multiplier{4}; auto i : {1,2,3,4,5,6,7,8,9,10}){
                std::cout << "result : " << ( i * multiplier) << std::endl;
            }

            //Setw on numbers before you print them
            const size_t ROWS {12}; 
            const size_t COLS {3};            
            std::cout << "Tabular data visualization with nested for loops : " << std::endl;
                        
            for (size_t row{0} ; row < ROWS ; ++ row){
                
                for (size_t col{0} ; col < COLS ; ++col){

                    std::cout  << "( row "  <<  std::setw(2) << row << ",col " << std::setw(2) <<  col << ")  ";
                }
                std::cout << std::endl;
            }
            
            return 0;
        }

};

class Show_Case{
    private:
        Show_Flow flow_show;
        Show_Loop loop_show;

    public:
        int flag {0};

        int show_menu(){
            std::clog << "--- Testing table: ---" << std::endl;
            std::clog << "- 1 - Flow control" << std::endl;
            std::clog << "- 2 - Flow with initializers" << std::endl;
            std::clog << "- 3 - Loops" << std::endl;
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
                flow_show.flow_if();
                flow_show.flow_switch();
            }
            else if(flag == 2){
                flow_show.flow_special();
            }
            else if (flag == 3){
                loop_show.for_loop();
                loop_show.while_loop();
                loop_show.complex_loop();
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