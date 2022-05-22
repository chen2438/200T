#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		while(cin>>n){
			int a[110]={},x=0;
			memset(a,-1,sizeof(a));
			for(int i=1;i<=n;i++){
				x++;
				for(int j=x;j<=n;j+=x)
					a[j]*=-1;
			}
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1) cnt++;
			cout<<cnt<<endl;
		}
	}
	return 0;
}
