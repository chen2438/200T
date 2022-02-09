#include<bits/stdc++.h>
using namespace std;
int sum1[1000],sum2[1000];
int a[1000];
int n,m;
int lowbit(int x){
	return x&(-x);
}
void update(int x,int w){//¸üÐÂÐ§¹û£º°ÑxÎ»ÖÃºóÃæËùÓÐµÄÊýµÄÖµ+w
	for(int i=x;i<=n;i+=lowbit(i)){
		sum1[i]+=w;//Î¬»¤Ç°×ººÍc[i]
		sum2[i]+=w*(x-1);//Î¬»¤Ç°×ººÍc[i]*(n-1)
	}
}
void range_update(int l,int r,int val){//¸üÐÂÐ§¹û£º°ÑlÎ»ÖÃµ½rÎ»ÖÃËùÓÐµÄÊýµÄÖµ+w
	update(l,val);
	update(r+1,-val);
}
int sum(int x){//Çó1->xµÄºÍ
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i)){
		ans+=x*sum1[i]-sum2[i];
	}
	return ans;
}
int range_ask(int l,int r){//Çól->rµÄºÍ
	return sum(r)-sum(l-1);
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		a[0]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			update(i,a[i]-a[i-1]);//Î¬»¤²î·ÖÊý×é
		}
	}
	return 0;
}
