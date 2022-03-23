#include "Complex.h"

bool double_equals(double l, double r)
{
    return abs(l - r) < 0.001;
}

Complex operator+(const Complex& l, const Complex& r)
{
    double real = l.real() + r.real();
    double imag = l.imag() + r.imag();

    return Complex(real, imag);
}

Complex operator+(const Complex& l, double r)
{
    double real = l.real() + r;
    double imag = l.imag();

    return Complex(real, imag);
}

Complex operator+(double l, const Complex& r)
{
    double real = l + r.real();
    double imag = r.imag();

    return Complex(real, imag);
}

Complex operator-(const Complex& l, const Complex& r)
{
    double real = l.real() - r.real();
    double imag = l.imag() - r.imag();

    return Complex(real, imag);
}

Complex operator-(const Complex& l, double r)
{
    double real = l.real() - r;
    double imag = l.imag();

    return Complex(real, imag);
}

Complex operator-(double l, const Complex& r)
{
    double real = l - r.real();
    double imag = r.imag();

    return Complex(real, imag);
}

Complex operator*(const Complex& l, const Complex& r)
{
    double real = l.real() * r.real();
    double imag = l.imag() * r.imag();

    return Complex(real, imag);
}

Complex operator*(const Complex& l, double r)
{
    double real = l.real() * r;
    double imag = l.imag();

    return Complex(real, imag);
}

Complex operator*(double l, const Complex& r)
{
    double real = l * r.real();
    double imag = r.imag();

    return Complex(real, imag);
}

Complex operator-(const Complex& obj)
{
    double real = obj.real();
    double imag = 0 - obj.imag();
    return Complex();
}

bool operator==(const Complex& l, const Complex& r)
{
    return ((l.real() == r.real()) && (l.imag() == r.imag()));
    return false;
}

bool operator!=(const Complex& l, const Complex& r)
{
    return ((l.real() != r.real()) && (l.imag() != r.imag()));
    return false;
}

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag)
{
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const
{
    return imag() == 0;
}

double Complex::real() const
{
    return real_data;
}

double Complex::imag() const
{
    return imag_data;
}

double Complex::abs() const
{
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const
{
    return { real(), -imag() };
}