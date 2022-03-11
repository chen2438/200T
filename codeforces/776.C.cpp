#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
#define scan(a) scanf("%d",&(a))
#define elif else if

const int maxn=778;
int matx[maxn][maxn];
int n,m;

struct node{
	int a,b,c,d;
};

bool j1(){
	FOR(i,1,n){
		FOR(j,1,m){
			if(i%2==1){
				if(j%2==1 and matx[i][j]) return false;
			}
			if(i%2==0){
				if(j%2==0 and matx[i][j]) return false;
			}
		}
	}
	return true;
}

int main(){
	int t;cin>>t;
	while(t--){
		char o;
		cin>>n>>m;
		mem(matx);
		FOR(i,1,n){
			FOR(j,1,m){
				cin>>o;
				if(o=='1') matx[i][j]=1;
				elif(o=='0') matx[i][j]=0;
			}
		}

		if(j1()){
			cout<<0<<'\n';
			continue;
		}

		node ans[10007];
		int cnt=1;
		if(matx[1][1]){
			cout<<-1<<'\n';
			continue;
		}
		int flag=1;
		FOR(i,1,n){
			if(matx[i][1]){
				if(!matx[i-1][1]){
					ans[cnt++]={i-1,1,i,1};
				}
				else{
					flag=0;
				}
			}
		}
		FOR(j,1,m){
			if(matx[1][j]){
				if(!matx[1][j-1]){
					ans[cnt++]={1,j-1,1,j};
				}
				else{
					flag=0;
				}
			}
		}
		if(!flag){
			cout<<-1<<'\n';
			continue;
		}
		FOR(i,2,n){
			FOR(j,2,m){
				if(matx[i][j]){
					if(!matx[i][j-1]){
						ans[cnt++]={i,j-1,i,j};
					}
					elif(!matx[i-1][j]){
						ans[cnt++]={i-1,j,i,j};
					}
					elif(!matx[i-1][j-1]){
						ans[cnt++]={i-1,j-1,i,j};
					}
					else{
						flag=0;
					}
				}
			}
			if(!flag) break;
		}
		if(!flag){
			cout<<-1<<'\n';
		}
		else{
			cout<<cnt-1<<'\n';
			FOR(i,1,cnt-1){

				cout<<ans[i].a<<' '<<ans[i].b<<' '<<ans[i].c<<' '<<ans[i].d<<'\n';
			}
		}

	}
	return 0;
}