#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;

const int maxn=507;
int a[maxn],b[maxn];

void solve(int val){
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		mem(a),mem(b);
		FOR(i,0,n-1){
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b,b+n);
		int pre=b[0],cnt=1,flag=0;
		FOR(i,1,n-1){
			if(pre==b[i]){
				cnt++;
			}
			else{
				if(cnt%2==1){
					flag=1;
					break;
				}
				else{
					pre=b[i];
					cnt=1;
				}
			}
		}
		if(flag){
			cout<<"-1\n";
			continue;
		}
		solve(a[0]);

	}
	return 0;
}