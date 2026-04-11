#include "Complex.h"
#include <cmath>
#include <iomanip>

using namespace std;

Complex::Complex() : re(0.0), im(0.0) {}

Complex::Complex(double real) : re(real), im(0.0) {}

Complex::Complex(double real, double imag) : re(real), im(imag) {}

Complex Complex::fromPolar(double modulus, double argument) {
    return Complex(modulus * cos(argument), modulus * sin(argument));
}

double Complex::getRe() const {
    return re;
}

double Complex::getIm() const {
    return im;
}

Complex Complex::conj() const {
    return Complex(re, -im);
}

double Complex::abs() const {
    return sqrt(re * re + im * im);
}

double Complex::arg() const {
    return atan2(im, re);
}

Complex& Complex::operator+=(const Complex& other) {
    re += other.re;
    im += other.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    re -= other.re;
    im -= other.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double newRe = re * other.re - im * other.im;
    double newIm = re * other.im + im * other.re;
    re = newRe;
    im = newIm;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    double denominator = other.re * other.re + other.im * other.im;
    if (denominator == 0) {
        re = 0;
        im = 0;
        return *this;
    }
    double newRe = (re * other.re + im * other.im) / denominator;
    double newIm = (im * other.re - re * other.im) / denominator;
    re = newRe;
    im = newIm;
    return *this;
}

Complex& Complex::operator+=(double value) {
    re += value;
    return *this;
}

Complex& Complex::operator-=(double value) {
    re -= value;
    return *this;
}

Complex& Complex::operator*=(double value) {
    re *= value;
    im *= value;
    return *this;
}

Complex& Complex::operator/=(double value) {
    if (value != 0) {
        re /= value;
        im /= value;
    }
    return *this;
}

Complex Complex::operator+() const {
    return *this;
}

Complex Complex::operator-() const {
    return Complex(-re, -im);
}

Complex operator+(const Complex& left, const Complex& right) {
    Complex result = left;
    result += right;
    return result;
}

Complex operator-(const Complex& left, const Complex& right) {
    Complex result = left;
    result -= right;
    return result;
}

Complex operator*(const Complex& left, const Complex& right) {
    Complex result = left;
    result *= right;
    return result;
}

Complex operator/(const Complex& left, const Complex& right) {
    Complex result = left;
    result /= right;
    return result;
}

Complex operator+(const Complex& left, double right) {
    Complex result = left;
    result += right;
    return result;
}

Complex operator-(const Complex& left, double right) {
    Complex result = left;
    result -= right;
    return result;
}

Complex operator*(const Complex& left, double right) {
    Complex result = left;
    result *= right;
    return result;
}

Complex operator/(const Complex& left, double right) {
    Complex result = left;
    result /= right;
    return result;
}

Complex operator+(double left, const Complex& right) {
    return right + left;
}

Complex operator-(double left, const Complex& right) {
    return Complex(left - right.re, -right.im);
}

Complex operator*(double left, const Complex& right) {
    return right * left;
}

Complex operator/(double left, const Complex& right) {
    double denominator = right.re * right.re + right.im * right.im;
    if (denominator == 0) {
        return Complex(0, 0);
    }
    return Complex(left * right.re / denominator, -left * right.im / denominator);
}

ostream& operator<<(ostream& os, const Complex& c) {
    os << "(" << c.re;
    if (c.im >= 0) {
        os << "+" << c.im << "i)";
    } else {
        os << c.im << "i)";
    }
    return os;
}

istream& operator>>(istream& is, Complex& c) {
    cout << "Enter real part: ";
    is >> c.re;
    cout << "Enter imaginary part: ";
    is >> c.im;
    return is;
}
