#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		/*
		if(n==1){
			cout<<1<<'\n';
		}
		if(n==2){
			cout<<2<<'\n';
		}
		*/
		if(n%3==0){
			while(n){
				cout<<21;
				n-=3;
			}cout<<'\n';
		}
		if(n%3==1){
			cout<<1;
			n-=1;
			while(n){
				cout<<21;
				n-=3;
			}cout<<'\n';
		}
		if(n%3==2){
			cout<<2;
			n-=2;
			while(n){
				cout<<12;
				n-=3;
			}cout<<'\n';
		}
	}
	return 0;
}