#include<iostream>
using namespace std;
int sum(int a ,int b)
{
    return a+b;
}
double sum(double a,double b)
{
    return a+b;
}

int main()
{
    int x,y;
    double p,q;
    
    cout<<"Enter two integers :";
    cin>>x>>y;
    
    cout<<"Enter two decimal numbers :";
    cin>>p>>q;
    
    cout<<"\nSum of integers = "<<sum(x,y)<<endl;
    cout<<"Sum of decimal numbers = "<<sum(p,q)<<endl;
    return 0;
}
