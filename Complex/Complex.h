#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <exception>
#include <stdexcept>
#include <math.h>

template <typename T>
class Complex
{
public:
    T  real() const { return re_; }
    T  imag() const { return im_; }
    T& real()       { return re_; }
    T& imag()       { return im_; }

    Complex() :
        re_ (0), im_ (0)
    {
    }
    Complex (const T& real) :
        re_ (real), im_ (0)
    {
    }
    
    Complex (const T& real, const T& imag) :
        re_ (real), im_ (imag)
    {
    }

    Complex<T> &operator = (const Complex<T> &another)
    {
        real() = another.real();
        imag() = another.imag();
        return *this;
    }

    Complex (const Complex<T> &another)
    {
        real() = another.real();
        imag() = another.imag();
    }

    Complex (Complex<T> &&another)
    {
        real() = another.real();
        imag() = another.imag();
        another.real() = 0;
        another.imag() = 0;
    }

    Complex<T> operator + (const Complex<T> &another) const
    {
        return Complex<T>(real() + another.real(), imag() + another.imag());
    }

    friend Complex<T> operator + (const T &left, const Complex<T> &right)
    {
        return Complex<T>(left) + right;
    }

    Complex<T> &operator += (const Complex<T> &another)
    {
        *this = *this + another;
        return *this;
    }

    Complex<T> operator - (const Complex<T> &another) const
    {
        return Complex<T>(real() - another.real(), imag() - another.imag());
    }

    friend Complex<T> operator - (const T &left, const Complex<T> &right)
    {
        return Complex<T>(left) - right;
    }

    Complex<T> operator -() const
    {
        return Complex<T> (-real(), -imag());
    }

    Complex<T> &operator -= (const Complex<T> &another)
    {
        *this = *this - another;
        return *this;
    }

    Complex<T> operator * (const Complex<T> &another) const
    {
        T re = real()*another.real() - imag()*another.imag();
        T im = imag() + another.imag();
        return Complex<T>(re, im);
    }

    friend Complex<T> operator * (const T &left, const Complex<T> &right)
    {
        return Complex<T>(left) * right;
    }

    Complex<T> &operator *= (const Complex<T> &another)
    {        
        *this = *this * another;
        return *this;
    }

    Complex<T> operator / (const T &re) const
    {
        if (re == 0)
            throw std::invalid_argument ("Devining by zero.");

        return Complex<T>(real() / re, imag() / re);
    }

    Complex<T> &operator /= (const T &re)
    {
        *this = *this / re;
        return *this;
    }

    bool operator == (const Complex<T> &another) const
    {
        return real() == another.real() && imag() == another.imag();
    }

    bool operator != (const Complex<T> &another) const
    {
        return !(*this == another);
    }

    friend std::ostream &operator << (std::ostream &os, const Complex<T> &x)
    {
        return os << x.real() << ',' << x.imag();
    }

    T abs()
    {
        return sqrt (real()*real() + imag()*imag());
    }

private:
    T re_;
    T im_;
};

#endif
