#include<iostream>
using namespace std;
bool judge(int x,int a){
	int s;
	while(x>0){
		s=x%10;
		x/=10;
		if(s==a)return true;
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	int a=3;
	while(t--){
		cin>>a;
		int cnt=0,sum=0;
		for(int i=1000;i<=9999;i++)
			if(judge(i,a) and i%a!=0){
				cnt++;
				sum+=i;
			}
		cout<<cnt<<" "<<sum<<endl;
	}
	return 0;
}
