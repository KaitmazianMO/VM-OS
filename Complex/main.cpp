#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>
#include <stdexcept>
#include <utility>

#include "Complex.h"

int main()
{                  
    Complex<float> x (1, 2);
    Complex<float> y (1, 2);                
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    std::cout << "Ops" << std::endl;
    try 
    {
        std::cout << x << " + " << y        << " = " << x + y << std::endl; 
        std::cout << x << " - " << y        << " = " << x - y << std::endl;     
        std::cout << x << " * " << y        << " = " << x * y << std::endl;      
        std::cout << x << " / " << y.real() << " = " << x / y.real() << std::endl;
    }
    catch (const std::invalid_argument &ex) 
    {
        std::cerr << ex.what() << std::endl;
    }

    std::cout << "abs" << std::endl;
    try 
    {
        std::cout << "(x + y).abs()      = " << (x + y).abs() << std::endl;
        std::cout << "(x - y).abs()      = " << (x - y).abs() << std::endl;
        std::cout << "(x * y).abs()      = " << (x * y).abs() << std::endl;  
        std::cout << "(x / y.real).abs() = " << (x / y.real()).abs() << std::endl;   
    }
    catch (const std::invalid_argument &ex) 
    {
        std::cerr << ex.what() << std::endl;
    }   

    std::cout << "Move" << std::endl;
    {
        Complex<float> new_y = std::move (y);
        std::cout << "y     =" << y << std::endl;
        std::cout << "new_y = "<< new_y << std::endl;
    }

    return 0;
}
