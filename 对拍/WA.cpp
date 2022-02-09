#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e4+5;
ll a[M],s[M];
ll l,p,n,sign=1,temp,maxn,cnt;
int main(){//input
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",s+i,a+i);
	}
	scanf("%lld%lld",&l,&p);
	
	for(int i=1;i<=n;i++){//distance between initial to station
		s[i]=l-s[i];
	}
	
	for(int d=n/2+1;d>0;d--){//sort
		for(int i=1;i+d<=n;i++){
			if(s[i]>s[i+d]){
				ll t1=s[i],t2=a[i];
				s[i]=s[i+d],a[i]=a[i+d];
				s[i+d]=t1,a[i+d]=t2;
			}
		}
	}
	
	for(int i=1;i<=n&&sign;i++){
		if(p<s[i]){//judge 
			temp=0,maxn=0;
			for(int j=1;j<=i-1;j++){//select and judge
				if(a[j]>maxn){
					maxn=a[j];
					temp = j;
				}
			}
			if(temp==0){
				sign = 0;
				break;
			}
			p+=maxn;
			cnt++;
			a[temp]=0;
			if(p<s[i])i--;//if can not ,again
			if(p>=l)break;
		}
	}
	if(sign)printf("%lld\n",cnt);
	else printf("%d\n",-1);
	return 0;
}
