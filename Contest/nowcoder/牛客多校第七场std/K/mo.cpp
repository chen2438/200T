#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005,M=2000005,lim=350;
typedef long long LL;
int n,m,a[N],id[N],s[2][M];
struct D{int id,l,r;} dat[N];
LL ans[N],nw;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool cmp(D a,D b)
{
	return id[a.l]==id[b.l]?a.r<b.r:a.l<b.l;
}

void add(int x)
{
	nw+=s[x&1][a[x]];
	++s[x&1][a[x]];
}

void del(int x)
{
	--s[x&1][a[x]];
	nw-=s[x&1][a[x]];
}

LL get(LL len)
{
	return len*(len+1)/2;
}

int main()
{
//	freopen("g.in","r",stdin);
//	freopen("g.out","w",stdout);
	n=getint(),m=getint();
	rep(i,1,n) a[i]=(getint()-1)^a[i-1],id[i]=(i-1)/lim+1;
	rep(i,1,m) dat[i].l=getint(),dat[i].r=getint(),dat[i].id=i,ans[i]=get(dat[i].r-dat[i].l+1);
	sort(dat+1,dat+1+m,cmp);
	int l=1,r=0;
	s[0][0]=1;
	rep(i,1,m)
	{
		while(r<dat[i].r) add(++r);
		while(r>dat[i].r) del(r--);
		while(l>dat[i].l) --l,add(l-1);
		while(l<dat[i].l) del(l-1),++l;
		ans[dat[i].id]-=nw;
	}
	rep(i,1,m) printf("%lld\n",ans[i]);
	return 0;
}
