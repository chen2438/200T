#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int task[200007];
int stat[200007];

struct BIT{
    #define MAXN (int)2e7+7
    #define INF (int)1e9+7
    //const static int MAXN = 2e7+7;
    //const static int INF = 1e9+7;
    #define maxs(a,b) ((a)>(b)?(a):(b))
    #define mins(a,b) ((a)<(b)?(a):(b))
    struct node{
        int val,i;//数值,原始下标
        bool operator<(const node &x)const{
            return val<x.val;
        }
        bool operator>(const node &x)const{
            return val>x.val;
        }
    };
    int n;
    node v[MAXN],mi[MAXN],ma[MAXN];
    int lowbit(int x){
        return x&(-x);
    }
    void update(int x){
        v[x].i=x;
        while(x<=n){
            mi[x]=ma[x]=v[x];
            int lowx=lowbit(x);
            for(int i=1;i<lowx;i<<=1){
                mi[x]=mins(mi[x],mi[x-i]);
                ma[x]=maxs(ma[x],ma[x-i]);
            }
            x+=lowbit(x);
        }       
    }
    node qmin(int l,int r){//查最小值
        node ans=(node){INF,0};
        while(r>=l){
            ans=min(ans,v[r]);
            for(r=r-1;r-lowbit(r)>=l;r-=lowbit(r))
                ans=min(ans,mi[r]);
        }
        return ans;
    }
    node qmax(int l,int r){//查最大值
        node ans=(node){-INF,0};
        while(r>=l){
            ans=max(ans,v[r]);
            for(r=r-1;r-lowbit(r)>=l;r-=lowbit(r))
                ans=max(ans,ma[r]);
        }
        return ans;
    }
}tr;

//要避免浪费
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;

	while(T--){
		memset(task,0,sizeof task);
		int n,m; cin>>n>>m;
		FOR(i,1,n) {
			stat[i]=1;
		}
		FOR(i,1,m){
			int x;cin>>x;
			tr.v[x].val=++task[x];
			tr.update(x);
		}
		int sum=m;
		int ans=0;
		while(sum>0){
			//cout<<sum<<endl;
			ans++;
			FOR(i,1,n){
				if(sum==0) break;
				if(task[i]>0){
					tr.v[i].val=--task[i];
					tr.update(i);
					stat[i]++;
					sum--;
				}
			}
			FOR(i,1,n){
				if(sum==0) break;
				if(stat[i]>ans) continue;
				if(task[i]==0){
					int pos=tr.qmax(1,n).i;
					tr.v[pos].val=--task[pos];
					tr.update(pos);
					stat[i]+=2;
					sum--;
				}
			}
		}
		FOR(i,1,n){
			ans=max(ans,stat[i]);
		}
		cout<<ans-1<<endl;


	}
	return 0;
}
/*
5
1000 1
3
*/