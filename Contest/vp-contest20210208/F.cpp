//#pragma GCC optimize(2)
//clock_t st=clock();
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

const int maxn=1e5+7;
int a[maxn];

int main(){
	int n,sum=0;
	cin>>n;
	FOR(i,1,n){
		scanf("%d",a+i);
		sum+=a[i];
	}
	if(sum%2==1){
		cout<<"NO";
		return 0;
	}
	sort(a+1,a+n+1);

	while(a[n]!=0){
		int dx=a[n-1]-a[n-2];
		if(a[n-2]==0)break;
		int p=n-2;
		while(a[p]==a[p-1]) p--;
		a[n-1]-=dx+1;
		a[n]-=dx+1;
		swap(a[n-1],a[p]);
		//if(a[n]==0) sort(a+1,a+n+1);
		if(a[n]==0){
			sum=0;
			FOR(i,1,n){
				sum+=a[i];
			}
			if(sum%2==0) {cout<<"YES";return 0;}
			else {cout<<"NO";return 0;}
		//	sort(a+1,a+n+1);
		}
	}
	
	if(a[n-1]!=a[n]){
		cout<<"NO";
	}
	else cout<<"YES";
	
	return 0;
}
