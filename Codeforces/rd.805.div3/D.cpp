#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define PII pair<int,int>
using namespace std;
//char s[200007];
int buck[200007];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		memset(buck,0,sizeof buck);
		vector<int> gs[30];
		string s;
		int p;
		cin>>s>>p;
		int sum=0;
		FOR(i,0,s.size()-1){
			//buck[s[i]-'a'+1]++;
			gs[s[i]-'a'+1].push_back(i);
			sum+=s[i]-'a'+1;
		}
		string ans=s;
		ROF(i,26,1){
			if(sum<=p)break;
			if(gs[i].size()){
				for(auto j:gs[i]){
					if(sum<=p)break;
					sum-=i;
					ans[j]='!';
				}
			}
		}
		FOR(i,0,ans.size()-1){
			if(ans[i]!='!')cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}