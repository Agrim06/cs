#include <iostream>
using namespace std;

class Shape {
public:
    virtual void display() {
        cout << "This is a shape" << endl;
    }
};

class Polygon : public Shape {
public:
    void display() {
        cout << "Polygon is a shape" << endl;
    }
};

class Rectangle : public Polygon {
public:
    void display() {
        cout << "Rectangle is a polygon" << endl;
    }
};

class Triangle : public Polygon {
public:
    void display() {
        cout << "Triangle is a polygon" << endl;
    }
};

class Square : public Rectangle {
public:
    void display() {
        cout << "Square is a rectangle" << endl;
    }
};

int main() {
    Shape* ptr;

    Shape s;
    Polygon p;
    Rectangle r;
    Triangle t;
    Square sq;

    ptr = &s;
    ptr->display();

    ptr = &p;
    ptr->display();

    ptr = &r;
    ptr->display();

    ptr = &t;
    ptr->display();

    ptr = &sq;
    ptr->display();

    return 0;
}
