#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define maxn 200000
int tree[200007][20];
int ansbit[20];

int lowbit(int k){
    return k & -k;
}

void add(int x,int k,int bit){
    while(x<=maxn){
    	tree[x][bit]+=k;
        x+=lowbit(x);
	}
}

int sum(int x,int bit){
	int ans=0;
	while(x!=0){
		ans+=tree[x][bit];
		x-=lowbit(x);
	}
	return ans;
}

void init(){
	int inbit;
	for(int i=1;i<=200000;++i){
		for(int j=17;j>=0;--j){
			if(i&(1<<j)) inbit=1;
			else inbit=0;
			add(i,inbit,j);
		}
	}
}
	
int main(){
   	int T,l,r;
   	init();
	cin>>T;
	while(T--){
		cin>>l>>r;
		memset(ansbit,0,sizeof(ansbit));
		for(int j=0;j<=17;j++){
			ansbit[j]=sum(r,j)-sum(l-1,j);
		}
		int max0=0;
		for(int i=0;i<=17;i++){
			max0=max(ansbit[i],max0);
		}
		cout<<r-l+1-max0<<endl;
	}
	return 0;
}

