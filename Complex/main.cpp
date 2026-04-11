#include "Complex.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    cout << "========================================" << endl;
    cout << "     COMPLEX NUMBERS DEMONSTRATION      " << endl;
    cout << "========================================\n" << endl;

    // Демонстрация конструкторов
    cout << "--- Constructors ---" << endl;
    Complex c1;  // (0,0)
    cout << "Default constructor: " << c1 << endl;

    Complex c2(5);  // (5,0)
    cout << "From real number: " << c2 << endl;

    Complex c3(3, 4);  // (3,4)
    cout << "From real and imag: " << c3 << endl;

    Complex c4 = Complex::fromPolar(5, atan2(4, 3));
    cout << "From polar (modulus=5, arg~0.927): " << c4 << endl;

    // Демонстрация методов
    cout << "\n--- Methods ---" << endl;
    cout << "c3 = " << c3 << endl;
    cout << "Real part: " << c3.getRe() << endl;
    cout << "Imag part: " << c3.getIm() << endl;
    cout << "Conjugate: " << c3.conj() << endl;
    cout << "Modulus: " << c3.abs() << endl;
    cout << "Argument (rad): " << c3.arg() << endl;

    // Демонстрация арифметических операций
    cout << "\n--- Arithmetic Operations ---" << endl;
    Complex a(2, 3);
    Complex b(4, 5);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    // Демонстрация с double
    cout << "\n--- Operations with double ---" << endl;
    Complex d(3, 4);
    double x = 2;
    cout << "d = " << d << endl;
    cout << "x = " << x << endl;
    cout << "d + x = " << d + x << endl;
    cout << "d - x = " << d - x << endl;
    cout << "d * x = " << d * x << endl;
    cout << "d / x = " << d / x << endl;
    cout << "x + d = " << x + d << endl;
    cout << "x - d = " << x - d << endl;
    cout << "x * d = " << x * d << endl;
    cout << "x / d = " << x / d << endl;

    // Демонстрация унарных операторов
    cout << "\n--- Unary Operators ---" << endl;
    Complex e(2, -3);
    cout << "e = " << e << endl;
    cout << "+e = " << +e << endl;
    cout << "-e = " << -e << endl;

    // Демонстрация составных операторов
    cout << "\n--- Compound Assignment Operators ---" << endl;
    Complex f(1, 2);
    Complex g(3, 4);
    cout << "f = " << f << ", g = " << g << endl;

    f += g;
    cout << "f += g -> f = " << f << endl;

    f -= Complex(2, 2);
    cout << "f -= (2,2) -> f = " << f << endl;

    f *= Complex(0, 1);
    cout << "f *= (0,1) -> f = " << f << endl;

    f /= Complex(1, 1);
    cout << "f /= (1,1) -> f = " << f << endl;

    // Демонстрация составных операторов с double
    cout << "\n--- Compound Assignment with double ---" << endl;
    Complex h(5, 5);
    cout << "h = " << h << endl;

    h += 3;
    cout << "h += 3 -> h = " << h << endl;

    h -= 2;
    cout << "h -= 2 -> h = " << h << endl;

    h *= 2;
    cout << "h *= 2 -> h = " << h << endl;

    h /= 4;
    cout << "h /= 4 -> h = " << h << endl;

    // Демонстрация ввода
    cout << "\n--- Input Operator ---" << endl;
    Complex input;
    cout << "Enter a complex number:" << endl;
    cin >> input;
    cout << "You entered: " << input << endl;

    cout << "\n========================================" << endl;
    cout << "          PROGRAM COMPLETED             " << endl;
    cout << "========================================" << endl;

    return 0;
}
