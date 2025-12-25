#include <iostream>
#include <math.h>
using namespace std;

int main(){
	double a,b,c,discriminant,root1,root2,realpart,imgpart;

	cout<<"Enter Co-efficient a,b,c";
	cin>>a>>b>>c;

	discriminant=b*b-4*a*c;

	if(discriminant>0){
		root1=(-b+sqrt(discriminant))/(2*a);
		root2=(-b-sqrt(discriminant))/(2*a);
		cout<<"Roots are real and distinct"<<endl;
		cout<<"Root1="<<root1<<endl;
		cout<<"Root=2"<<root2<<endl;
	}
	else if(discriminant==0){
		root1=-b/(2*a);
		cout<<"Roots are real & equal"<<endl;
		cout<<"Root1=Root2="<<root1<<endl;
	}
	else{
		realpart=-b/(2*a);
		imgpart=sqrt(-discriminant)/(2*a);
		cout<<"Roots are Complex & Imaginary"<<endl;
		cout<<"Root1="<<realpart<<"+"<<imgpart<<"i"<<endl;
		cout<<"Root2="<<realpart<<"-"<<imgpart<<"i"<<endl;
	}
	return 0;
}


