#include <iostream>
using namespace std;

int main(){
	const int cities=5;
	const int days=6;
	int temp[cities][days];

	cout<<"enter the maximum temperature for 5 cities(each for 6 days)";

	for(int i=0; i<cities; i++){
		cout<<"\ncity"<<i+1<<":\n";
		
		for(int j=0; j<days; j++){
			cout<<"Day"<<j+1<<":";
			cin>>temp[i][j];
		}
	}
	int maxtemp=temp[0][0];
	int minitemp=temp[0][0];
	int maxcity=0,maxday=0;
	int minicity=0,miniday=0;

	for(int i=0; i<cities; i++){
		for(int j=0; j<days; j++){
			if(temp[i][j]>maxtemp){
				maxtemp=temp[i][j];
				maxcity=i;
				maxday=j;
			}
			if(temp[i][j]<minitemp){
				minitemp=temp[i][j];
				minicity=i;
				miniday=j;
			}
		}
	}

	cout<<"\n                             \n";
	cout<<"highest temperature:"<<maxtemp<<"C (city"<<maxcity+1<<"day"<<maxday+1<<")\n";
	cout<<"lowest temperature:"<<minitemp<<"C (city"<<minicity+1<<"day"<<miniday+1<<")\n";
	cout<<"                    \n";
	return 0;
}



