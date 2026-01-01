#include <iostream>
using namespace std;

class Complex {
public:
    float real, imag;

    void read() {
        cin >> real >> imag;
    }

    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }

    Complex operator + (Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};

int main() {
    Complex c1, c2, c3;

    cout << "Enter real and imaginary part of first complex number: ";
    c2.read();

    cout << "Enter real and imaginary part of second complex number: ";
    c3.read();

    c1 = c2 + c3;

    cout << "Result of addition: ";
    c1.display();

    return 0;
}
