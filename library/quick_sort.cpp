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

void qsort(int a[],int l,int r){
    int mid=a[(l+r)/2];
    int i=l,j=r;
    while(i<j){
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    if(l<j) qsort(a,l,j);
    if(r>i) qsort(a,i,r);
}

int main(){
	int n,a[int(1e5)];
	cin>>n;
	FOR(i,0,n-1) scanf("%d",a+i);
	qsort(a,0,n-1);
	FOR(i,0,n-1) printf("%d ",a[i]);
	return 0;
}

