#include <iostream>
#include <vector>
#include <math.h>

template <int T>
class myuint
{

    private:
        std::string number;

    public:
        // with and w/o parameters
        myuint(int num);
        myuint();

        // implementing get and set of the current myuint value
        std::string getCurrent();
        void setCurrent(std::string num);

        // to add convertion type function
        //...
        
        // operators
        myuint<T> operator+(myuint<T> num);
        myuint<T> operator-(myuint<T> num);
        myuint<T> operator>>(myuint<T> num);
        myuint<T> operator<<(myuint<T> num);

        myuint<T> operator*(myuint<T> num);
        myuint<T> operator/(myuint<T> num);
        myuint<T> operator%(myuint<T> num);


};