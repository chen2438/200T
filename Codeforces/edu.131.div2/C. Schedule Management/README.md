https://codeforces.com/contest/1701/problem/C

### 标签

二分

### 题意

有 n 人要完成 m 项任务, n <= m, 每一项任务都有一个精通的人，精通的人完成它需要 1 h, 其他人完成需要 2 h.

问至少需要多少小时, 才能将全部任务完成.

### 思路

二分答案, 见代码注释.

### 代码

#### AC

![image-20220709135124065](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-09-055124.png)

![image-20220709135133688](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-09-055134.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

#define int long long
const int N=2e5+7;
int n,m;
int task[N];

//二分的特征是假设已经知道答案, check函数根据答案反推出这个答案成不成立
bool check(int t){
	int sum=m;//注意sum多次减去数可能会造成int负数溢出
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
```

注意 sum 多次减去数可能会造成 int 负数溢出.

![image-20220709135206808](http://nme-200t.oss-cn-hangzhou.aliyuncs.com/notes/2022-07-09-055207.png)

#### TLE

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

int task[200007];
int stat[200007];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		memset(task,0,sizeof task);
		int n,m; cin>>n>>m;
		FOR(i,1,n) stat[i]=1;
		FOR(i,1,m){
			int x;cin>>x;
			task[x]++;
		}
		int sum=m, ans=0;
		while(sum>0){
			ans++;
			FOR(i,1,n){
				if(sum==0) break;
				if(task[i]>0){
					task[i]--;
					stat[i]++;
					sum--;
				}
			}
			FOR(i,1,n){
				if(sum==0) break;
				if(stat[i]>ans or task[i]>0) continue;
                int max0=0,pos;
                FOR(i,1,n){
                    if(max0<task[i]) max0=task[i],pos=i;
                }
                task[pos]--;
                stat[i]+=2;
                sum--;
			}
		}
		FOR(i,1,n) ans=max(ans,stat[i]);
		cout<<ans-1<<endl;
	}
	return 0;
}
```

