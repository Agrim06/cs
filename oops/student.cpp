#include<iostream>
using namespace std;

class student {

       string usn,name;
       int m1,m2,m3;
       float avg;
       
       public : void read();
                void calculate();
                void print();
};

void student ::read()
{
       cout<<"\nEnter USN :";
       cin>>usn;
       cout<<"ENter Name :";
       cin>>name;
       cout<<"Enter marks in 3 tests :";
       cin>>m1>>m2>>m3;
}

void student :: calculate(){
        int minmark;
        if(m1<=m2&&m1<=m3)
	{
                 minmark=m1;
		 }
        else if(m2<=m1 && m2<=m3){
                 minmark=m2;
		 }
        else {
                minmark=m3;
                avg=(m1+m2+m3-minmark)/2.0;         
}
}
void student::print()
{
        cout<<"\nUSN :"<<usn;
        cout<<"\nName :"<<name;
        cout<<"\n Average of best two marks :"<<avg<<endl;
}

int main()
{
         student s[10];
         int n;
         cout<<"Enter number of students (max 10) :" ;
         cin>>n;
         for(int i=0;i<n;i++)
         {
               cout<<"\nEnter details of students "<<i+1<<" : ";
               s[i].read();
               s[i].calculate();
         }
         cout<<"\n----Student Details ---\n";
         for(int i=0;i<n;i++)
                s[i].print();
                
                return 0;
}
