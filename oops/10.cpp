#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void display() {
        cout << "I am a vehicle" << endl;
    }
};

class FourWheeler : public Vehicle {
public:
    void display() {
        cout << "I have four wheels" << endl;
    }
};

class Car : public FourWheeler {
public:
    void display() {
        cout << "I am a car" << endl;
    }
};

int main() {
    Car c;
    c.display();  
    return 0;
}
