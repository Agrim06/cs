#include<iostream>
using namespace std;

class shape{
public:
void display(){
cout<<"This is shape"<<endl;
}
};
class polygon:public shape{
public:
void display(){
cout<<"Polygon is a shape"<<endl;
}
};
class rectangle:public polygon{
public:
void display(){
cout<<"Rectangle is a polygon"<<endl;
}
};
class triangle:public polygon{
public:
void display(){
cout<<"triangle is a polygon"<<endl;
}
};
class square:public rectangle{
public:
void display(){
cout<<"square is a rectangle"<<endl;
}
};

int main(){
shape s;
polygon p;
rectangle r;
triangle t;
square sq;

s.display();
p.display();
r.display();
t.display();
sq.display();

return 0;
}
