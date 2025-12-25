#include <iostream>
using namespace std;

class vechicle{
public:
void vech(){
cout<<"I am vechicle"<<endl;
}
};
class fourwheel:public vechicle{
public:
void four(){
cout<<" I am fourwheel"<<endl;
}
};
class car:public fourwheel{
public:
void Car(){
cout<<"I am car"<<endl;
}
};

int main(){
car c;
c.Car();
c.four();
c.vech();
return 0;
}

