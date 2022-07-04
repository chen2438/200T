//web:https://www.acwing.com/problem/content/2005/
//begin:4.30 16:36
//end:4.30 16:42
//judge:AC
//optimize:no
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

//const int maxn=5e4+7;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;cin>>s;
	int l=0,ans=0;
	FOR(i,0,s.size()-2){
		if(s[i]=='(' and s[i+1]=='('){
			l++;
		}
		else if(s[i]==')' and s[i+1]==')'){
			ans+=l;
		}
	}
	cout<<ans<<endl;
	return 0;
}