#include<bits/stdc++.h>
using namespace std;
const int N=10000+10;
int v[N],le[N],ri[N];
int f[N];
int main(){
	cout<<"1 1\n"<<"2 1\n";
	for(int n=3;n<=100;++n){
		fill(v+1,v+n+1,0),v[1]=v[n]=1;
		int ans=2;
		while(1){
			for(int i=1;i<=n;++i) le[i]=v[i]?i:le[i-1];
			for(int i=n;i>=1;--i) ri[i]=v[i]?i:ri[i+1];
			int len=1,pos;
			for(int i=1;i<=n;++i)
				if(min(i-le[i],ri[i]-i)>len) len=min(i-le[i],ri[i]-i),pos=i;
			if(len==1) break;
			v[pos]=1,++ans;
		}
		cout<<n<<" "<<ans<<endl;
	}
	return 0;
}
