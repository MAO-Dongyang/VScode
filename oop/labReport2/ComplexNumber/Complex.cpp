#include "Complex.h"
#include <iostream>
using namespace std;

complex Z0{0, 0}; // 定义零元

bool equalComple(complex Z1, complex Z2)
{
    if (Z1.real == Z2.real && Z1.imag == Z2.imag)
    {
        return true;
    }
    else
    {
        return false;
    }

} // 定义相等

complex oppositeComplex(complex Z)
{
    complex _Z;
    _Z.real = -Z.real;
    _Z.imag = -Z.imag;
    return _Z;
} // 定义加法逆元

complex reciprocalComplex(complex Z)
{
    if (equalComple(Z, Z0))
    {
        cout << "Divisor cannot be 0" << endl; // 零元无幺元
    }
    complex _Z;
    _Z.real = Z.real / (Z.real * Z.real + Z.imag * Z.imag);
    _Z.imag = -Z.imag / (Z.real * Z.real + Z.imag * Z.imag);
    return _Z;
} // 定义乘法逆元

void addComplex(complex c1, complex c2, complex &result)
{
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
} // 定义加法

void multiplyComplex(complex c1, complex c2, complex &result)
{
    result.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    result.imag = (c1.imag * c2.real) + (c1.real * c2.imag);
} // 定义乘法

void subtractComplex(complex c1, complex c2, complex &result)
{
    addComplex(c1, oppositeComplex(c2), result);
} // 利用加法逆元定义加法逆运算

void divisionComplex(complex c1, complex c2, complex &result)
{
    multiplyComplex(c1, reciprocalComplex(c2), result);
} // 利用乘法逆元定义乘法逆运算

void Complex::displayComplex()
{
    cout << data.real << " + " << data.imag << "i" << endl;
}

Complex Complex::operator*(Complex const &c2)
{
    Complex res(0, 0);
    multiplyComplex(data, c2.data, res.data);
    return res;
}

Complex Complex::operator/(Complex const &c2)
{
    Complex res(0, 0);
    divisionComplex(data, c2.data, res.data);
    return res;
}

Complex Complex::operator+(Complex const &c2)
{
    Complex res(0, 0);
    addComplex(data, c2.data, res.data);
    return res;
}

Complex Complex::operator-(Complex const &c2)
{
    Complex res(0, 0);
    subtractComplex(data, c2.data, res.data);
    return res;
}

Complex::Complex(double real, double imag)
{
    data.real = real;
    data.imag = imag;
}

Complex::~Complex()
{
}
