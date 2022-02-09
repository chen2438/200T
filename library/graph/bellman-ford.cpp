#include<bits/stdc++.h>
using namespace std;
#define MAX_E 10000
#define MAX_V 10000
#define INF (1<<30)
struct edge {
	int from,to,cost;
};

edge es[MAX_E];//±ß 
int d[MAX_V];//×î¶Ì¾àÀë 
int V,E;//¶¥µã£¬±ß 

int adt=0;
void add(int u,int v,int w){//¼Ó±ß½¨Ê÷ 
	es[++adt]={v,head[u]};
//	head[u]=adt;
}

void input(){
	cin>>V>>E;
	int u,v,w;
	for(int i=1;i<=E;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
//	E*=2;
}

void shortest_path(int s){
	for(int i=1;i<=V;i++)d[i]=INF;
	d[s]=0;
	while(true){
		bool update=false;
		for(int i=1;i<=E;i++){
			edge e=es[i];
			if(d[e.from]!=INF and d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
			//	cout<<333<<endl;
				update=true;
			}
		}
		if(!update) break;
	}
}

int main(){
	input();
	shortest_path(0);
	for(int i=1;i<=V;i++){
		cout<<d[i]<<endl;
	}
} 
