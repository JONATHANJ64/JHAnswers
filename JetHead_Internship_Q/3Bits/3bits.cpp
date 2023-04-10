#include <iostream>

int main() {
    // Iterate over numbers from 1 to 100
    for (int i = 1; i <= 100; ++i) {
        int count = 0;
        // Check each bit of the current number by shifting it right and checking the least significant bit
        for (int j = 0; j < 32; ++j) {
            if ((i >> j) & 1) { // If the j-th bit is set to 1
                ++count; // Increment the count of 1 bits
            }
        }
        // If the number has exactly 3 bits set to 1, print it to the console
        if (count == 3) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
