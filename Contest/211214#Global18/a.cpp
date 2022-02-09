#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	int a[1000];
	while(T--){
		int n;
		cin>>n;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		int avg=sum/n;
		if(avg*n==sum){
			cout<<0<<endl;
		//	continue;
		}
		else{
			cout<<1<<endl;
		}
		
	}
	return 0;
}
