/*CPS2004 - OOP
  Task 3 - Big Integers (in C++)
  Luke D'Amato
*/

/* Things to do:
* PART 1:
* - implement and overload operators +, -, shifting  OK
* - templated convertion function 
* - copy constructors from int types  OK
* - optimize where possible    OK?
* _____________________________
* PART 2:
* - implement operators *, /, %   OK
* - overloading new operators   OK
* - optimize where possible   OK?
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

// getting the current myuint
template <int T>
std::string myuint<T>::getCurrent()
{
    return myuint<T>::number;
}

// setting the current myuint value 
template <int T>
void myuint<T>::setCurrent(std::string num)
{
  myuint<T>::number = num;
}

// ________________________________________

// creating and overloading the + operator
template <int T>
myuint<T> myuint<T>::operator+(myuint<T> num)
{
    std::string num1 = myuint<T>::number;
    std::string num2 = num.getCurrent();

    std::string result = " ";

    int num1Size = num1.size();
    int num2Size = num2.size();
    int tmp = 0;

    while(num1Size >= 0 || num2Size >= 0)
    {
        tmp += ((num1Size >= 0) ? num1[num1Size] - '0':0);
        tmp += ((num2Size >= 0) ? num2[num2Size] - '0':0);

        // typecasting with %2 and char, adding result
        result = char(tmp %2 + '0') + result;

        // reduing numbers size after each iteration 
        num1Size --;
        num2Size --;
        tmp = tmp / 2;
    }

    // creating the variable of type myuint and setting it with current value
    myuint<T> resultADD;
    resultADD.setCurrent(result);

    return resultADD;
}

// creating and overloading the - operator
template <int T>
myuint<T> myuint<T>::operator-(myuint<T> num)
{
    //getting current value and storing in resultSub
    std::string resultSub = num.getCurrent();

    int subSize = resultSub.size();

    for(int cnt = 0; cnt < subSize; cnt++)
    {
        resultSub[cnt] == '0' ? (resultSub[cnt] = '1') : (resultSub[cnt] = '0');
    } 

    // setting current with resultSub
    num.setCurrent(resultSub);

    return myuint<T>::operator+(num);
}

// creating and overloading the >> operator
template <int T>
myuint<T> myuint<T>::operator>>(myuint<T> num)
{
    std::string rightShift = myuint<T>::number;
    for(int cnt = 0; cnt < num; cnt++)
    {
        rightShift.insert(0, "0");
    }

    // checking result size, truncat if bigger 
    rightShift.erase(rightShift.end() - num, rightShift.end());

    myuint<T> resultRS;
    resultRS.setCurrent(rightShift);

    return resultRS;
}

// creating and overloading the << operator
template <int T>
myuint<T> myuint<T>::operator<<(myuint<T> num)
{
    std::string leftShift = myuint<T>::number;
    for(int cnt = 0; cnt < num; cnt++)
    {
        leftShift.erase(leftShift.begin(), leftShift.begin() + 1);
        leftShift.append("0");
    }

    myuint<T> resultLS;
    resultLS.setCurrent(leftShift);

    return resultLS;
}

// ________________________________________

// creating and overloading the * operator
template <int T>
myuint<T> myuint<T>::operator*(myuint<T> num)
{
    std::string num1 = myuint<T>::number;
    std::string num2 = num.getCurrent();

    std::string result = "";

    std::vector<myuint<T>> tmpStack;

    myuint<T> tmpResult;

    for(int cnt1 = 0; cnt1 < T; cnt1++)
    {
        for(int cnt2 = 0; cnt2 < T; cnt2++)
        {
            if(num1[cnt1] == '1' && num2[cnt2] == '1')
            {
                result = result + '1';
            }
            else 
            {
                result = result + '0';
            }
        }

        
        tmpResult.setCurrent(result);
        tmpStack.push_back(tmpResult);
        result = "";
    }

    // final result (value)
    myuint<T> value(0);
    for(int cnt = 0; cnt < tmpResult.size(); cnt++)
    {
        value += tmpStack.back() << cnt;
        tmpStack.pop_back();
    }

    return value;
}

// creating and overloading the / operator
template <int T>
myuint<T> myuint<T>::operator/(myuint<T> num)
{
    int cnt = 1;

    while ((*this -= num) >= num)
    {
        cnt++;
    }

    myuint<T> result = (cnt);
    return result;
}

// creating and overloading the % operator
template <int T>
myuint<T> myuint<T>::operator%(myuint<T> num)
{
    // only remainder needs to be calculated
    myuint<T> result = *this;

    return result;
}

// ________________________________________
int main()
{
    // testing code with num1 and num2 as big integer examples...

    // creates a 1024-bit unsigned int ’5’
    myuint<1024> num1(5);
    std::cout << num1.getCurrent() << std::endl;

    // shifts it by 1000 bits and adds 23
    // ((( adding brackets to fix possible mistake?? )))
    myuint<1024> num2 = (num1 << 1000) + 23; 
    std::cout << num2.getCurrent() << std::endl;
}