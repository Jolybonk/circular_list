#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double re;
    double im;

public:
    // Конструктор без параметров
    Complex();

    // Конструктор по вещественному числу
    Complex(double real);

    // Конструктор по вещественной и мнимой части
    Complex(double real, double imag);

    // Конструктор по модулю и аргументу
    // Создает комплексное число из полярных координат (модуль, аргумент в радианах)
    static Complex fromPolar(double modulus, double argument);

    // Геттеры
    double getRe() const;
    double getIm() const;

    // Возвращает комплексно-сопряженное число
    Complex conj() const;

    // Возвращает модуль числа
    double abs() const;

    // Возвращает аргумент числа в радианах (atan2)
    double arg() const;

    // Составные операторы присваивания с комплексным числом
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    // Составные операторы присваивания с double
    Complex& operator+=(double value);
    Complex& operator-=(double value);
    Complex& operator*=(double value);
    Complex& operator/=(double value);

    // Унарный плюс (возвращает копию числа)
    Complex operator+() const;

    // Унарный минус (возвращает противоположное число)
    Complex operator-() const;

    // Дружественные бинарные операторы
    friend Complex operator+(const Complex& left, const Complex& right);
    friend Complex operator-(const Complex& left, const Complex& right);
    friend Complex operator*(const Complex& left, const Complex& right);
    friend Complex operator/(const Complex& left, const Complex& right);

    friend Complex operator+(const Complex& left, double right);
    friend Complex operator-(const Complex& left, double right);
    friend Complex operator*(const Complex& left, double right);
    friend Complex operator/(const Complex& left, double right);

    friend Complex operator+(double left, const Complex& right);
    friend Complex operator-(double left, const Complex& right);
    friend Complex operator*(double left, const Complex& right);
    friend Complex operator/(double left, const Complex& right);

    // Операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

#endif // COMPLEX_H
