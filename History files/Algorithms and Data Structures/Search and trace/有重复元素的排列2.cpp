#include<bits/stdc++.h>
#define FOR(i,a,b) for(register int i=(a);i<=(b);i++)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;

int n,sum,cnt[1000]={};
string data;
char ans[1000];

void dfs(int step){
	FOR(i,0,25){
		if(cnt[i]>0){
			ans[step]=char(i+'a');
			if(step==n-1){
				sum++;
				printf("%s\n",ans);
			}
			else{
				cnt[i]--;
				dfs(step+1);
				cnt[i]++;
			}
		}
	}
}

int main(){
	cin>>n>>data;
	FOR(i,0,n-1){
		cnt[data[i]-'a']++;
	}
	dfs(0);
	cout<<sum<<endl;
	return 0;
}


