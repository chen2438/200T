#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		string s;
		cin>>s;
		int len=s.size();
		char now='a';
		FOR(i,0,len-1){
			if(s[i]=='?'){
				now='a';
				if(i>0 and s[i-1]==now) now++;
				if(i<len-1 and s[i+1]==now) now++;
				if(i>0 and s[i-1]==now) now++;
				s[i]=now;
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}