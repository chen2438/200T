#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset((a),0,sizeof(a))
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
			for(int j=0;j<i.size();j++){
				string l,r;
				FOR(k,0,j) l+=i[k];
				FOR(k,j+1,i.size()-1) r+=i[k];
				if(mp[l] and mp[r]) ans+='1';
				else ans+='0';
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}