#include <iostream>
using namespace std;

class Sample {
public:
    int x, y;

    void read() {
        cin >> x >> y;
    }

    void display() {
        cout << "x = " << x << " , y = " << y << endl;
    }

    void operator ++() {
        ++x;
        ++y;
    }
};

int main() {
    Sample s;

    cout << "Enter two values: ";
    s.read();

    cout << "Before increment: ";
    s.display();

    ++s;

    cout << "After pre-increment: ";
    s.display();

    return 0;
}
