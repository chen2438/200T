#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

string d_to_oth(int n,int radix){
	int flag=-1;
	string ans="";
	if(n<0){
		flag=1;
		n=-n;
	}
	do{
		int t=n%radix;
		if(t>=0 and t<=9) ans+=t+'0';
		else ans+=t-10+'A';
		n/=radix;
	}while(n!=0);
	reverse(ans.begin(),ans.end());
	if(flag==1) ans="-"+ans; 
	return ans;	
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n,x,y;
		cin>>n>>x>>y;
		string s1=d_to_oth(n,x);
		string s2=d_to_oth(n,y);
		int cnt1=0,cnt2=0;
		for(auto i:s1){
			if(i=='1')cnt1++;
		}
		for(auto i:s2){
			if(i=='1')cnt2++;
		}
		if(cnt1>cnt2)cout<<">\n";
		else if(cnt1==cnt2) cout<<"=\n";
		else cout<<"<\n";
	}
	return 0;
}