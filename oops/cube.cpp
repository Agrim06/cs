#include<iostream>
using namespace std;

class Cube {
public:
    float side;

    void display() {
        cout << "Side: " << side << endl;
        cout << "Volume: " << side * side * side << endl;
        cout << "Outer Area: " << 6 * side * side << endl;
        cout << "_____________________________" << endl;
    }
};

int main() {
    Cube c1, c2, c3;

    cout << "ENTER SIDES OF 3 CUBES: ";
    cin >> c1.side >> c2.side >> c3.side;

    cout << "Cube 1:" << endl;
    c1.display();

    cout << "Cube 2:" << endl;
    c2.display();

    cout << "Cube 3:" << endl;
    c3.display();

    return 0;
}
