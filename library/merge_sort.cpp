#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(register int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(register int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

int tmp[int(1e5)]={};
void merge_sort(int q[],int l,int r){
	
    if(l>=r) return;
    int mid=l+r>>1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid and j<=r){
    	if(q[i]<=q[j]) tmp[k++]=q[i++];
        else tmp[k++]=q[j++];
	}
    while(i<=mid) tmp[k++]=q[i++];
    while(j<=r) tmp[k++]=q[j++];
    for(i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
}

int main(){
	int n,a[int(1e5)];
	cin>>n;
	FOR(i,0,n-1) scanf("%d",a+i);
	merge_sort(a,0,n-1);
	FOR(i,0,n-1) printf("%d ",a[i]);
	return 0;
}

