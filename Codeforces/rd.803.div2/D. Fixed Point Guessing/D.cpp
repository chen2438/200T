#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

bool judge(int l,int r){
	int x,cnt=0;
	FOR(i,l,r){
		cin>>x;
		if(l<=x and x<=r) cnt++;
	}
	if(cnt%2==1) return true;
	else return false;
}

int ask(int l,int r){
	int mid=(l+r)/2;
	cout<<"? "<<l<<' '<<mid<<endl;
	//cout.flush(); endl已经有flush()的作用
	if(judge(l,mid)){
		if(l==r) return l;
		return ask(l,mid);
	}
	else return ask(mid+1,r);
	return 0;
}

signed main(){
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int ans=ask(1,n);
		cout<<"! "<<ans<<endl;
		//cout.flush();
	}
	return 0;
}