#include <iostream>
#include <string>
#include <iomanip>

class Show_array{
    private:


    public:

        int array_init(){
           //Declare an array of ints
            int scores [10]; // Junk data
            //Read data      
            std:: cout << " scores [1] : " << scores[1] << std::endl;
            //Read with a loop
            for( size_t i {0} ; i < 10 ; ++i){
                std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
            }

            //Declare and initialize at the same time            
            double salaries[5] {12.7, 7.5, 13.2, 8.1, 9.3};            
            for(size_t i{0}; i < 5; ++i){
                std::cout << "salary[" << i << "] : " << salaries[i] << std::endl;
            }
            
            //If you don't initialize all the elements, those you leave out
            //are initialized to 0            
            int families[5] {12, 7, 5};            
            for(size_t i{0}; i < 5; ++i){
                std::cout << "families[" << i << "] : " << families[i] << std::endl;
            }    

            //Omit the size of the array at declaration
            int class_sizes[] {10,12,15,11,18,17,23,56}; 

            // Read only arrays            
            const int birds[] {10,12,15,11,18,17,23,56};             
        
            int count { std::size(scores)}; // std::size( C++17)

            std::cout << "sizeof(scores) : " << sizeof(scores) << std::endl;
            std::cout << "sizeof(scores[0]) : " << sizeof(scores[0]) << std::endl;
            std::cout << "count : " << count << std::endl;
            
           count = sizeof(scores)/sizeof(scores[0]);
            for(size_t i {0} ; i < count ; ++i){
                std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
            }
        
            return 0;
        }

        int array_char(){
            //Declare array
            char message [6]  {"Hello"};
            int data[5] {1,2,3,3,3};
            std::cout << "data : " << data << std::endl;            
            // Will probably print garbage after your char array
            std::cout << "message : " << message << std::endl;

            //Print out the array through looping            
            std::cout << "message : ";
            for( auto c : message){
                std::cout << c ;
            }
            std::cout << std::endl;
        
            //If a character array is null terminated, it's called as C-String            
            char message1 [] {'H','e','l','l','o','\0'};
            std::cout << "message1 : " << message1 << std::endl;
            std::cout << "sizeof(message1) : " << sizeof(message1) << std::endl;

            char message2 [6] {'H','e','l','l','o'};
            std::cout << "message2 : " << message2 << std::endl;
            std::cout << "sizeof(message2) : " << sizeof(message2) << std::endl;

            char message3 [] {'H','e','l','l','o'}; // This is not a c string ,
                                                    //as there is not null character
            std::cout << "message3 : " << message3 << std::endl;
            std::cout << "sizeof(message3) : " << sizeof(message3) << std::endl;
            
            //String literal            
            char message4 [] {"Hello"};
            std::cout << "message4 : " << message4 << std::endl;
            std::cout << "sizeof(message4) : " << sizeof(message4) << std::endl;  

            //Can't safely print out arrays other than those of characters
            int numbers [] {1,2,3,4,5};
            std::cout << "numbers :  " << numbers << std::endl;

            return 0;
        }


        int fortune_teller(){
            int house_block [7] [5] [3] {
                {
                    {1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15} 
                },
                {
                    {16,17,18},{19,20,21},{22,23,24},{25,26,27},{28,29,30}  
                },
                {
                    { 31,32,33},{34,35,36},{37,38,39},{40,41,42},{43,44,45} 
                },
                {
                    {46,47,48},{49,50,51},{52,53,54},{55,56,57},{58,59,60}  
                },
                {
                    {61,62,63},{64,65,66},{67,68,69},{70,71,72},{73,74,75} 
                },
                {
                    {76,77,78},{79,80,81},{82,83,84},{85,86,87},{88,89,90}  
                },
                {
                    {91,92,93},{94,95,96},{97,98,99},{100,101,102},{103,104,105} 
                }
            };


            for(size_t i{0}; i < std::size(house_block) ; ++i){

                for(size_t j{0} ; j < std::size(house_block[i]) ; ++j){

                    for(size_t k{0} ; k < std::size(house_block[i][j]) ; ++k){

                        std::cout << house_block[i][j][k] << "     ";
                    }
                }
            }   

            //srand() has to run once per program run
            std::srand(std::time(0)); // Seed

            char predictions [] [90] {
                "a lot of kinds running in the backyard!",
                "a lot of empty beer bootles on your work table.",
                "you Partying too much with kids wearing weird clothes.",
                "you running away from something really scary",
                "clouds gathering in the sky and an army standing ready for war",
                "dogs running around in a deserted empty city",
                "a lot of cars stuck in a terrible traffic jam",
                "you sitting in the dark typing lots of lines of code on your dirty computer",
                "you yelling at your boss. And oh no! You get fired!",
                "you laughing your lungs out. I've never seen this before.",
                ", huum, I don't see anything",
                "you drinking wine"
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
            return  0;
        }
};


class Show_Case{
    private:
        Show_array array_show;

    public:
        int flag {0};

        int show_menu(){
            std::clog << "--- Testing table: ---" << std::endl;
            std::clog << "- 1 - Array init" << std::endl;
            std::clog << "- 2 - Array of charactors" << std::endl;
            std::clog << "- 3 - Multi dimension array and fortune teller" << std::endl;
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
                array_show.array_init();
                
            }
            else if(flag == 2){
                array_show.array_char();
            }
            else if (flag == 3){
                array_show.fortune_teller();
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