#include<iostream>
using namespace std;
class employee{
    int eno;
    string name;
    float basic,da,it,net;
    
    public : void read();
                 void calc();
                 void print();
};

void employee :: read()
{
      cout<<"\nEnter Employee Number : ";
      cin>>eno;
      cout<<"Enter Employee Name ";
      cin>>name;
      cout<<"Enter basic salary :";
      cin>>basic;
}

void employee::calc()
{
      da=0.52*basic;
      float gross=basic+da;
      it=0.30*gross;
      net=gross-it;
}

void employee::print()
{
      cout<<"\nEmployee Number :"<<eno;
      cout<<"\nEmployee Name :"<<name;
      cout<<"\nBasic :"<<basic;
      cout<<"\nDA :"<<da;
      cout<<"\nIT :"<<it;
      cout<<"\nNet Salary :"<<net<<endl;
}

int main()
{
        int n;
        cout<<"Enter number of employees :";
        cin>>n;
        employee e[50];
        for(int i=0;i<n;i++)
        {
               cout<<"\nEnter the details of employee "<<i+1<<" : ";
               e[i].read();
               e[i].calc();
               
        }
        
        cout<<"\n - - - Employee Details ---\n";
        for(int i=0;i<n;i++)
              e[i].print();
              
              return 0;
}
