#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
#define scan(a) scanf("%d",&(a))
#define elif else if

const int maxn=778;
int matx[maxn][maxn];


int main(){
	int t;cin>>t;
	while(t--){
		int n,m,sum=0;
		char o;
		cin>>n>>m;
		mem(matx);
		FOR(i,1,n){
			FOR(j,1,m){
				cin>>o;
			//	cout<<i<<' ';
				if(o=='1') matx[i][j]=1,sum++;
				elif(o=='0') matx[i][j]=0;
			}
		}
		int ans;
		//while(sum){
			ans=0;
			int st=0,sy=0,gy=0;
			FOR(i,1,n){
				FOR(j,1,m){
					if(!st and matx[i][j]){
					//	cout<<"mod=1,"<<"i="<<i<<",j="<<j<<endl;
						st=1,sy=gy=0;
						sum--;
						sy=j;
						if(!matx[i][j+1]) gy=j+1;
					}
					elif(st and matx[i][j] and !matx[i][j+1] and !gy){
					//	cout<<"mod=2,"<<"i="<<i<<",j="<<j<<endl;
						sum--;
						gy=j;
					}
					elif(st and gy and !matx[i][j] and sy<=j and j<=gy){
					//	cout<<"mod=3,"<<"i="<<i<<",j="<<j<<endl;
						if(matx[i][j+1]) ans=1;
						st=0,sy=gy=0;
					}
					elif(st and matx[i][j] and gy and gy<j){
					//	cout<<"mod=4,"<<"i="<<i<<",j="<<j<<endl;
						ans=1;
					}
				}
				if(ans) break;
			}
		//}
		if(ans) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}