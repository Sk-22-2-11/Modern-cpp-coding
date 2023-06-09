#include <iostream>
#include <bitset>
#include <iomanip>

class Show_Bits{
    private:


    public:

        int bit_oprt(){
            unsigned short int data {15};
            std::cout << "data (dec) : " <<std::showbase <<  std::dec << data << std::endl;
            std::cout << "data (oct) : " <<std::showbase <<  std::oct << data << std::endl;
            std::cout << "data (hex) : " <<std::showbase <<  std::hex << data << std::endl;
            std::cout << "data (bin) : " << std::bitset<16>(data) << std::endl;    

            unsigned short int value {0xff0u};
            std::cout << "value : " << std::bitset<16>(value) 
            << ", dec : " << value << std::endl;
            //Shift left by one bit
            value = static_cast<unsigned short int>(value << 1);
            std::cout << "value : " << std::bitset<16>(value) 
            << ", dec : " << value << std::endl;
            //Shift left by one bit
            value = static_cast<unsigned short int>(value << 1);
            std::cout << "value : " << std::bitset<16>(value) 
            << ", dec : " << value << std::endl;
            //Shift right by one bit
            value = static_cast<unsigned short int>(value >> 1);
            std::cout << "value : " << std::bitset<16>(value) 
            << ", dec : " << value << std::endl;
            //Shift right by four bits 
            value = static_cast<unsigned short int>(value >> 2);
            std::cout << "value : " << std::bitset<16>(value) 
            << ", dec : " << value << std::endl;

            int COLUMN_WIDTH {20};
            unsigned char value1 {0x3}; // 0000 0011
            unsigned char value2 {0x5}; // 0000 0101            

            std::cout << std::setw(COLUMN_WIDTH) << "value1 : " 
                << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1) << std::endl; 
                
            std::cout << std::setw(COLUMN_WIDTH) << "value2 : "
                << std::setw(COLUMN_WIDTH) << std::bitset<8>(value2) << std::endl;
            
            //AND
            std::cout << std::endl;
            std::cout << "Bitwise AND :  " << std::endl;
            std::cout << std::setw(COLUMN_WIDTH) << "value1 & value2 : "
                << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 & value2) << std::endl;
            std::cout << std::endl;

            //OR
            std::cout << std::endl;
            std::cout << "Bitwise OR :  " << std::endl;
            std::cout << std::setw(COLUMN_WIDTH) << "value1 | value2 : "
                << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 | value2) << std::endl;
            std::cout << std::endl;

            //NOT
            std::cout << std::endl;
            std::cout << "Bitwise NOT " << std::endl;            
            std::cout << std::setw(COLUMN_WIDTH) << "~value1 : "
                << std::setw(COLUMN_WIDTH) <<  std::bitset<8>(~value1) << std::endl;                
            std::cout << std::setw(COLUMN_WIDTH) << "~value2 : "
                << std::setw(COLUMN_WIDTH) << std::bitset<8>(~value2) << std::endl;

            //XOR
            std::cout << std::endl;
            std::cout << "Bitwise XOR :  " << std::endl;
            std::cout << std::setw(COLUMN_WIDTH) << "value1 ^ value2 : "
                << std::setw(COLUMN_WIDTH) << std::bitset<8>(value1 ^ value2) << std::endl;
            std::cout << std::endl;

            return 0;
        }

        int bit_mask(){
            const int COLUMN_WIDTH {20};
            
            //Highlight position for bit of interest with a 1
            //Mask other positions with 0            
            const unsigned char mask_bit_0 {0b00000001} ;//Bit0
            const unsigned char mask_bit_1 {0b00000010} ;//Bit1
            const unsigned char mask_bit_2 {0b00000100} ;//Bit2
            const unsigned char mask_bit_3 {0b00001000} ;//Bit3
            const unsigned char mask_bit_4 {0b00010000} ;//Bit4
            const unsigned char mask_bit_5 {0b00100000} ;//Bit5
            const unsigned char mask_bit_6 {0b01000000} ;//Bit6
            const unsigned char mask_bit_7 {0b10000000} ;//Bit7
            
            //Sandbox variable
            unsigned char var {0b00000000};// Starts off all bits off
            
            std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
                << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

            //Set a few bits : make them 1's regardless of what's in there
            //Setting : |= with mask of the bit   

            //Set bit 1
            std::cout << "Setting bit in position 1" << std::endl;
            var |= mask_bit_1;
            std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
                << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

            //RESETTING BITS : set to 0
            //Resetting : &= (~mask)
            
            //Reset bit 1
            std::cout << "Resetting bit in position 1" << std::endl;
            var &= (~mask_bit_1);
            std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
                << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

            //Check state of a bit
            std::cout << std::endl;
            std::cout << "Checking the state of each bit position (on/off)" << std::endl;
            std::cout << "bit0 is " << ((var & mask_bit_0) >> 0 )<< std::endl;
            std::cout << "bit1 is " << ((var & mask_bit_1) >> 1 ) << std::endl;
            std::cout << std::boolalpha;
            std::cout << "bit6 is " << ((var & mask_bit_6) >> 6 ) << std::endl;
            std::cout << "bit6 is " << static_cast<bool>(var & mask_bit_6) << std::endl;
            std::cout << "bit7 is " << ((var & mask_bit_7) >> 7 ) << std::endl;
            std::cout << "bit7 is " << static_cast<bool>(var & mask_bit_7) << std::endl;

            //Toggle bits
            //Toggle : var ^ mask            
            //Toggle bit 0
            std::cout << std::endl;
            std::cout << "Toggle bit 0" << std::endl;
            var ^= mask_bit_0;
            std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
                << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;
            //Toggle bit7 
            std::cout << "Toggle bit 7" << std::endl;
            var ^= mask_bit_7;
            std::cout << std::setw(COLUMN_WIDTH) <<  "var : "
                << std::setw(COLUMN_WIDTH) << std::bitset<8>(var) << std::endl;

            return 0;

        }

        int bit_color(){
            const unsigned int red_mask {0xFF000000};
            const unsigned int green_mask {0x00FF0000};
            const unsigned int blue_mask {0x0000FF00};
            const unsigned int alpha_mask {0x000000FF};// Transparency information
            
            
            unsigned int my_color {0xAABCDE00};
            
            //We shift to make sure the color byte of interest is in the 
            // lower index byte position so that we can interpret that as an integer,
            // which will be between 0 and 255. 
            
            //Set some format options
            std::cout << std::dec << std::showbase << std::endl;
            
            std::cout << "Red is : " <<  ((my_color & red_mask) >> 24) << std::endl;
            std::cout << "Green is : " <<  ((my_color & green_mask) >> 16) << std::endl;
            std::cout << "Blue is : " <<  ((my_color & blue_mask) >> 8) << std::endl;
            std::cout << "Alpha is : " <<  ((my_color & alpha_mask) >> 0) << std::endl;
            return 0;
        }

};


class Show_Case{
    private:
        Show_Bits bit_show;
    public:
        int flag {0};

        int show_menu(){
            std::clog << "--- Data operations testing table: ---" << std::endl;
            std::clog << "- 1 - Shift and logical operators" << std::endl;
            std::clog << "- 2 - Masks" << std::endl;
            std::clog << "- 3 - Color information" << std::endl;
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
                bit_show.bit_oprt();
            }
            else if(flag == 2){
                bit_show.bit_mask();
            }
            else if (flag == 3){
                bit_show.bit_color();
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