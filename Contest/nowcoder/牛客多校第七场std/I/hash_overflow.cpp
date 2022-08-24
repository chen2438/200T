#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid ((l+r)>>1)

using namespace std;
typedef long long LL;
const int N=200005,M=28;
const int base=1000000009;
char s[N];
int n,m,a[N],c[N],nxt[N][M];
int lst[M],pos[M<<1],pt[N][M],p[N];
LL bin[N],hsh[N];

LL gethsh(int l,int r)
{
	return hsh[l]-hsh[r+1]*bin[r-l+1];
}

int getc(int x,int c)
{
	int p=nxt[x][c],rt=0;
	rep(i,0,m-1) if(nxt[x][i]<p) ++rt;
	return rt;
}

void init()
{
	rep(i,1,n) a[i]=s[i]-'a';
	rep(i,1,n)
	{
		if(lst[a[i]]) c[i]=i-lst[a[i]];
		lst[a[i]]=i;
	}
	rep(i,0,m-1) nxt[n+1][i]=n+1;
	repd(i,n,1)
	{
		rep(j,0,m-1) nxt[i][j]=nxt[i+1][j];
		nxt[i][a[i]]=i;
		rep(j,0,m-1) pt[i][j]=nxt[i][j];
		sort(pt[i],pt[i]+m);
	}
	bin[0]=1;
	rep(i,1,n) bin[i]=bin[i-1]*base;
	repd(i,n,1) hsh[i]=hsh[i+1]*base+c[i];
}

bool cmp(int x,int y)
{
	int l=-1,r=-1;
	int px=0,py=0,p=0;
	while(px<m && py<m)
	{
		int nw;
		if(pt[x][px]-x<pt[y][py]-y) nw=pt[x][px++]-x+1;
		else nw=pt[y][py++]-y+1;
		if((!p || pos[p]<nw) && nw<=n-max(x,y)+1) pos[++p]=nw;
	}
	while(px<m)
	{
		int nw=pt[x][px++]-x+1;
		if((!p || pos[p]<nw) && nw<=n-max(x,y)+1) pos[++p]=nw;
	}
	while(py<m)
	{
		int nw=pt[y][py++]-y+1;
		if((!p || pos[p]<nw) && nw<=n-max(x,y)+1) pos[++p]=nw;
	}
	LL dx=0,dy=0;
	rep(i,1,p)
	{
		LL tx=dx,ty=dy;
		int t=pos[i];
		if(nxt[x][a[x+t-1]]==x+t-1) tx=dx-c[x+t-1]*bin[t-1];
		if(nxt[y][a[y+t-1]]==y+t-1) ty=dy-c[y+t-1]*bin[t-1];
		LL X=gethsh(x,x+t-1)+tx;
		LL Y=gethsh(y,y+t-1)+ty;
		if(X!=Y)
		{
			l=pos[i-1],r=t-1;
			break;
		}
		dx=tx;
		dy=ty;
	}
	if(l==-1 && r==-1) l=pos[p],r=n-max(x,y)+1;
	while(l<=r)
	{
		LL X=gethsh(x,x+mid-1)+dx;
		LL Y=gethsh(y,y+mid-1)+dy;
		if(X==Y) l=mid+1;
		else r=mid-1;
	}
	--l;
	if(l==n-max(x,y)+1) return x>y;
	return getc(x,a[x+l])<getc(y,a[y+l]);
}

void solve()
{
	rep(i,1,n) p[i]=i;
	sort(p+1,p+1+n,cmp);
}

int main()
{
//	freopen("g.in","r",stdin);
	scanf("%d%d",&n), m = 26;
	scanf("%s",s+1);
	init();
	solve();
	rep(i,1,n) printf("%d ",p[i]);
	puts("");
	return 0;
}