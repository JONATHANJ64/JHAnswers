// This is a program that prints numbers from 1 to 100, with some special cases
#include <iostream>

int main()
{
    for (int i = 1; i <= 100; ++i)
    {
        // If the number is divisible by both 3 and 5
        if (i % 3 == 0 && i % 5 == 0)
        {
            std::cout << "HotDog ";
            // If the number is divisible by 3 only
        }
        else if (i % 3 == 0)
        {
            std::cout << "Hot ";
            // If the number is divisible by 5 only
        }
        else if (i % 5 == 0)
        {
            std::cout << "Dog ";
            // If the number is not divisible by 3 or 5
        }
        else
        {
            std::cout << i << " ";
        }
    }
    // Print a newline character to separate the output from the shell prompt
    std::cout << std::endl;
    return 0;
}