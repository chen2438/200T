#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll sx,sy,vx,vy;
ll minx=100;
ll a[10][10];
ll n[8][2]= {{-2,-1},{2,1},{-2,1},{2,-1},{-1,-2},{1,2},{-1,2},{1,-2}};
//ll n[8][2]= {1,2,2,1,-1,2,2,-1,1,-2,-2,1,-1,-2,-2,-1};
void dfs(ll x,ll y,ll s) {
	if(x==vx&&y==vy) {
		minx=min(s,minx);
		return ;
	}
	if(s>minx) {
		return ;
	}
	if(x<1||x>8||y<1||y>8) {
		return ;
	}
	for(ll i=0; i<8; i++) {
		ll tx=x+n[i][0],ty=y+n[i][1];
		if(tx>=1&&tx<=8&&ty>=1&&ty<=8) {
			if(a[tx][ty]==0) {
				a[tx][ty]=1;
				dfs(tx,ty,s+1);
				a[tx][ty]=0;
			}
		}
	}
}
int main() {
	string s,e;
	while(cin>>s>>e) {
		sx=s[0]-'a'+1;
		sy=s[1]-'0';
		vx=e[0]-'a'+1;
		vy=e[1]-'0';
		
		memset(a,0,sizeof(a));
		minx=100;
		dfs(sx,sy,0);
		cout<<"To get from "<<s<<" to "<<e<<" takes "<<minx<<" knight moves.\n";
	}
	return 0;
}
