#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

vector<string> v;
unordered_map<string,int> mp;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		v.clear();
		mp.clear();
		FOR(i,0,n-1){
			string s;cin>>s;
			v.push_back(s);
			mp[s]=1;
		}
		string ans;
		for(string i:v){
			int has=0;
			FOR(j,0,i.size()-1){
				string l,r;
				l=i.substr(0,j+1);
				r=i.substr(j+1);
				if(mp[l] and mp[r]) {has=1;break;}
			}
			if(has) ans+='1';
			else ans+='0';
		}
		cout<<ans<<endl;
	}
	return 0;
}