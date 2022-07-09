#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int N=2e5+7;
int n,m;
int task[N];

//二分的特征是假设已经知道答案, check函数根据答案反推出这个答案成不成立
bool check(int t){
	int sum=m;
	FOR(i,1,n){
		if(task[i]>=t*1){//这个工人全部用于完成精通任务
			sum-=t;//完成了t个精通任务
		}
		else{//这个工人要同时完成精通和非精通任务
			sum-=task[i];//完成了所有他的精通任务
			sum-=(t-task[i])/2;//完成了 剩余时间/2 取整的非精通任务
		}
	}
	if(sum<=0) return true;//完成了所有任务
	else return false;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		memset(task,0,sizeof task);
		FOR(i,1,m){
			int x;cin>>x;
			task[x]++;
		}
		int l=1,r=1e9;//r=2*m也可以,复杂度相同
		while(l<r){//整数二分
			int mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		cout<<r<<endl;
	}
	return 0;
}
