#include <iostream>
using namespace std;

void max(int a, int b) {
    if (a > b)
        cout << "Larger integer value is: " << a << endl;
    else
        cout << "Larger integer value is: " << b << endl;
}

void max(double a, double b) {
    if (a > b)
        cout << "Larger double value is: " << a << endl;
    else
        cout << "Larger double value is: " << b << endl;
}

int main() {
    int x, y;
    double p, q;

    cout << "Enter two integers: ";
    cin >> x >> y;
    max(x, y);

    cout << "Enter two double values: ";
    cin >> p >> q;
    max(p, q);

    return 0;
}
