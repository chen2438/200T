#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int N = 5007;
string s;
int has[N][N];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	int len=s.size();
	int l=0,r=len-1;
	FOR(i,0,len-1){
		if(s[i]=='b' and s[i+1]=='e' and s[i+2]=='a' and s[i+3]=='r') {
			FOR(j,l,i){
			    FOR(k,i+3,r){
			        has[j][k]=1;
			    }
			}
			l=i;
		}
	}
	
	long long ans=0;
	FOR(i,0,len-1){
		FOR(j,i+3,len-1){
			if(has[i][j]) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
