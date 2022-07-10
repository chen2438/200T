#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define PII pair<int,int>
using namespace std;

unordered_map<string,int> ml;
unordered_map<string,int> mr;
//#define int long long
//int a[200007];
//PII ga[200007];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		ml.clear();
		mr.clear();
		int n,k;cin>>n>>k;
		FOR(i,1,n){
			string s;cin>>s;
			if(ml[s]!=0) mr[s]=i;
			else ml[s]=mr[s]=i;
		}
		while(k--){
			string l,r;cin>>l>>r;
			if(ml[l]==0 or ml[r]==0) {cout<<"NO"<<endl;continue;}
			if(ml[l]<=mr[r]) {cout<<"YES"<<endl;continue;}
			else {cout<<"NO"<<endl;continue;}
		}
	}
	return 0;
}