#include<bits/stdc++.h>
#define FOR(i,a,b) for(register int i=(a);i<=(b);i++)
#define mem(a) memset(a,0,sizeof(a))
using namespace std;

int n;
string input;
int data[1000],vst[1000];
string ans;
set <string> s;
void dfs(int p,int step){
	ans[step]=input[p];
	if(step==n-1){
		s.insert(ans);
		return;
	}
	FOR(i,0,n-1){
		if(vst[i]<vst[p]){
			vst[i]++;
			dfs(i,step+1);
			vst[i]--;
		}
	}
}

int main(){
	cin>>n;
	cin>>input;
	ans=input;
	FOR(i,0,n-1){
		mem(vst);
		vst[i]=1;
		dfs(i,0);
	}
	
	set<string>::iterator it;
	string t;
	for(it=s.begin();it!=s.end();it++){
	    printf("%s\n",(*it).c_str());
	}
	cout<<s.size()<<endl;
	return 0;
}

