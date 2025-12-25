#include <iostream>
using namespace std;

class complex {
    float real;
    float img;

public:
    complex();                           
    complex(float r, float i);          
    void display();                     
    complex add(int c);             
    complex add(complex s2);            
};

complex::complex() {
    real = 0;
    img = 0;
}

complex::complex(float r, float i) {
    real = r;
    img = i;
}


void complex::display() {
    cout << real << " + " << img << "i" << endl;
}


complex complex::add(int a) {
    complex temp;
    temp.real = real + a;
    temp.img = img;
    return temp;
}


complex complex::add(complex s2) {
    complex temp;
    temp.real = real + s2.real;
    temp.img = img + s2.img;
    return temp;
}

int main() {
    complex c1(3, 4), c2(5, 6), result;

    cout << "First complex number: ";
    c1.display();

    cout << "Second complex number: ";
    c2.display();

    result = c1.add(5);     
    cout << "Result of add(c1, 5): ";
    result.display();

    result = c1.add(c2);    
    cout << "Result of add(c1, c2): ";
    result.display();

    return 0;
}


