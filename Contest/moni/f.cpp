#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#define LL long long

const int maxn=4e5+10;
using namespace std;
LL n,sx,sy,w;
LL dx1=0,x1=0;
struct node{
	LL x=0,dx=0,k=1;
	LL t1=LLONG_MAX,t2=LLONG_MAX;
}a[maxn];

bool cmp(node x,node y){
	return x.t1<y.t1;
}

void output(int n){//用于调试 
	cout<<endl;
	for(int i=0;i<2*n;i++){
		printf("i=%d x=%d dx=%d t1=%lld t2=%lld\n",i,a[i].x,a[i].dx,a[i].t1,a[i].t2);
	}
	cout<<endl;
}

void input(){//输入 
	cin>>n>>sx>>sy>>w;
	for(int i=0;i<n;i++){	
		cin>>a[i].x>>a[i+n].x>>a[i].dx>>a[i+n].dx;
		a[i].x-=sx;
		a[i+n].x-=sy;	
	}
}

bool First(){//当 时间=0 时特判 
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

void init(){//初始化 
	for(int i=0;i<2*n;i++){	
		if(a[i].dx*a[i].x<0){
			a[i].t1=-a[i].x/a[i].dx;
			a[i].t2=a[i].t1+1;
			if(a[i].x<0) a[i].k*=-1;
		}
		if(a[i].dx*a[i].x>0){
			dx1+=abs(a[i].dx);
			x1+=abs(a[i].x);
		}
		if(a[i].x==0) dx1+=abs(a[i].dx);
		if(a[i].dx==0) x1+=abs(a[i].x);
	}
//	output(n);
	sort(a,a+n*2,cmp);
}


int main(){
	input();
	if(First()) return 0;//时间为0 
	init();
	LL dx2=dx1,x2=x1,t,l,r;
	for(int j=0;j<n*2;j++){
		if(a[j].dx*a[j].x<0){
			dx2+=a[j].k*a[j].dx;
			x2+=a[j].k*a[j].x;
		}
	}
	
	if((w-x2)%dx2==0) t=(w-x2)/dx2;
	else t=(w-x2)/dx2+1;
	l=0;r=a[0].t1;
	if(t>=0 and t<=r){
		cout<<t;
		return 0;
	}
	
	for(int i=0;i<n*2+2;i++){
		l=a[i].t2;
		r=a[i+1].t1;
//		cout<<l<<" "<<r<<endl; 用于调试 

		if(a[i].dx*a[i].x<0){
			dx2-=a[i].k*a[i].dx;
			x2-=a[i].k*a[i].x;
			a[i].k*=-1;
			dx2+=a[i].k*a[i].dx;
			x2+=a[i].k*a[i].x;
		}
		
		if(dx2==0) continue;
		if((w-x2)%dx2==0) t=(w-x2)/dx2;
		else t=(w-x2)/dx2+1;
		if(t>=l and t<=r){
			cout<<t;
			return 0;
		}
	}
	return 0;
}
