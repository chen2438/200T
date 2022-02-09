#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#define LL long long
#define INF ((1<<31)-1)
const int maxn=4e5+10;
using namespace std;
	LL n,sx,sy,w;
struct node{
	int x=0,dx=0,k=1;
	LL t1=LLONG_MAX,t2=LLONG_MAX;
}a[maxn];

bool cmp(node x,node y){
	return x.t1<y.t1;
}

void output(int n){
	cout<<endl;
	for(int i=0;i<2*n;i++){
		printf("i=%d x=%d dx=%d t1=%lld t2=%lld\n",i,a[i].x,a[i].dx,a[i].t1,a[i].t2);
	}
	cout<<endl;
}

bool First(){
	LL ans=0;
	for(int i=0;i<n*2;i++){
		ans+=abs(a[i].x);
		if(ans>=w){
			cout<<0;
			return true;
		}
	}
	return false;
}

int main(){

	cin>>n>>sx>>sy>>w;
	for(int i=0;i<n;i++){	
		cin>>a[i].x>>a[i+n].x>>a[i].dx>>a[i+n].dx;
	}
	if(First()) return 0;
	output(n); 
	LL ans=0;
	LL t=0;
	while(1){
		t++;
		ans=0;
		for(int i=0;i<n;i++){	
			a[i].x+=a[i].dx;
			a[i+n].x+=a[i+n].dx;
			ans+=abs(a[i].x-sx);
			ans+=abs(a[i+n].x-sy);
		}
		if(ans>=w){
			cout<<t;
			return 0;
		}	
	
	}
	return 0;
}
