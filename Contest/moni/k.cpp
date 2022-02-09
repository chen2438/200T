#include<iostream>
#include<cstring>
using namespace std;
int main(){
	long long a,b;
	cin>>a>>b;
	
	long long day=0,ans=0,dayp,cnt=0;
	int dayp0=1;
	while(1){
		day++;
		if(day%a==0){
			ans++;
			cnt++;
			if(ans==1)dayp=
		}
		if(ans==7){
			cout<<day;
			return 0;
		}

		if(ans<=0 and day>a){
			cout<<-1;
			return 0;
		}
	}
	/*
	for(int i=2;i<=10000;i++){
		c[i]=c[i-1]+a;
		d[i]=d[i-1]+1;
	}
	cout<<d[7];
	*/
	/*
	for(int i=7;i<=10000;i++){
		if(d[i]>=c[i-7])
	}
	if(b>=6*a)cout<<7*a;
	else cout<<-1;
	*/
	return 0;
}
