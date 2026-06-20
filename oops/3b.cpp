#include <iostream>
using namespace std;

void swapValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside function (Call by Value): a = " << a << " b = " << b << endl;
}

int main()
{
    int x = 10, y = 20;

    cout << "Before swap: x = " << x << " y = " << y << endl;
    swapValue(x, y);
    cout << "After swap: x = " << x << " y = " << y << endl;

    return 0;
}
