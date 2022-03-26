#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

const int maxn=5e5+7;

struct node{
	int x,y;
}a[maxn];

stack<node> st;

int main(){
	freopen("stack.in","r",stdin);
	freopen("stack.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	FOR(i,1,n){
		cin>>a[i].x;
	}
	FOR(i,1,n){
		cin>>a[i].y;
	}
	int l,r;
	FOR(i,1,q){
		int cnt=0;
		cin>>l>>r;
		st=stack<node>();
		FOR(j,l,r){
			if(st.empty() or a[j].x!=st.top().x and a[j].y<st.top().y){
				st.push({a[j].x,a[j].y});
			}
			else{
				while(!st.empty() and (a[j].x==st.top().x or a[j].y>=st.top().y)){
					st.pop();
				}
				st.push({a[j].x,a[j].y});
			}
			if(st.size()==1){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}