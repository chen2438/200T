#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

vector<int> a;
int b[200007];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		a.clear();
		a.push_back(0);
		memset(b,0,sizeof b);
		int n;cin>>n;
		FOR(i,1,n){
			/*FOR(j,1,n){
				cout<<b[j]<<" ";
			}cout<<endl;*/
			if(b[i]==0){
				int ind=i;
				while(1){
					if(ind>n or b[ind]==1)break;
					b[ind]=1;
					a.push_back(ind);
					ind*=2;
				}
				b[i]=1;
			}
		}
		//cout<<a.size()<<endl;
		int ans=0;
		//FOR(i,1,n-1) if(a[i]*2==a[i+1])ans++;
		cout<<2<<endl;
		FOR(i,1,n){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}


