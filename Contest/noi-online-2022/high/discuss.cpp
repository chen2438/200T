#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

const int maxn=1e4+7;

bool a[maxn][maxn];

int n;

bool ch1(int x,int y){
	FOR(i,1,n){
		if(a[x][i] and a[y][i]){
			return true;
		}
	}
	return false;
}

bool ch2(int x,int y){
	int ans=0;
	FOR(i,1,n){
		if(a[x][i] and !a[y][i]){
			ans++;break;
		}
	}
	FOR(i,1,n){
		if(!a[x][i] and a[y][i]){
			ans++;break;
		}
	}
	if(ans==2)return true;
	else return false;
}


int main(){
	freopen("discuss.in","r",stdin);
	freopen("discuss.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		mem(a);
		cin>>n;
		FOR(i,1,n){
			int m;cin>>m;
			FOR(j,1,m){
				int mi;cin>>mi;
				a[j][mi]=1;
			}
		}
		int f=0;
		FOR(i,1,n){
			FOR(j,i+1,n){
				if(ch1(i,j) and ch2(i,j)){
					f=1;
					cout<<"YES\n";
					cout<<i<<" "<<j<<'\n';
					break;
				}
			}
			if(f)break;
		}
		if(!f)cout<<"NO\n";

	}
	
	return 0;
}