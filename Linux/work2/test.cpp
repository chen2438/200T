//机房空调好冷 感冒了 对不住了

#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
#define LL long long
LL a,b,w,x,c;

bool judge(LL t){
	if(b-x*t>=0)
		return c-t<=a;
	return c-t<=a-((x*t-b)/w+((x*t-b)%w!=0));
}
int main(){
	while(cin>>a>>b>>w>>x>>c){
		if(c<=a){
			cout<<0<<endl;
			break;
		}
		LL l=1;
		LL r=(LL)1<<60;
		while(l+3<r){
			LL mid=(l+r)>>1;
			if(judge(mid)) r=mid;
			else l=mid;
		}
		for(LL i=l;i<=r;i++)
			if(judge(i)){
				cout<<i<<endl;
				break;
			}
	}
	return 0;
}