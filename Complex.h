#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <exception>
#include <stdexcept>

template <typename T>
class Complex
{
public:
    T  real() const { return r_; }
    T  imag() const { return i_; }
    T& real()       { return r_; }
    T& imag()       { return i_; }

    Complex() :
        r_ (0), i_ (0)
    {
    }
    Complex (const T& real) :
        r_ (real), i_ (0)
    {
    }
    
    Complex (const T& real, const T& imag) :
        r_ (real), i_ (imag)
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

    //std::ostream &operator << (std::ostream &os) const
    //{
    //    return os << real() << ',' << imag();
    //}

    friend std::ostream &operator << (std::ostream &os, const Complex<T> &x)
    {
        return os << x.real() << ',' << x.imag();
    }

    T abs()
    {
        return sqrt (real()*real() + imag()*imag());
    }

private:
    T r_;
    T i_;
};

#endif
