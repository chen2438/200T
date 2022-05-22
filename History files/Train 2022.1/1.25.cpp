//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

struct node{
	int di,fu;
}sta[10007];

bool cmp(node x,node y){
	return x.di<y.di;
}

int N,L,P;
priority_queue<int,vector<int>,less<int> > heap;

int main(){
	cin>>N;
	int di,fu;
	FOR(i,0,N-1){
		cin>>di>>fu;
		sta[i]={di,fu};
	}
	cin>>L>>P;
	FOR(i,0,N-1){
		sta[i].di=L-sta[i].di;
	}

	sort(sta,sta+N,cmp);
	sta[N++]={L,0};

	int ans=0,pos=0,fue=P;

	FOR(i,0,N-1){
		int di=sta[i].di-pos;
		while(fue<di){
			if(heap.empty()){
				cout<<-1;
				return 0;
			}
			fue+=heap.top();
			heap.pop();
			ans++;
		}
		fue-=di;
		pos=sta[i].di;
		heap.push(sta[i].fu);
	}
	cout<<ans<<endl;
	return 0;
}

/*
3
5 1
8 8
8 7
9 1
*/