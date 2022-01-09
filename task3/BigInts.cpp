/*CPS2004 - OOP
  Task 3 - Big Integers (in C++)
  Luke D'Amato
*/

/* Things to do:
* PART 1:
* - implement operators +, -, expo (**) 
* - overloading binary integers 
* - templated convertion function
* - copy constructors from int types
* - optimize where possible
* _____________________________
* PART 2:
* - implement operators *, /, % 
* - overloading new operators
* - optimize where possible
* PART 3:
* - check if there are any design flaws + optimize code where possible 
* - templating lib should be able to auto switch to built-in integers
* _____________________________
* EXTRA:
* - research moder CPU features
* - manupilatuion techniques to reduce overhead? (godbolt.org)
* - take note of any design or implmentation features (efficiency)
*/

#include <iostream>
#include "BigInts.hpp"

using namespace std;


int main()
{
    myuint<1024> i(5); // creates a 1024-bit unsigned int ’5’
    // myuint<2048> j = i << 1000 + 23; // shifts it by 1000 bits and adds 23

    // return j.template convert_to<int>() // returns 23
}