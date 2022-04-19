#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int maxn=2e5+7;
int n,k,s[maxn],ans[maxn];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		mem(s);
		mem(ans);
		cin>>n>>k;
		char o;
		FOR(i,1,n){
			cin>>o;
			s[i]=o-'0';
		}
		if(k==0){
			FOR(i,1,n)cout<<s[i];
			cout<<"\n0";
			FOR(i,2,n)cout<<" 0";
			cout<<'\n';
			continue;
		}
		int tk=k;
		if(k%2==1){
			FOR(i,1,n){
				s[i]=abs(s[i]-1);
				//cout<<s[i];
			}//cout<<endl;
		}

		{
			FOR(i,1,n){
				if(tk==0)break;
				if(s[i]==0){
					s[i]=1;
					--tk;
					ans[i]=1;
				}
			}
			//cout<<"tk="<<tk<<endl;
			if(tk>0){
				ans[n]+=tk;
				if(tk%2==1){
					s[n]=0;
				}
			}
		}
		FOR(i,1,n){
			cout<<s[i];
		}cout<<'\n';
		FOR(i,1,n){
			cout<<ans[i]<<" ";
		}cout<<'\n';
	}
	return 0;
}