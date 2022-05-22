#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

char matx[1007][1007];
string md="???xx?x??x?xxxxx?x";

int Find(int x,int y){
	int _i=0;
	FOR(i,0,5){
		FOR(j,0,2){
			if(md[_i]=='?'){
				if(matx[i+x][j+y]!='?')return 0;
			}
			_i++;
			//if(md[_i++]!=matx[i+x][j+y])return 0;
		}
	}
	return 1;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	int sum1=0,sum2=0;
	FOR(i,0,n-1){
		FOR(j,0,m-1){
			char c;cin>>c;
			matx[i][j]=c;
			if(c=='?')sum1++;
		}
	}
	FOR(i,0,n-1){
		FOR(j,0,m-1){
			if(matx[i][j]=='?' and i+5<=n and j+2<=m){
				//cout<<i<<" "<<j<<endl;
				sum2+=Find(i,j);
			}
		}
	}
	cout<<sum1<<" "<<sum2+sum1;

	return 0;
}