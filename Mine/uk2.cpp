#include<bits/stdc++.h>
using namespace std;
int main(){
	int len[1001],a[1001];
	int n;
	while(cin>>n and n!=0){
		int i=0,ans;
		while(n--){
			cin>>a[i];
			ans=a[i];
			for(int j=0;j<i;j++)
				if(a[i]>a[j] and ans<len[j]+a[i]) ans=max(ans,len[j]+a[i]);
			len[i]=ans;
			i++;
		}
		ans=len[0];
		for(int j=0;j<i;j++)
			ans=max(ans,len[j]);
		cout<<ans<<endl;
	}
    return 0;
}
