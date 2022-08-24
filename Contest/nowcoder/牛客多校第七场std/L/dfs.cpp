#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int n,m;

vector<pii>g[N];

int vis[N];

int w[N],ban[N],u[N],v[N];

int s[N];

void dfs(int x,int f=0)
{
    vis[x]=1;
    for(auto [v,id]:g[x])
    {
        if(v==f)
            continue;
        if(!vis[v])
        {
            dfs(v,x);
            if(!s[v])
                ban[id]=1;
            s[x]+=s[v];
        }
        else if(vis[v]!=2)
            s[x]++,s[v]--;
    }
    vis[x]=2;
}

int ecc;

void gans(int x,int &mx,int &mn,int eid)
{
    vis[x]=eid;
    for(auto [v,id]:g[x])
        if(!ban[id])
        {
            if(!vis[v])
                gans(v,mx,mn,eid);
            if(mx==-1||(w[id]>w[mx]||(w[id]==w[mx]&&id>mx)))
                mx=id;
            if(mn==-1||(w[id]<w[mn]||(w[id]==w[mn]&&id<mn)))
                mn=id;
        }
}

int S,T;

int cnt=1,head[N];

struct Edge{
    int ne,to,w;
}edg[N*4+1];

void build(int u,int v,int w,int rw=0)
{
    ++cnt;
    edg[cnt].to=v;
    edg[cnt].w=w;
    edg[cnt].ne=head[u];
    head[u]=cnt;
    ++cnt;
    edg[cnt].to=u;
    edg[cnt].w=rw;
    edg[cnt].ne=head[v];
    head[v]=cnt;
}

queue<int>q;

int d[N];

bool bfs()
{
    fill(d+S,d+T+1,-1);
    q.push(S);
    d[S]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int tmp=head[x];tmp;tmp=edg[tmp].ne)
        {
            int v=edg[tmp].to;
            if(d[v]!=-1||!edg[tmp].w)
                continue;
            d[v]=d[x]+1;
            q.push(v);
        }
    }
    return d[T]!=-1;
}

int dinic(int x,int mn)
{
    if(x==T||!mn)
        return mn;
    int flow=0,tmpf;
    for(int tmp=head[x];tmp;tmp=edg[tmp].ne)
    {
        int v=edg[tmp].to;
        if(d[v]==d[x]+1&&(tmpf=dinic(v,min(mn,edg[tmp].w)))>0)
        {
            flow+=tmpf;
            mn-=tmpf;
            edg[tmp].w-=tmpf;
            edg[tmp^1].w+=tmpf;
        }
        if(!mn)
            break;
    }
    if(!flow)
        d[x]=-1;
    return flow;
}

vector<int>tp;

int getpath(int x,int T,vector<int>&p)
{
    if(x==T)
    {
        p=tp;
        return 1;
    }
    tp.push_back(x);
    for(int tmp=head[x];tmp;tmp=edg[tmp].ne)
        if(!edg[tmp].w)
        {
            int v=edg[tmp].to;
            if(getpath(v,T,p))
            {
                edg[tmp].w=1;
                return 1;
            }
        }
    tp.pop_back();
    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        // assert(u[i]!=v[i]);
        g[u[i]].push_back({v[i],i});
        g[v[i]].push_back({u[i],i});
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    fill(vis+1,vis+n+1,0);
    int ans=-1,pi=-1,qi=-1;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            int mx=-1,mn=-1;
            gans(i,mx,mn,++ecc);
            if(w[mx]-w[mn]>ans)
                ans=w[mx]-w[mn],pi=mx,qi=mn;
        }
    S=0,T=n+1;
    for(int i=1;i<=n;i++)
        for(auto [v,id]:g[i])
            if(id!=pi&&id!=qi&&i<v)
                build(i,v,1,1);
    build(S,u[pi],1);
    build(S,v[pi],1);
    build(u[qi],T,1);
    build(v[qi],T,1);
    int flow=0;
    while(bfs())
        flow+=dinic(S,INT_MAX);
    assert(flow==2);
    printf("%d\n",ans);
    vector<int>path,U,V;
    getpath(u[pi],T,U);
    tp.clear();
    getpath(v[pi],T,V);
    reverse(V.begin(),V.end());
    for(auto x:U)
        path.push_back(x);
    for(auto x:V)
        path.push_back(x);
    printf("%d\n",(int)path.size());
    for(int i=0;i<path.size();i++)
        printf("%d%c",path[i]," \n"[i+1==path.size()]);
}
/*
5 6
1 2 1
1 3 -2
2 3 1
3 4 3
4 5 1
2 5 2
*/