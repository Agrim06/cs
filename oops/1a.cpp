#include <iostream>
using namespace std;

class Sphere {
public:
    float radius;
    float volume;
    float surfaceArea;

    void read() {
        cout << "Enter radius: ";
        cin >> radius;
    }

    void calculate() {
        volume = (4.0 / 3.0) * 3.14159 * radius * radius * radius;
        surfaceArea = 4 * 3.14159 * radius * radius;
    }

    void display() {
        cout << "\nRadius: " << radius << endl;
        cout << "Volume: " << volume << endl;
        cout << "Surface Area: " << surfaceArea << endl;
    }
};

int main() {
    Sphere s[3];   

    for (int i = 0; i < 3; i++) {
        cout << "\nSphere " << i + 1 << endl;
        s[i].read();
        s[i].calculate();
    }

    cout << "\n--- Sphere Details ---\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nSphere " << i + 1 << " Details:";
        s[i].display();
    }

    return 0;
}
