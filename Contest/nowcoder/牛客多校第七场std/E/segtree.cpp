#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-x))
using namespace std;

const int maxn = 410000;

int n;
int a[maxn];
struct node
{
	int i,c;
}b[maxn];
inline bool cmp(const node &k1,const node &k2){ return k1.c<k2.c; }

int s1[maxn],s2[maxn];
void add(int x,int c,int sum[])
{
	for(;x<=n;x+=lowbit(x)) sum[x]+=c;
}
int query(int x,int sum[])
{
	int re=0;
	for(;x;x-=lowbit(x)) re+=sum[x];
	return re;
}
ll ans1[maxn],ans2[maxn];
int num[maxn];
struct segment
{
	int seg[maxn<<2],flag[maxn<<2];
	void build(const int x,const int l,const int r)
	{
		seg[x]=n+1; flag[x]=0;
		if(l==r) return;
		int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
		build(lc,l,mid); build(rc,mid+1,r);
	}
	void pushdown(const int x)
	{
		if(flag[x])
		{
			int lc=x<<1,rc=lc|1;
			int &cc=flag[x];
			seg[lc]+=cc; flag[lc]+=cc;
			seg[rc]+=cc; flag[rc]+=cc;
			cc=0;
		}
	}
	int loc,c;
	void upd(const int x,const int l,const int r)
	{
		if(l==r)
		{
			seg[x]=c;
			return;
		}
		pushdown(x);
		int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
		if(loc<=mid) upd(lc,l,mid);
		else upd(rc,mid+1,r);
		seg[x]= min(seg[lc],seg[rc]);
	}
	int lx,rx;
	void add(const int x,const int l,const int r)
	{
		if(rx<l||r<lx) return;
		if(lx<=l&&r<=rx)
		{
			seg[x]+=c;
			flag[x]+=c;
			return;
		}
		pushdown(x);
		int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
		add(lc,l,mid); add(rc,mid+1,r);
		seg[x]=min(seg[lc],seg[rc]);
	}
	vector<int>V;
	void findx(const int x,const int l,const int r)
	{
		if(seg[x]>0) return;
		if(l==r)
		{
			seg[x]=n+1;
			V.push_back(l);
			return;
		}
		pushdown(x);
		int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
		findx(lc,l,mid); findx(rc,mid+1,r);
		seg[x]=min(seg[lc],seg[rc]);
	}
}seg;

void calc(ll ans[])
{
	seg.build(1,1,n);
	for(int i=0;i<=n;i++) s1[i]=s2[i]=0;
	
	for(int i=1;i<=n;i++)
	{
		num[i]= query(a[i],s1);
		add(a[i],1,s1);
		
		add(a[i],1,s2);
		ans[i]= ans[i-1]+ query(n,s2)-query(a[i],s2);
		
		seg.lx=a[i]+1,seg.rx=n,seg.c=-1;
		if(seg.lx<=seg.rx) seg.add(1,1,n);
		
		seg.loc=a[i], seg.c=num[i];
		seg.upd(1,1,n);
		
		seg.V.clear();
		seg.findx(1,1,n);
		for(auto j:seg.V) add(j,-1,s2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		b[i]=(node){i,a[i]};
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++) a[b[i].i]=i;
	
	calc(ans1);
	for(int i=1;i<=n;i++) a[i]=n-a[i]+1;
	calc(ans2);
	
	for(int i=1;i<=n;i++) cout<<min(ans1[i],ans2[i])<<'\n';
	
	return 0;
}
