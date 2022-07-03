#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using ll=long long;
 
const int N = 1e5+7;
int m;
struct node{ll o,L,R,x,l,c;}p[N];
 
int search(ll pos,int l,int r){
	if(l==r) return l;
	int mid=(l+r)/2;
	if(p[mid].L<=pos and pos<=p[mid].R) return mid;
	if(pos<p[mid].L) return search(pos,l,mid-1);
	if(p[mid].R<pos) return search(pos,mid+1,r);
	return -1;
}
 
int ask(ll pos){
	ll i=search(pos,1,m);
	if(p[i].o==1) return p[i].x;
	else{
		int npos=(pos-(p[i].L-1))%p[i].l;
		if(npos==0) npos=p[i].l;
		return ask(npos);
	}
 
	return -1;
}
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>m;
	ll o,L,R,x,l,c;
	FOR(i,1,m){
		cin>>o;
		if(o==1){
			cin>>x;
			L=p[i-1].R+1, R=L, l=0, c=0;
		}
		if(o==2){
			cin>>l>>c;
			L=p[i-1].R+1, R=L+l*c-1, x=0;
		}
		p[i]={o,L,R,x,l,c};
	}
	int n;cin>>n;
	while(n--){
		ll pos;cin>>pos;
		cout<<ask(pos)<<' ';
	}
	return 0;
}