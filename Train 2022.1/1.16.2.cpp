#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[510][510]{};
int d[5][2]={0,0,1,0,-1,0,0,1,0,-1};
int n,m,oo,r,c;
struct node
{
	int x;
	int y;
	int step;
}nw,nt;
int BFS(int x,int y)
{
	queue<node>q;
	int xx,yy,zz;
	nw.x=x;
	nw.y=y;
	nw.step=0;
	q.push(nw);
	while(!q.empty())
	{
		nw=q.front();
		q.pop();
		for(int i=1;i<=4;++i)
		{
			xx=nw.x+d[i][0];
			yy=nw.y+d[i][1];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]==0)
			{
				/*
				nt.x=xx;
				nt.y=yy;
				nt.step=nw.step+1;
				*/
				a[nw.x][nw.y]=1;
				//if(xx==r&&yy==c) return nt.step;
				if(xx==r&&yy==c) return nw.step+1;
				//q.push(nt);
				q.push((node){xx,yy,nw.step+1});
				
				
			}
		}
	}
	return -1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>oo;
		int x,y;
		for(int i=1;i<=n;++i)
		{
			string s;
			cin>>s;
			for(int j=0;j<m;++j)
				if(s[j]=='#') a[i][j+1]=1;
				else if(s[j]=='.') a[i][j+1]=0;
				else if(s[j]=='S') x=i,y=j+1;
				else if(s[j]=='E') r=i,c=j+1;
		}
		int re=BFS(x,y);
		cout<<re<<endl;
	}
	return 0;
}
