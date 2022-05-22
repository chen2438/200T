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
	FOR(i,1,N){
		cin>>di>>fu;
		sta[i]={di,fu};
	}
	cin>>L>>P;
	sta[N+1]={L,P};
	sta[0]={0,0};

	sort(sta,sta+N+2,cmp);

	int ans=0;
	di=0,fu=0;
	heap.push(P);
	ROF(i,N+1,1){
		di=sta[i].di-sta[i-1].di;
		if(fu<di){
			while(fu<di){
				if(heap.empty()){
					cout<<-1;
					return 0;
				}
			//	cout<<heap.top()<<endl;
				fu+=heap.top();
				heap.pop();
				ans++;
			}
		}
		fu-=di;
		heap.push(sta[i-1].fu);
	}
	cout<<ans-1<<endl;
	return 0;
}
