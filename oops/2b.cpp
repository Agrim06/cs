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
    Cube c[3];

    for(int i = 0 ; i < 3 ; i++){
        cout<<"ENTER SIDE OF CUBE " << i+1 << ": ";
        cin>>c[i].side;
    }

    for(int i = 0 ; i < 3 ; i++){
        cout << "Cube " << i+1 << ":" << endl;
        c[i].display();
    }

    return 0;
}