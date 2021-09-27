#include "Complex.h"

#include <cmath>

    Complex::Complex() :
        re_ (0), im_ (0)
    {
    }
    Complex::Complex (double real) :
        re_ (real), im_ (0)
    {
    }
    
    Complex::Complex (double real, double imag) :
        re_ (real), im_ (imag)
    {
    }

    Complex &Complex::operator = (const Complex &another)
    {
        real() = another.real();
        imag() = another.imag();
        return *this;
    }

    Complex::Complex (const Complex &another)
    {
        real() = another.real();
        imag() = another.imag();
    }

    Complex::Complex (Complex &&another)
    {
        real() = another.real();
        imag() = another.imag();
        another.real() = 0;
        another.imag() = 0;
    }

    Complex Complex::operator + (const Complex &another) const
    {
        return Complex (real() + another.real(), imag() + another.imag());
    }

    Complex operator + (double left, const Complex &right)
    {
        return Complex (left) + right;
    }

    Complex &Complex::operator += (const Complex &another)
    {
        *this = *this + another;
        return *this;
    }

    Complex Complex::operator - (const Complex &another) const
    {
        return Complex (real() - another.real(), imag() - another.imag());
    }

    Complex operator - (double left, const Complex &right)
    {
        return Complex (left) - right;
    }

    Complex Complex::operator -() const
    {
        return Complex (-real(), -imag());
    }

    Complex &Complex::operator -= (const Complex &another)
    {
        *this = *this - another;
        return *this;
    }

    Complex Complex::operator * (const Complex &another) const
    {
        double re = real()*another.real() - imag()*another.imag();
        double im = imag() + another.imag();
        return Complex (re, im);
    }

    Complex operator * (double left, const Complex &right)
    {
        return Complex (left) * right;
    }

    Complex &Complex::operator *= (const Complex &another)
    {        
        *this = *this * another;
        return *this;
    }

    Complex Complex::operator / (double re) const
    {
        return Complex (real() / re, imag() / re);
    }

    Complex &Complex::operator /= (double re)
    {
        *this = *this / re;
        return *this;
    }

    bool Complex::operator == (const Complex &another) const
    {
        return real() == another.real() && imag() == another.imag();
    }

    bool Complex::operator != (const Complex &another) const
    {
        return !(*this == another);
    }

    std::ostream &operator << (std::ostream &os, const Complex &x)
    {
        return os << x.real() << ',' << x.imag();
    }

    double Complex::abs()
    {
        return sqrt (real()*real() + imag()*imag());
    }
