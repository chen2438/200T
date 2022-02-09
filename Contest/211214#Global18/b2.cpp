#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;

int a[1000];
int inbit[200007][20];
void init(){
	for(int i=1;i<=200000;i++){
		for(int j=17;j>=0;j--){
			if(val&(1<<j)) inbit[i][j]++;
		}
	}
}

int main(){
	/*
	int at=1;
	for(int i=0;i<20;i++){
		at<<=1;
		a[i]=at-1;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	*/
	int T;
	cin>>T;
	while(T--){
	//	memset(bit,0,sizeof(bit));
		int l,r;
		cin>>l>>r;
		for(int i=l;i<=r;++i){
			pb(i);
		}
		int max0=0;
		for(int i=17;i>=0;i--){
			max0=max(bit[i],max0);
		}
		//cout<<r-l+1-max0<<endl;
		for(int i=17;i>=0;i--){
			cout<<bit[i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}

