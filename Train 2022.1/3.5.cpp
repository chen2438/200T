#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int k;
char rule1[15],rule2[15];
set<string> nums;

void dfs(string s){
	const int ssize=nums.size();
	nums.insert(s);
	if(nums.size()==ssize) return; //判重 
	int len=s.length();
	FOR(i,0,len-1)
		FOR(j,0,k-1)
			if(s[i]==rule1[j]){
				string stmp=s;
				stmp[i]=rule2[j];
				dfs(stmp);
			}
}
int main(){
	string sn;
	cin>>sn>>k;
	FOR(i,0,k-1)
		cin>>rule1[i]>>rule2[i];
	dfs(sn);
	cout<<nums.size();
	return 0;
}
