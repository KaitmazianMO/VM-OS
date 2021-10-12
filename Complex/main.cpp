#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>
#include <stdexcept>
#include <utility>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Complex.h"

int failed = 0;

std::string to_str (const Complex &x)
{
    return "(" + std::to_string (x.real()) + ", " + std::to_string (x.imag()) + ")";
}

bool TestEqual (Complex left, Complex right)
{
    if (left != right)
    {
        std::cerr << "Failed: " << to_str (left) << " != " + to_str (right) << std::endl;
        ++failed;
        return false;
    }
    return true;
}

double rand_num_mod_1000()
{
    int rnd = std::rand() % 1000;
    return rnd;
}

#define TestEqual_(l, r) 

int main (int argc, char *argv[])
{       
    std::srand (std::time(nullptr));
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <number-of-tests>" << std::endl; 
        exit (1);
    }

    const int n_tests = strtoll (argv[1], NULL, 10);
    for (int i = 0; i < n_tests; ++i)
    {       
        {
            Complex num {rand_num_mod_1000(), rand_num_mod_1000()};
            if (!TestEqual (num, num))
                std::cout << "Is equal operator test failed" << std::endl;
        }
        {
            double r1 = rand_num_mod_1000(), i1 = rand_num_mod_1000();
            double r2 = rand_num_mod_1000(), i2 = rand_num_mod_1000();
            if (!TestEqual (Complex {r1, i1} + Complex {r2, i2}, Complex {r1 + r2, i1 + i2}))
                std::cout << "Plus operator test failed" << std::endl;
        }
        {
            double r1 = rand_num_mod_1000(), i1 = rand_num_mod_1000();
            double r2 = rand_num_mod_1000(), i2 = rand_num_mod_1000();
            if (!TestEqual (Complex {r1, i1} - Complex {r2, i2}, Complex {r1 - r2, i1 - i2}))
                std::cout << "Minus operator test failed" << std::endl;
        }
        {
            double r1 = rand_num_mod_1000(), i1 = rand_num_mod_1000();
            double r2 = rand_num_mod_1000(), i2 = rand_num_mod_1000();
            if (!TestEqual (Complex {r1, i1} * Complex {r2, i2}, Complex {r1*r2 - i1*i2, i1 + i2}))
                std::cout << "Multiply operator test failed" << std::endl;
        }   
        {
            double r1 = rand_num_mod_1000(), i1 = rand_num_mod_1000();
            double r  = rand_num_mod_1000();
            if (r == 0) r = n_tests; // avoid zero devidng
            if (!TestEqual (Complex {r1, i1} / r, Complex {r1/r, i1/r}))
                std::cout << "Devisor operator test failed" << std::endl;
        }     
    }

    if (failed)
    {
        std::cerr << "Failed " << failed << " tests.\n";
    }
    else 
    {
        std::cerr << "All " << n_tests << " tests was passed successfully.\n";
    }

    return failed;
}
