#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	string s,t;
	while(T--){
		int ans=1,cmp=-1;
		cin>>s>>t;
		reverse(all(s));
		reverse(all(t));
		for(char i:t){
			int found=s.find(i);//用 int 而不是 size_t
			if(found!=string::npos and found>cmp){
				//s.erase(found,1);//删除就不能保证先后顺序！
				s[found]='0';
				cmp=found;
			}
			else{ans=0;break;}
		}
		if(ans) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}