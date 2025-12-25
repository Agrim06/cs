#include<iostream>
using namespace std;
int sum_two_nums(int a ,int b)
{
      return a+b;
}
double sum_two_nums(double a,double b)
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
    
    cout<<"\nSum of integers = "<<sum_two_nums(x,y)<<endl;
    cout<<"Sum of decimal numbers = "<<sum_two_nums(p,q)<<endl;
    return 0;
}
