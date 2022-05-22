#include<iostream>
using namespace std;
int main(){
	int t;
	int a[20]={0};
	while(cin>>t and t!=-1){
		a[0]=t;
		int i=1,ans=0;
		while(cin>>a[i] and a[i]!=0)
			i++;
		for(int j=0;j<i;j++)
			for(int k=0;k<i;k++)
				if(a[j]==2*a[k]) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
