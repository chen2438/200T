## D. Permutation Restoration

https://codeforces.com/contest/1701/problem/D

### 标签

取整不等式, 贪心, 排列

### 题意

有一个排列 a 和数组 b, 定义 $ b_i = \lfloor \frac{i}{a_i} \rfloor$.

现在给定 b, 求出任意一个符合条件的 a.

题目保证有解.

### 思路

[参考](https://zhuanlan.zhihu.com/p/539664374)

$由于\  b_i = \lfloor \frac{i}{a_i} \rfloor $

$即\ b_i \leq \frac{i}{a_i} \lt b_i+1$ 

$所以\ \frac{i}{b_i+1} \lt a_i \leq \frac{i}{b_i} $

![image-20220709213536648](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207092135698.png)

### 代码

#### AC

![image-20220709213605420](https://nme-200t.oss-cn-hangzhou.aliyuncs.com/template/202207092136469.png)

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define PII pair<int,int>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<PII> v[n+7];
    int ans[n+7];
    FOR(i,1,n){
    	int b,l,r;cin>>b;
        l=i/(b+1)+1;
        if(b==0) r=n;
        else r=i/b;
        v[l].push_back({r, i});
    }
    set<PII> s;
    FOR(i,1,n){
    	for(auto it: v[i]) s.insert(it);
    	auto it=s.begin();
    	ans[(*it).second]=i;
    	s.erase(s.begin());
    }
    FOR(i,1,n) cout<<ans[i]<<" ";
    cout<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
```

#### TLE

```cpp
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;

struct node{
	int a,b,l,r,dif,index;
};//a[i], b[i], l<=a[i]<=b[i], r-l, i

bool cmp1(const node &x,const node &y){
	//if(x.dif==y.dif) return x.index<y.index;
	return x.r<y.r;
}

bool cmp2(const node &x,const node &y){
	return x.index<y.index;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		vector<node> p(n+7);
		vector<int> vst(n+7,0);
		FOR(i,1,n){
			int b,l,r;cin>>b;
			l=i/(b+1)+1;
			if(b==0) r=n;
			else r=i/b;
			p[i]={0,b,l,r,r-l,i};
			//printf("l=%d, r=%d\n",l,r);
		}
		sort(p.begin()+1,p.begin()+n+1,cmp1);//O(nlogn)
		FOR(i,1,n){
			FOR(j,p[i].l,p[i].r){//O(n^2)
				if(!vst[j]){
					vst[j]=1;
					p[i].a=j;
					break;
				}
			}
		}
		sort(p.begin()+1,p.begin()+n+1,cmp2);
		FOR(i,1,n){
			cout<<p[i].a<<" ";
		}
		cout<<endl;
	}
	return 0;
}
```

