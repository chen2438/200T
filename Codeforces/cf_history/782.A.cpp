#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n,r,b;
		cin>>n>>r>>b;//7 4 3
		int duan=b+1;//4
		int tmp=r/duan;//1
		int yu=r%duan;//0
		int cnt=0;
		FOR(j,1,yu){
			FOR(i,1,tmp+1){
				cout<<"R";cnt++;
			}
			cout<<"B";cnt++;
		}
		//cout<<endl;
		while(cnt<n){
			FOR(i,1,tmp){
				cout<<"R";cnt++;
			}
			if(cnt!=n){cout<<"B";cnt++;}
		}
		
		cout<<endl;
	}
	return 0;
}