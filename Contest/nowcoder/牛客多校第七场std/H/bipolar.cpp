#include<bits/stdc++.h>
using namespace std;
namespace bipolar
{
	const int MAXN=111111;
	int low[MAXN],dfn[MAXN],pa[MAXN];
	int idx;
	vector<int> G[MAXN];
	vector<int> ord;
	void dfs(int u)
	{
		dfn[u]=++idx;
		low[u]=u;
		for(auto v:G[u])
		{
			if(dfn[v]==0)
			{
				ord.push_back(v);
				dfs(v);
				pa[v]=u;
				if(dfn[low[v]]<dfn[low[u]])
					low[u]=low[v];
			}
			else if(dfn[v]!=0 and dfn[v]<dfn[low[u]])
				low[u]=v;
		}
	}
	struct node
	{
		int val;
		node *pre,*nxt;
	}*head,*tail,npool[MAXN];
	int top;
	node *pos[MAXN];
	node *nn(int x)
	{
		node *tmp=&npool[top++];
		tmp->val=x;tmp->pre=tmp->nxt=nullptr;
		return tmp;
	}
	void ins_before(int x,int p)
	{
		node *xx=nn(x),*pp=pos[p];
		pos[x]=xx;
		xx->pre=pp->pre;
		if(pp->pre)pp->pre->nxt=xx;
		else head=xx;
		xx->nxt=pp;
		pp->pre=xx;
	}
	void ins_after(int x,int p)
	{
		node *xx=nn(x),*pp=pos[p];
		pos[x]=xx;
		xx->nxt=pp->nxt;
		if(pp->nxt)pp->nxt->pre=xx;
		else tail=xx;
		xx->pre=pp;
		pp->nxt=xx;
	}
	vector<int> solve(int n,int S,int T)
	{
		vector<int> sgn(n+5);
		dfn[S]=++idx;
		dfs(T);
		pos[S]=head=tail=nn(S);
		for(int i=1;i<=n;i++)sgn[i]=1;
		sgn[S]=-1;
		ins_after(T,S);
		for(auto u:ord)
		{
			if(sgn[low[u]]<0)
			{
				ins_before(u,pa[u]);
			}
			else
			{
				ins_after(u,pa[u]);
			}
			sgn[pa[u]]=-sgn[low[u]];
		}
		vector<int> ret;
		for(auto z=head;z;z=z->nxt)
		{
			ret.push_back(z->val);
		}
		return ret;
	}
}
namespace test
{
	vector<vector<int>> G;
	vector<int> ins,dfn,low;
	int ind,bcc;
	stack<int> s;
	void dfs(int u,int p)
	{
		dfn[u]=low[u]=++ind;
		s.push(u);ins[u]=1;
		for(auto v:G[u])
		{
			if(v==p)continue;
			if(not ins[v])
			{
				dfs(v,u);
				low[u]=min(low[u],low[v]);
				if(low[v]>=dfn[u])
				{
					++bcc;
					int vv;
					do
					{
						vv=s.top();
						ins[vv]=2;
						s.pop();
					}
					while(v!=vv);
				}
			}
			else if(ins[v]==1)
				low[u]=min(low[u],dfn[v]);
		}
		if(not p)s.pop();
	}
	int chk(int n)
	{
		ins.resize(n+5);
		dfn.resize(n+5);
		low.resize(n+5);
		ind=0;
		bcc=n;
		dfs(1,0);
		return bcc==n+1;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m,A,B;
	cin>>n>>m>>A>>B;
	vector<int> p(n+5);
	vector<vector<int>> G0(n+5),G(n+5);
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	test::G.resize(n+5);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		bipolar::G[u].push_back(v);
		bipolar::G[v].push_back(u);
		test::G[u].push_back(v);
		test::G[v].push_back(u);
		G0[u].push_back(v);
		G0[v].push_back(u);
	}
	test::G[A].push_back(B);
	test::G[B].push_back(A);
	if(not test::chk(n))
	{
		cout<<-1<<endl;
		return 0;
	}
	auto ord=bipolar::solve(n,A,B);
	vector<int> b(n+5);
	for(int i=0;i<n;i++)
	{
		b[ord[i]]=i+1;
	}
	for(int i=1;i<=n;i++)
		cerr<<b[i]<<' ';
	cerr<<endl;
	vector<int> pa(n+5),sz(n+5),dep(n+5),deg(n+5);
	function<void(int)> dfs0=[&](int u)
	{
		sz[u]=1;
		for(auto v:G0[u])
		{
			if(not dep[v])
			{
				pa[v]=u;
				dep[v]=dep[u]+1;
				G[u].push_back(v);
				deg[u]++;
				dfs0(v);
				sz[u]+=sz[v];
			}
		}
	};
	dep[A]=1;
	dfs0(A);
	vector<int> invb(n+5);
	for(int i=1;i<=n;i++)
	{
		invb[b[i]]=i;
	}
	vector<int> ok(n+5),done(n+5),sp(n+5);
	auto chk=[&]()
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			ok[i]=(p[i]==b[i]);
			cnt+=ok[i];
		}
		return cnt==n;
	};
	vector<vector<int>> op;
	auto rot=[&](int x)
	{
//		cerr<<"rot "<<x<<endl;
		vector<int> tmppos;
		int t=x;
		while(t!=A)
		{
			tmppos.push_back(t);
			t=pa[t];
		}
		tmppos.push_back(A);
		t=p[A];
		for(int i=tmppos.size()-1;i>0;i--)
		{
			p[tmppos[i]]=p[tmppos[i-1]];
		}
		p[x]=t;
//		cerr<<"rot "<<x<<endl;
//		for(int i=1;i<=n;i++)cerr<<p[i]<<' ';
//		cerr<<endl;
		reverse(tmppos.begin(),tmppos.end());
		op.push_back(tmppos);
	};
//	for(int i=1;i<=n;i++)cerr<<pa[i]<<' ';
//	cerr<<endl;
	while(not chk())
	{
//		cerr<<"go! "<<endl;
//		for(int i=1;i<=n;i++)cerr<<p[i]<<' ';
//		cerr<<endl;
		fill(sp.begin(),sp.end(),0);
		vector<int> down(n+5);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(not done[b[i]] and deg[i]==0)
			{
				sp[b[i]]=1;
				cnt++;
				down[i]=i;
				int u=i;
				while(u!=A and deg[pa[u]]==1)
				{
					sp[b[pa[u]]]=1;
					cnt++;
					down[pa[u]]=i;
					u=pa[u];
				}
			}
		}
//		cerr<<"sp: ";
//		for(int i=1;i<=n;i++)if(sp[i])cerr<<i<<' ';
//		cerr<<endl;
		vector<int> used(n+5);
		while(cnt)
		{
//			cerr<<"test "<<cnt<<endl;
			if(sp[p[A]])
			{
//				cerr<<"case 1"<<endl;
				cnt--;
				used[p[A]]=1;
				int u=down[invb[p[A]]];
				while(sp[p[u]] and used[p[u]] and dep[invb[p[u]]]>dep[invb[p[A]]])
					u=pa[u];
				rot(u);
			}
			else
			{
//				cerr<<"case 2"<<endl;
				int maxp=-1;
				for(int i=1;i<=n;i++)
				{
					if(sp[p[i]] and not used[p[i]])
					{
						if(maxp==-1 or dep[i]>dep[maxp])
						{
							maxp=i;
						}
					}
				}
				rot(maxp);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(invb[i]!=A and sp[i])
				deg[pa[invb[i]]]--;
			if(sp[i])
				done[i]=1;
		}
	}
	cout<<op.size()<<endl;
	for(auto &vec:op)
	{
		cout<<vec.size();
		for(auto x:vec)cout<<' '<<x;
		cout<<endl;
	}
	
	return 0;
}