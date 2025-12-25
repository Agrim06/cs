#include<iostream>
using namespace std;

int main(){
	int n,sum=0;
	cout<<"Enter a positive intger:";
	cin>>n;
	for(int i=1; i<=n; ++i){
		sum+=i;
	}
	cout<<"Sum of natural number from 1 to "<<n<<"="<<sum<<endl;
	return 0;
}
