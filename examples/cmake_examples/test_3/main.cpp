#include "header.hpp"

int main()
{
    int a = 3;
    int b = 5;
    int sum = add(a,b);
    std::cout << "Sum of " << a <<" and " << b << " is "<< sum << std::endl;
    int product = multiply(a,b);
    std::cout << "Product of " << a <<" and " << b << " is "<< product << std::endl;
    double c = 2.5;
    double d = 10.02;
    double quotient = divide(c,d);
    std::cout << "Result of " << c <<" divided by " << d << " is "<< quotient << std::endl;
    quotient = divide(d,c);
    std::cout << "Result of " << d <<" divided by " << c << " is "<< quotient << std::endl;
    return 0;
}
    


