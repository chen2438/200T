#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

int n,tree[2000007];

int lowbit(int k){
    return k & -k;
}

void add(int x,int k){
    while(x<=n){
        tree[x]+=k;
        x+=lowbit(x);
    }
}

int sum(int x){
    int ans=0;
    while(x!=0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}

int k;
int s[507][507],maxsec=INF;
int vst[507];
clock_t st;

void dfs(int pos,int step,int sec){
	//if(maxsec<sec) return;
	if(clock()-st>10000){
		cout<<maxsec;
		exit(0);
	}
	if(step==k-1){
		sec=maxs(sec,s[pos][n]);
		maxsec=mins(sec,maxsec);
		return;
	}
	FOR(i,pos+1,n){
		if(vst[i]==0){
			vst[i]=1;
			dfs(i+1,step+1,maxs(sec,s[pos][i]));
			vst[i]=0;
		}
	}
}

int main(){
    cin>>n>>k;
    int tmp;
    FOR(i,1,n){
        scanf("%d",&tmp);
        add(i,tmp);
    }
    
    FOR(i,1,n){
    	FOR(j,i,n){
    		s[i][j]=sum(j)-sum(i-1);
    	//	cout<<i<<" -> "<<j<<" "<<s[i][j]<<" ";
    	}
    	//cout<<endl;
    }
    st=clock();
    mem(vst);
    vst[1]=1;
    dfs(1,0,inf);
    cout<<maxsec;
    return 0;

}