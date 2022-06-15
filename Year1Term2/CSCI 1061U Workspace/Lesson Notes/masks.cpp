// main.cpp
// by Thomas Chiarello

#include <iostream>
#include <ctime>

int main(){




//Tasks 2 and 3
//I want to set bit 3 and i want to reset bit 8
unsigned int mask_to_set_bit_3 = 4; // 0...0100
y = y | mask_to_set_bit_3;

unsigned int mask_to_reset_bit_8 = 128; // 0...010000000
mask_to_reset_bit_8 = ~mask_to_reset_bit_8; // 1...101111111
y = y & mask_to_reset_bit_8; 

// Task 4


return 0;
}