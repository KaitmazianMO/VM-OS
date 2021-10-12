#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream> 
/*
namespace std
{
    class ostream;
}
*/

class Complex
{
public:
    double  real() const { return re_; }
    double  imag() const { return im_; }
    double& real()       { return re_; }
    double& imag()       { return im_; }

    Complex();
    Complex (double real);
    Complex (double real, double imag);
    Complex (const Complex &another);
    Complex (Complex &&another);

    Complex &      operator = (const Complex &another);
    Complex        operator + (const Complex &another) const;
    friend Complex operator + (double left, const Complex &right);
    Complex &      operator += (const Complex &another);
    Complex        operator - (const Complex &another) const;
    friend Complex operator - (double left, const Complex &right);
    Complex        operator -() const;
    Complex       &operator -= (const Complex &another);
    Complex        operator * (const Complex &another) const;
    friend Complex operator * (double left, const Complex &right);
    Complex &      operator *= (const Complex &another);
    Complex        operator / (double re) const;
    Complex &      operator /= (double re);
    bool           operator == (const Complex &another) const;
    bool           operator != (const Complex &another) const;
    double         abs();
    friend std::ostream &operator << (std::ostream &os, const Complex &x);

private:
    double re_;
    double im_;
};

#endif
