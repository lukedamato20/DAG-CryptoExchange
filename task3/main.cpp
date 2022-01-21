#include <iostream>
#include "myuint.hpp"
#include "myuint.cpp"

void testing();

int main()
{
    testing();

    return 0;
}

void testing()
{
    // testing code with num1 and num2 as big integer examples...
    std::cout << "test output" << std::endl;

    // creates a 1024-bit unsigned int ’5’
    myuint<1024> num1(5);
    std::cout << num1.getCurrent() << std::endl;

    // shifts it by 1000 bits and adds 23
    // ((( adding brackets to fix possible mistake?? )))
    myuint<2048> num2 = (num1 << 1000) + 23; 
    std::cout << num2.getCurrent() << std::endl;

    // outputting result from convertion function
    std::cout << num2.converType<int>() << std::endl;

    return num2.template converType<int>(); // returns 23
}