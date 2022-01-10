#include <iostream>
#include <vector>

template <int T>
class myuint
{
    public:
        // with and w/o parameters
        myuint();
        myuint(int num);
        std::string number;

        // implementing get and set of the current myuint value
        std::string getCurrent();
        void setCurrent(std::string num);

        // operators
        myuint<T> operator+(myuint<T> num);
        myuint<T> operator-(myuint<T> num);
        myuint<T> operator>>(myuint<T> num);
        myuint<T> operator<<(myuint<T> num);

        myuint<T> operator*(myuint<T> num);
        myuint<T> operator/(myuint<T> num);
        // myuint<T> operator%(myuint<T> num);
};