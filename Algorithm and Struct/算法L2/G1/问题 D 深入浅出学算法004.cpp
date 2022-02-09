#include<iostream>
using namespace std;
int gcd (int a,int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
int main(){
	int t;
	cin>>t;
	int a[10010]={0};
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)
			cin>>a[j];
		long long sum=a[1];
		for(int j=2;j<=n;j++)
			sum=sum*a[j]/gcd(sum,a[j]);
		cout<<sum<<endl;
	}
	return 0;
}
