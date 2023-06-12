#include <iostream>
#include <string>
#include <iomanip>

class Show_pt{
    private:


    public:

        int pt_navgt(){
            //Increment/ decrement pointer addresses manually            
            int scores[10] {11,12,13,14,15,16,17,18,19,20};            
            
            int * p_score { scores};//scores++;
            
            std::cout << "Values in scores array (p_score pointer increment) : " << std::endl;
            std::cout << "Address : " << p_score << " value : " <<  *(p_score) << std::endl;
            ++p_score; // Moves froward by sizeof(int) : 4 bytes
            std::cout << "Address : " << p_score << " value : " <<  *(p_score) << std::endl;
            ++p_score; // Moves froward by sizeof(int) : 4 bytes

            std::cout << std::endl;
            std::cout << "Explicit addition of integer : " << std::endl;
            p_score = scores; // Reset the pointer to the start of the array
            std::cout << "scores[4] : " << *(p_score + 4) << std::endl; // Moves forward by 4 * sizeof(int)

            //Can also do arithmetic on the array name
            //just like any pointer.
            std::cout << std::endl;
            std::cout << "Pointer arithmetic on array name: " << std::endl;
            for ( size_t i{0} ; i < std::size(scores) ; ++i){
                std::cout <<"Value : "<< *(scores + i) << std::endl;
            }
        
            //Print in reverse order with -- operator on p_score            
            std::cout<< std::endl;
            std::cout << "Elements in reverse order -- arithmetic on the p_scores pointer: " << std::endl;
            p_score = scores + std::size(scores) -1;
            for ( size_t i{std::size(scores)} ; i > 0 ; --i){
                std::cout <<"Value : "<< *(p_score--) << std::endl;		// Here we do the -1 thing, because
                                                                        //scores is already pointing to the first
                                                                        //element in the array.
            }
            
            // Can Print the elements in reverse order with array index            
            std::cout<< std::endl;
            std::cout << "Elements in reverse order with array index notation: " << std::endl;
            for ( size_t i{std::size(scores)} ; i > 0 ; --i){
                std::cout <<"Value : "<< scores [ i -1] << std::endl;
            }
            
            p_score = scores;
            
            scores[0] = 31; // Array index notation
            *(scores + 1) = 32; // Equivalent to scores[1] = 32 . Pointer arithmetic on array name
            *(p_score + 2) = 33; // Equivalent to scores[2] = 33 . Pointer arithmetic on p_score pointer
            
            std::cout << std::endl;
            std::cout << "Printing out the array after modification of 3 first elements: " << std::endl;
            for ( size_t i{0} ; i < std::size(scores) ; ++i){
                std::cout <<"Value : "<< scores[i] << std::endl;
            }
    
            //Array index notation
            //    int * pointer1 {&scores[0]};
            //    int * pointer2 {&scores[8]};
            //Pointer arithmetic notation
            int * pointer1 {scores + 0};
            int * pointer2 {scores + 8};
            
            std::cout << "pointer2 - pointer1 : " << pointer2 - pointer1 << std::endl; // 8 
            std::cout << "pointer1 - pointer2 : " << pointer1 - pointer2 << std::endl; // -8

            std::ptrdiff_t pos_diff = pointer2 - pointer1;
            std::ptrdiff_t neg_diff = pointer1 - pointer2;
            std::cout << "pointer2 - pointer1 : " << pos_diff << std::endl; // 8 
            std::cout << "pointer1 - pointer2 : " << neg_diff << std::endl; // -8
            std::cout << "sizeof(std::ptrdiff_t) : " << sizeof(std::ptrdiff_t) << std::endl;

            return 0;
        }

        int pt_compare(){
            int scores[10] {11,12,13,14,15,16,17,18,19,20};
            
            int * pointer1 {&scores[0]};
            int * pointer2 {&scores[8]};
            
            //Can also compare pointers
            
            //The further you go in the array, the bigger the address
            
            std::cout << "Comparing pointers : " <<std::boolalpha <<  std::endl;
            
            std::cout << "pointer1 > pointer2 : " <<  (pointer1 > pointer2) << std::endl;
            std::cout << "pointer1 < pointer2 : " << (pointer1 < pointer2) << std::endl;
            std::cout << "pointer1 >= pointer2 : " <<  (pointer1 >= pointer2) << std::endl;
            std::cout << "pointer1 <= pointer2: " << (pointer1 <= pointer2) << std::endl;
            std::cout << "pointer1 == pointer2 : " <<  (pointer1 == pointer2) << std::endl;
            std::cout << "pointer1 != pointer2 : " << (pointer1 != pointer2) << std::endl;           

            return 0;
        }


        int pt_swap_array(){
            int arr0[5]{ 1,2,3,4,5 };
            int arr1[5]{ 6,7,8,9,10 };

            int * p_arr1 {arr1};
            int * p_arr0 {arr0};

            //Print arr0
            std::cout << "arr0 : ";
            for (size_t i{}; i < std::size(arr0); ++i) {
                std::cout << *(p_arr0 + i) << " ";
            }
            std::cout << std::endl;

            //Print arr1
            std::cout << "arr1 : ";
            for (size_t i{}; i < std::size(arr1); ++i) {
                std::cout << *(p_arr0 + i) << " ";
            }
            std::cout << std::endl;

            int * temp{nullptr};

            temp = p_arr1;
            p_arr1 = p_arr0;
            p_arr0 = temp;

            //Print arr0
            std::cout << "arr0 : ";
            for (size_t i{}; i < std::size(arr0); ++i) {
                std::cout << *(p_arr0 + i) << " ";
            }
            std::cout << std::endl;

            //Print arr1
            std::cout << "arr1 : ";
            for (size_t i{}; i < std::size(arr1); ++i) {
                std::cout << *(p_arr1 + i) << " ";
            }
            std::cout << std::endl;
            return  0;
        }
};


class Show_Case{
    private:
        Show_pt pt_show;

    public:
        int flag {0};

        int show_menu(){
            std::clog << "--- Testing table: ---" << std::endl;
            std::clog << "- 1 - Pointer navigation" << std::endl;
            std::clog << "- 2 - Compare pointers" << std::endl;
            std::clog << "- 3 - Swap an array" << std::endl;
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
                pt_show.pt_navgt();
                
            }
            else if(flag == 2){
                pt_show.pt_compare();
            }
            else if (flag == 3){
                pt_show.pt_swap_array();
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