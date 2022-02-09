#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a));
using namespace std;
int bin[200][40];
void d2b(int val,int mbit,int th){
	ROF(i,mbit-1,0){
		if(val & (1 << i))
			bin[th][i]++;
	}
//	reverse(bin[th],bin[th]+mbit);
}
int main(){
	int T;
	cin>>T;
	int n,l,data,ans,one;
	while(T--){
		ans=0;
		mem(bin);
		cin>>n>>l;
		FOR(i,0,n-1){
			cin>>data;
			d2b(data,l,i);
		}
		FOR(i,0,l-1){
			one=0;
			FOR(j,0,n-1)
				if(bin[j][i]) one++;
			if(one>n-one) ans|=(1<<i);
		}
		cout<<ans<<endl; 
		
	}
} 
