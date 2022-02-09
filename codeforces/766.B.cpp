#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a));
using namespace std;
int m,n;

struct node{
	int i,j;
	float dist;
}dis[100007];

bool cmp(node x, node y){
	return x.dist<y.dist;
}

float CalDis(float x1,float y1,float x2,float y2){
	return fabs(x1-x2)+fabs(y1-y2);
}

int FindCorner(int x,int y){
	int cor[4];
	cor[0]=CalDis(1,1,x,y);
	cor[1]=CalDis(1,n,x,y);
	cor[2]=CalDis(m,1,x,y);
	cor[3]=CalDis(m,n,x,y);
	sort(cor,cor+4);
	return cor[3];
}

int main(){
	int T;
	cin>>T;
	float midm,midn;
	int cnt,ans;
	while(T--){
		mem(dis);
		cin>>m>>n;
		midm=(1.0+m)/2.0;
		midn=(1.0+n)/2.0;
		cnt=0;
		
		FOR(i,1,m)
			FOR(j,1,n)
				dis[cnt++]={i,j,CalDis(i,j,midm,midn)};
		
		sort(dis,dis+n*m,cmp);
		FOR(k,0,n*m-1){
			ans=FindCorner(dis[k].i,dis[k].j);
			cout<<ans<<" ";
		}
		cout<<endl;
	}
	return 0;
}
