#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;

const int maxn=1e5+7;
int a[maxn];
priority_queue<int,vector<int>,greater<int>> pq;

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		mem(a);
		int sum=0;
		FOR(i,1,n){
			cin>>a[i];
			sum+=a[i];
		//	pq.push(a[i]);
		}
		if(sum==0){
			cout<<0<<'\n';
			continue;
		}
		//sort(a+1,a+n+1,greater<int>);
		int prepos=0,ans=1;
		while(sum>0){
			int newpos=0,max0=0;
			FOR(i,1,n){
				if(max0<a[i] and i!=prepos){
					max0=a[i];
					newpos=i;
				}
			}
			prepos=newpos;
			a[prepos]--;
			sum--;
		}

	}
	return 0;
}